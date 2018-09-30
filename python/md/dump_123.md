----------------
title : 씹어먹는 C 언어 - <23 - 2. 파일 하고 이야기 하기 (파일 입출력)>
cat_title : 23 - 2. 파일 하고 이야기 하기 (파일 입출력)
next_page : 125
--------------



이번 강좌에서는


* 파일 위치 지시자(File `Position Indicator)` 에 대한 이해

* `fseek` 함수 다루기

* `fopen` 에서 `"r+", "w+", "a", "a+"` 형태에 대해 배우고, 쓰기/읽기 전환 시 문제점에 대해 알기

* `fprintf` 함수와 `fscanf` 함수를 사용하기

* 도서 관리 프로그램에 입출력 처리 적용하기

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F151829424D2B0FC122EAB3)

  안녕하세요~ 여러분. 파일 입출력의 관한 두 번째 강좌 입니다! 사실 지난번에는 뭔가 아쉬움이 남게 끝냈었습니다. 파일 입출력으로 무언가 제대로된 프로그램도 만들어 보지 않고 단순히 어떻게 사용하는지에 대해서만 간단히 다루어 보았었는데 이번에는 본격적으로 파일 입출력을 이용해서 무언가를 해보도록 하겠습니다.


### 파일 위치 지시자(File `Position Indicator)`

  지난번에 파일 위치 지시자에 관해서 대충 설명하고 나갔는데요, 지난번의 설명이 무언가 부족하다는 느낌이 강하게 들어서 여기서 다시 한번 짚고 넘어가도록 하겠습니다.  스트림의 기본 모토는 바로 ‘순차적으로 입력을 받는다’ 입니다. 즉 스트림에서 데이터를 입력 받을 때 에는 질서 정연하게 앞에 있는 데이터 먼저 순서대로 읽어들이게 되죠. 뒤에서 부터 거꾸로 읽는다나 데이터들을 뛰어 넘으며 읽어 들인다는 듯한 비정상적인 짓들을 하지 않습니다. 이렇게 순차적으로 읽어들이는 것을 가능하게 해주는 것이 바로 ‘파일 위치 지시자’ 때문입니다.

```cpp
/* 파일에서 문자를 하나씩 입력 받는다 */
#include <stdio.h>

int main()
{
    FILE *fp = fopen("some_data.txt", "r");
    char c;

    if(fp == NULL)
    {
        printf("file open error ! \n");
        return 0;
    }

    while((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
}
```




성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F206F774A4D29DC64132DAF)



참고로 아래는 `some_data.txt` 에 들어 있엇던 내용입니다. 당연하게도 화면에 출력된 내용과 정확히 일치합니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1666014A4D29DC642A3D72)




  위 소스 코드에서 흥미로왔던 점은 없나요? 사실 이전 강좌에서도 다루었던 예제이지만 무언가 궁금한 점이 있을 것입니다. 바로 `fgetc(fp)` 를 실행할 때 마다 파일에 그 다음 문자를 입력 받는 다는 점이지요. 컴퓨터는 어떻게 어디까지 읽어들었는지를 알고 이전에 입력 받았던 문자 바로 다음 문자를 입력 받는 것일까요? 그 이유는 간단합니다. 다음에 입력 받을 위치를 미리 표시해 놓으면 되지요. 이렇게 '다음에 입력 받아야 할 위치' 를 기억해 놓은 것을 '파일 위치 지시자' 가 하는 일입니다. 파일 위치 지시자는 파일에서 다음에 입력 받을 부분의 위치를 가리키고 있습니다.
  예를 들어 위 예제에서 `fgetc` 를 세 번 호출했다고 해봅시다. 그렇다면 파일 위치 지시자는 아래 그림과 같은 위치를 가리키고 있게 됩니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F196F7D564D29DE910B763E)


  어때요? 간단하지요. `fgetc` 를 호출하기 전에는 `T` 를 가리켰다가 한 번 호출하면 `H,` 두 번 호출하면 `E,` 세번 호출하면 `R` 을 가리키게 되지요. 따라서 다음번 `fgetc` 호출에서는 `R` 을 읽어들이고 파일 위치 지시자를 한 칸 옆으로 이동시킵니다.
  이렇게 파일 위치 지시자가 다음으로 한 칸 씩 움직이는 바람에 데이터를 순차적으로 읽어들일 수 있게 되는 것이지요. 하지만 놀랍게도 C 언어에서는 파일 위치 지시자의 위치를 사용자 마음대로 바꿀 수 있게 해주는 여러가지 함수들을 지원해주고 있습니다. 그 중 대표적으로 가장 많이 사용하는 `fseek` 함수가 있지요. `fseek` 함수는 다음과 같이 생겼습니다. (자세한 설명은 [ C 언어 함수 레퍼런스 - fseek 함수](http://itguru.tistory.com/72)를 참조하세요)

```info
int fseek ( FILE * stream, long int offset, int origin );
```



  여기서 `stream` 에는 우리가 파일 위치 지시자를 옮기고 싶은 스트림의 포인터를, `origin` 에는 어디서 부터 옮길지, 그리고 `offset` 에는 얼마만큼 옮길지에 대한 정보가 들어가게 됩니다. 참고로 `origin` 에는 `SEEK_SET, SEEK_CUR, SEEK_END` 들이 있는데 각각 파일의 시작, 현재 파일 위치 지정자의 위치, 파일의 끝을 의미합니다. 그리고 `offset` 에는 `origin` 으로 부터 얼마나 옮길 것인지 숫자를 써주면 됩니다. 재미있는 점은 `+` 값을 쓰면 오른쪽으로 (위의 사진을 기준으로), - 값을 쓰면 왼쪽으로 파일 위치 지정자가 움직입니다.

```cpp
/* fseek 함수 예제 */
#include <stdio.h>
int main()
{
    FILE *fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if(fp == NULL)
    {
        printf("file open error ! \n");
        return 0;
    }

    fgets(data, 5, fp);
    printf("입력 받은 데이터 : %s \n", data);

    c = fgetc(fp);
    printf("그 다음에 입력 받은 문자 : %c \n", c);

    fseek(fp, -1, SEEK_CUR);

    c = fgetc(fp);
    printf("그렇다면 무슨 문자가? : %c \n", c);

    fclose(fp);
}
```


성공적으로 컴파일 하였다면



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1203C2554D2A94FE0D0274)



와 같이 나오는 것을 볼 수 있습니다. 참고로, `some_data.txt` 에 있었던 내용은 이전 내용과 동일하게 `There is some data in this FILE!!!!` 입니다. 소스를 살펴보자면,



```cpp
    fgets(data, 5, fp);
```



  위와 같이 `fgets` 함수를 통해서 `fp` 로 부터 입력을 받습니다. 이 때, 문자열 형태로 입력을 받는데 입력을 받을 때 \n 이 나올 때 까지 입력을 받거나 (두번째 인자의 크기 `- 1)` 만큼 입력을 받을 때 까지 입력을 받게 됩니다. 위 경우 \n 이 나오기 전에 4 바이트 만큼 입력을 받으므로 `data` 에는 "Ther" 이란 내용의 문자열이 들어갑니다. 참고적으로 왜 1 만큼 뺀 크기로 입력을 받냐면, `data` 에 문자열을 구성하기 위해 맨 뒤에는 언제나 `NULL` 문자를 위한 자리를 만들어주어야 하기 때문이죠.
  이렇게 입력을 받게 된다면 이제 파일 위치 지정자는 `e` 를 가리키게 됩니다.





```cpp
   c = fgetc(fp);
   printf("그 다음에 입력 받은 문자 : %c \n", c);
```



  그 다음에 `fgetc` 로 `fp` 에서 문자를 받아 오면 역시 생각했던 대로 `e` 가 출력이 되겠지요. 그리고 파일 위치 지정자는 다시 한 칸 옆으로 옮겨가서 ' ' 을 가리키게 됩니다. 띄어쓰기도 엄연한 문자이지요. (즉, 띄어쓰기에도 `ASCII` 값이 당연히 대응되어 있습니다)


```cpp
    fseek(fp, -1, SEEK_CUR);
```



  드디어 `fseek` 함수를 사용했습니다. 앞에서 말했듯이 `SEEK_CUR` 은 현재 파일 위치 지정자의 위치를 나타내고, 두번째 인자로 -1 을 전달했으므로 왼쪽으로 1 만큼 옮기라는 것이지요. 즉, 현재 파일 위치 지정자의 위치에서 왼쪽으로 1 만큼 다시 옮겼으니 ' ' 을 가리키고 있던 파일 위치 지정자가 이전의 'e' 를 가리키게 됩니다. 따라서 다시
```cpp
    c = fgetc(fp);
    printf("그렇다면 무슨 문자가? : %c \n", c);
```


을 호출하여 문자를 입력 받으면 다시 `e` 가 나오게 되는 것이지요. 어때요. 간단하지요?

```cpp
/* 파일의 마지막 문자를 보기*/
#include <stdio.h>

int main()
{
    FILE *fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if(fp == NULL)
    {
        printf("file open error ! \n");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    c = fgetc(fp);
    printf("파일 마지막 문자 : %c \n", c);

    fclose(fp);
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F15610F344D2AA01C1C69E1)

와 같이 잘 나옵니다. 참고로 `some_data.txt` 에는 여태까지 위에서 써왔던 데이터인 `There is some data in this FILE!!!!` 가 들어있습니다. 이 때 이 파일의 마지막 문자는 `!` 가 되겠지요.

```cpp
    fseek(fp, -1, SEEK_END);
```


   위 소스에서 가장 중요한 부분은 딱 위 하나 입니다. 파일 위치 지정자를 파일의 맨 끝에서 한 칸 왼쪽으로 간 부분으로 옮깁니다. 왜 한 칸 왼쪽으로 옮기냐면, 맨 끝으로 옮기게 되면 그 부분에는 `EOF` (파일의 끝) 을 나타내는 것이 들어 있기 때문에 우리가 원하는 결과가 아니게 되지요. 우리가 파일에 입력한 맨 마지막 문자는 `EOF` 바로 왼쪽에 위치한 `!` 가 됩니다.




### 파일에 쓰기, 읽기 같이 하기


  여태까지 여러분은 하나의 파일에 읽기 또는 쓰기 작업을 한 번에 하나씩 밖에 할 수 없었습니다. 그런데 다행스럽게도 `fopen` 에는 하나의 파일에 대해 읽기/쓰기를 모두 할 수 있는 방법을 지원해줍니다.

```cpp
/* fopen 의 "r+" 인자 이용해보기 */
#include <stdio.h>
int main()
{
    FILE *fp = fopen("some_data.txt", "r+");
    char data[100];

    fgets(data, 100, fp);
    printf("현재 파일에 있는 내용 : %s \n", data);

    fseek(fp, 5, SEEK_SET);

    fputs("is nothing on this file", fp);

    fclose(fp);
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F202B06554D2AAC4813A052)

와 같이 잘 나옵니다. 그리고 수정된 `some_data.txt` 의 모습은 아래와 같습니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1827FB554D2AAC491AC05D)

아주 잘 되는군요. 일단 맨 처음에

```cpp
    FILE *fp = fopen("some_data.txt", "r+");
```


같이 하였습니다. 이는 `some_data.txt` 를 "읽기 및 쓰기형식으로 열겠다" 라는 뜻인데, 파일이 존재하지 않는다면 열지를 않겠다는 의미 입니다. 만일 파일이 존재한다면 파일의 내용을 지우지 않지요. 반면에 뒤에서 배울 "w+" 도 "읽기 및 쓰기 형식으로 열겠다" 이지만, 이 경우 파일이 존재하지 않는다면 파일을 새로 만들고 파일이 존재한다면 파일의 내용을 싹 지워버리게 됩니다.

```cpp
    fgets(data, 100, fp);
    printf("현재 파일에 있는 내용 : %s \n", data);
```


를 통해 파일의 있는 내용들을 모두 읽어들였습니다 (정확히 말하면 최대 100 바이트 까지 읽지만 우리의 파일의 내용은 100 바이트 보다 작으므로 모두 읽어들여다고 보면 됩니다). 그리고 이와 함께 파일 위치 지정자도 파일 맨 끝을 가리키고 있겠지요.

```cpp
    fseek(fp, 5, SEEK_SET);
```


이에 위와 같이 `fseek` 함수를 이용하여 파일의 맨 앞에서 5 칸 떨어진 곳으로 이동해봅시다. 0 칸 떨어졌을 때는 `T, 1` 칸은 `h, ...` 와 같은 방식으로 세보면 5 칸 떨어진 곳은 ' ' 임을 알 수 있습니다. (공백 문자가 위치한 곳) 그리고 이제 여기에

```cpp
    fputs("is nothing on this file", fp);
```


를 하게 되면 이전에 있던 내용은 무시하고 `is nohting on this file` 이 차지하는 만큼 덮어 씌우기가 됩니다. 따라서 위의 사진에서도 나타나듯이 파일에 위와 같이 나타나게 되지요.

```cpp
/* 특정한 파일을 입력 받아서 소문자를 대문자로, 대문자를 소문자로 바꾸는 프로그램*/
#include <stdio.h>
int main()
{
    FILE *fp = fopen("some_data.txt", "r+");
    char c;

    if(fp == NULL)
    {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        /* c 가 대문자일 경우 */
        if(65 <= c && c <= 90)
        {
            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);

        }
        /* c 가 소문자일 경우*/
        else if(97 <= c && c <= 122)
        {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
        }
    }

    fclose(fp);
}

```

성공적으로 컴파일 하였다면 원래는 아래와 같은 파일이


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F1404963D4D2AB75D190A83)

와 같이 괴상하게 변해버렸습니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F187FE03D4D2AB75D1FD0D9)

사실 프로그램이 종료 되지도 않아서 강제로 종료해야만 했었습니다.

도대체 왜 이런 일이 발생한 것일까요?

```cpp
while ((c = fgetc(fp)) != EOF)
    {
        /* c 가 대문자일 경우 */
        if(65 <= c && c <= 90)
        {
            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);

        }
        /* c 가 소문자일 경우*/
        else if(97 <= c && c <= 122)
        {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
        }
```


위 소스를 보면 큰 문제는 없어 보입니다. 일단 대문자일 경우만 살펴보면 `ASCII` 표를 보면 영어 대문자의 경우 값이 `65 ~ 90` 에 있으므로 위와 같이 `if` 문을 설정하면 대문자들을 처리할 수 있습니다.

```cpp
            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);
```


  사실 위 과정에서는 문제가 없습니다.
  예를 들어서 `What?` 이란 문자열이 있을 때 `c` 에 `W` 가 들어있다면 현재 파일 위치 지시자는 그 다음인 `h` 를 가리키고 있을 것입니다. 따라서 `w` 부분에 `W` 를 쓰기 위해 파일 위치 지시자를 한 칸 뒤로 옮겨서 `w` 를 가리키게 하고, `fputc` 를 통해 (c 에 32 를 더한 값, 아스키 코드표를 보면 그 대문자에 해당하는 소문자값 임을 알 수 있다) 을 써서 결과적으로 `what?` 가 됩니다.

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F170CE3404D2ABADE2D991F)

그런데 도대체 무엇이 문제일까요? 사실 그 이유는 간단합니다.

스트림 작업에서 읽기/쓰기 를 변환할 때 에는 반드시 `fflush` 함수를 호출하거나 `fseek` 이나 `rewind` 와 같은 함수를 호출하여 파일 위치 지정자를 다시 설정해주어야 하기 때문(자세한 내용은 [fopen 함수 레퍼런스](http://itguru.tistory.com/58)를 참조)입니다. 따라서 반드시 위와 같이 쓰기 작업 후 다시 읽기 작업 (while 문에서 fputc 를 통해 읽기 작업이 수행된다) 을 할 때 에는 `fflush` 나 `fseek` 함수를 호출해 주시기 바랍니다.

이를 토대로 코드를 수정해보았습니다.

```cpp
#include <stdio.h>

int main()
{
    FILE *fp = fopen("some_data.txt", "r+");
    char c;

    if(fp == NULL)
    {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        /* c 가 대문자일 경우 */
        if(65 <= c && c <= 90)
        {
            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);
            /*

            쓰기 - 읽기 모드 전환을 위해서는 무조건
            fseek 함수와 같은 파일 위치 지정자 설정 함수들을
            호출해야 한다.

            */
            fseek(fp, 0 , SEEK_CUR);
        }
        /* c 가 소문자일 경우*/
        else if(97 <= c && c <= 122)
        {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0 , SEEK_CUR);
        }
    }

    fclose(fp);
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F1404963D4D2AB75D190A83)

위와 같았던 파일 내용이


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F15787D3D4D2AB75D3556F0)

아래와 같이 예쁘게 바뀝니다.
```cpp
            /*

            쓰기 - 읽기 모드 전환을 위해서는 무조건
            fseek 함수와 같은 파일 위치 지정자 설정 함수들을
            호출해야 한다.

            */
            fseek(fp, 0 , SEEK_CUR);
```


위 소스에서 굳이 파일 위치 지정자 의 위치를 옮길 필요가 없음에도 불구하고 `fseek` 함수를 통해 파일 위치 지정자를 설정하였습니다. 사실 위와 같이 `fseek` 함수를 호출하면 파일 위치 지정자는 하나도 옮겨지지 않습니다. 단순히 쓰기작업에서 읽기 작업으로 바꾸기 위해 `fseek` 함수를 호출한 것 뿐이지요.

만일 위의 `fseek` 이 마음에 들지 않는다면

```cpp

            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);

          fflush(fp);
```


로 하셔도 됩니다. 아무튼 `fseek` 이든 `fflush` 함수든 호출해 주어야만 합니다.



### `fopen` 함수의 기타 인자 사용


```cpp
/* fopen 의 'append' 기능 사용*/
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "a");
    char c;
    if(fp == NULL)    {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }
    /* 아래 내용이 파일 뒤에 덧붙여진다.*/
    fputs("IS ADDED HAHAHAHA", fp);
    fclose(fp);
}
```

성공적으로 컴파일 하였다면아래와 같았던 파일 내용이


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F153F80554D2ABDF3340478)

아래 처럼 바뀝니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F113F13554D2ABDF4337D6B)

  `fopen` 부분을 살펴보면

```cpp
    FILE *fp = fopen("some_data.txt", "a");
```


  로 파일을 "a" 형식을 열었습니다. 이 뜻은 파일을 '덧붙이기(append)' 형식으로 연다는 의미입니다. 기존의 "w" 로 열었을 때에는 파일의 내용이 모두 지워지는 대신에 맨 앞부터 내용이 쓰여졌는데 덧붙이기 형식에서는 파일의 맨 끝부분 부터 내용이 쓰여지고 앞 부분은 전혀 건들여지지 않습니다. 즉, 이전에 파일에 들어가 있었던 내용들은 아주 소중하게 보호가 됩니다.

"r+" 나 "w+" 와 마찬가지로 "a+" 형식도 있는데 이도 마찬가지로 읽기/덧붙이기 를 번갈아가면서 할 수 있습니다. 참고로 읽는 작업은 파일 어디에서든지 사용할 수 있지만 쓰기 작업의 경우 아무리 파일 위치 지시자를 이동 시켜 보아도 '기존파일의 끝 부분 위치' 에서 부터만 쓸 수 있습니다.



### `fscanf` 사용하기




```cpp
/* fscanf 이용하기 */
#include <stdio.h>

int main()
{
    FILE *fp = fopen("some_data.txt", "r");
    char data[100];

    if(fp == NULL)
    {
        printf("파일 열기 오류! \n");
        return 0;
    }

    printf("---- 입력 받은 단어들 ---- \n");

    while (fscanf(fp,"%s", data) != EOF)
    {
        printf("%s \n", data);
    }

    fclose(fp);
}
```


  성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F115F7C394D2AA3EE029D1D)

와 같이 잘 나옵니다. `fscanf` 함수는 우리가 여태까지 사용해왔던 `scanf` 함수와 아주 아주 유사한데, 사실 `scanf` 가 `stdin` 에서만 입력을 받고 `fscanf` 는 임의의 스트림에서도 입력을 받을 수 있는 좀더 일반화 된 함수라고 보시면 됩니다.

`fscanf` 함수의 첫번째 인자로 입력을 받을 스트림을 써주게 되는데, 따라서

```cpp
fscanf(stdin, "%s", data);
scanf("%s", data);

```

는 정확히 일치하는 문장들 입니다. 아무튼 `fscanf` 는 사용자가 지정한 형식에 맞게 데이터를 읽어오게 되는데 `fgets` 와는 달리 띄어쓰기나 탭 문자들도 모두 인식하므로 위와 같이 각각의 단어들을 읽어오는데 요긴하게 사용할 수 있습니다.

```cpp
    while (fscanf(fp,"%s", data) != EOF)
    {
        printf("%s \n", data);
    }
```


  일단 위 소스에서 가장 중요한 부분을 봅시다. `fscanf` 를 통해 `fp` 에서 문자열을 읽어오고 있는데 `fgets` 는 \n 이 나올 때 까지 하나의 문자열로 보고 받아들이지만 `fscanf` 는 띄어쓰기나 탭 문자(\t), \n 들 중 어느 하나가 나올 때 까지 입력 받으므로 파일에서는 각 단어들을 하나씩 읽어들이게 됩니다. 물론 읽어 들인 만큼 파일 위치 지정자는 이동하게 되지요. 이 때 `fscanf` 가 더이상 새로운 데이터를 입력을 받을 수 없을 경우에는 `EOF` 를 리턴하게 됩니다. 즉, 파일의 끝에 도달하면 `EOF` 를 리턴하여 `while` 문을 빠져나갑니다.

```cpp
/* 파일에서 'this' 를 'that' 으로 바꾸기*/
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("some_data.txt", "r+");
    char data[100];

    if(fp == NULL)
    {
        printf("파일 열기 오류! \n");
        return 0;
    }

    while (fscanf(fp,"%s", data) != EOF)
    {
        if(strcmp(data, "this") == 0)
        {
            fseek(fp, -(long)strlen("this"), SEEK_CUR);
            fputs("that", fp);

            fflush(fp);
        }
    }

    fclose(fp);
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F1622D03A4D2AC95E15E280)

위와 같았던 파일이


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F1128033A4D2AC9630CFAC8)

아래 처럼 `this` 들이 모두 `that` 으로 바뀐 것을 보실 수 있습니다. 사실 그 원리는 아주 간단합니다.

```cpp
     while (fscanf(fp,"%s", data) != EOF)
    {
        if(strcmp(data, "this") == 0)

```

이전 예제에서와 같은 방식으로 `fscanf` 들을 통해 파일에서 단어들을 입력받는데, 각각의 단어들을 `strcmp` 함수를 이용하여 `this` 와 같은지 비교를 하지요. 만일 같다면 이제 `this` 를 `that` 으로 덮어 씌우기만 하면 됩니다.

```cpp
             fseek(fp, -(long)strlen("this"), SEEK_CUR);
            fputs("that", fp);
```

`fscanf` 에서 “this” 를 입력 받은 시점에서 파일 위치 지정자는 `this` 바로 다음 문자를 가리키고 있으므로 “this” 의 길이만큼 왼쪽으로 이동시킨다면 파일 위치 지정자는 `t` 를 가리키게 되지요. 이제 이 상태에서 `fputs` 로 “that” 을 쓴다면 “this” 가 들어가 있던 자리에 “that” 이 정확히 자리를 대체하게 됩니다. 그리고 마지막으로

```cpp
             fflush(fp);
```

위 쓰기 작업이 끝나면 다시 `while` 문에서 `fscanf` 로 읽기 작업을 하게 되므로 `fflush` 를 사용해 주어야만 합니다. 물론 이전 처럼 `fseek` 를 사용하셔도 되고요

### 파일 입출력 실제로 적용해보기



이제 본격적으로 파일 입출력을 이용해서 무언가를 해보아야 겠죠?
가장 먼저 여태가지 만들어보았던 도서 관리 프로그램에 입출력 기능을 적용시켜봅시다.

일단 아래는 입출력 기능을 적용시키기 전 단계의 도서 관리 프로그램으로 여태까지 배운 새로운 기술들을 이용하여 작성하였습니다.




```cpp

/*
지난번에 만들었었던 도서 관리 프로그램으로 우리가 여태까지 배운 최신 C 언어 기술들(!!) 을 이용하여 새롭게 만들었습니다.어떻게 보면 http://itguru.tistory.com/60 의 생각해 볼 문제의 두번째 문제의 해답이 되기도 하겠군요*/
#include <stdio.h>
#include <stdlib.h>
struct BOOK{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};
typedef struct BOOK BOOK;
char compare(char *str1, char *str2);
int register_book(BOOK *book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
int main () {
    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */
    BOOK *book_list;
    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf("%d", &user_choice);
    book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);
    while (1)    {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n"); 
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");        printf("당신의 선택은 : ");        scanf("%d", &user_choice);        if(user_choice == 1)        {            /* 책을 새로 추가하는 함수 호출 */            register_book(book_list, &num_total_book);        }        else if(user_choice == 2)        {            /* 책을 검색하는 함수 호출 */            search_book(book_list, num_total_book);        }        else if(user_choice == 3)        {            /* 책을 빌리는 함수 호출 */            borrow_book(book_list);        }        else if(user_choice == 4)        {            /* 책을 반납하는 함수 호출 */            return_book(book_list);        }        else if(user_choice == 5)        {            /* 프로그램을 종료한다. */            break;        }    }    free(book_list);    return 0;}/* 책을 추가하는 함수*/int register_book(BOOK *book_list, int *nth){    printf("책의 이름 : ");    scanf("%s", book_list[*nth].book_name);    printf("책의 저자 : ");    scanf("%s", book_list[*nth].auth_name);    printf("책의 출판사 : ");    scanf("%s", book_list[*nth].publ_name);    book_list[*nth].borrowed = 0;    (*nth)++;    return 0;}/* 책을 검색하는 함수 */int search_book(BOOK *book_list, int total_num_book){    int user_input; /* 사용자의 입력을 받는다. */    int i;    char user_search[30];    printf("어느 것으로 검색 할 것인가요? \n");    printf("1. 책 제목 검색 \n");    printf("2. 지은이 검색 \n");    printf("3. 출판사 검색 \n");    scanf("%d", &user_input);    printf("검색할 단어를 입력해주세요 : ");    scanf("%s", user_search);    printf("검색 결과 \n");    if(user_input == 1)    {        /*        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을        사용자가 입력한 검색어와 비교하고 있다.        */        for(i = 0;i < total_num_book; i++)        {            if(compare(book_list[i].book_name, user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);            }        }    }    else if(user_input == 2)    {        /*        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을        사용자가 입력한 검색어와 비교하고 있다.        */        for(i = 0;i < total_num_book; i++)        {            if(compare(book_list[i].auth_name, user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);            }        }    }    else if(user_input == 3)    {        /*        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를        사용자가 입력한 검색어와 비교하고 있다.        */        for(i = 0;i < total_num_book; i++)        {            if(compare(book_list[i].publ_name, user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);            }        }    }    return 0;}char compare(char *str1, char *str2){    while (*str1)    {        if(*str1 != *str2)        {            return 0;        }        str1++;        str2++;    }    if(*str2 == '\0')        return 1;    return 0;}int borrow_book(BOOK *book_list){    /* 사용자로 부터 책번호를 받을 변수*/    int book_num;    printf("빌릴 책의 번호를 말해주세요 \n");    printf("책 번호 : ");    scanf("%d", &book_num);    if(book_list[book_num].borrowed == 1)    {        printf("이미 대출된 책입니다! \n");    }    else    {        printf("책이 성공적으로 대출되었습니다. \n");        book_list[book_num].borrowed = 1;    }    return 0;}int return_book(BOOK *book_list){    /* 반납할 책의 번호 */    int num_book;    printf("반납할 책의 번호를 써주세요 \n");    printf("책 번호 : ");    scanf("%d", &num_book);    if(book_list[num_book].borrowed == 0)    {        printf("이미 반납되어 있는 상태입니다\n");    }    else    {        book_list[num_book].borrowed = 0;        printf("성공적으로 반납되었습니다\n");    }    return 0;}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F134BA8504D29D1221117EE)

와 같이 여러가지 재미있는 것들을 할 수 있습니다.

위 소스에서는 여태까지 배운 것들을 대부분 사용하였는데요, 예를 들면

```cpp
struct BOOK
{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};

typedef struct BOOK BOOK;
```

을 통해서 귀찮게 'struct BOOK' 이라고 매번 써야 하는 대신에 'BOOK' 이라고 해도 'struct BOOK' 의 의미를 지니게 하였습니다. 참고적으로 위 문장들은

```cpp
typedef struct BOOK
{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
} BOOK;
```

와 같이 써도 동일한 의미를 지닙니다.

또한 재미있는 부분은로 다음과 같이 동적할당을 이용하였는데

```cpp
    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf("%d", &user_choice);

    book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);
```

위와 같이 하여서 `book_list` 의 책들의 최대 보관 개수를 지정하여 그 크기에 딱 맞는 배열을 생성하도록 하였습니다. 이전과 함수의 모습도 많이 달라졌는데

```cpp
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);
int borrow_book(int *borrowed);
int return_book(int *borrowed);
```

가 기존의 구조체를 쓰지 않았을 때의 함수들의 모습이라면 아래는

```cpp
int register_book(BOOK *book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
```

구조체를 써서 훨씬 간단해진 함수들의 모습 입니다.

  아무튼 위 소스에 대한 설명은 이정도로 마치도록 하고 (나머지 부분은 여러분이 스스로 분석/개량 해보세요!) 이제 본격적으로 파일 입출력을 도서 관리 프로그램에 적용시켜 봅시다. 먼저 우리가 하고 싶은 일은 현재 도서관에 등록된 장서들의 목록을 예쁘게 파일에 출력시키는 것입니다. 사실 이는 간단하므로 여러분들도 만들어보시기 바랍니다.

```cpp
int register_book(BOOK *book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
int print_book_list(BOOK *book_list, int total_num_book);
int main ()
{
    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */

    BOOK *book_list;

    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf("%d", &user_choice);

    book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);
    while (1)
    {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
      printf("6. 책들의 내용을 book_list.txt 에 출력 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        if(user_choice == 1)
        {
            /* 책을 새로 추가하는 함수 호출 */
            register_book(book_list, &num_total_book);
        }
        else if(user_choice == 2)
        {
            /* 책을 검색하는 함수 호출 */
            search_book(book_list, num_total_book);
        }
        else if(user_choice == 3)
        {
            /* 책을 빌리는 함수 호출 */
            borrow_book(book_list);
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
            return_book(book_list);
        }
        else if(user_choice == 5)
        {
            /* 프로그램을 종료한다. */
            break;
        }
        else if(user_choice == 6)
        {
            print_book_list(book_list, num_total_book);
        }
    }

    free(book_list);
    return 0;
}
int print_book_list(BOOK *book_list, int total_num_book)
{
    FILE *fp = fopen("book_list.txt", "w");
    int i;

    if(fp == NULL)
    {
        printf("출력 오류 ! \n");
        return -1;
    }

    fprintf(fp, " 책 이름/저자 이름/출판사/반납 유무\n");
    for(i = 0; i < total_num_book; i++)
    {
        fprintf(fp, "%s / %s / %s", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
        if(book_list[i].borrowed == 0)
            fprintf(fp, " /NO \n");
        else
            fprintf(fp, " /YES \n");
    }

    fclose(fp);
}
```


바뀐 부분만 보면 위와 같습니다.성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F167B6A4F4D29D63C3AE67C)

와 같이 나옵니다.
이제 6 번을 눌러서 출력을 해보면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F11780A4F4D29D63D64A800)

와 같이 아주 예쁘게 파일에 출력되었음을 알 수 있습니다.

위 소스 코드에서 주목해야 할 부분은 바로 파일에 내용을 출력하는 `print_book_list` 함수 입니다. `print_book_list` 에서 새로운 입출력 함수를 사용하였는데 바로 `fprintf` 함수 입니다. 이 함수는 `printf` 와 비슷하게 생겼는데 `printf` 의 경우 인자로 지정한 내용을 콘솔 화면(정확히 말하면 `stdout)` 에 출력하는 반면에 `fprintf` 함수는 지정한 스트림에 출력하게 되지요. 다시 말하면

```cpp
fprintf(stdout, "Hello, World! \n");
printf("Hello, World! \n");
```


은 정확히 동일한 작업을 하게 됩니다. 아무튼, `printf` 가 화면에 출력한다면 `fprintf` 는 스트림에 출력하신다고 생각하면 됩니다. 그렇다면

```cpp
    fprintf(fp, " 책 이름/저자 이름/출판사/반납 유무\n");
    for(i = 0; i < total_num_book; i++)
    {
        fprintf(fp, "%s / %s / %s", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
        if(book_list[i].borrowed == 0)
            fprintf(fp, " /NO \n");
        else
            fprintf(fp, " /YES \n");
    }
```


은 쉽게 이해할 수 있으리라 봅니다. 맨 첫번째 문장에서 책 이름/저자 이름/출판사/반납 유무 를 화면에 출력했다면, 아래 `for` 문에서 `book_list` 에 들어있는 책의 정보들을 모두 표시하게 되지요. 상당히 간단하지요?

  원래는 도서 관리 프로그램에서 출력한 데이터를 읽어들이는 작업도 같이 해볼려고 했는데 이 부분은 여러분들께 생각해보기로 남기겠습니다^^ 그럼 이번 강좌는 여기에서 마치도록 하겠고요, 다음 시간 까지도 파일 입출력에 대해서 좀더 이야기 보도록 하겠습니다!

### 생각해보기

#### 문제 1

위의 도서관리 프로그램에서 출력한 도서 목록을 입력 받아서 배열에 집어 넣는 작업을 만들어보세요. 참고로 도서 목록 출력 파일의 형식은 아래와 같다고 합시다.

```info
전체 책의 개수
책 이름
저자 이름
출판사 이름
대출 유무
책 이름
저자 이름
출판사 이름
대출 유무
```

예를 들면

```info
2 2
C언어
Psi Psi
itguru
offset
AAA
```

와 같은 형식 이지요. 물론 파일에 도서 목록을 출력하는 작업도 수정해야 되겠지요. (난이도 : 中)

#### 문제 2

파일에서 특정한 단어를 검색하여 몇 번째 줄에 나오는지 모두 출력하는 프로그램을 만드세요. (난이도 : 上)
(참고로 1 줄의 기준은 \n 의 유무로 합시다. 따라서 `fscanf` 를 사용하면 안되겠지요?)

#### 문제 3

파일에서 특정한 문자를 검색하여 몇 개나 나오는지 출력하는 프로그램을 만드세요. (난이도 : 下)



```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <23 - 2. 파일 하고 이야기 하기 (파일 입출력)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```






----------------
title : C 언어 레퍼런스 - strcspn 함수
cat_title :  strcspn
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strcspn

```info
#include <string.h> // C++ 에서는 <cstring>

size_t strcspn ( const char * str1, const char * str2 );
```


문자열에서 다른 문자열에 포함되어 있는 문자들을 검색하되, 첫번째로 일치하는 문자에 도달하기 까지 읽어들인 문자의 개수를 리턴한다.

다시 설명 하자면 `str2` 에 들어있는 문자들 중에서 `str1` 에 들어있는 문자와 일치하는 것이 있다면 첫번째로 일치하는 문자 까지 읽어들인 수를 리턴한다.

예를 들어 `str1` 에 "Hello, World" 가 들어 있고, `str2` 에 "aeiou" 가 들어 있다면 `str2` 에 들어 있는 문자들, 즉 `a,e,i,o,u` 를 `str1` 에서 검색하는 것인데 첫번째로 일치하는 것, 즉 `e` 가 정답이 된다. 이 때, 리턴하는 값은 `str1` 에서 'e' 까지 읽어들이는데 읽은 문자의 수, 즉 1 을 리턴하게 된다.



###  인자


`str1`

검색을 수행할 C 형식 문자열

`str2`

검색할 문자들을 포함하고 있는 C 형식 문자열



###  리턴값


만일 `str2` 의 문자들 중 `str1` 에 일치하는 것이 있다면 첫번째로 일치하는 문자까지 도달하기 위해 읽어들인 문자들의 수 (즉, 그 문자의 위치 `- 1` 이라 보면 된다) 를 리턴한다. 만일 일치하는 것이 없다면 `str1` 의 길이가 리턴된다.





###  구현 예


```cpp
/*

아래 소스는
http://www.koders.com/c/fidE1F6D546E578F9FF41B8000B08F8A73D4D86F8FA.aspx
에서 가져왔습니다.

*/
size_t strcspn (const char *s, const char *reject)
{
    size_t count = 0;

    while (*s != '\0')
        if (strchr (reject, *s++) == NULL)
            ++count;
        else
            return count;

    return count;
}
```


상당히 간단한 코드이다. `strchr` 의 사용법만 알면 쉽게 이해할 수 있지만, 살짝 비효율 적인데 함수를 호출하는 작업이 시간이 꽤 걸리기 때문이다. 아래 나온 코드는 좀더 복잡하지만 빠르게 수행된다.

```cpp
/*

아래 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/
size_t strcspn(const char *string, const char *control)
{
    const unsigned char *str = string;
    const unsigned char *ctrl = control;

    unsigned char map[32];
    int count;

    // Clear out bit map
    for (count = 0; count < 32; count++) map[count] = 0;

    // Set bits in control map
    ,   while (*ctrl)
    {
        map[*ctrl >> 3] |= (1 << (*ctrl & 7));
        ctrl++;
    }

    // 1st char in control map stops search
    count = 0;
    map[0] |= 1;
    while (!(map[*str >> 3] & (1 << (*str & 7))))
    {
        count++;
        str++;
    }
    return count;
}
```


위 함수의 작동 원리를 해석하는데 에는 상당히 고난이도의 통찰력이 필요하다. 설명해보자면, 일단 `map` 이란 배열은 `control` 에 포함되어 있는 문자들에 대한 정보를 저장하는 배열이다. (control 이 검색될 문자들을 포함하고 있는 배열)

이 때, `map` 에는 다음과 같은 형식으로 문자에 대한 정보가 저장된다.

```cpp
        map[*ctrl >> 3] |= (1 << (*ctrl & 7));
// map[*ctrl >> 3] = map[*ctrl >> 3] | (1 << (*ctrl & 7)); 와 같다.
```


이는 다음과 같이 해석할 수 있다.

`01100101` 이라는 값이 있다고 하자. (즉 `*ctrl` 에 해당한다) 이를 `>> 3` 수행 시킴으로써, 처음 5 부분만 추출할 수 있다. 이를 `000 01100 01100` 으로 만들면서 원래 값의 처음 5 자리 `01100` 을 추출한다. 이는 이 값의 `ID` 로 볼 수 있다. 같은 `ID` 를 가진 값들은 배열의 같은 원소 (`map[ID]`) 에 저장이 된다.

이 때, 나머지 세 자리 부분에 대한 정보를 저장해야 하는데, 이는 간단히 해결할 수 있다. 남은 세 부분의 값이 0 이면 `map[ID]` 의 마지막 비트, 3 이면 끝에서 세 번째 비트, 7 이면 맨 앞 비트를 1 로 만들어버리면 된다. 예를 들어서 `control` 에 `00110 00110 0101, 00110 00110 0011, 0011 00110 00111` 이 있었다면 `map[00110]` 에 값이` 10101000` 이 된다.

다시말해 `map[ID]` 에 해당하는 원소에 `ID000` 부터 `ID111` 까지의 정보를 모두 가지고 있다는 말이 된다. 상당히 기발한 아이디어 이다.

따라서 이렇게 `control` 에 대한 정보를 `map` 에 저장한 후, 이를 `str` 과 비교해보면 된다. `str` 에 비교하는 경우, `str` 의 특정한 문자에 해당하는 `map` 값이 0 인지 1 인지 확인만 해주면 된다. (즉 0 이면 `control` 에 없다는 것이고 1 이면 `control` 에 있다는 것이므로)



###  실행 예제


```cpp
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strcspn/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] = "fcba73";
    char keys[] = "1234567890";
    int i;
    i = strcspn (str,keys);
    printf ("The first number in str is at position %d.\n",i+1);
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F164A00274C559C0D15F82D)



###  연관된 함수





*  [strspn](http://itguru.tistory.com/97)  :  문자열에 다른 문자열에 포함된 정도를 구한다.



*  [strstr](http://itguru.tistory.com/101)   :  문자열에 특정한 문자열에 포함된 위치를 구한다.

*  [strncmp](http://itguru.tistory.com/90)  :  두 문자열의 일부분일 비교한다.








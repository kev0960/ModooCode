----------------
title : C++ 레퍼런스 - istream::getline 함수
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 [저의 모토인 '지식전파'](http://itguru.tistory.com/notice/107) 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ istream::getline

```info
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
```

스트림으로 부터 한 줄을 읽는다.
  입력 시퀀스(sequence) 로 부터 문자를 읽어들여 C 형식의 문자열로 `s` 에 저장한다.
이 함수는 최대 (n - 1) 개의 문자들을 읽어들일 때 까지나 (n 번째는 NULL 문자로 채워진다), 제한자(delimiter) 가 나타날 때 까지 읽게 된다. 제한자는 함수의 인자 `delim` 으로 전달되며, 명시하지 않았다면 '\n' 으로 간주한다. 또한 입력은 파일의 끝에 도달하거나, 입력 작업시 오류가 발생시 자동으로 종료된다.

  제한자를 찾았다면, 시퀀스에서 추출되지만 버려지게 된다. 즉, `s` 에 저장이 되지 않으며, 그 입력 연산은 제한자 다음 부터 진행되게 된다. 따라서 여러분이 이 제한자를 추출하고 싶지 않다면 `get` 함수를 사용하면 된다.

종료 널 문자는 데이터 추출이 완료되었을 때 자동으로 뒤에 붙게 된다.

이 함수를 통해 읽어진 문자의 개수를 알고 싶다면 [gcount](http://itguru.tistory.com/192)함수를 호출하면 된다.

  동일한 이름을 가진 전역 함수가 `<string>` 에 존재한다. 이 전역 함수는 비슷한 작업을 하지만 C 형식 문자열 대신에 표준 C++ 문자열 객체를 사용한다. `getline (string)` 함수를 참조



###  인자




`s`

  C 형식 문자열을 저장할 배열을 가리키는 포인터

`n`

  저장할 문자의 최대 개수 (끝의 종료 널 문자를 포함한 값)로, 이는 `streamsize` 타입의 정수값이다. 만일 이 `streamsize` 최대 크기에 도달하여 입력이 중단되었으면 `failbit` 플래그가 설정된다.

`delim`

  제한자(delimiter) 로 이 문자에 도달시 추출이 중단된다. 이 때, 이 문자는 `s` 에 기록되지는 않지만 스트림에서 사라지게 된다. 이 인자는 꼭 사용하지 않아도 되고, 명시하지 않았을 경우 '\n' 으로 제한자를 주었다고 생각한다.



###  리턴값




이 함수는 `*this` 를 리턴한다.

만일 입력시 발생된 오류들은 내부 상태 플래그를 통해 알아낼 수 있다.

플래그오류`eofbit`작업 중 문자들의 끝에 도달하였을 때`failbit`끝에 바로 도달해버려서 어떠한 문자도 추출해 낼 수 없을 경우. 혹은 `n - 1` 개의 문자들을 모두 추출하여서 입력 작업이 중단되었을 경우에도 설정된다. 또한 일부 `eofbit` 를 설정하는 오류들이 `failbit` 도 설정할 수 있다.
`badbit`위 같은 일들 외의 다른 오류가 발생시

  ios::exceptions 를 통해 적절한 플래그가 설정되어 있을 경우 위와 같은 상황이 발생시 ios_base::failure 이 `throw` 된다.



###  실행 예제


```cpp
/*

getline 함수를 통해 사용자로 부터 문자열을 입력 받는다.
이 예제는
http://www.cplusplus.com/reference/iostream/istream/getline
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main ()
{
    char name[256], title[256];

    cout << "Enter your name: ";
    cin.getline (name,256);

    cout << "Enter your favourite movie: ";
    cin.getline (title,256);

    cout << name << "'s favourite movie is " << title;

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F171C67424E4BDFE4051BA6)





###  템플릿 멤버 선언




```cpp
// ( basic_istream<charT,traits> )
typedef charT char_type;
basic_istream& getline (char_type* s, streamsize n );
basic_istream& getline (char_type* s, streamsize n, char_type delim );
```




###  연관된 함수


*  [istream::get](http://itguru.tistory.com/191)  :  서식화 되지 않은 데이터를 스트림에서 가져온다.
*  [istream::ignore](http://itguru.tistory.com/193)  :  문자를 추출하고 버린다.
*  [istream::gcount](http://itguru.tistory.com/192)`` : 이전의 서식화 되지 않았던 입력 작업서 추출하였던 문자의 개수를 얻어온다.






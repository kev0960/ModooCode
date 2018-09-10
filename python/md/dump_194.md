----------------
title : C++ 레퍼런스 - istream::peak 함수
cat_title :  istream::peak
--------------

```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ istream::peek

```info

int peek ( );
```



그 다음 문자를 살짝 훔쳐본다`` (즉, 스트림에서 빼오지는 않고 읽기만 한다)
따라서 [get](http://itguru.tistory.com/191)처럼 스트림에서 문자를 빼내는 것이 아니라, 그 문자는 그냥 스트림에 남아있게 된다.

###  인자

없음



###  리턴값




그 다음 문자의 값을 리턴한다. 오류가 발생 시에 이 함수는 `EOF` 를 리턴하며, 내부 상태 플래그를 다음과 같은 상황에 맞게 변경하게 된다.

플래그오류`eofbit`작업 중 문자들의 끝에 도달하였을 때`failbit``-`
`badbit`위 같은 일들 외의 다른 오류가 발생시


위와 같은 플래그들이 [ios::exceptions](http://itguru.tistory.com/150)`` 함수들로 설정되었다면, ios_base::failure 가 `throw` 된다.



###  실행 예제


```cpp

/*


이 예제는
 [http://www.cplusplus.com/reference/iostream/istream/peek/](http://www.cplusplus.com/reference/iostream/istream/peek/)
에서 가져왔습니다.


*/
#include <iostream>
using namespace std;


int main () {
char c;
int n;
char str[256];


cout << "Enter a number or a word: ";
c=cin.peek();


if ( (c >= '0') && (c <= '9') )
{
cin >> n;
cout << "You have entered number " << n << endl;
}
else
{
cin >> str;
cout << " You have entered word " << str << endl;
}


return 0;
}
```




실행 결과




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F205F8A46509C37A00C73BC)







###  템플릿 멤버 정의




```cpp

( basic_istream<charT,traits> )
typedef traits::int_type int_type;
int_type peek ( );
```






###  연관된 함수

*  [istream::get](http://itguru.tistory.com/191)`` : 스트림에서 서식화 되지 않은 데이터를 가져온다.
*  [istream::operator>>](http://itguru.tistory.com/147): 스트림에서 서식화 된 데이터를 가져온다.




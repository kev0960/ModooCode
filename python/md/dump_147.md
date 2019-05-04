----------------
title : C++ 레퍼런스 - istream::operator>> (추출 연산자)
cat_title :  istream::operator>> (추출 연산자)
ref_title : istream::operator>>
publish_date : 2011-08-17
--------------


##@ cpp-ref-start

#@ istream::operator>>

```info-format
istream& operator>> (bool& val );
istream& operator>> (short& val );
istream& operator>> (unsigned short& val );
istream& operator>> (int& val );
istream& operator>> (unsigned int& val );
istream& operator>> (long& val );
istream& operator>> (unsigned long& val );
istream& operator>> (float& val );
istream& operator>> (double& val );
istream& operator>> (long double& val );
istream& operator>> (void*& val );

istream& operator>> (streambuf* sb );

istream& operator>> (istream& ( *pf )(istream&));
istream& operator>> (ios& ( *pf )(ios&));
istream& operator>> (ios_base& ( *pf )(ios_base&));

// 아래 함수들은 멤버들이 아니라, 전역 함수들이다.

istream& operator>> (istream& is, char& ch );
istream& operator>> (istream& is, signed char& ch );
istream& operator>> (istream& is, unsigned char& ch );

istream& operator>> (istream& is, char* str );
istream& operator>> (istream& is, signed char* str );
istream& operator>> (istream& is, unsigned char* str );
```

서식화 된 데이터를 추출(extract)한다.

연산자(`>>`) 은 입력 스트림에서 사용되는데, **추출 연산자(extraction operator)** 이라 불리기도 한다. 이 연산자는 스트림에서 데이터의 해석을 필요로 하는 입력 작업을 수행하게 된다. 

예를 들어, 입력 받은 숫자 데이터 (문자 형태로 입력될 것이다) 를 사용자가 지정한 수치 형태로 변환한다든지 등 말이다.

참고적으로 3 가지 종류의 멤버 함수들과, 한 가지 종류의 전역 함수들이 [istream](http://itguru.tistory.com/146)객체에 적용되는 추출 연산자에서 오버로드 된다.


* 첫번재 종류의 멤버 함수는 **산술 추출자(arithmetic extractor)** 이다. 이들은 입력 데이터로 부터 문자들을 받아서 이 추출자의 인자의 특정 타입의 형태로 값을 해석하게 된다. 그 결과값은 인자로 전달된 변수에 저장되게 된다. (위 소스에서 상단 부분)



* `streambuf` 형태의 복사는 연산자 우변에 전달된 스트림 버퍼 객체로 부터 더 이상 복사 할 수 없을 때 까지 최대한 많은 문자들을 복사한다.



* 마지막 종류의 멤버 함수는 인자로 함수 포인터를 가지고 있다. 이들은 **조작자(manipulator)** 함수로 사용되게 만들어졌다. 조작자 함수는 이 연산자와 함께 사용되도록 특이적으로 만들어진 함수들이다. (위 소스에서 세번째 부분)



* 전역 함수가 오버로드 하는 경우는 인자가 문자거나 C 형식 문자열일 때 연산자를 오버로드 하는데, 이들은 입력스트림으로 부터 한 개의 문자 혹은 문자들의 나열을 입력 받는다. (위 소스에서 마지막 부분)




 이 함수들이 연산자 오버로딩 함수들이기 때문에 이 연산자를 사용하기 위해서는

```cpp-formatted
strm >> variable;
```

와 같이 사용하면 된다. 이 때 `strm` 은 [istream](http://itguru.tistory.com/146) 객체의 이름이고, `variable` 은 우변으로 전달되는 인자이다. 물론 이 연산자를 아래처럼 쭉 이어나가서 사용해도 된다.

```cpp-formatted
strm >> variable1 >> variable2 >> variable3;  //...
```

이는 `strm` 객체에 추출 연산을 계속 진행하는 것과 다름 없다.

표준 [istream](http://itguru.tistory.com/146)객체에 사용시 효과가 있는 조작자들은


* `boolalpha` : `bool` 값을 문자열로(true, `false)`

* `dec` : 십진수를 사용

* `hex` : 16 진수를 사용한다.



* `noboolalpha` : `bool` 값에 문자열을 사용하지 않는다 (0,1)



* `noskipws` : 공백문자(whitespace) 를 생략하지 않는다.

* `oct` : 8 진수를 사용한다.



* `skipws` : 공백 문자(whitespace)를 생략한다


* `ws` : 공백문자를 추출한다.


다른 조작자들도 [istream](http://itguru.tistory.com/146)객체에 사용 가능하지만 효과는 없다.

아래의 인자를 가지는 조작자들은 `istream` 객체에 영향이 있다. 이들은 `<iomanip>` 헤더파일에 정의되어 있으며 명시적으로 포함 시켜 주어야만 한다.


* `setiosflags` : 서식 플래그를 설정한다.

* `setbase` : 진법 플래그를 설정한다.



* `resetiosflags` : 서식 플래그를 재설정 한다.




###  인자들


* `val` :  입력 시퀀스(sequence)에서 문자들을 추출하여 주어진 인자의 타입에 맞게 수치값으로 해석하려 한다. 만일 성공적으로 해석하였다면 그 값은 `val` 에 저장된다. 데이터가 정확히 어떠한 방식으로 해석될지는 이전에 스트림에 적용된 조작자와, 로케일(locale) 에 의해 결정된다.
* `sb` :  입력 시퀀스로 부터 문자들을 추출하여 `End Of File` 이 나타나기 전이나, 버퍼가 성공적으로 문자를 삽입(insert)할 때 까지 `sb` 에 저장한다.
* `pf` : `pf(*this)` 를 호출하는데, 보통 조작자 함수이다.
* `ch` : 단일 문자를 추출하여 `ch` 에 저장한다.
* `str` :  문자를 추출하여 C 형식 문자열로 저장한다. (즉 `str` 이 문자열의 시작 부분을 가리키고, `null` 문자로 문자열이 끝난다) 추출은 다음 문자가 공백 문자(whitespace) 이거나 널 문자 혹은 `End of file` 에 도달하였을 때 종료된다. 입력 받은 문자열 끝에는 자동적으로 널 문자가 붙게 된다.
이 때 만일 필드의 너비가 0 보다 크게 설정되었다면 (이는 [ios_base::width](http://itguru.tistory.com/152)혹은 `setw` 로 설정할 수 있다) 입력 받을 문자의 수를 제한할 수 도 있다(버퍼 오버플로우 문제를 막기 위해). 이 경우 입력 받은 문자의 수가 필드 너비 값에 도달하기 하나 전에, 입력을 중단하고 나머지 한 문자를 널 종료 문자(null terminating character) 로 채운다. 그리고 자동으로 필드 너비 값이 0 으로 재설정 되버린다.

* `is` : 작업이 수행될 스트림 객체. 이는 전역 함수의 첫 번째 인자로 연산자의 왼쪽에 위치한다.




###  리턴값

객체 자기 자신을 리턴한다 (`*this`)

발생된 오류는 내부 플래그를 변화시키게 된다.

|플래그|오류|
|-----|----|
|`eofbit`|작업 중 문자들의 끝에 도달하였을 때|
|`failbit`|끝에 바로 도달해버려서 어떠한 문자도 추출해 낼 수 없을 경우. 혹은 `n - 1` 개의 문자들을 모두 추출하여서 입력 작업이 중단되었을 경우에도 설정된다. 또한 일부 `eofbit` 를 설정하는 오류들이 `failbit` 도 설정할 수 있다.|
|`badbit`|위 같은 일들 외의 다른 오류가 발생시|

추가적으로 [ios::exceptions](http://itguru.tistory.com/150) 의 멤버 함수를 통해 적절하게 플래그가 설정되어있다면, 위와 같은 상황 발생 시 `ios_base::failure` 예외가 `throw` 된다.


###  실행 예제


```cpp-formatted
/*

cin 으로 여러 작업을 수행한다.
이 예제는
http://www.cplusplus.com/reference/iostream/istream/operator%3E%3E/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main() {
  int n;
  char str[10];

  cout << "Enter a number: ";
  cin >> n;
  cout << "You have entered: " << n << endl;

  cout << "Enter a hexadecimal number: ";
  cin >> hex >> n;  // manipulator
  cout << "Its decimal equivalent is: " << n << endl;

  cout << "Enter a word: ";
  cin.width(10);  // limit width
  cin >> str;
  cout << "The first 9 chars of your word are: " << str << endl;

  return 0;
}
```

 실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F144DE2524E4B71D4023599)


###  템플릿 전역 함수들

```cpp-formatted
template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         charT& ch);

template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         signed char& ch);

template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         unsigned char& ch);

template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         charT* str);

template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         signed char* str);

template <class charT, class traits>
basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is,
                                         unsigned char* str);
```


###  참고 자료


* [istream::get](http://itguru.tistory.com/191) : 서식화 되지 않는 데이터를 스트림에서 가져온다.

* [istream::getline](http://itguru.tistory.com/149) : 스트림에서 한 줄을 입력 받는다.

* `ostream::operator<<` : 서식에 맞게 데이터를 삽입한다.

* `istream::sentry` : 입력 연산 전에 스트림을 준비 및 마무리 한다.
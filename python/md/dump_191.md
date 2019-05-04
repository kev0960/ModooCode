----------------
title : C++ 레퍼런스 - istream::get 함수
cat_title : istream::get
ref_title : get
publish_date : 2012-11-07
--------------

##@ cpp-ref-start

#@ istream::get

```info-format
int get();
istream& get ( char& c );
istream& get ( char* s, streamsize n );
istream& get ( char* s, streamsize n, char delim );
istream& get ( streambuf& sb);
istream& get ( streambuf& sb, char delim );
```

스트림에서 서식화 되지 않은(unformatted)  데이터를 가져온다.

이 멤버 함수들은 서식화되지 않는 입력 연산을 수행한다. 함수 호출 시 인자의 타입과 개수에 따라서 다음과 같이 오버로딩 된다.


`int get();`

스트림에서 문자 한 개를 가져온뒤, 그 값을 리턴한다 (int 로 형변환 됨)


`istream& get ( char& c );`

스트림에서 문자 한 개를 가져온 뒤, `c` 에 저장한다.


`istream& get (char* s, streamsize n );`

스트림에서 문자들을 가져온 뒤, `s` 에 C 형식 문자열로 저장한다. 문자는제한 문자 '\n' 이 나올 때 까지나, `n - 1` 개의 문자를 받을 때 까지 입력받게 된다. 또한 입력 작업 시 오류가 발생할 경우 또한 중단되게 된다. 또한 이 함수는 제한 문자는 스트림에서 빼내지 않기 때문에 (즉, 다음 번 입력 시 가장 첫번째로 입력 받는 것이 그 제한 문자일 것이다) 만일 제한 문자를 스트림에서 빼내 버리기 위해서는 [getline](http://itguru.tistory.com/149)과 같은 함수를 이용해야만 한다. `s` 맨 마지막에는 자동으로 널 문자(Null terminating character)가 붙여지게 된다.


`istream& get (char* s, streamsize n, char delim );`

위와 동일하지만, 제한 문자를 '\n' 대신에 사용자가 임의로 지정할 수 있다.


`istream& get (streambuf& sb);`

스트림에서 문자들을 받는뒤, 이를 스트림 버퍼 `sb` 에 입력 한다. 문자는 제한 문자 '\n' 이 나올 때 까지나, 파일 끝에 도달할 때 까지 입력 받는다. 또한, 이 함수는 입력 스트림에서 입력 과정에 오류가 발생하였을 때나, `sb` 에서 출력시 오류가 발생하였을 때 중단하게 된다.


`istream& get (streambuf& sb, char delim );`

위와 동일하지만 제한 문자를 '\n' 대신에 사용자가 원하는 것으로 설정할 수 있다.


바로 직전의 입력 과정에서 읽어들인 문자의 수는 [gcount](http://itguru.tistory.com/192)함수로 알아 낼 수 있다.




###  인자


`c`

추출한 문자를 저장할 `char` 변수

`s`

추출한 문자열을 C 형식 문자열로 저장하기 위한 포인터

`n`

입력 받을 최대 문자의 수 (널 종료 문자열을 포함해서) 이는 또한 `streamsize` 타입의 정수값이다.

`delim`

제한 문자. 이 문자를 읽어들이기게 되면 입력 작업이 종료된다. 만일 이 문자를 사용자가 지정하지 않았다면 디폴트로 '\n' 이 설정된다.

`sb`

출력 스트림 버퍼 (streambuf 의 객체 혹은 이 스트림을 상속하고 있는 클래스들의 객체)


###  리턴값




맨 첫 번째 오버로딩의 경우 이 함수는 읽어들인 문자의 수를 리턴한다. 나머지 것들의 경우 `*this` 를 리턴한다.
스트림 상의 오류는 다음과 같은 내부 상태 플래그들로 설정된다.

|플래그|오류|
|-----|----|
|`eofbit`|작업 중 문자들의 끝에 도달하였을 때|
|`failbit`|끝에 바로 도달해버려서 어떠한 문자도 추출해 낼 수 없을 경우. (`streambuf` 를 사용하는 경우 sb 에 문자 출력 불가시에도 설정될 수 있다) 또한 `eofbit` 이 설정되는 경우 `failbit` 또한 같이 설정될 수 있다|
|`badbit`|위 같은 일들 외의 다른 오류가 발생시|


위와 같은 플래그들이 [ios::exceptions](http://itguru.tistory.com/150) 함수로 설정되었다면, `ios_base::failure` 가 `throw` 된다.


###  실행 예제




```cpp-formatted
/*


이 예제는
 [http://www.cplusplus.com/reference/iostream/istream/get/](http://www.cplusplus.com/reference/iostream/istream/get/)
에서 가져왔습니다.


*/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  char c, str[256];
  ifstream is;

  cout << "Enter the name of an existing text file: ";
  cin.get(str, 256);

  is.open(str);  // open file

  while (is.good())  // loop while extraction from file is possible
  {
    c = is.get();  // get character from file
    if (is.good()) cout << c;
  }

  is.close();  // close file

  return 0;
}
```



실행 결과




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F130C9946509A59621796E3)







###  템플릿 멤버 정의




```cpp-formatted
(basic_istream<charT, traits>)

  typedef charT char_type;
int_type get();
basic_istream& get(char_type& c);
basic_istream& get(char_type* s, streamsize n);
basic_istream& get(char_type* s, streamsize n, char_type delim);
basic_istream& get(basic_streambuf<char_type, traits>& sb);
basic_istream& get(basic_streambuf<char_type, traits>& sb, char_type delim);
```

###  참고 자료


*  [istream::getline](http://itguru.tistory.com/149): 스트림에서 한 줄을 입력받는다.
*  [istream::ignore](http://itguru.tistory.com/193): 문자를 스트림에서 입력받고 버린다.
*  [istream::gcount](http://itguru.tistory.com/192): 마지막 서식화되지 않는 입력 작업에서 입력 받은 문자의 수를 얻는다.
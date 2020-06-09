----------------
title : C++ 레퍼런스 - istream 클래스
cat_title :  istream 클래스
ref_title : istream, <istream>, std::basic_istream, basic_istream
publish_date : 2011-08-17
--------------


##@ cpp-ref-start

#@ istream

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F195A313C509A45B20CA82E)

`istream` 객체는 문자들의 나열을 읽고 해석하는데 사용된다. `istream` 의 멤버 함수들은 아래와 같이 두 가지 형태의 입력 방식을 지원한다.

#### 서식화된 입력 (Formatted input)

이 함수들은 문자들의 나열에서 데이터를 추출하고, 특정 타입에 맞게 데이터를 해석하고 서식화 한다. 이러한 형식의 작업은 추출 연산자 (extraction operator) 인 
 [istream::operator>>](http://itguru.tistory.com/147) 을 오버로드 하는 멤버 및 전역 함수들에 의해 처리된다.

#### 서식화 되지 않은 입력 (Unformatted input)


`istream` 클래스의 대부분의 다른 멤버 함수들은 서식화된 입력을 사용하지 않는다. 즉, 입력 받은 문자들로 부터 어떠한 해석도 이루어지지 않는다는 뜻이다. 이 멤버 함수들은 입력되는 문자들의 나열에서 부터 정해진 개수의 문자만을 입력 받는다 (
 [get](http://itguru.tistory.com/191), 
 [getline](http://itguru.tistory.com/149), 
 [peek](http://itguru.tistory.com/194), `read`, `readsome`). 또한 `get pointer` 을 조절하거나 (
 [ignore](http://itguru.tistory.com/193), `seekg`, `tellg`, `unget`) 마지막 서식화 되지 않았던 입력 작업의 정보를 얻어오는 함수(
 [gcount](http://itguru.tistory.com/192))들도 있다.


 표준 객체인 `cin` 은 이 클래스로 부터 만들어진 인스턴스 이다.

 이 클래스는 [ios_base](http://itguru.tistory.com/144)와 [ios](http://itguru.tistory.com/145)로 부터 모든 것들을 상속 받았다.

#### 서식 정보(Formatting information)


* 서식 플래그(format flag) : 입출력 작업들이 어떠한 형식으로 해석되어야 할지를 지시하는 내부 지시자들의 집합이다. 이 지시자들의 상태는
 [flags](http://itguru.tistory.com/153),
 [setf](http://itguru.tistory.com/155)나
 [unsetf](http://itguru.tistory.com/156)함수들을 호출하거나 조작자(manipulator) 들을 사용함으로써 바뀔 수 있다.



* 필드 너비(field width) : 출력될 다음 원소의 너비에 대한 정보이다. 이 값은 멤버 함수인
 [width](http://itguru.tistory.com/152)를 호출하거나, 인자 있는 조작자인 `setw` 를 사용함으로써 얻어지거나 수정될 수 있다.



* 채우기 문자(fill character) : 필드의 너비를 맞추기 위해 부가적으로 채워지는 문자. 이는
 [fill](http://itguru.tistory.com/181)함수를 호출하거나, 인자가 있는 조작자인 `setfill` 을 사용하므로써 얻어지거나 수정될 수 있다.

* 출력 정밀도(display precision) : 부동 소수점 데이터를 출력시 어떠한 정밀도로 표시할 것인지를 나타낸다. 이 값은 [precision](http://itguru.tistory.com/157)함수나 인자 있는 조작자인 `setprecision` 을 통해 얻어지거나 수정될 수 있다.

* 로케일 객체(locale object) : 입출력 작업을 서식화 할 때 고려해야 할 로케일 정보(언어 문화권의 차이에 따라 달라지는 특성) 들을 담고 있다. 로케일 객체는 [getloc](http://itguru.tistory.com/160)함수를 호출함으로써 얻어지고 [imbue](http://itguru.tistory.com/158)함수를 통해 조작할 수 있다.




#### 상태 정보


* 오류 상태(error state) : 내부 지시자가 현재 스트림의 오류 상태를 나타내고 있다. 객체는
 [rdstate](http://itguru.tistory.com/171) 함수를 호출함으로써 얻어지고, `clear$iostream` 와
 [setstate](http://itguru.tistory.com/179) 함수를 호출함을 통해 수정될 수 있다. 각각의 값은
 [good](http://itguru.tistory.com/164), 
 [eof](http://itguru.tistory.com/167), 
 [fail](http://itguru.tistory.com/165), 
 [bad](http://itguru.tistory.com/166) 를 호출함으로써 얻어진다.



* 예외 마스크(exception mask) : 내부 예외 상태 지시자. `exceptions` 를 통해 이 값을 얻어낼거나 수정할 수 있다.




#### 그 외


* 이벤트 함수 스택(event function stack) : 특정 이벤트가 일어낼 때 호출되었던 콜백 함수들을 가리키는 포인터들의 스택. 추가적인 콜백 함수들은
 [register_callback](http://itguru.tistory.com/159) 함수를 호출함으로써 스택에 등록할 수 있다.

* 내부 확장 가능 배열(internal extensible arrays) : 두 개의 배열로 `long` 객체와 `void` 포인터들을 저장하기 위한 것이다. 이 배열은 [xalloc](http://itguru.tistory.com/162) 함수를 호출함으로써 확장될 수 있고, 각각의 객체들의 레퍼런스는 [iword](http://itguru.tistory.com/161) 나 [pword](http://itguru.tistory.com/163) 함수를 호출함으로써 얻어진다.



* 엮여진 스트림(tied stream)을 가리키는 포인터 : 이 스트림 객체와 엮여진 스트림을 가리키는 포인터를 의미하며, `tie` 함수를 호출함으로써 얻어지거나 설정된다. (엮여진 스트림에 대한 설명은 `tie` 함수 참조)



* 스트림 버퍼(stream buffer) 을 가리키는 포인터 : `streambuf` 객체와 연관된 포인터로, [rdbuf](http://itguru.tistory.com/182)함수를 호출함으로써 수정되거나 얻어진다.




### 멤버 클래스

* `sentry` : 입력 연산 전에 스트림을 준비 및 마무리 한다.


###  Public 멤버들


* 생성자

* 소멸자


#### 서식화된 입력


*  [operator>>](http://itguru.tistory.com/147) : 서식화된 데이터를 추출(입력)한다.

#### 서식화 되지 않은 입력


*  [gcount](http://itguru.tistory.com/192) : 마지막 서식화 되지 않은 입력에서 받아들였었던 문자의 개수를 구한다.

*  [get](http://itguru.tistory.com/191) : 스트림으로 부터 서식화 되지 않은 데이터를 얻는다.

*  [getline](http://itguru.tistory.com/149): 스트림으로 부터 한 줄을 입력받는다.

*  [ignore](http://itguru.tistory.com/193): 문자들을 입력 받고 지운다.

*  [peek](http://itguru.tistory.com/194): 그 다음으로 추출될 문자를 얻어온다.

* `read` : 데이터 블록을 읽는다.

* `readsome` : 버퍼에서 읽기 가능한 데이터 블록을 읽어온다.

* `putback` : 문자를 다시 집어넣는다.


* `unget` : `get pointer` 을 감소 시킨다.


#### 위치 관련


* `tellg` : `get pointer` 의 위치를 얻는다.

* `seekg` : `get pointer` 의 위치를 설정한다.


#### 동기화

* `sync` : 입력 버퍼를 문자들의 소스에 동기화 시킨다.

#### ios 로 부터 상속 받은 함수들


*  [good](http://itguru.tistory.com/164) : 스트림의 상태가 입출력 작업을 할 수 있는지 확인한다.

*  [eof](http://itguru.tistory.com/167) : `eof` 비트가 설정되었는지 확인한다.

*  [fail](http://itguru.tistory.com/165) : `fail` 비트나 `bad` 비트가 설정되었는지 확인한다.

*  [bad](http://itguru.tistory.com/166) : `bad` 비트가 설정되었는지 확인한다.

*  [ios::operator!](http://itguru.tistory.com/168) : 스트림 객체에 오류 플래그(fail 비트나 `bad` 비트)가 설정되었는지 확인한다.

*  [ios::operator void*](http://itguru.tistory.com/170) : 포인터로 변환한다.

*  [rdstate](http://itguru.tistory.com/171) : 오류 상태 플래그(error state flag)를 얻어온다.

*  [setstate](http://itguru.tistory.com/179) : 오류 상태 플래그를 설정한다.

*  [clear](http://itguru.tistory.com/180) :  오류 상태 플래그들을 설정한다

* `copyfmt` : 서식 정보를 복사한다.

*  [fill](http://itguru.tistory.com/181) : 채우기 문자(fill character) 을 얻거나 설정한다.

*  [ios::exceptions](http://itguru.tistory.com/150) : 예외 마스크를 얻거나 설정한다.

* `imbue` : 로케일을 설정한다.



*  [tie](http://itguru.tistory.com/190) : 엮어진 스트림(tied stream)을 얻거나 설정한다.



*  [rdbuf](http://itguru.tistory.com/182) : 연관된 스트림 버퍼를 얻거나 설정한다.

* `narrow` : 표준 `char` 형으로 문자를 변환한다.

* `widen` : 표준 `wchar_t` 형으로 문자를 변환한다.


 [ios_base](http://itguru.tistory.com/144) 로 부터 상속된 함수들


*  [flags](http://itguru.tistory.com/153) : 서식 플래그를 수정하거나 얻어온다.

*  [setf](http://itguru.tistory.com/155) : 특정 서식 플래그를 설정한다.



*  [unsetf](http://itguru.tistory.com/156): 특정 서식 플래그를 초기화 한다.



*  [precision](http://itguru.tistory.com/157) : 부동 소수점 정밀도를 수정하거나 얻어온다.



*  [width](http://itguru.tistory.com/152) : 필드의 너비를 수정하거나 얻어온다

*  [imbue](http://itguru.tistory.com/158) : 로케일을 채운다.

*  [getloc](http://itguru.tistory.com/160) : 현재 로케일을 얻어온다

*  [xalloc](http://itguru.tistory.com/162) : 내부 확장 가능 배열의 새로운 인덱스를 리턴한다. (정적 함수)

*  [iword](http://itguru.tistory.com/161) : 내부 확장 가능 배열의 특정 정수 원소의 레퍼런스를 얻는다.

*  [pword](http://itguru.tistory.com/163) : 내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.

*  [register_callback](http://itguru.tistory.com/159) : 이벤트 콜백 함수를 등록한다.

* `sync_with_stdio` : `iostream` 과 `cstdio` 스트림과의 동기화를 활성화 하거나 비활성화 한다.
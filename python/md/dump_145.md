----------------
title : C++ 레퍼런스 - ios 클래스
cat_title : ios 클래스
ref_title : ios, <ios>
publish_date : 2011-08-17
--------------


##@ cpp-ref-start

#@ ios

표준 스트림 클래스의 타입 의존적인 멤버(type-dependent) 들을 포함하는 기초 클래스



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F016CA136509A4531255174)



이 클래스는 스트림 클래스의 [ios_base](http://itguru.tistory.com/144)를 제외한 모든 클래스의 기초 클래스가 되도록 만들어졌다.

`ios` 는 기반 클래스인 [ios_base](http://itguru.tistory.com/144)와 함께 표준 스트림의 객체가 입력이냐, 출력이냐에 무관하게, 공통적으로 필요한 멤버들을 정의하고 있다. `ios_base` 의 경우 그들 중 템플릿 인자와 무관한 것들, `ios` 는 템플릿 인자에 의존적인 멤버들을 정의하게 된다.

`ios` 는 `ios_base` 로 부터 파생된 것이기 때문에 [ios_base](http://itguru.tistory.com/144)의 정보를 포함하고 있으며 다음과 같은 것들이 추가되었다.


* 채우기 문자(fill character) : 필드 너비를 맞추기 위해 채워지는 문자를 의미한다. 이는 `fill` 함수를 호출함으로써 설정되거나 얻어질 수 있다.
* 엮여진 스트림(tied stream)을 가리키는 포인터 : 이 스트림 객체와 엮여진 스트림을 가리키는 포인터를 의미하며, `tie` 함수를 호출함으로써 얻어지거나 설정된다. (엮여진 스트림에 대한 설명은 `tie` 함수 참조)
* 스트림 버퍼(stream buffer) 을 가리키는 포인터 : `streambuf` 객체와
연관된 포인터로,
 [rdbuf](http://itguru.tistory.com/182)함수를 호출함으로써 수정되거나 얻어진다.




###  멤버 함수



* 생성자

* 소멸자


상태 플래그 함수


* [good](http://itguru.tistory.com/164) : 스트림의 상태가 입출력 작업을 할 수 있는지 확인한다.

* [eof](http://itguru.tistory.com/167) : `eof` 비트가 설정되었는지 확인한다.

* [fail](http://itguru.tistory.com/165) : `fail` 비트나 `bad` 비트가 설정되었는지 확인한다.

* [bad](http://itguru.tistory.com/166): `bad` 비트가 설정되었는지 확인한다.

* [ios::operator!](http://itguru.tistory.com/168): 스트림 객체에 오류 플래그(`fail` 비트나 `bad` 비트)가 설정되었는지 확인한다.

* `ios::operator void*` : 포인터로 변환한다.

* [rdstate](http://itguru.tistory.com/171) : 오류 상태 플래그(error state flag)를 얻어온다.

* [setstate](http://itguru.tistory.com/179) : 오류 상태 플래그를 설정한다.

* [clear](http://itguru.tistory.com/180) : 오류 상태 플래그들을 설정한다.





서식


* `copyfmt` : 서식 정보를 복사한다.

* [fill](http://itguru.tistory.com/181): 채우기 문자(fill character) 을 얻거나 설정한다.




그 외


* [ios::exceptions](http://itguru.tistory.com/150): 예외 마스크를 얻거나 설정한다.

* `imbue` : 로케일을 설정한다.



* [tie](http://itguru.tistory.com/190) : 엮어진 스트림(tied stream)을 얻거나 설정한다.



* [rdbuf](http://itguru.tistory.com/182) : 연관된 스트림 버퍼를 얻거나 설정한다.

* `narrow` : 표준 `char` 형으로 문자를 변환한다.

* `widen` : 표준 `wchar_t` 형으로 문자를 변환한다.




`ios_base` 로 부터 상속된 함수들


* [flags](http://itguru.tistory.com/153): 서식 플래그를 수정하거나 얻어온다.

* [setf](http://itguru.tistory.com/155) : 특정 서식 플래그를 설정한다.



* [unsetf](http://itguru.tistory.com/156) : 특정 서식 플래그를 초기화 한다.
* [precision](http://itguru.tistory.com/157) : 부동 소수점 정밀도를 수정하거나 얻어온다.
* [width](http://itguru.tistory.com/152) : 필드의 너비를 수정하거나 얻어온다

* [imbue](http://itguru.tistory.com/158) : 로케일을 채운다.

* [getloc](http://itguru.tistory.com/160) : 현재 로케일을 얻어온다

* [xalloc](http://itguru.tistory.com/162) : 내부 확장 가능 배열의 새로운 인덱스를 리턴한다. (정적 함수)

* [iword](http://itguru.tistory.com/161) : 내부 확장 가능 배열의 특정 정수 원소의 레퍼런스를 얻는다.

* [pword](http://itguru.tistory.com/163) : 내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.

* [register_callback](http://itguru.tistory.com/159) : 이벤트 콜백 함수를 등록한다.

* `sync_with_stdio` : `iostream` 과 `cstdio` 스트림과의 동기화를 활성화 하거나 비활성화 한다.
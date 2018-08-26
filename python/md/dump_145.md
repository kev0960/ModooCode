

```warning
  이 레퍼런스의 모든 내용은 http://www.cplusplus.com/reference/iostream/
 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ 
Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 저의 모토인 '지식전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 씹어먹는 C++ 강좌는 어때요?
```

ios


표준 스트림 클래스의 타입 의존적인 멤버(type-dependent) 들을 포함하는 기초 클래스



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F016CA136509A4531255174)



이 클래스는 스트림 클래스의 ios_base 를 제외한 모든 클래스의 기초 클래스가 되도록 만들어졌다.
ios 는 부모 클래스인 ios_base 와 함께 표준 스트림의 객체가 입력이냐, 출력이냐에 무관하게, 공통적으로 필요한 멤버들을 정의하고 있다. ios_base 의 경우 그들 중 템플릿 인자와 무관한 것들, ios 는 템플릿 인자에 의존적인 멤버들을 정의하게 된다. 

  ios 는 ios_base 로 부터 파생된 것이기 때문에 ios_base 의 정보를 포함하고 있으며 다음과 같은 것들이 추가되었다. 

* 채우기 문자(fill character) :  필드 너비를 맞추기 위해 채워지는 문자를 의미한다. 이는 fill 함수를 호출함으로써 설정되거나 얻어질 수 있다.엮여진 스트림(tied stream)을 가리키는 포인터 :  이 스트림 객체와 엮여진 스트림을 가리키는 포인터를 의미하며, tie 함수를 호출함으로써 얻어지거나 설정된다.  (엮여진 스트림에 대한 설명은 tie 함수 참조)
스트림 버퍼(stream buffer) 을 가리키는 포인터 :  streambuf 객체와 연관된 포인터로, rdbuf 함수를 호출함으로써 수정되거나 얻어진다. 
 멤버 함수

* 생성자소멸자
상태 플래그 함수

* good  :  스트림의 상태가 입출력 작업을 할 수 있는지 확인한다.eof  :  eof 비트가 설정되었는지 확인한다.fail  :  fail 비트나 bad 비트가 설정되었는지 확인한다.bad :  bad 비트가 설정되었는지 확인한다. operator! :  스트림 객체에 오류 플래그(fail 비트나 bad 비트)가 설정되었는지 확인한다.operator void* :  포인터로 변환한다. rdstate  :  오류 상태 플래그(error state flag)를 얻어온다.setstate  :  오류 상태 플래그를 설정한다.clear  :   오류 상태 플래그들을 설정한다. 


서식

* copyfmt  :  서식 정보를 복사한다.fill :  채우기 문자(fill character) 을 얻거나 설정한다. 

그 외

* exceptions :  예외 마스크를 얻거나 설정한다.   imbue :  로케일을 설정한다. 
tie  :  엮어진 스트림(tied stream)을 얻거나 설정한다. 
rdbuf  :  연관된 스트림 버퍼를 얻거나 설정한다. narrow  : 표준 char 형으로 문자를 변환한다.widen :  표준 wchar_t 형으로 문자를 변환한다. 

ios_base 로 부터 상속된 함수들

* flags :  서식 플래그를 수정하거나 얻어온다. setf  :  특정 서식 플래그를 설정한다. 
unsetf  :  특정 서식 플래그를 초기화 한다. 
precision  :  부동 소수점 정밀도를 수정하거나 얻어온다. 
width  :  필드의 너비를 수정하거나 얻어온다imbue  :  로케일을 채운다.getloc  :  현재 로케일을 얻어온다xalloc  :  내부 확장 가능 배열의 새로운 인덱스를 리턴한다. (정적 함수)iword  :  내부 확장 가능 배열의 특정 정수 원소의 레퍼런스를 얻는다.pword  :  내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.register_callback  :  이벤트 콜백 함수를 등록한다. sync_with_stdio :  iostream 과 cstdio 스트림과의 동기화를 활성화 하거나 비활성화 한다.

공감sns신고저작자표시'C++ Reference > IOstream' 카테고리의 다른 글C++ 레퍼런스 - istream::getline 함수(0)
2011.08.18C++ 레퍼런스 - istream::operator>> (추출 연산자)(0)
2011.08.17C++ 레퍼런스 - istream 클래스(0)
2011.08.17C++ 레퍼런스 - ios 클래스(0)
2011.08.17C++ 레퍼런스 - ios_base 클래스(0)
2011.08.17C++ IOstream (입출력) 라이브러리(1)
2011.08.17




```warning
이 레퍼런스의 모든 내용은 http://www.cplusplus.com/reference/iostream/
 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ 
Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 씹어먹는 C++ 강좌는 어때요?
```


ifstream



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F11562C3C509A4623156640)

파일 입력 스트림 클래스 이다. 
  ifstream 은 입력 스트림으로 부터 데이터를 읽을 수 있게 해준다. 이 함수의 객체는 내부적으로 filebuf 객체를 가리키는 포인터로, 이는 rdbuf 함수를 통해 얻어질 수 있다. 이 스트림과 파일을 연관(associate)시키기 위해서 생성자에 인자로 파일 이름을 지정하거나, open 함수를 통해서 할 수 있다. 

  만일 모든 파일 작업이 끝나게 되면 close 함수를 통해 스트림과 파일 관계를 끊을 수 있다. 한 번 끊어진다면 같은 다른 파일과 스트림을 연관시켜서 사용할 수 있게 된다. 

  is_open 함수를 통해 현재 스트림 객체가 파일과 연관이 되어 있는지 확인할 수 있다.

 Public 멤버

* 생성자 - 객체를 생성하며 부가적으로 파일과 연관시킬 수 있다.rdbuf  :  filebuf 객체를 얻는다. is_open :  파일이 열려있는지 확인한다. open  :  파일을 연다. close  :  파일을 닫는다. 
istream 으로 부터 상속 받은 멤버들

* operator>> :  서식화된 데이터를 추출(입력)한다. gcount  :  마지막 서식화 되지 않은 입력에서 받아들였었던 문자의 개수를 구한다.get  :  스트림으로 부터 서식화 되지 않은 데이터를 얻는다. getline :  스트림으로 부터 한 줄을 입력받는다. ignore :  문자들을 입력 받고 지운다. peek :  그 다음으로 추출될 문자를 얻어온다.  read  :  데이터 블록을 읽는다.  readsome  :  버퍼에서 읽기 가능한 데이터 블록을 읽어온다.putback  :  문자를 다시 집어넣는다.  
unget :  get pointer 을 감소 시킨다.tellg  :  get pointer 의 위치를 얻는다. seekg  :  get pointer 의 위치를 설정한다.sync  :  입력 버퍼를 문자들의 소스에 동기화 시킨다. sentry  :  예외로 부터 안전한 접두/접미 작업을 수행한다. (클래스)
ios 로 부터 상속 받은 함수들

* good  :  스트림의 상태가 입출력 작업을 할 수 있는지 확인한다.eof  :  eof 비트가 설정되었는지 확인한다.fail  :  fail 비트나 bad 비트가 설정되었는지 확인한다.bad :  bad 비트가 설정되었는지 확인한다. operator! :  스트림 객체에 오류 플래그(fail 비트나 bad 비트)가 설정되었는지 확인한다.operator void* :  포인터로 변환한다. rdstate  :  오류 상태 플래그(error state flag)를 얻어온다.setstate  :  오류 상태 플래그를 설정한다.clear  :   오류 상태 플래그들을 설정한다copyfmt  :  서식 정보를 복사한다.fill :  채우기 문자(fill character) 을 얻거나 설정한다.exceptions :  예외 마스크를 얻거나 설정한다.   imbue :  로케일을 설정한다. 
tie  :  엮어진 스트림(tied stream)을 얻거나 설정한다. 
rdbuf  :  연관된 스트림 버퍼를 얻거나 설정한다. narrow  : 표준 char 형으로 문자를 변환한다.widen :  표준 wchar_t 형으로 문자를 변환한다. 
ios_base 로 부터 상속된 함수들

* flags :  서식 플래그를 수정하거나 얻어온다. setf  :  특정 서식 플래그를 설정한다. 
unsetf  :  특정 서식 플래그를 초기화 한다. 
precision  :  부동 소수점 정밀도를 수정하거나 얻어온다. 
width  :  필드의 너비를 수정하거나 얻어온다imbue  :  로케일을 채운다.getloc  :  현재 로케일을 얻어온다xalloc  :  내부 확장 가능 배열의 새로운 인덱스를 리턴한다. (정적 함수)iword  :  내부 확장 가능 배열의 특정 정수 원소의 레퍼런스를 얻는다.pword  :  내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.register_callback  :  이벤트 콜백 함수를 등록한다. sync_with_stdio :  iostream 과 cstdio 스트림과의 동기화를 활성화 하거나 비활성화 한다.

공감sns신고저작자표시'C++ Reference > IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios_base::flags 함수(0)
2011.08.19C++ 레퍼런스 - ios_base::width(0)
2011.08.18C++ 레퍼런스 - ifstream 클래스(0)
2011.08.18C++ 레퍼런스 - ios::exceptions(0)
2011.08.18C++ 레퍼런스 - istream::getline 함수(0)
2011.08.18C++ 레퍼런스 - istream::operator>> (추출 연산자)(0)
2011.08.17


----------------
title : C++ 레퍼런스 - ios::exceptions
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 [저의 모토인 '지식전파'](http://itguru.tistory.com/notice/107) 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios::exceptions

```cpp
iostate exceptions ( ) const;
void exceptions ( iostate except );
```


예외 마스크(exception `mask)` 를 얻거나 설정한다.

첫번째 형태의 함수는 현재 스트림의 예외 마스크를 리턴한다.

두번째 형태의 함수는 새로운 예외 마스크를 설정하고 `clear(rdstate())` 를 호출한다.

  예외 마스크는 모든 스트림 객체가 각각 가지고 있는 데이터로,예외마스크에 해당하는 상태 플래그가 설정 되었을 시 반드시 예외를 `throw``` 해야만 한다. 이 마스크는 ios_base::iostate 타입의 객체로, 아래와 같은 멤버 상수들의 조합으로 값이 결정된다.


플래그 값
의미
`eofbit`
스트림으로부터 추출 작업(extracting operation)을 수행 중` End` – `Of` – ` File`에 도달하는 경우
`failbit`
마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을 `` 경우
`badbit`
스트림 버퍼의 입출력 작업이 실패하여 발생한 오류
`goodbit`
오류가 없다`. .

  한 개 이상의 상태 플래그를 `OR` 연산자로 조합하여 하나의 비트 마스크(bit mask)를 만들 수 있게 된다. 기본값로 스트림 객체는 `goodbit` 예외 마스크를 가지고 있는데, 이 말은 어떠한 상태 플래그가 설정 되어도 예외를 던지지 않는다는 의미 이다.



###  인자




`except`

  ios_base::iostate 형의 비트 마스크 값으로 오류 상태 플래그 비트들(badbit, `eofbit, failbit)` 의 조합에 의해 설정된다.




###  리턴값




  ios_base::iostate 타입의 비트 마스크로 이 함수를 호출하기 직전의 예외 마스크를 리턴한다.



###  실행 예제


```cpp

/*사용자가 file 의 exception 에 failbit 와 badbit 를 등록하였으므로 이들 비트가 설정될 때 예외를 throw 하게 된다. 나의 경우 test.txt 파일에 내용이 존재하지 않았으므로failbit 가 설정되어서 예외가 throw 된 것이다.*/#include <iostream>#include <fstream>using namespace std;int main (){    ifstream file;    file.exceptions ( ifstream::failbit | ifstream::badbit );    try    {        file.open ("test.txt");        file.get();    }    catch (ifstream::failure e)    {        cout << "Exception opening/reading file";    }    file.close();    return 0;}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F145ED6344E4BEA8A334FD9)




###  템플릿 멤버 정의




```cpp
// ( basic_ios<charT,traits> )
iostate exceptions () const;
iostate exceptions ( iostate except );
```





###  연관된 함수

*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.








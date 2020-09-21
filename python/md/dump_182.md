----------------
title : C++ 레퍼런스 - ios::rdbuf 함수
cat_title :  ios::rdbuf
publish_date : 2012-03-25
ref_title : ios::rdbuf, rdbuf
--------------



##@ cpp-ref-start

#@ ios::rdbuf

```info-format
streambuf* rdbuf ( ) const;
streambuf* rdbuf ( streambuf* sb );

```

연관된 스트림 버퍼를 설정하거나 얻는다.
첫번째 형태의 함수는 연관된 스트림 버퍼를 리턴한다.
두 번째 형태의 경우 현재 스트림을 `sb` 와 연관 시키고 이전에 연관되어 있었던 스트림 버퍼를 리턴한다. 이 때 상태 플래그는 `goodbit` 로 설정된다.



###  인자


`sb`

연관시킬 스트림 버퍼를 가리키는 포인터



###  리턴값

이전에 연관되어 있었던 스트림 버퍼

###  실행 예제


```cpp
/*이 예제는http://www.cplusplus.com/reference/iostream/ios/rdbuf/에서
 * 가져왔습니다.*/
#include <iostream>
#include <fstream>

using namespace std;
int main() {
  streambuf *psbuf, *backup;
  ofstream filestr;
  filestr.open("test.txt");
  backup = cout.rdbuf();  // 현재 cout 의 스트림 버퍼를 백업한다. 
  psbuf = filestr.rdbuf();   // 파일 스트림 버퍼를 얻는다
  cout.rdbuf(psbuf);         // 파일 스트림 버퍼를 cout 에 연관시킨다
  cout << "This is written to the file"; // 따라서 이것은 파일에 쓰여진다.
  out.rdbuf(backup);        // 원래 cout 의 스트림 버퍼로 돌아간다.
  filestr.close();
      return 0;
}
```

#### 실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F19116F414F6E86F8080AC6)

파일에 잘 출력된 것을 알 수 있다.

###  템플릿 멤버 정의


```cpp-formatted
(basic_ios<charT, traits>)

  basic_streambuf<charT, traits>* rdbuf() const;
basic_streambuf<charT, traits>* rdbuf(basic_streambuf<charT, traits> sb);
```

###  연관된 자료

* `streambuf` :  스트림의 기반(base) 버퍼 클래스
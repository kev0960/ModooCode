----------------
title : C++ 레퍼런스 - ios::fail 함수
cat_title :  ios::fail
ref_title : fail, ios::fail
publish_date : 2011-10-23
--------------



##@ cpp-ref-start

#@ ios::fail

```info-format
bool fail ( ) const;
```


`failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
이 함수는 `failbit` 이나 `badbit` 중 어느 하나가 설정(set) 되어 있으면 `true` 를 리턴한다. 이 플래그들은 입력 작업 시 파일 끝(End `Of File)` 에 도달하기 전에 오류가 발생할 시 설정되는 플래그 들이다.

  `failbit` 은 보통 입력 작업 시 내부적인 논리 오류로 인해 발생되는 오류, 예컨대 입력 받기를 기대하였던 값이 오지 않을 때 (파일에 접근할 수 없다던지..) 설정되므로, `failbit` 이 설정되더라도 스트림의 다른 입출력 작업들은 가능하다. 반면에 `badbit` 의 경우 스트림의 완전성(integrity)이 깨질 때, 쉽게 말하면 하나의 스트림에 동시의 두 개의 다른 작업이 진행될 때 발생되는 것이므로 `badbit` 이 설정되면 다른 입출력 작업들은 할 수 없게 된다. `badbit` 은 `bad` 함수를 통해 상태를 독립적으로 확인할 수 있다.

이 함수는 `operator!` 와 동일하게 작동한다.



###  인자


없다



###  리턴값




`badbit` 나 `failbit` 가 설정되어 있다면 `true` 를 리턴한다. 아니면 `false`



###  템플릿 멤버 선언




```cpp-formatted
(basic_ios<charT, traits>)bool fail() const;
```




###  실행 예제




```cpp-formatted
/*

cin 으로 int 형 변수를 입력 받는데, 그 외의 타입의 값이 오면 failbit 가 설정되어
입력을 중지한다.

*/
#include <iostream>
using namespace std;

int main() {
  int i;
  while (!cin.fail()) {
    cin >> i;
    cout << "What you typed : " << i << endl;
  }

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F203CBC3E4EA35BD02BF7FF)




###  참고 자료

* `ios_base::iostate`  :  스트림 상태 플래그들을 위한 타입
*  [ios::bad](http://itguru.tistory.com/166)  :  `badbit` 이 설정되어 있는지 확인한다.
*  [ios::good](http://itguru.tistory.com/164):  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
*  [ios::setstate](http://itguru.tistory.com/179)  :  오류 상태 플래그를 설정한다.
*  [ios::clear](http://itguru.tistory.com/180)  :  오류 상태 플래그를 설정한다.
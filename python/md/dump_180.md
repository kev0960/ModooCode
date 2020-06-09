----------------
title : C++ 레퍼런스 - ios::clear
cat_title :  ios::clear
ref_title : clear
publish_date : 2012-03-25
--------------



##@ cpp-ref-start

#@ ios::clear

```info-format
void clear ( iostate state = goodbit );
```


오류 상태 플래그를 설정한다.
오류 상태 플래그를 새로운 값으로 설정한다. 참고로 이와 유사한 동작을 하는 [ios::setstate](http://itguru.tistory.com/179)의 경우, 이전의 오류 상태 플래그를 보존하면서 설정하지만, ios::clear 의 경우 이전의 오류 상태 플래그 값을 보존하지 않는다.

만일 인자를 넣어주지 않는다면 (혹은 인자로 `goodbit` 을 전달하면) 모든 오류 상태 플래그는 초기화된다.

현재의 오류 상태 플래그는 [ios::rdstate](http://itguru.tistory.com/171)함수로 얻을 수 있다.



###  인자

`state`

새롭게 바꿀 `ios_base::iostate` 타입의 객체로 아래의 오류 상태 멤버 상수들의 조합 (비트 OR 연산) 으로 구성된다.

|플래그 값|의미|
|-------|----|
|`eofbit`|스트림으로부터 추출 작업(extracting operation)을 수행 중 End Of File 에 도달하는 경우|
|`failbit`|마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을 경우|
|`badbit`|스트림 버퍼의 입출력 작업이 실패하여 발생한 오류|
|`goodbit`|오류가 없다|

만일 인자로 아무 것도 전달하지 않는다면 디폴트 인자로 `goodbit` 가 전달된다.




###  리턴값



없음



###  실행 예제




```cpp-formatted
/*

test.txt 를 in 형식으로 open 하였으므로 읽기만 가능한다. 따라서 쓰기를 하면
오류가 발생하므로 myfile.fail() 이 true 가 되고 입출력 작업은 중지되지만 오류
상태 플래그를 초기화함으로써 나중에 getline 을 수행할 수 있게 된다.

이 예제는
http://www.cplusplus.com/reference/iostream/ios/clear/
에서 가져왔습니다.

*/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  char buffer[80];
  fstream myfile;

  myfile.open("test.txt", fstream::in);

  myfile << "test";
  if (myfile.fail()) {
    cout << "Error writing to test.txt\n";
    myfile.clear();
  }

  myfile.getline(buffer, 80);
  cout << buffer << " successfully read from file.\n";

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F182B374B4F6E75AF1F5F53)




###  템플릿 멤버 정의





```cpp-formatted
(basic_ios<charT, traits>)

  void clear(iostate state = goodbit);
```




###  참고 자료

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::bad](http://itguru.tistory.com/166)  :  `badbit` 이 설정되어 있는지 확인한다.
*  [ios::good](http://itguru.tistory.com/164) :  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
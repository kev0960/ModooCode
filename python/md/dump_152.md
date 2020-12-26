----------------
title : C++ 레퍼런스 - ios_base::width
cat_title :  ios_base::width
publish_date : 2011-08-18
ref_title : ios_base::width, width
path : /C++ Reference/iostream
--------------



##@ cpp-ref-start

#@ ios_base::width

```cpp-formatted
streamsize width() const;
streamsize width(streamsize wide);
```


너비를 설정하거나 얻어온다.
위 소스에서 첫번째 형태의 함수는 현재 필드 너비를 구한다.
두번째 형태의함수는 필드의 너비를 수정한다.

필드 너비는 출력될 문자의 최소 개수를 의미한다. 만일 출력할 문자의 개수가 필드 너비보다 작다면, 채우기 문자(fill character) 을 넣어서 필드 너비를 맞추게 된다. 이 때 어디에 채우기 문자가 들어갈지는 서식 플래그인 `adjustfield` (`left, right, internal` 이 있다) 가 결정한다.

또한 채우기 문자는 [ios::fill](http://itguru.tistory.com/181)을 통해 수정하거나, 얻어질 수 있다.

서식 플래그 `adjustfield` 는 `setf` 나 [flags](http://itguru.tistory.com/153) 함수를 통해서, 혹은 `left, right, internal` 과 같은 조작자(manipulator) 을 넣음으로써, 혹은 인자가 있는 조작자인 `setiosflags` 를 통해서 수정될 수 있다.

또한 필드 너비는 인자가 있는 조작자인 `setw` 를 통해서도 수정될 수 있다.


###  인자


`wide`

스트림의 필드 너비의 새로운 값으로, `streamsize` 타입으로 정수 형태 이다.



###  리턴값


  함수 호출 직전의 필드 너비 값



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/width/
에서 가져왔습니다

*/
#include <iostream>
using namespace std;

int main() {
  cout << 100 << endl;
  cout.width(10);
  cout << 100 << endl;
  cout.fill('x');
  cout.width(15);
  cout << left << 100 << endl;
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F205F6A374E4BF4E1335046)




###  참고 자료


* `setw` : 필드 너비를 조절한다.
*  [ios_base::flags](http://itguru.tistory.com/153):  서식 플래그를 수정하거나 얻는다.
*  [ios_base::setf](http://itguru.tistory.com/155)  :  특정 서식 플래그를 수정한다.
*  [ios::fill](http://itguru.tistory.com/181):  채우기 문자를 얻거나 수정한다.
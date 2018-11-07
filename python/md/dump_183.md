----------------
title : C++ 레퍼런스 - STL 컨테이너 - vector::assign 함수
cat_title :  vector::assign
ref_title : assign
path : /C++ Reference/Containers/vector
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ vector::assign

```info
template <class InputIterator>
  void assign ( InputIterator first, InputIterator last );
void assign ( size_type n, const T& u );

```

벡터에 새로운 내용을 집어 넣는다.
벡터 객체에 이전에 있었던 원소들은 모두 삭제하고, 인자로 받은 새로운 내용을 집어 넣는다.

첫번째 형태의 함수의 경우 `first` 부터 `last` 까지에 있는 원소들의 내용이 벡터에 들어가게 된다. (first 부터 last 바로 직전 원소 까지) 물론, 원래 벡터에 있었던 원소들은 삭제된다.

두번째 형태는 원래 내용을 다 지우고 원소 `u` 를 `n` 개 가지는 벡터로 만든다.



###  인자





`first, last`

`first` 부터 `last` 바로 직전까지의 원소들을 벡터에 대입한다.

`n`

몇번 `u` 를 반복해서 집어 넣을 지에 대해 전달한다. 이 때 `n` 은 `size_type` 타입으로, 부호 없는 정수 타입이다.

`u`

반복될 원소로 `T` 타입이다.



###  리턴값


없다



###  실행 예제



```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/stl/vector/assign/
에서 가져왔습니다

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> first;
  vector<int> second;
  vector<int> third;

  first.assign(7, 100);  // 100 을 7 번 반복해서 집어 넣는다.

  vector<int>::iterator it;
  it = first.begin() + 1;

  second.assign(it, first.end() - 1);  // first 의 처음과 끝을 제외한 원소들

  int myints[] = {1776, 7, 4};
  third.assign(myints, myints + 3);  // 배열로 부터 받는다.

  cout << "Size of first: " << int(first.size()) << endl;
  cout << "Size of second: " << int(second.size()) << endl;
  cout << "Size of third: " << int(third.size()) << endl;
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F19102C4E4F6E967A10EEAF)




###  연관된 함수

* vector::operator= : 벡터 내용을 복사한다.
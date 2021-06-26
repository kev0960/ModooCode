----------------
title : C++ 레퍼런스 - STL 컨테이너 - vector 생성자
cat_title :  vector 생성자
publish_date : 2012-03-25
path : /C++ Reference/Containers/vector
--------------



##@ cpp-ref-start

#@ vector::vector


```cpp
explicit vector ( const Allocator& = Allocator() );
explicit vector ( size_type n, const T& value= T(), const Allocator& = Allocator() );
template <class InputIterator>
         vector ( InputIterator first, InputIterator last, const Allocator& = Allocator() );
vector ( const vector<T,Allocator>& x );
```


벡터를 생성한다.
벡터 컨테이너 객체를 생성하고, 사용한 생성자에 따라서 벡터 원소들을 초기화 한다.

```cpp-formatted
explicit vector(const Allocator& = Allocator());
```

▶ 디폴트 생성자(default `constructor)` 로 빈 벡터를 생성한다. 어떠한 원소도 담지 않고 있으므로 `size` 는 0 이다.


```cpp-formatted
explicit vector(size_type n, const T& value = T(),
                const Allocator& = Allocator());
```

▶값이 `T` 인 원소를 `n` 개 가지는 벡터 컨테이너를 생성한다.


```cpp-formatted
template <class InputIterator>
vector(InputIterator first, InputIterator last, const Allocator& = Allocator());
```

▶`first` 부터 `last` 번째 원소 까지 반복자가 순회(iterate) 하며, 각각의 원소들을 생성되는 벡터 컨테이너의 원소로 복사한다.


```cpp-formatted
vector(const vector<T, Allocator>& x);
```

▶복사 생성자. 벡터 `x` 와 동일한 원소 (복사본) 를 가지는 벡터를 생성한다.




###  인자




`n`

몇 번이나 원소를 반복해서 생성할지 나타낸다. 이 때 `n` 은 부호 없는 정수 타입이다.

`value`

벡터 컨테이너 객체에서 `n` 번 반복될 원소의 값
따라서 `value` 의 타입은 `T` 이다.

`first, last`

복사할 범위의 시작과 끝을 나타내는 반복자이다. 이 때 `first` 가 가리키는 원소 부터, `last` 가 가리키는 원소바로 직전까지 복사가 된다 (즉, 원소 전체를 복사하기 위해서는 `last` 에 `end` 를 전달하면 된다)

`x`

같은 클래스 템플릿 인자 (`T, Allocator`) 을 가지는 벡터 객체로, 이 객체가 복사되어 생성된다.



###  실행 예제



```cpp-formatted
/*이 예제는http://www.cplusplus.com/reference/stl/vector/vector/에서
 * 가져왔습니다.*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned int i;  // 위에서 설명한 생성자들을 차례대로 오버로딩함 vector<int>
                   // first;                                // int 를 보관할 빈
                   // 벡터 생성    vector<int> second (4,100); // 값이 100 인
                   // int 원소 4 개 보관    vector<int> third
                   // (second.begin(),second.end());  // second 의 처음 ~ 끝으로
                   // 생성    vector<int> fourth (third); // 세 번째 벡터 복사본
  // 배열을 통해서도 생성 가능하다.

  int myints[] = {16, 2, 77, 29};
  vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
  cout << "The contents of fifth are:";
  for (i = 0; i < fifth.size(); i++) cout << " " << fifth[i];
  cout << endl;
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F181EE0434F6DEDE33C9FD7)





###  시간 복잡도





디폴트 생성자의 경우 상수 시간
동일한 원소 반복해서 생성하는 생성자 경우, `n` 에 비례
반복자를 이용해서 생성하는 경우, 두 반복자 사이 거리에 비례.
복사 생성자의 경우 `x` 의 크기에 비례한다.




###  참고 자료


* vector::assign : 벡터 내용을 대입한다.
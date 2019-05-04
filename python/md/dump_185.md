----------------
title : C++ 레퍼런스 - vector::push_back
cat_title : vector::push_back
ref_title : push_back
path : /C++ Reference/Containers/vector
publish_date : 2012-08-05
--------------

##@ cpp-ref-start

#@ vector::push_back

```info-format
void push_back ( const T& x );

```

벡터 끝에 원소를 추가한다.

현재의 마지막 원소 뒤에 새로운 원소를 추가하며, 그 원소의 값은 `x` 의 복사본으로 초기화 된다.


이 함수는 효과적으로 벡터의 크기를 1 늘리는데, 만일 `capacity` 와 벡터 `size` 가 같다면 내부적으로 재할당이 일어나게 된다. 이 때 이전에 사용되었던 반복자(iterator) , 레퍼런스, 포인터들은 사용할 수 없게 된다.




###  인자


* `x` : 새로 추가 될 원소에 복사 될 원소`T` 는 벡터에 저장되어있는 원소들의 타입이다.


###  리턴값

없음

만일 재할당이 발생한다면 이는 `Allocator::allocate()` 를 이용해서 수행되는데, 예외를 던질(throw) 수 있다. (디폴트 할당자의 경우 만일 요청한 할당이 성공하지 않을 경우 `bad_alloc` 이 던져진다)




###  실행 예제




```cpp-formatted
/*

이 예제는
 [http://www.cplusplus.com/reference/stl/vector/push_back/](http://www.cplusplus.com/reference/stl/vector/push_back/)
에서 가져왔습니다

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> myvector;
  int myint;

  cout << "Please enter some integers (enter 0 to end):\n";

  do {
    cin >> myint;
    myvector.push_back(myint);
  } while (myint);

  cout << "myvector stores " << (int)myvector.size() << " numbers.\n";

  return 0;
}
```




실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F1519CE4C501DD721070E78)





###  시간 복잡도



상수 (다만 재할당이 일어 날 수 있음)


###  참고 자료




* `vector::pop_back` : 마지막 원소를 삭제한다.
*  [vector::insert](http://itguru.tistory.com/186): 원소를 추가한다.
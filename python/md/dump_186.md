----------------
title : C++ 레퍼런스 - vector::insert
cat_title :  vector::insert
ref_title : insert
path : /C++ Reference/Containers/vector
--------------








```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```



#@ vector::insert


```info

iterator insert ( iterator position, const T& x );
    void insert ( iterator position, size_type n, const T& x );
template <class InputIterator>
    void insert ( iterator position, InputIterator first, InputIterator last );
```



원소를 추가한다.
특정 위치에 원소를 추가함으로써 벡터가 확장된다.


이 함수는 벡터의 크기를 효과적으로 증가시키는데, 만일 새로운 벡터의 size 가 현재 벡터의 `capacity` 보다 크다면 재할당을 하게 된다. 재할당 시, 벡터 컨테이너의 이전에 얻은 모든 반복자(iterator), 레퍼런스들은 무효화 된다.


벡터는 배열의 형태로 저장되기 때문에 벡터 끝이 아닌 임의의 위치에 원소를 삽입하게 되면 그 뒤에 있는 원소들을 뒤로 이동시키게 된다. 따라서벡터에서 원소들 중간에 새로운 원소들을 삽입하는 일은 그다시 효율적이지 못하다.

따라서 이러한 작업을 많이 하게 된다면 다른 순차 컨테이너 ( [deque](http://itguru.tistory.com/176), [list](http://itguru.tistory.com/177)) 를 참고하기 바란다.




###  인자


`position`

새로운 원소가 추가될 위치

`iterator` 은 멤버 타입으로 임의 접근 반복자 타입(random access iterator type) 이다.

`x`

삽입할 원소의 값으로 `T` 형이다. (T 는 벡터에 삽입되는 원소들의 타입)

`n`

삽입할 원소의 수. 각 원소들은 같은 값 `x` 로 초기화된다.멤버 타입 `size_type` 은 부호 없는 정수 이다.

`first, last`

특정 범위의 원소들을 지칭하는 반복자이다. `first` 에서 `last` 전 까지의 원소들을 `position` 에 삽입하게 된다. 한 가지 주의할 것은 `first` 에서 `last` 까지가 아닌 `last` 직전 까지의 원소들이다. 즉 `last` 번째의 원소는 삽입되지 않는다.



###  리턴값




`iterator insert ( iterator position, const T& x );` 

함수만 리턴값이 있는데 이는 새롭게 추가된 원소를 가리키는 반복자를 리턴한다.
만일 재할당이 일어나게 되면 `Allocator::allocate()` 를 이용해서 할당을 하게 되는데 성공적으로 할당이 되지 않았을 경우 예외를 던지(throw) 게 된다. 디폴트 할당자의 경우 `bad_alloc` 을 던진다.



###  실행 예제




```cpp

/*


이 예제는
 [http://www.cplusplus.com/reference/stl/vector/insert/](http://www.cplusplus.com/reference/stl/vector/insert/)
에서 가져왔습니다


*/
#include <iostream>
#include <vector>
using namespace std;


int main ()
{
vector<int> myvector (3,100);
vector<int>::iterator it;


it = myvector.begin();
it = myvector.insert ( it , 200 );


myvector.insert (it,2,300);


// "it" no longer valid, get a new one:
it = myvector.begin();


vector<int> anothervector (2,400);
myvector.insert (it+2,anothervector.begin(),anothervector.end());


int myarray [] = { 501,502,503 };
myvector.insert (myvector.begin(), myarray, myarray+3);


cout << "myvector contains:";
for (it=myvector.begin(); it<myvector.end(); it++)
cout << " " << *it;
cout << endl;


return 0;
}
```



실행 결과



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F1243AE4F501DDDF2111AAA)





###  시간 복잡도



삽입 이후의 벡터의 크기가 삽입 이전에 결정될 수 있다면 입력되는 원소의 개수와 (복사 생성) 삽입 위치 뒤에 있는 원소들의 개수 (이동 연산) 의 합에 선형으로 비례한다.
만일 삽입 이후의 벡터의 크기가 결정될 수 없다면 삽입 이전에 결정되지 않는다면 (이는 `void insert ( iterator position, InputIterator first, InputIterator last );` 함수에서 `InputIterator` 가 순방향, 양방향, 임의 접근 반복자 모두가 아닐 경우) 삽입되는 원소의 수와 삽입 위치 뒤에 있는 원소의 개수의 곱에 비례한다.



###  연관된 함수


*  [vector::push_back](http://itguru.tistory.com/185): 벡터 끝에 원소를 추가한다.
* vector::erase : 원소를 삭제한다.




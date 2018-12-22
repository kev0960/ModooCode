----------------
title : 씹어먹는 C++ - <3. C++ 의 세계로 오신 것을 환영합니다. (new, delete)>
cat_title: 3. C++ 의 세계로 오신 것을 환영합니다. (new, delete)
next_page : 172
publish_date : 2012-01-01
--------------


이번 강좌에서는

* `new` 와 `delete` 의 사용

* **Welcome to Object Oriented Programming World!**
  
![](/img/ChewingCpplogo.png)

안녕하세요~ 여러분. 오랜 공백기간을 뚫고 찾아온 Psi 입니다. 그동안 많이 기다리셨죠? 이제 부터 본격적으로 이전의 C 에서 탈피하여 C++ 의 세계로 인도해드릴 것입니다.

메모리를 관리하는 문제는 언제나 중요한 문제입니다. 프로그램이 정확하게 실행되기 위해서는 컴파일 시에 모든 변수의 주소값이 확정되어야만 했습니다. 하지만, 이를 위해서는 프로그램에 많은 제약이 따르기 때문에 프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 **힙(heap)** 이라는 공간이 따로 생겼습니다.

하지만 이전에 컴파일러에 의해 완벽히 확정되어 안정성이 보장되는 **스택(stack)** 과는 다르게 힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임이 따릅니다. [위 문단이 이해되지 않는 분이라면 이 글을 읽어보도록 합시다](http://itguru.tistory.com/98)

C 언어에서는 `malloc` 과 `free` 함수를 지원하여 힙 상에서의 메모리 할당을 지원하였습니다. C++ 에서도 마찬가지로 `malloc` 과 `free` 함수를 사용할 수 있습니다.

하지만, 언어 차원에서 지원하는 것으로 바로 `new` 와 `delete` 라고 할 수 있습니다. `new` 는 말 그대로 `malloc` 과 대응되는 것으로 메모리를 할당하고 `delete` 는 `free` 에 대응되는 것으로 메모리를 해제합니다. 그럼 한 번 소스를 살펴볼까요.

```cpp-formatted
/* new 와 delete 의 사용 */
#include <iostream>
using namespace std;

int main() {
  int* p = new int;
  *p = 10;

  cout << *p << endl;

  delete p;
  return 0;
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F134A4E3B4EFFDB710F5F69)

위와 같이 `int` 영역이 잘 할당 되어서 10 이 출력이 되었음을 알 수 있습니다.

```cpp-formatted
int* p = new int;
```


먼저 위와 같이 `int` 크기의 공간을 할당하여 그 주소값을 `p` 에 집어 넣었음을 알 수 있습니다. `new` 를 사용하는 방법은

```cpp-formatted
T* pointer = new T;
```


와 같습니다. `T` 에는 임의의 타입이 들어가겠지요. 그리고 이제 `p` 위치에 할당된 공간에

```cpp-formatted
*p = 10;
```


를 통해서 값을 집어넣었고 이를 출력하였습니다. 마지막으로 할당된 공간을 해제하기 위해서 `delete` 를 사용하였는데

```cpp-formatted
delete p;
```


위와 같이 `delete p` 를 하게 되면 `p` 에 할당된 공간이 해제됩니다. 물론 `delete` 로 해제할 수 있는 메모리 공간은 사용자가 `new` 를 통해서 할당한 공간만 가능합니다.

```cpp-formatted
/* 지역 변수 delete 하기 */
#include <iostream>
using namespace std;

int main() {
  int a = 5;

  delete &a;

  return 0;
}
```


만일 위 처럼 지역 변수를 무리하게 `delete` 로 해제해버리려 한다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F13656D404EFFDE912153AD)

위와 같이 `Heap` 이 아닌 공간을 해제하려고 한다는 경고 메세지가 나타나게 됩니다.



###  new 로 배열 할당하기


```cpp-formatted
/* new 로 배열 할당하기 */

#include <iostream>
using namespace std;
int main() {
  int arr_size;
  cout << "array size : ";
  cin >> arr_size;
  int *list = new int[arr_size];
  for (int i = 0; i < arr_size; i++) {
    cin >> list[i];
  }
  for (int i = 0; i < arr_size; i++) {
    cout << i << "th element of list : " << list[i] << endl;
  }
  delete[] list;
  return 0;
}
```


  성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F133842454EFFE02A270E1B)

  위 소스에는 많은 새로운 내용이 담겨 있으니 차근 차근 살펴보도록 합시다.

```cpp-formatted
int arr_size;

cout << "array size : ";
cin >> arr_size;

int *list = new int[arr_size];
```


먼저 위와 같이 배열의 크기를 잡을 `arr_size` 라는 변수를 정의하였고 그 값을 입력 받았습니다. 그리고 `list` 에 `new` 를 이용하여 크기가 `arr_size` 인 `int` 배열을 생성하였습니다. 배열을 생성할 때 에는 `[]` 를 이용해 배열의 크기를 넣어주면 되는데,

```cpp-formatted
T* pointer = new T[size];
```


`T` 를 임의의 타입이라 하면 위와 같이 하면 됩니다. 따라서 `list` 는 이제 크기가 `arr_size` 인 `int` 배열을 가지게 됩니다. 사실 여기서 한 가지 놀라운 점이 있는데 C 에선 변수의 선언을 모두 최상단에 몰아서 해야 했지만 C++ 은 그렇지 않다는 점입니다. C++ 에서는 편리하게도 소스의 아무대서나 변수를 선언할 수 있으며, 그 변수는 그 변수를 포함하고 있는 중괄호를 빠져 나갈 때 소멸됩니다. 예를 들어서 아래와 같은 코드를 봅시다.

```cpp-formatted
// 생략
{
  int a = 4;
  cout << "안에서 a : " << a;
}

cout << "밖에서 a : " << a;
```


만일 여러분이 위와 같이 중괄호 안에서 변수 `a` 를 선언하였다면 변수 `a` 의 사용 범위는 그 중괄호 안 뿐입니다. 즉 안에서 `a` 는 4 로 잘 출력이 되겠지만 "밖에서 a :" 문장은 오류가 나게 될 것입니다. 왜냐하면 변수 `a` 가 그 곳에서는 존재하지 않기 때문이죠. 따라서 여러분은 이 점을 항상 유의하셔야 겠습니다. 또한 한 가지 더 재미있는 점은, 어떤 변수를 사용할 때 컴파일러는 그 변수를 가장 가까운 범위(scope) 부터 찾게 됩니다. 예를 들어 아래의 코드를 보세요

```cpp-formatted
int a = 4;
{
  cout << "외부의 변수 1" << a << endl;
  int a = 3;
  cout << "내부의 변수 " << a << endl;
}

cout << "외부의 변수 2" << a << endl;
```


외부의 변수 1 의 출력 결과를 보면 자명하게 4 가 될 것입니다. 왜냐하면 그 때까지 정의된 변수 `a` 는 앞서 정의한 `int a = 4` 하나 거든요. 하지만 그 아래에서 새롭게 `int a = 3;` 으로 정의한 후 (분명히 이 변수는 위에서의 `a = 4` 와 다른 변수 입니다) 내부의 변수를 출력해보면 3 이 나옵니다.

이는 앞서 말한 '가장 가까운 범위에서 찾는다' 라는 원칙 하에서 _'내부의 변수 << a '_ 에서 `a` 를 사용할 때 가장 가까운 범위 내에 있는 변수는 바로 같은 중괄호 내에 있는 `int a= 3;` 이므로 3 이 출력되는 것이지요. 바깥 범위에 있는 `a = 4` 의 `a` 는 내부에 있는 `a = 3` 의 `a` 에 의해 **가려집니다**. 그리고 중괄호를 지나면서 이 내부 변수는 소멸됩니다.

이제 다시 외부의 변수 2 를 출력할 때에는 `a = 4` 에서의 `a` 가 출력되어 4 가 나오게 되는 것입니다. 하지만 아래와 같이 같은 범위 안에 동일한 변수를 선언하는 것은 허용되지 않습니다.

```warning
    int a;
    a = 3;
    int a;
```


왜냐하면 그 다음에 `a` 를 사용하였을 때 둘 다 같은 범위 안에 있기 때문에 컴파일러는 어떠한 `a` 를 사용할 지 모르기 때문이지요. 한 가지 당부하고 싶은 말은 결코 위와 같은 변수의 선언 범위를 고려할 만큼 쪼잔하게 변수 이름을 짓지 말자 입니다.

사람의 눈은 컴파일러가 아니기 때문에 위와 같이 변수 이름을 중복해서 사용한다면 큰 혼동이 있을 뿐더러 나중에 디버깅시 곤란해질 수 있으니 항상 변수 이름은 다르게 짓는 습관을 들이는 것이 좋습니다.

이제 다시 본론으로 돌아와서 원래 코드를 살펴봅시다.

```cpp-formatted
for (int i = 0; i < arr_size; i++) {
  cin >> list[i];
}
for (int i = 0; i < arr_size; i++) {
  cout << i << "th element of list : " << list[i] << endl;
}
```


그림과 같이 `for` 문 안에서 `int i` 를 선언하여 `cin` 을 이용하여 `list` 를 받았습니다. 이렇게 `for` 문 초기식에서 정의된 `i` 는 과연 `for` 문 안에서 정의된 것일까요. `for` 문 밖에서 정의된 것일까요. 즉 `i` 를 `for` 문 밖에서도 사용할 수 있을까요? 

답은 안에서 정의된 것입니다. 즉 `i` 는 밖에서 사용할 수 없지요. 이렇게 `for` 문 초기식에 `i` 를 정의해버리면 좋은 점이 설사 밖에 `i` 를 다른 용도로 사용했더라도 `for` 문 안에서는 `i` 를 *카운터(counter)* 로 사용할 수 있기 때문에 오류가 발생할 가능성이 줄어듭니다.

아무튼 이렇게 해서 `list` 의 각 원소들을 입력받고 또 이를 출력할 수 있었습니다.

```cpp-formatted
delete[] list;
```


마지막으로 살펴볼 부분은 `delete` 하는 부분으로 앞서 `new []` 를 이용해서 할당 하였으면 아래에서는 `delete []` 를 통해서 해제하면 됩니다. 즉 `new - delete` 가 짝을 이루고 `new [] - delete []` 가 짝을 이루는 것이지요.



###  돌아온 마이펫



아마도 예전에 저의 C 언어 강좌를 보신 분들이라면 `switch` 문을 배우면서 간단하게 만들어보았던 마이펫을 기억하실 것입니다. 이번에는 그 때 기억을 살려서 동물 관리 프로그램을 간단하게 만들어보았습니다. 소스를 보기 전에 여러분들도 간단히 만들어보시는 것도 좋을 것 같습니다. 일단 조건은 다음과 같습니다.


* 동물(`struct Animal`) 이라는 구조체를 정의해서 이름(`char name[30]`), 나이(`int age`),체력(`int health`), 배부른 정도(`int food`), 깨끗한 정도의(`int clean`) 값을 가진다.
* 처음에 동물 구조체의 포인터 배열(`struct Animal* list[30]`)을 만들어서 사용자가 동물을 추가할 때 마다 하나씩 생성한다.
* `play` 라는 함수를 만들어서 동물의 상태를 변경하고 `show_stat` 함수를 만들어서 지정하는 동물의 상태를 출력한다.
* 1 턴이 지날 때 마다 동물의 상태를 변경한다 1 턴이 지날 때 마다 동물의 상태를 변경한다.

  대략 이 정도로만 하고 저는 한번 아래와 같이 소스를 짜보았습니다.

```cpp-formatted
#include <iostream>
using namespace std;

typedef struct Animal {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도
} Animal;

void create_animal(Animal *animal) {
  cout << "동물의 이름? ";
  cin >> animal->name;

  cout << "동물의 나이? ";
  cin >> animal->age;

  animal->health = 100;
  animal->food = 100;
  animal->clean = 100;
}

void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  // 하루가 지나면
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal *animal) {
  cout << animal->name << "의 상태" << endl;
  cout << "체력    : " << animal->health << endl;
  cout << "배부름 : " << animal->food << endl;
  cout << "청결    : " << animal->clean << endl;
}
int main() {
  Animal *list[10];
  int animal_num = 0;

  for (;;) {
    cout << "1. 동물 추가하기" << endl;
    cout << "2. 놀기 " << endl;
    cout << "3. 상태 보기 " << endl;

    int input;
    cin >> input;

    switch (input) {
      int play_with;
      case 1:
        list[animal_num] = new Animal;
        create_animal(list[animal_num]);

        animal_num++;
        break;
      case 2:
        cout << "누구랑 놀게? : ";
        cin >> play_with;

        if (play_with < animal_num) play(list[play_with]);

        break;

      case 3:
        cout << "누구껄 보게? : ";
        cin >> play_with;
        if (play_with < animal_num) show_stat(list[play_with]);
        break;
    }

    for (int i = 0; i != animal_num; i++) {
      one_day_pass(list[i]);
    }
  }
  for (int i = 0; i != animal_num; i++) {
    delete list[i];
  }
}
```


  성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F153D833B4F0033FA2BEBE4)

  그림과 같이 잘 작동됨을 알 수 있습니다. 사실 위 코드에는 그다지 특별한 것이 없습니다. 일단 주요 부분을 살펴볼까요.

```cpp-formatted
typedef struct Animal {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도
} Animal;
```


위와 같이 `Animal` 구조체를 만들어서 `typedef` 를 통해 `struct Animal` 을 `Animal` 로 간추렸습니다. 그리고,

```cpp-formatted
list[animal_num] = new Animal;
create_animal(list[animal_num]);
```


위와 같이 `Animal` 을 `new` 로 생성하면 `create_animal` 함수를 통해서 `Animal` 의 각 값들을 초기화 해주었고요, 사용자가 놀기를 요청하면

```cpp-formatted
if (play_with < animal_num) play(list[play_with]);
```

위 처럼 `play` 함수를 호출해서 놀기를 수행하였습니다. 마지막으로 사용자가 각 동물의 상태를 보기 원한다면

```cpp-formatted
if (play_with < animal_num) show_stat(list[play_with]);
```


`show_stat` 함수를 호출해서 사용자가 지정한 동물의 상태를 출력하도록 하였습니다. 사실 매우 간단한 이야기 입니다. 그런데 무언가 상당히 낭비 같지 않으세요? 사용자가 `play` 를 호출하면 `list[play_with]` 를 전달해야만 했습니다.

하지만 이러면 어떨까요?`Animal` 구조체 자체에 함수를 만들어서, 각 구조체 변수가 각각 자신의 함수를 가지게 되는 것입니다. 그러면 `list[play_with]->play()` 와 같이 "각 변수 자신의 함수" 를 호출하여 자신의 데이터를 이용해서 처리하게 되는 것이지요.

이렇게 할 수 만 있다면 `play` 함수에 귀찮게 인자를 전달할 필요도 없고 또 함수 내부에서도

```cpp-formatted
void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}
```


위와 같이 귀찮게 `animal->` 을 앞에 붙여가면서 작업할 필요도 없습니다. 왜냐하면 `list[play_with]->play()` 라고 했을 때 `play` 는 '자기 자신의 함수' 이기 때문에

```cpp-formatted
health += 10;
food -= 20;
clean -= 30;
```


이렇게 해도 된다는 것입니다. 왜냐하면 `list[play_with]->play()` 이라 했을 때 `health, food, clean` 이 의미하는 것이 `list[play_with]` 의 것이기 때문입니다. 상당히 괜찮은 생각 아닌가요? 위 소스에서 불편한 점은 이것만이 아닙니다. `new` 를 통해 새로운 동물을 할당하는 부분을 살펴봅시다.

```cpp-formatted
list[animal_num] = new Animal;
create_animal(list[animal_num]);
```


`new Animal` 을 통해 동물을 생성한 다음에 반드시 `create_animal` 함수를 호출해야만 했습니다. 왜냐하면 `new Animal` 을 통해 새로운 `Animal` 을 할당한 상태라면 `health, food` 등 변수에 아무런 값이 들어가 있지 않기 때문이죠. 다시 말해서 만일 프로그래머가 실수로 `Animal` 을 생성한 후 `create_animal` 을 호출하지 않는다면 나중에 `play` 함수 등을 호출 할 때 끔찍한 오류가 발생하게 됩니다. 초기화 되지 않는 값에 연산을 수행하는 오류이지요.

그렇다면 만일 `new` 로새로운 `Animal` 을 생성할 때 자동으로 호출되는 함수가 있으면 어떨까요. 즉 `new` 가 알아서 호출해주는 그런 함수. 그렇게 된다면 사용자는 귀찮게 `create_animal` 을 호출할 필요도 없고, 자동으로 호출되는 함수에서 멤버 변수들 (health, food, ...) 들을 초기화 해준다면 나중에 초기화 되지 않아서 생기는 오류도 막을 수 있을 것입니다.

자 이제. 여러분은 위 동물 프로그램이 크나큰 인기를 얻어서 확장팩을 제작하게 되었습니다. `Animal` 이라 단순하게 분류하였던 것을 조금 더 세분화 해서 `Bird, Fish` 등으로 나누어서 처리하려고 합니다. `Bird` 와 `Fish` 는 기본적으로 `Animal` 과 유사하지만 `Bird` 에는 현재 날고 있는 고도를 나타내는 변수인 `int` height; 가 새로 추가되고, `Fish` 에는 현재 잠수하고 있는 수심을 나타내고 있는 변수인 `int` deep; 이 추가되었습니다.

그러면 여러분은 아래와 같이 소스를 짤 것입니다.

```cpp-formatted
typedef struct Bird {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도

  // 여기까지는 Animal 과 동일하다.
  int height;  // 나는 고도

} Bird;

typedef struct Fish {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도

  // 여기까지는 Animal 과 동일하다.
  int deep;  // 나는 고도

} Fish;
```


와 정말로 시간 낭비가 아닐 수 없었습니다. `Animal` 과 거의 똑같지만 조금조금씩 달라진 것 때문에 구조체를 새로 두 개나 만들어야 한다는 말입니다. 그냥`Animal` 과 동일한 부분은 가져다 쓰고 새로 추가된 부분만 살포시 추가해 주면 안될까요?

그런데 문제는 이 뿐만이 아닙니다. 여러분은 더이상 `Animal*` 배열 하나로 살 수 없게 됩니다. 이제 `Animal*` 따로, `Fish*` 따로, `Bird*` 따로 만들어서 관리해야 될 뿐더러` play` 함수, `show_stat` 함수도 모두 `Animal, Fish, Bird` 에 맞게 각각 새로 작성해야 합니다. 다시 말해서 고작 `int height` 나 `int deep` 변수 하나 추가한 덕분에 여태까지 짠 코드 양의 2 배를 써야 하는 위기 상황에 처했습니다.

정말 말이 안되지요. 하지만 C 언어의 세계에 살고 있던 여러분은 이 모든 것을 꿋꿋히 해내고 있었을 것입니다.

그리고 이제. 이곳을 탈출할 때가 온 것 같습니다.

여러분,

**객체지향프로그래밍의 세계로 오신것을 환영합니다.**

##@ chewing-cpp-end
----------------
title : 씹어먹는 C++ - <4 - 1. 이 세상은 객체로 이루어져 있다>
cat_title: 4 - 1. 이 세상은 객체로 이루어져 있다
next_page : 173
publish_date : 2012-02-29
--------------


이번 강좌에서는
* 객체 지향 프로그래밍의 도래
* 객체란 무엇인가, 클래스란 무엇인가
* 접근 지시자 (public, private)

![](/img/ChewingCpplogo.png)


안녕하세요 여러분~ 그간 침묵을 깨고 오래간만에 C++ 강좌를 이어 나가고자 합니다. 앞선 3 강을 읽으셨던 분들은 다 느껴셨겠지만 기존의 C 언어를 통해서 대형 프로젝트를 개발하기 위해서는 많은 어려움들이 있기 마련입니다. (그래도 아직도 많은 수의 프로그램이 C 로 쓰여지고 있습니다)

사실 컴퓨터 프로그래밍 언어는 이러한 난관을 뚫고서 발전해 나갔습니다. 초기의 컴퓨터는 이름만 들어도 유명한 에니악(ENIAC) 과 같이 거대한 크기를 자랑하였습니다. 이러한 컴퓨터를 어떻게 프로그래밍 했냐고요?  아래 사진 오른쪽에 보이는 수 많은 진공관들 사이의 전선 연결을 바꾸어 가며 전기 신호를 전달했다고 합니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F204144494F4CB9F1063F09)

즉, 우리가 컴퓨터 상에서 소스 코드를 치는 것을 직접 손으로 조작했다고 보시면 됩니다. 정말로 끔찍한 일이 아닐 수 없지요. 이것을 '컴퓨터 언어 '라고 보기에는 조금 무리가 있을 것 같습니다. 아무튼 진공관 상에서 단순한 전선 연결 배치로 명령을 했던 언어가 1 세대 컴퓨터 언어 입니다. 참고로 위 그림 아래에 써있는 말이 무슨 말이냐면, 이와 같이 '컴퓨터 프로그래밍' 을 수행하였는데 어딘 가에서 오류가 났을 때 어떠한 진공관이 고장났다는 의미인데 (아니면 전선 배치를 잘못했거나), 이를 수정하기 위해서 19000 여개의 달하는 진공관들을 확인해야 했다고 하네요.

1950 년대 이후 컴퓨터 내장 메모리가 만들어지고, 실질적으로 '컴퓨터 프로그래밍' 을 할 수 있게 되자, 2 세대 컴퓨터 언어가 등장하였는데요, 가장 첫번째로 나온 것이 어셈블리어 (Assembly language) 입니다. 언어라고 하기에 보다는 컴퓨터에 직접 명령을 내리는 기계어 (0 과 1 로 이루어짐) 에 사람들이 보기 쉽게 문자열을 대응 시킨 것에 가까운 형태였습니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F2051944F4F4CBBEB1E6EF9)

위 그림은 `IBM PC` 어셈블리어로 쓰여진 것을 캡쳐한 것입니다. 어셈블리어는 말그대로 기계어와 1 : 1 대응 되어 있기 때문에, 할 수 있는 동작이 매우 단순합니다. 즉, 우리가 "`1 + 1` 을 계산해봐!" 라고 C 언어에서 쉽게 말하는 것을 어셈블리어에서는 "음, 1 을 어디에 저장하고, 또 1 을 어디에 저장하고, 이제 `CPU` 에 메모리 어디에서 1 을 불러오고, 또 `CPU` 에 메모리 어디에서 1 을 불러오고, 이들에 덧셈을 수행해!" 라고 말하는 것과 동일한 것입니다.

참으로 노가다가 아닐 수 없지요. 위  캡쳐한 사진도 사실 보면, 어떠한 값이 97 과 122 사이에 있다면 32 를 빼라는 의미 인데, 이를 일일히 지정하고 있는 것을 볼 수 있습니다. 여기까지의 컴퓨터 언어는 저급 언어 (Low level) 이라 부르며, 수준이 낮다는 것이 아니라, 조금더 기계어에 근접해 있다는 것을 의미합니다. 그리고, 이 때부터 초보적인 수준의 고급 언어(High level) 가 등장하게 되었는데, 은행과 같은 금융 쪽에서 많이 쓰였던 `COBOL` 이나, 수치 계산용으로 쓰이는 `FORTRAN` 이 등장하게 됩니다. 그리고 꽤나 쉬운 언어였던 `BASIC` 도 한 몫 하게 되지요.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F1553D8494F4CC0640CD2EA)

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F17758B4E4F4CC0A1277867)

위의 `FORTRAN` 코드를 살작 보면 알겠지만 어셈블리어를 통해서는 매우 복잡한 명령 (예를 들어서 화면에 출력한다던지) 을 단순하게 처리하고 있음을 알 수 있습니다. 이런 2 세대 초기의 언어들은 어셈블리어에 비해서는 획기적인 발전이 있을 수 있었습니다. 하지만 문제는 데이터 타입이나, 프로그램 문법 구조가 완전하지가 않아서 복잡한 데이터 타입을 단순히 모두 배열로 처리한다던지, 논리 구조를 모두 `goto` 문으로 처리한다던지의 문제가 있었습니다.

이렇게 하게 되면 오류가 발생하여도 찾기가 굉장히 힘든, 소위 말하는 스파게티 코드가 만들어지지요. 스파게티코드란, 스파게티 처럼 프로그램의 논리 구조가 뒤엉킨 상태를 의미합니다. 그래서 유명한 컴퓨터 과학자 다익스트라 (Dijkstra) 가 "Go to statement considered harmful" 이라는 유명한 글을 남기게 됩니다. 아무튼 이 때문에 조금 더 체계적인 프로그래밍 언어가 크게 필요로 해졌습니다.

그래서 짠하고 나타난 것이 3 세대 프로그래밍 언어, 절차 지향 언어 (Procedural programming language) 라고 불리는 파스칼(Pascal) 언어와 그 뒤를 이어서 C 언어가 등장하게 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F14209E394F4CC276266FCE)

위 그림은 파스칼 언어로, 우리가 지금 아는 C 언어와 상당히 유사합니다. 함수라는 개념이 완성되었고, (이전에도 있었지만 불완전한 면이 있었다), 변수의 타입 (위 그림의 `var` 부분을 보면 알 수 있지만 정수형, 문자열 등등) 이 정립되어서 기존의 배열을 남발하던 것에서 벗어날 수 있게 됩니다.

절차(?) 를 지향한다라는 말이 이해가 잘 안가실 텐데, 영어로 보면, `Procedure` 를 지향하는 언어, 즉 프로시져 (함수) 를 지향한다는 것입니다. 다시 말해 프로그램을 설계할 때 중요한 부분을 하나의 프로시져로 만들어서 쪼개어 처리한다는 것입니다. 물론 기존의 언어들에서도 프로시져라는 것은 존재하였지만, 함수의 인자와 같은 개념이 없었고, 비로소 이 때야 완전한 함수 라는 것이 만들어지게 되는 것입니다.

그렇게 해서 절차 지향 언어로 몇십년을 버텨왔습니다. 그러나, 프로그램의 크기가 예전보다 상상도 할 수 없을 만큼 거대해 지자 새로운 패러다임이 필요하게 되었는데요, 그것이 바로 **객체 지향 언어(Object oriented language)** 입니다. 이를 사용하는 언어는 C++ 을 비롯한 Java, Python, C# 등등 아마 90년대 이후에 생긴 언어들은 대부분 객체 지향 언어 일 것입니다.



###  객체란?

그럼, 절차 지향적 언어의 뭐가 부족해서 였는지 객체 지향 언어를 필요로 하게 된 것일까요? 먼저 지난 강좌의 `Animal` 구조체를 가져와서 살펴 봅시다. 우리는

```cpp-formatted
typedef struct Animal {
  char name[30];  // 이름
  int age;        // 나이

  int health;  // 체력
  int food;    // 배부른 정도
  int clean;   // 깨끗한 정도
} Animal;
```

위와 같이 `Animal` 구조체를 정의한 후, `animal` 변수를 만들어서 이를 필요로 하는 함수들에게

```cpp-formatted
play(list[play_with]);
```


이와 같이 전달해 주었습니다. 그런데, 곰곰히 생각해 보면 `Play` 함수에 인자로 전달하는 것이 매우 불필해보입니다. 이 상황을 그림을 생각하면, 마치 [러시아식 유머](http://uncyclopedia.kr/wiki/%EB%9F%AC%EC%8B%9C%EC%95%84%EC%8B%9D_%EC%9C%A0%EB%A8%B8) 처럼 "`Play` 가 `Animal` 을 합니다!" 라고 볼 수 있는데, 사실은 "`Animal` 이 `Play` 를 한다" 가 더 맞기 때문이지요.

다시 말해서 `Animal` 자체가 `Play` 를 하는 것이지, `Play` 가 `Animal` 을 해주는 것이 아닙니다. 만일 `Animal` 자체가 `Play` 를 한다 라는 개념을 생각하게 된다면, 다음과 같이 생각할 수 있을 것입니다.

```cpp-formatted
Animal animal;

// 여러가지 초기화 (생략)

animal.play();   // 즉 내가 (animal 이) Play 를 한다!
animal.sleep();  // 내가 sleep 을 한다!
```

이렇게 하면 `play` 함수에 `animal` 을 인자로 주지 않아도 됩니다. 왜냐하면 내가 `play` 하는 것이기 때문에 내 정보는 이미 `play` 함수가 다 알고 있기 때문입니다. `play` 함수는 나의 상태들, 예를 들어서 체력이나, 배고픔 정도나 피곤한 정도 등을 모두 알 수 있기 때문에 나에 대한 적절한 처리를 할 수 있게 되는 것입니다. 즉, `animal` 은 자신의 상태를 알려주는 변수(variable) 과, 자신이 하는 행동들 (play, sleep 등등) 을 수행하는 함수(method) 들로 이루어졌다고 볼 수 있습니다.

결과적으로 객체는 다음과 같이 정의됩니다.

객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리 이다.

이 때 객체가 현실 세계에서의 존재하는 것들을 나타내기 위해서는 **추상화(abstraction)** 라는 과정이 필요합니다. 컴퓨터 상에서 현실 세계를 100% 나타낼 수 없는 것이기 때문에, 적절하게 컴퓨터에서 처리할 수 있도록 바꾸는 것인데, 예를 들어서 핸드폰의 경우 '전화를 한다', '문자를 보낸다' 와 같은 것들은 '핸드폰이 하는 것' 이므로 함수로 추상화시킬 수 있고,핸드폰의 상태를 나타내는 것들, 예를 들어서 자기 자신의 전화 번호나 배터리 잔량 같은 것은변수로 추상화시킬 수 있습니다.

아래 그림은 흔히 객체를 나타내기 위한 그림 입니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F2012E33F4F4CCAF12C29D8)
http://journals.ecs.soton.ac.uk/java/tutorial/java/objects/object.html에서 인용하였습니다.

이와 같이 어떠한 객체는 자기 만의 정보를 나타내는 변수들과, 이를 가지고 어떠한 작업을 하는 함수들로 둘러싸고 있다고 보시면 됩니다. 참고로, 이러한 객체의 변수나 함수들을 보통 **인스턴스 변수(instance variable)** 와 **인스턴스 메소드(instance method)** 라고 부르게 되는데, 그냥 알고 계시는 변수와 함수와 동일한 것으로 생각하시면 됩니다. 누군가 인스턴스 메소드라고 하면 "아 그냥 객체에 정의되어 있는 함수구나" 라고 생각하시면 됩니다.

그림을 메소드가 변수들을 감싸고 있는 것 처럼 그리는 이유는 진짜로 변수들이 외부로 부터 '보호' 되고 있기 때문입니다. 다시 말해, 외부에서 어떠한 객체의 인스턴스 변수의 값을 바꾸지 못하고오직 객체의 인스턴스 함수를 통해서만 가능하다는 것이지요 (물론 항상 이렇게 극단적으로 불가능 한 것은 아니고 사실 사용자가 조절할 수 있습니다) 이를 단순히 코드로 표현한다면, 예컨대 `Animal` 의 `food` 를 바꾼다고 할 때

```cpp-formatted
Animal animal;
// 초기화 과정 생략

animal.food += 100;         // --> 불가능
animal.increase_food(100);  // --> 가능
```


이렇게 된다는 것입니다. 일단 `animal.food +=` 100; 자체는 외부에서 `animal` 이라는 '객체' 의 '인스턴스 변수' 에 '직접' 접근하는 것이기 때문에 불가능한 것이고, 아래의 `animal.increase_food(100);` 의 경우 `animal` 객체의 '인스턴스 함수' 를 통해서 값을 수정하는 것이기 때문에가능한 것이지요. 이와 같이 외부에서 직접 인스턴스 변수의 값을 바꿀 수 없고 항상 인스턴스 메소드를 통해서 간접적으로 조절하는 것을 **캡슐화(Encapsulation)** 라고 부릅니다.

이 개념을 처음 들었을 때 이게 왜 필요하냐고 생각하시는 분들이 많습니다. 저도 캡슐화를 굳이 해야될 이유를 못찼었거든요. 그냥, `animal.food += 100;` 하나 `animal.increase_food(100);` 하나 거기서 거기이지 라는 생각을 말이죠.

일단 여기서는 캡슐화의 장점에 대해서는 나중에 설명하겠지만 간단하게 말하자면, "객체가 내부적으로 어떻게 작동하는지 몰라도 사용할 줄 알게 된다" 라고 볼 수 있습니다. 예컨대 `animal.increase_food(100);` 을 하면 내부적으로 `food` 변수 값이 100 증가하는것 뿐만이 아니라 몸무게도 바뀔 수 있고, 행복도도 올라갈 수 있고 등등 여러가지 작업들이 일어나겠지요. 만일 `increase_food` 함수를 사용하지 않았다면

```cpp-formatted
animal.food += 100;
animal.weight += 10;
//... 여러가지 처리
```


여러가지 처리를 프로그래머가 직접 해주어야 합니다. 하지만 이것은 프로그래머가 `food` 를 100 늘리는 과정에서 정확히 어떠한 일들이 일어나는지 알아야지만 가능하다는 것입니다. 이는 상당히 피곤한 작업이겠지요. 더군다나, 대형 프로젝트에서는 객체들을 한 사람이 설계하는 것이 아니기 때문에 다른 사람이 작성한 것을 읽고 완벽히 이해해야만 합니다. 짜증나는 일이 겠지요. 하지만 인스턴스 메소드를 이용하면 "`food` 를 늘리려면 `increase_food` 를 이용하세요~ (나머지는 우리가 다 알아서 할께요)" 라는 것만 알아도 `increase_food(100)` 해버리면, 객체 내부적으로 알아서 처리되기 때문에 이를 사용하는 프로그래머가 굳이 이해하지 않아도 됩니다.

"내부적으로 어떻가 처리되는지는 알 필요가 없다!" 라는 말이 조금 못마땅 하다고 생각하시는 분들이 있을 것입니다. 사람이 그렇게 무책임 해서도 되나 말이죠. 하지만 곰곰히 생각해보면 우리가 접하는 모든 전자 기기들은 캡슐화 되어 있다고 볼 수 있습니다. 노트북의 경우도, 화면에 글자 'a' 를 띄우기 위해서 우리는 컴퓨터 내부에서 어떠한 연산이 처리되는지 알 필요 없습니다. 단순히 우리가 하는 일은 '키보드의 a 를 누른다' 라는, 마치 `my_computer.keyboard_hit('a');` 라는 메소드를 호출하는 것과 동일한 작업이지요. 만일 노트북이 캡슐화 되어 있지 않다면요? 그건 여러분의 상상에 맡기겠습니다.



###  클래스


자 그러면 객체는 C++ 상에서 어떻게 만들어낼까요. 이를 위해 C++ 에서 객체를 만들 수 있는 장치를 준비하였습니다. 쉽게 말하면 객체의 '설계도' 라고 볼 수 있지요. 바로 클래스(class) 입니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F16603A484F4D993B0DC2A3)

위와 같이 안의 내용은 차있지 않고 빈 껍질로만 생각할 수 있습니다. 그리고 우리는 이 객체의 설계도를 통해서 실제 객체를 만들게 되지요. C++ 에서 이와 같이 클래스를 이용해서 만들어진 객체를 인스턴스(instance) 라고 부릅니다. 앞서 객체의 변수와 메소드를 왜 인스턴스 변수와 인스턴스 메소드라고 했는지 아시겠죠?

```cpp-formatted
#include <iostream>

class Animal {
 private:
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}
```


성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F1324C5384F4D9B8B374245)


 와 같이 나오게 됩니다. 새로운 개념들이 왕창 많이 등장했으니 코드를 천천히 살펴봅시다.

```cpp-formatted
Animal animal;
```

먼저 `main` 함수에서 `Animal` 클래스의 인스턴스를 어떻게 생성하였는지 살펴 봅시다. 기존의 구조체에서 구조체 변수를 생성할 때와 동일한데, 구조체의 경우 앞에 `struct` 를 명시 했어야 했지만 여기서는 그러지 않아도 됩니다. 그냥 `int` 나 `char` 처럼 `Animal` 이라고 써주면 됩니다. 이와 같이 `Animal animal;` 을 했으면 `Animal` 클래스의 인스턴스 `animal` 을 만들게 된 것이지요. 이제 본격적으로 클래스가 어떻게 되어 있는지 살펴봅시다.

```cpp-formatted
class Animal {
 private:
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};
```


위는 `Animal` 이라는 클래스를 나타낸 것으로 `Animal` 클래스를 통해서 생성될 임의의 객체에 대한 설계도라고 볼 수 있습니다. 즉, `Animal` 클래스를 통해서 생성될 객체는 `food, weight` 라는 변수가 있고, `set_animal, increase_food, view_stat` 이라는 함수들이 있는데, `Animal` 클래스 상에서 이들을 지칭할 때 각각 **멤버 변수(member variable) 과 멤버 함수(member function)** 라고 부릅니다.

즉, 인스턴스로 생성된 객체에서는 인스턴스 변수, 인스턴스 함수, 그리고 그냥 클래스 상에서는 멤버 변수, 멤버 함수 라고 부르는 것입니다. 멤버 변수와 멤버 함수는 실재 하는 것이 아니지요. 인스턴스가 만들어져야 비로소 세상에 나타나는 것입니다. 즉, 설계도 상에 있다고 해서 아파트가 실제로 존재하는 것이 아닌 것 처럼 말이지요.

```cpp-formatted
private:
int food;
int weight;
```

먼저 멤버 변수들을 정의한 부분을 봅시다. 처음 보는 키워드가 있지요? 이러한 키워드를 '접근 지시자' 라고 하는데,외부에서 이러한 멤버들에 접근을 할 수 있냐 없냐를 지시해주는 것입니다. `private` 키워드의 경우, 아래에 쓰여진 것들은 모두 객체 내에서 보호되고 있다 라는 의미이지요. 즉, 앞서 객체 그림을 떠올리면 멤버 변수들이 안에서 보호 받고 있던 것 기억하시죠? `private` 되고 있는 모든 것들은 자기 객체 안에서만 접근할 수 있을 뿐 객체 외부에서는 접근할 수 없게 됩니다. 다시 말해

```cpp-formatted
void set_animal(int _food, int _weight) {
  food = _food;
  weight = _weight;
}
```


와 같이 같은 객체 안에서 `food` 와 `weight` 에 접근하는 것은 가능한 일이지만

```cpp-formatted
int main() {
  Animal animal;
  animal.food = 100;
}
```


처럼 객체 밖에서 인위적으로 `food` 에 접근하는 것은 불가능 하다는 것입니다. (실제로 컴파일 해보면 오류가 발생합니다) 반면에 `public` 키워드의 경우,

```cpp-formatted
public:
void set_animal(int _food, int _weight) {
  food = _food;
  weight = _weight;
}
void increase_food(int inc) {
  food += inc;
  weight += (inc / 3);
}
void view_stat() {
  std::cout << "이 동물의 food   : " << food << std::endl;
  std::cout << "이 동물의 weight : " << weight << std::endl;
}
```


이와 같이 멤버 함수들을 `public` 으로 지정하였습니다. `public` 이라는 것은 말 그대로 공개된 것으로 외부에서 마음껏 이용할 수 있게 됩니다. 그래서 `main` 함수에서도 이들을

```cpp-formatted
animal.set_animal(100, 50);
animal.increase_food(30);
animal.view_stat();
```


처럼 마음껏 접근할 수 있었습니다. 만일 멤버 함수들을 `private` 로 설정해버렸다면 어떨까요. `public` 키워드를 지워봅시다.

그냥 컴파일 해보면

```compiler-warning
'Animal::set_animal' : cannot access private member declared in class 'Animal'
```


위와 같은 오류가 3 개 정도 등장하게 됩니다. 다시 말해, `Animal` 의 `private` 멤버 함수에 접근할 수 없다는 의미겠지요. 결과적으로 외부에서 접근을 할 수 없는 객체는 그냥 아무짝에도 쓸모 없는 덩어리로 남게 됩니다.

참고로 키워드 명시를 하지 않았다면 기본적으로 `private` 로 설정됩니다. 즉, 맨 위의 `private` 키워드를 지워도 상관이 없다는 것이지요. 그냥 `private` 없이

```cpp-formatted
class Animal {
  int food;
  int weight;
  // ... 생략
```


이렇게 해도 `food` 와 `weight` 는 알아서 `private` 로 설정 됩니다.

만일 멤버 변수들도 `public` 으로 공개해버리면 어떨까요. 그러면 `main` 함수에서 마치 예전에 구조체를 사용했던 것 처럼

```cpp-formatted
animal.food = 100;
```


로 손쉽게 접근할 수 있게 됩니다. 이제 멤버 변수에 대해 조금 더 자세히 살펴 보도록 합시다.

```cpp-formatted
void set_animal(int _food, int _weight) {
  food = _food;
  weight = _weight;
}
```


위는 각 멤버 변수들의 값을 설정하는 부분인데요, 여기서 `food` 와 `weight` 는 누구의 것일까요? 당연하게도, 객체 자신의 것입니다. 그렇기 때문에 `food` 와 `weight` 가 누구 것인지 명시할 필요 없이 그냥 `food, weight` 라고 사용하면 됩니다. `set_animal` 을 호출한 객체의 `food` 와 `weight` 값이기 때문이지요. 마찬가지로 `increase_food` 를 살펴보면

```cpp-formatted
void increase_food(int inc) {
  food += inc;
  weight += (inc / 3);
}
```


이와 같이 얼마나 `food` 를 증가시킬 지 입력 받은 다음에 내부적으로 `food` 와 `weight` 를 모두 처리해주게 됩니다.

이번 강좌는 여기서 마치도록 하겠습니다. 한 가지 꼭 기억하실 점은, 객체가 무엇인지, 그리고 클래스가 무엇인지 꼭 명심해 두시기 바랍니다. 또 앞으로 계속 나올 인스턴스, 인스턴스 변수, 인스턴스 함수, 멤버 변수, 멤버 함수 와 같은 용어들을 잘 파악하고 있어야지 뒤에가서 헷갈리지 않겠죠.

### 생각 해볼 문제

#### 문제 1

여러분은 아래와 같은 `Date` 클래스를 디자인 하려고 합니다. `set_date` 는 말그대로 `Date` 함수 내부를 초기화 하는 것이고 `add_day, add_month, add_year` 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)

```cpp-formatted
class Date {
  int year;
  int month;
  int day;

 public:
  void set_date(int _year, int _month, int _day) {}
  void add_day(int inc) {}
  void add_month(int inc) {}
  void add_year(int inc) {}
  void get_date() {}
};
```

##@ chewing-cpp-end
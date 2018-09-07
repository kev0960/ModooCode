----------------
title : 씹어먹는 C++ - <4 - 4. 스타크래프트를 만들자 ② (const, static)>
--------------




이번 강좌에서는* 생성자 초기화 리스트(initializer `list)`
* 클래스의 `const, static` 변수
* 레퍼런스 타입을 리턴하는 함수
* `this` 포인터
* `const` 멤버 함수



등에 대해 배웁니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F023FAA3651A1D1AA06E952)




안녕하세요 여러분. 무려 5 개월 만의 컴백 입니다! 최근 들어서 그동안 바뻣던 일이 잘 풀려서 여러 강좌들을 폭풍 업로드 하려 합니다`.` 아무쪼록 2013년 안으로 저의 씹어먹는 C++ 강좌가 완결될 수 있도록 노력하겠습니다 :) 그 동안 기다려 주셔서 정말로 감사합니다~ . 아무쪼록 2013년 안으로 저의 씹어먹는 C++ 강좌가 완결될 수 있도록 노력하겠습니다 :) 그 동안 기다려 주셔서 정말로 감사합니다~~


이번 강좌에서는 지난 강좌에서 만들었던 `Marine` 클래스를 변형하는것 부터 시작하도록 하겠습니다.




###  생성자의 초기화 리스트(initializer `list)`




```cpp

#include <iostream>
using namespace std;

class Marine
{
int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
int damage; // 공격력
bool is_dead;

public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성

int attack(); // 데미지를 리턴한다.
void be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치

void show_status(); // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
damage(5), is_dead(false) {}

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return damage;
}
void Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
}

int main()
{
Marine marine1 (2, 3);
Marine marine2 (3, 5);

marine1.show_status();
marine2.show_status();
}
```

성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1277033A50EFAD3713AECF)

와 같이 됩니다.
예전에 만들었던 `Marine` 클래스와 달라진 것은 딱 하나인데, 바로 생성자에서 무언가 특이한 것을 도입했다는 것입니다. 한 번 살펴보도록 할까요.

```cpp

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
damage(5), is_dead(false) {}
```


놀랍게도 함수 본체에는 아무것도 없습니다. 오직, 위에 추가된 이상한 것들이 기존의 생성자가 했던 일과 동일한 작업을 하고 있을 뿐입니다. 기존의 생성자는
```cpp

Marine::Marine()
{
hp = 50;
coord_x = coord_y = 0;
damage = 5;
is_dead = false;
}
```



게 생겼는데, 그 내부에서 하던 멤버 변수들의 초기화 작업들을 새롭게 추가한 것들이 대신해서 하고 있을 뿐입니다.


위와 같이 생성자 이름 뒤에


```cpp

: hp(50), coord_x(0), coord_y(0),
damage(5), is_dead(false) {}
```



로 오는 것을 초기화 리스트 (initializer list) 라고 부르며, 생성자 호출과 동시에 멤버 변수들을 초기화해주게 됩니다.


```cpp

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
damage(5), is_dead(false) {}
```



위에서 `coord_x` 는 `x` 로 초기화 되고, `is_dead` 는 `false` 로 초기화 되게 됩니다.


멤버 초기화 리스트의 일반적인 꼴은 아래와 같습니다.

```cpp

(생성자 이름) : var1 ( arg1 ), var2 ( arg2) { }
```



여기서 `var` 들은 클래스의 멤버 변수들을 지칭하고, `arg` 는 그 멤버 변수들을 무엇으로 초기화 할 지 지칭하는 역할을 합니다. 한 가지 흥미로운 점은 `var1` 과 `arg1` 의 이름이 같아도 되는데, 실제로 아래의 예제는


```cpp

Marine::Marine(int coord_x, int coord_y) : coord_x(coord_x), coord_y(coord_y), hp(50),
damage(5), is_dead(false) {}
```






정상적으로 작동합니다. 왜냐하면 `coord_x ( coord_x )` 에서 바깥쪽의 `coord_x` 는무조건`` 멤버 변수를 지칭하게 되는데, 이 경우 coord_x 를 지칭하는 것이고, 괄호 안의 `coord_x` 는 원칙상 `Marine` 이 인자로 받은 `coord_x` 를 우선적으로 지칭하는 것이기 때문입니다. 따라서 실제로, 인자로 받은 `coord_x` 가 클래스의 멤버 변수 `coord_x` 를 초기화 하게 됩니다. 아래는 당연한 얘기 겠지만



```cpp

Marine::Marine(int coord_x, int coord_y)
{
coord_x = coord_x;
coord_y = coord_y;
hp = 50;
damage = 5;
is_dead = false;
}
```



컴파일러가 두 `coord_x` 모두 인자로 받은 `coord_x` 로 구분해서 오류가 나겠지요.


그렇다면, 왜 도대체 초기화 리스트를 사용해야 되냐고 물을 수 있습니다. 왜냐하면


```cpp

Marine::Marine()
{
hp = 50;
coord_x = coord_y = 0;
damage = 5;
is_dead = false;
}
```



나


```cpp

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
damage(5), is_dead(false) {}
```



는 하는 일이 똑같아 보이기 때문이죠. 하지만 실제로 약간의 차이가 있습니다. 왜냐하면, 초기화 리스트를 사용한 버전의 경우 '생성과 초기화를 동시에' 하게 됩니다. 반면에 초기화 리스트를 사용하지 않는다면 '생성을 먼저 하고 그 다음에 대입' 을 수행하게 됩니다. 쉽게 말하면 초기화 리스트를 사용하는 것은

```cpp

int a = 10;
```



이라 하는 것과 같고, 그냥 예전 버전의 생성자를 사용하는 것은

```cpp

int a;
a = 10;
```



이라 하는 것과 동일하다는 것입니다. 만약에 `int` 가 대신에 클래스 였다면, 전자의 경우 '복사 생성자' 가 호출되는데, 후자의 경우 '디폴트 생성자' 가 호출된 뒤 대입이 수행된다는 이야기 이겠지요. 딱 보아도 후자가 조금 더 하는 작업이 많게 됩니다. 따라서 초기화 리스트를 사용하는 것이조금 더 효율적인 작업이라는 사실을 알 수 있지요. 그 뿐만 아니라, 우리 경험상 반드시 '생성과 동시에 초기화 되어야 하는 것들' 이 몇 가지 있었습니다. 대표적으로`` 레퍼런스와 상수가  있지요.


앞서 배운 바에 따르면 상수와 레퍼런스들은 모두 생성과 동시에 초기화가 되어야 합니다.

```warning

const int a;
a = 3;

int& ref; // 이것이 왜 안되는지 기억이 안난다면
ref = c; // [http://itguru.tistory.com/141](http://itguru.tistory.com/141) 를 참조
```



모두 컴파일 오류가 나겠지요. 따라서 만약에 클래스 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 초기화 리스트를 사용해서 초기화 시켜주어야만 합니다.


```cpp

#include <iostream>
using namespace std;

class Marine
{
int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;

const int default_damage; // 기본 공격력

public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성

int attack(); // 데미지를 리턴한다.
void be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치

void show_status(); // 상태를 보여준다.
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
default_damage(5), is_dead(false) {}

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return default_damage;
}
void Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
}

int main()
{
Marine marine1 (2, 3);
Marine marine2 (3, 5);

marine1.show_status();
marine2.show_status();

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F122A983A50EFB93B1314D5)



이 됩니다.


위 마린 클래스는 프로그래머들의 실수로 마린의 공격력이 이상하게 변하는 것을 막기 위해서 기본 공격력이라는 상수 멤버를 도입해서, 딱 고정 시켜 버리고 마음 편하게 프로그래밍 할 수 있도록 하였습니다. 따라서 이를 위해 생성자에서 초기화 리스트를 도입해서


```cpp

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) {}
```



와 같이, `default_damage` 를 생성과 동시에 초기화 할 수 있도록 하였습니다. 따라서 우리는 상수인 `default_damage` 를 5 로 초기화 할 수 있고, 이 값은 영원히 바뀌지 않게 됩니다.


```cpp

Marine marine1 (2, 3);
Marine marine2 (3, 5);

marine1.show_status();
marine2.show_status();
```



위와 같이 `Marine` 의 객체들 (marine1, marine2) 를 생성하면서 생성자 오버로딩에 따라 `Marine(int x, int y)` 가 호출되는데, 이를 통해 각각 (2,3) 과 (3,5) 에 위치해 있는 마린 객체들을 만들 수 있게 되었습니다. 그리고, `show_status` 를 호출해 보면 이들이 제대로 정의 되어 있다는 사실을 알 수 있습니다.


```cpp

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());
```



마찬가지로 `Marine` 객체들이 서로 공격하는 과정도 잘 실행되고 있음을 알 수 있습니다.


위와 같이 중요한 값들을 상수로 처리하는 것은 매우 유용한 일입니다. 다른 프로그래머가 이 클래스를 사용하면서 실수로 `marine` 의 `default_damage` 를 변경하는 명령을 집어 넣더라고 컴파일 오류가 발생하기 때문에 프로그램을 실행해서 지루한 디버깅 과정을 거쳐서 알아 내는 것 보다 훨씬 효율적으로 오류를 발견할 수 있겠지요.


```cpp

#include <iostream>
using namespace std;

class Marine
{
int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;

const int default_damage; // 기본 공격력

public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성
Marine(int x, int y, int default_damage);

int attack(); // 데미지를 리턴한다.
void be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치

void show_status(); // 상태를 보여준다.
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return default_damage;
}
void Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
}

int main()
{
Marine marine1 (2, 3, 10);
Marine marine2 (3, 5, 10);

marine1.show_status();
marine2.show_status();

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F22711E4451A0F8170A9E8A)



이 예제에서는 생성자 하나를 새로 더 추가하였는데 한 번 살펴보도록 합시다.


```cpp

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) {}
```



이전에는 `default_damage` 에 초기화 리스트로 5 를 전달하였는데, 이 생성자의 경우 어떤 값을 전달할 지 인자로 받은 다음에 그 내용을 상수에 넣어주었습니다. 마찬가지로 이는

```cpp

const int default_damage = (인자로 받은 default_damage);
```



를 실행한 것과 마찬가지 이기 때문에 잘 작동됨을 알 수 있습니다. 그리고, 실제로 5 가 아닌 10 의 `HP` 가 깎였음을 `show_status` 를 통해 확인 할 수 있습니다.





###  생성된 총 `Marine` 수 세기 (static 변수)





자, 이번에는 여태까지 만들어지는 총 `Marine` 의 수를 알아내기 위해 코드를 짠다고 생각해봅시다. 이를 위해서는 많은 방법이 있겠지만 가장 단순한 두 방식을 생각해본다면


`1.` 어떠한 배열에 `Marine` 을 보관해 놓고, 생성된 마린의 개수를 모두 센다.
`2.` 어떤 변수를 만들어서 `Marine` 의 생성시에 1 을 추가하고, 소멸시에 1 을 뺀다.


을 생각할 수 있을 것입니다. 첫 번째 방법의 경우, (물론 vector 라는 `STL` 자료형을 이용하면 쉽게 할 수 있겠지만 나중에 이야기 하도록 합시다.`)`  따로 크기가 자유자재로 변할 수 있는 배열을 따로 만들어야 하는 문제점이 있고, 두번째의 같은 경우 만일 어떠한 함수 내에서 이런 변수를 정의하였다면 다른 함수에서도 그 값을 이용하기 위해 인자로 계속 전달해야 하는 귀찮음이 있습니다. 물론 전역 변수로 만들면 되지 않겠냐고 물을 수 도 있겠지만, 전역 변수의 경우 프로젝트의 크기가 커질 수 록 프로그래머의 실수로 인해 서로 겹쳐서 오류가 날 가능성이 다분하기에 반드시 필요한 경우가 아니면 사용을 하지 않습니다. (실제로 꼭 필요한 경우가 아니면 전역변수는 사용하지 맙시다`)`


하지만 C++ 에서는 위와 같은 문제를 간단하게 해결 할 수 있는 기능을 제공하고 있습니다. 마치 전역 변수 같지만 클래스 하나에만 종속되는 변수인 것인데요, 바로`static` 멤버 변수`` 입니다. 예전에 C 언어에서 어떠한 함수의 `static` 변수( [http://itguru.tistory.com/83](http://itguru.tistory.com/83) 참조) 가 지역 변수들 처럼 함수가 종료될 때 소멸되는 것이 아니라 프로그램이 종료될 때 소멸되는 것 처럼, 어떤 클래스의 `static` 멤버 변수의 경우, 멤버 변수들 처럼, 객체가 소멸될 때 소멸되는 것이 아닌, 프로그램이 종료될 때 소멸되는 것입니다.


또한, 이 `static` 멤버 변수의 경우, 클래스의 모든 객체들이 '공유' 하는 변수로써 각 객체 별로 따로 존재하는 멤버 변수들과는 달리 모든 객체들이 '하나의' `static` 멤버 변수를 사용하게 됩니다. 그럼 바로 아래의 예제를 살펴 보도록 합시다.

```cpp

// static 멤버 변수의 사용

#include <iostream>
using namespace std;

class Marine
{
static int total_marine_num;

int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;

const int default_damage; // 기본 공격력

public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성
Marine(int x, int y, int default_damage);

int attack(); // 데미지를 리턴한다.
void be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치

void show_status(); // 상태를 보여준다.

~Marine() { total_marine_num --;}
};
int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) { total_marine_num ++;}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
default_damage(5), is_dead(false) { total_marine_num ++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) { total_marine_num ++; }

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return default_damage;
}
void Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine()
{
Marine marine3(10, 10, 4);
marine3.show_status();
}
int main()
{
Marine marine1 (2, 3, 5);
marine1.show_status();

Marine marine2 (3, 5, 10);
marine2.show_status();

create_marine();

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F23493B3451A0FC9111D803)

와 같이 나오게 됩니다.
```cpp

static int total_marine_num;
```



먼저 위와 같이 클래스 `static` 변수를 정의하였습니다. 모든 전역 및 `static` 변수들은 정의와 동시에 값이 자동으로 0  으로 초기화 되기 때문에 이 경우 우리가 굳이 따로 초기화 하지 않아도 되지만 클래스 `static` 변수들의 경우 아래와 같은 방법으로 초기화 합니다.

```cpp

int Marine::total_marine_num = 0;
```



간혹 어떤 사람들의 경우 클래스 내부에서


```cpp

class Marine
{
static int total_marine_num = 0;
```



와 같이 초기화 해도 되지 않냐고 묻는 경우가 있는데, 멤버 변수들을 위와 같이 초기화 시키지 못하는 것처럼 `static` 변수 역시 클래스 내부에서 위와 같이 초기화 하는 것은 불가능 합니다. 위와 같은 꼴이 되는유일한 경우는 `const static` 변수`` 일 때만 가능한데, 실제로


```cpp

class Marine
{
const static int x = 0;
```



으로 쓸 수 있습니다.


그럼 실제로 `total_marine_sum` 이 잘 작동하고 있는지 살펴보도록 합시다. 클래스의 편한 점이 생성자와 소멸자를 제공한다는 점인데, 덕분에 `Marine` 이 생성될 때, 그리고 소멸될 때 굳이 따로 처리하지 않고도, 생성자와 소멸자 안에 `total_marine_num` 을 조작하는 문장을 넣어주면 편하게 처리할 수 있습니다. 그 결과


```cpp

Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) { total_marine_num ++;}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
default_damage(5), is_dead(false) { total_marine_num ++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) { total_marine_num ++; }
```



로 각 생성자 호출 시에 `total_marine_num` 을 1 씩 증가시키는 문장을 넣었고,

```cpp

~Marine() { total_marine_num --;}
```



소멸 될때는 1 감소시키는 문장을 넣었습니다.


```cpp

Marine marine1 (2, 3, 5);
marine1.show_status();

Marine marine2 (3, 5, 10);
marine2.show_status();
```



따라서 위를 실행하면 실제로 총 `Marine` 의 수가 `1, 2` 늘어나는 것을 확인할 수 있고, 그 다음에 `create_marine` 을 실행하였을 때


```cpp

void create_marine()
{
Marine marine3(10, 10, 4);
marine3.show_status();
}

```

역시 `marine3` 을 생성함으로써 총 `marine` 의 수가 3 이 됨을 확인할 수 있는데, `marine3` 은 `create_marine` 의 지역 객체이기 때문에 `create_marine` 이 종료될 때 소멸되게 됩니다. 따라서 다시 `main` 함수로 돌아와서


```cpp

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();
```



에서 총 마린수를 표시할 때 2 명으로 나오게 됩니다.


그런데 클래스 안에 `static` 변수 만 만들 수 있는 것이 아닙니다. 놀랍게도 클래스 안에는 `static` 함수도 정의할 수 있는데, `static` 변수가 어떠한 객체에 종속되는 것이 아니라, 그냥 클래스 자체에 딱 1 개 존재하는 것인 것 처럼, `static` 함수 역시 어떤 특정 객체에 종속되는 것이 아니라 클래스 전체에 딱 1 개 존재하는 함수입니다.


즉, `static` 이 아닌 멤버 함수들의 경우 객체를 만들어야지만 각 멤버 함수들을 호출할 수 있지만 `static` 함수의 경우, 객체가 없어도 그냥 클래스 자체에서 호출할 수 있게 됩니다. 그럼, 아래 예제를 살펴볼까요.

```cpp

// static 함수

#include <iostream>
using namespace std;

class Marine
{
static int total_marine_num;
const static int i = 0;

int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;

const int default_damage; // 기본 공격력

public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성
Marine(int x, int y, int default_damage);

int attack(); // 데미지를 리턴한다.
void be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치

void show_status(); // 상태를 보여준다.
static void show_total_marine();
~Marine() { total_marine_num --;}
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
cout << "전체 마린 수 : " << total_marine_num << endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) { total_marine_num ++;}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
default_damage(5), is_dead(false) { total_marine_num ++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) { total_marine_num ++; }

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return default_damage;
}
void Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine()
{
Marine marine3(10, 10, 4);
Marine::show_total_marine();
}
int main()
{
Marine marine1 (2, 3, 5);
Marine::show_total_marine();

Marine marine2 (3, 5, 10);
Marine::show_total_marine();

create_marine();

cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
marine2.be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F0225E15051A162F122F9E0)



와 같이 나옵니다.


`static` 함수는 앞에서 이야기 한 것과 같이, 어떤 객체에 종속되는 것이 아니라 클래스에 종속되는 것으로, 따라서 이를 호출하는 방법도 (객체).(멤버 함수) 가 아니라,

```cpp

Marine::show_total_marine();
```



와 같이 (클래스)::(static 함수) 형식으로 호출하게 됩니다. 왜냐하면 어떠한 객체도 이 함수를 소유하고 있지 않기 때문이죠. 그러하기에, `static` 함수 내에서는 클래스의 `static` 변수 만을 이용할 수 밖에 없습니다. 만일 `static` 함수 내에서 아래처럼 그냥 클래스의 멤버 변수들을 이용한다면


```cpp

void Marine::show_total_marine()
{
cout << default_damage << endl; // default_damage 는 멤버 변수
cout << "전체 마린 수 : " << total_marine_num << endl;
}
```



`default_damage` 가 누구의 `default_damage` 인지 아무도 모르는 상황이 발생합니다. 즉, 어떤 객체의 `default_damage` 인지 `static` 변수인 `show_total_marine()` 은 알 수 없겟죠. 왜냐하면 앞에서 계속 말해왔듯이 어떤 객체에도 속해이지 않기 때문이니까요!



###  this




```cpp

// 자기 자신을 가리키는 포인터 this


#include <iostream>
using namespace std;


class Marine
{
static int total_marine_num;
const static int i = 0;


int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;


const int default_damage; // 기본 공격력


public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성
Marine(int x, int y, int default_damage);


int attack(); // 데미지를 리턴한다.
Marine& be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치


void show_status(); // 상태를 보여준다.
static void show_total_marine();
~Marine() { total_marine_num --;}
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
cout << "전체 마린 수 : " << total_marine_num << endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) { total_marine_num ++;}


Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),

default_damage(5), is_dead(false) { total_marine_num ++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) { total_marine_num ++; }

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack()
{
return default_damage;
}
Marine& Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;

return *this;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

int main()
{
Marine marine1 (2, 3, 5);
marine1.show_status();

Marine marine2 (3, 5, 10);
marine2.show_status();

cout << endl << "마린 1 이 마린 2 를 두 번 공격! " << endl;
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```




성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F257CA24D51A1684431CF90)





와 같이 나옵니다.


일단 가장 먼저 눈에 띄는 것은 바로 레퍼런스를 리턴하는 함수와 `this` 라는 것인데, 차근 차근 살펴 보도록 하겠습니다.


```cpp

Marine& Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;


return *this;
}
```



일단 `this` 라는 것이 C++ 언어 차원에서 정의되어 있는 키워드 인데, 이는 객체 자신을 가리키는 포인터의 역할을 합니다. 즉, 이 멤버 함수를 호출하는 객체 자신을 가리킨다는 것이지요. 따라서, 실제로 위 내용은


```cpp

Marine& Marine::be_attacked(int damage_earn)
{
this->hp -= damage_earn;
if(this->hp <= 0)
this->is_dead = true;


return *this;
}
```



과 동일한 의미가 됩니다. (구조체 포인터 변수에서 `->` 를 이용해서 구조체 원소들에 접근했던 것을 상기해보세요) 실제로 모든 멤버 함수 내에서는 `this` 키워드가 정의되어 있으며 클래스 안에서 정의된 함수 중에서 `this` 키워드가 없는 함수는 (당연하게도) `static` 함수 뿐입니다.


그러면 이제 `Marine&` 을 리턴한다는 말이 도대체 무엇인지 생각해봅시다. 이전 강좌에서 배운 바에 따르면 레퍼런스라는 것이 어떤 변수의 다른 별명이라고 했습니다. (실제로 레퍼런스를 '별명(alias)' 라고 부르기도 합니다) 그런데, 그 별명을 리턴한다니, 무슨 말일까요? '레퍼런스를 리턴하는 함수' 에 대해 알아보기 위해 아래와 같은 짤막한 예제 클래스를 살펴보도록 합시다.






###  레퍼런스를 리턴하는 함수




```cpp

// 레퍼런스를 리턴하는 함수
#include <iostream>
using namespace std;

class A
{
int x;

public:
A(int c) : x(c) {}

int& access_x() { return x; }
int get_x() { return x;}
void show_x() { cout << x << endl;}
};

int main()
{
A a(5);
a.show_x();

int& c = a.access_x();
c = 4;
a.show_x();

int d = a.access_x();
d = 3;
a.show_x();

// 아래는 오류
// int& e = a.get_x();
// e = 2;
// a.show_x();

int f = a.get_x();
f = 1;
a.show_x();
}
```


성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F011F503951A175F824DDF6)

와 같이 나옵니다.
일단 위 클래스 `A` 는 아래와 같이 `int` 와 `int` 의 레퍼런스를 리턴하는 두 개의 함수를 가지고 있습니다.


```cpp

int& access_x() { return x; }
int get_x() { return x;}
```



`access_x` 는 `x` 의 레퍼런스를 리턴하게 되고, `get_x` 는 `x` 의 '값' 을 리턴하게 되지요. 실제로 이들이 어떻게 작동하는지 살펴보도록 하겠습니다.


```cpp

int& c = a.access_x();
c = 4;
a.show_x();
```



여기서 레퍼런스 `c` 는 x 의 레퍼런스, 즉 'x 의 별명'을 받았습니다. 따라서, `c` 는 `x` 의 별명으로 탄생하게 되는 것이지요.레퍼런스를 리턴하는 함수는 그 함수 부분을 원래의 변수로 치환했다고 생각해도 상관이 없습니다. 다시 말해서

```cpp

int &c = x; // 여기서 x 는 a 의 x
```



와 동일한 말이라는 것입니다. 따라서 `c` 의 값을 바꾸는 것은 `a` 의 `x` 의 값을 바꾸는 것과 동일한 의미이므로 (c 는 단순히 x 에 다른 이름을 붙여준 것일뿐!) `show_x` 를 실행 시에 `x` 의 값이 5 에서 4 로 바뀌었음을 알 수 있습니다. 그렇다면 아래 예도 살펴볼까요.


```cpp

int d = a.access_x();
d = 3;
a.show_x();
```



이번에는 `int&` 가 아닌 그냥 `int` 변수에 'x 의 별명' 을 전달하였습니다. 만일 `d` 가 `int&` 였다면 `x` 의 별명을 받아서 `d` 역시 또 다른 `x` 의 별명이 되었겠지만, `d` 가 그냥 `int` 변수 이므로, 값의 복사가 일어나 d 에는 `x` 의 값이 들어가게 됩니다. 그리고 당연히, `d` 는 `x` 의 별명이 아닌 또 다른 독립적인 변수 이기에, `d =` 3; 을 해도 `x` 의 값은 바뀌지 않은 채, 그냥 4 가 출력되게 되죠.

```warning

// 아래는 오류
// int& e = a.get_x();
// e = 2;
// a.show_x();
```



그럼 주석 처리된 위 예를 살펴봅시다. 주석을 풀면 컴파일이 안되므로 주석 처리 해 놓은 것인데, 실제로 주석을 풀고 컴파일을 해보면

```warning

error C2440: 'initializing' : cannot convert from 'int' to 'int &' (int 를 int& 로 바꿀 수 없습니다)
```



아래와 같은 오류가 발생합니다. 그 이유는 레퍼런스가 아닌 타입을 리턴하는 경우는 '값' 의 복사가 이루어지기 때문에 임시 객체가 생성되는데, 임시객체의 레퍼런스를 가질 수 없기 때문입니다. (임시객체는 문장이 끝나게 되면 소멸됩니다) 이 과정을 그림으로 그려보면 아래와 같습니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F272F193851A18E5A29B569)

`get_x` 의 리턴으로 인해 임시로 '복사생성' 된 `int` 는 `a.get_x()` 부분을 대체하며 위 그림의 경우
```cpp

int &e = x'
```



과 같이 되는데, x' 은 문장이 끝날 때 자동으로 소멸되는 임시 객체 이기 때문에 레퍼런스를 만들 수 없습니다. 설사 레퍼런스를 만들었다고 해도 '이미 존재하지 않는 것에 대한 별명' 이 되므로 이 레퍼런스에 접근하는 것은 오류이겠지요. 아무튼 이러한 이유로 `int` 를 리턴하는 `a.get_x` 에 대해서는 레퍼런스를 만들 수 없습니다. (정확한 설명을 하자면 `int&` 는 좌측값에 대한 레퍼런스 이고, `a.get_x()` 는 우측값 이기 때문에 레퍼런스를 만들 수 없습니다. 좌측값, 우측값 내용은 나중에 더 자세히 다루겠지만 [궁금하신 분들은 이 글을 읽어보세요](http://itguru.tistory.com/189)`!)`


```cpp

int f = a.get_x();
f = 1;
a.show_x();
```



마지막으로 위 코드는 익히 보왔던 것 처럼, 임시로 생성된 `int` 변수 (위 그림에서는 x' `)` 이 `f` 에 복사되는데, 역시 `f = 1` 한 것이 실제 객체 `a` 의 `x` 에게는 아무런 영향을 끼칠 수 없겠지요. 한 가지 재미있는 점은

```cpp

a.access_x() = 3;
```



위 문장이 잘 작동한다는 점인데, 앞에서도 말했지만 '레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 됀다' 라는 말이 명확히 들어맞는 다는 점입니다. 즉, 위 문장은 결국

```cpp

a.x = 3;
```



과 동일한 말이 됩니다. 그 에 반면, 잘 알고 있듯이

```cpp

a.get_x() = 3;
```



은 역시 오류가 나게 되는데, 왜냐하면  a.get_x() 는 `get_x()` 가 리턴하면서 생성되는 임시 객체 (x') 으로 치환되며 임시객체에 대입을 하게 되는 모순적인 상황이 발생하게 됩니다.


그럼 이제 다시 예전의 `Marine` 예제로 돌아가보도록 합시다.


```cpp

Marine& Marine::be_attacked(int damage_earn)
{
this->hp -= damage_earn;
if(this->hp <= 0)
this->is_dead = true;


return *this;
}
```



위 경우 `be_attacked` 함수는 `Marine&` 타입을 리턴하게 되는데, 위 경우, `*this` 를 리턴하게 됩니다. 앞에서도 말했지만 `this` 가 지금 이 함수를 호출한 객체를 가리키는 것은 기억 하시죠? 그렇기 때문에 `*this` 는 그 객체 자신을 의미하게 됩니다. 따라서,

```cpp

marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
```



문장의 경우, 먼저 `marine2.be_attacked(marine1.attack())` 이 먼저 실행되고 리턴되는 것이 다시 `marine2` 이므로 그 다음에 또 한 번`marine2.be_attacked(marine1.attack`()) 가 실행된다고 생각할 수 있습니다. 간단하죠? 만일, `be_attacked` 함수의 리턴 타입이 `Marine&` 이 아니라 그냥 `Marine` 이라고 해봅시다. 즉, 만일 `be_attacked` 함수가 아래와 같이 바뀌었다고 가정한다면


```cpp

MarineMarine::be_attacked(int damage_earn)
{
this->hp -= damage_earn;
if(this->hp <= 0)
this->is_dead = true;


return *this;
}
```



위로 바뀐 함수를 가지고

```cpp

marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
```



를 실행해보면 `marine2` 는 실제로 두 번 공격이 아닌 1 번 공격으로 감소한 `HP` 만을 보입니다. (즉 40 이 아닌 45 로 나옴) 이는 앞에서도 설명했듯이 리턴타입이 `Marine` 이므로, 임시 객체 `Marine` 을 생성해서, `*this` 의 내용으로 복사가 되고 (즉, `Marine` 의 복사 생성자 호출) 이 임시 객체에 대한 `be_attacked` 함수가 호출되게 되는 것입니다. 따라서 결국 두 번째 `be_attacked` 는 `marine2` 가 아닌 엉뚱한 임시 객체에 대해 호출되는 것이므로 결국 `marine2` 는 `marine1` 의 공격을 1 번만 받게 됩니다.





###  const 함수




`C++` 에서는 변수들의 값을 바꾸지 않고 읽기 만 하는, 마치 상수 같 C++ 에서는 변수들의 값을 바꾸지 않고 읽기 만 하는, 마치 상수 같은멤버 함수를 '상수 함수' 로써 선언할 수 있습니다. 아래의 예제를 살펴봅시다.
```cpp

// 상수 멤버 함수

// 자기 자신을 가리키는 포인터 this
#include <iostream>
using namespace std;


class Marine
{
static int total_marine_num;
const static int i = 0;


int hp; // 마린 체력
int coord_x, coord_y; // 마린 위치
bool is_dead;


const int default_damage; // 기본 공격력


public:
Marine(); // 기본 생성자
Marine(int x, int y); // x, y 좌표에 마린 생성
Marine(int x, int y, int default_damage);


int attack() const ; // 데미지를 리턴한다.
Marine& be_attacked(int damage_earn); // 입는 데미지
void move(int x, int y); // 새로운 위치


void show_status(); // 상태를 보여준다.
static void show_total_marine();
~Marine() { total_marine_num --;}
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
cout << "전체 마린 수 : " << total_marine_num << endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
default_damage(5), is_dead(false) { total_marine_num ++;}


Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),

default_damage(5), is_dead(false) { total_marine_num ++; }

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50),
default_damage(default_damage), is_dead(false) { total_marine_num ++; }

void Marine::move(int x, int y)
{
coord_x = x;
coord_y = y;
}
int Marine::attack() const
{
return default_damage;
}
Marine& Marine::be_attacked(int damage_earn)
{
hp -= damage_earn;
if(hp <= 0)
is_dead = true;

return *this;
}
void Marine::show_status()
{
cout << " *** Marine *** " << endl;
cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
cout << " HP : " << hp << endl;
cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

int main()
{
Marine marine1 (2, 3, 5);
marine1.show_status();

Marine marine2 (3, 5, 10);
marine2.show_status();

cout << endl << "마린 1 이 마린 2 를 두 번 공격! " << endl;
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

marine1.show_status();
marine2.show_status();
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F257CA24D51A1684431CF90)



와 같이 나옵니다. 사실 위 소스는 거의 바뀐 것은 없고, 단순히 예시를 위해 아래와 같이 `attack` 함수를 살짝 바꾸었습니다.

```cpp

int attack() const ; // 데미지를 리턴한다.
```



일단 상수 함수는 위와 같은 형태로 선언을 하게 됩니다. 즉,

```cpp

(기존의 함수의 정의) const;
```



그리고 함수의 정의 역시 `const` 키워드를 꼭 넣어주어야 하는데, 아래와 같이 말이지요.


```cpp

int Marine::attack() const
{
return default_damage;
}
```



그렇게 하였으면 위 `attack` 함수는 '상수 멤버 함수' 로 정의된 것입니다. 우리는 상수 함수로 이 함수를 정의함으로써, 이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 다른 프로그래머에게 명시 시킬 수 있습니다. 당연하게도, 상수 함수 내에서는 객체들의 '읽기' 만이 수행되며, 상수 함수 내에서 호출 할 수 있는 함수로는 다른 상수 함수 밖에 없습니다.


사실 많은 경우 클래스를 설계할 때, 멤버 변수들은 모두 `private` 에 넣고, 이 변수들의 값에 접근하는 방법으로 `get_x` 함수 처럼 함수를 `public` 에 넣어 이 함수를 이용해값을 리턴받는 형식을 많이 사용합니다. 이렇게 하면 멤버 변수들을 `private` 에 넣음으로써 함부로 변수에 접근하는 것을 막고, 또 그 값은 자유롭게 구할 수 있게 됩니다.


그럼 이번 강좌는 여기서 마치도록 하겠습니다!






###  생각해보기




`1.` 아래와 같은 코드에서 `copy constructor` 는 몇 번 이나 표시될까요?
```cpp

class A
{
    int x;


public:
    A(int c) : x(c) {}
    A(const A& a) { x = a.x; cout << "복사생성" << endl;}
};


class B
{
    A a;


public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) { }
    A get_A() { return a;}
};


int main()
{
    B b(10);
    A a1 = b.get_A();


}
```



(난이도 : 上 `-`사실 이 글을 잘 읽었더라면 틀리게 답하는 것이 맞습니다`.` 컴파일러는 불필요한 복사를 막기 위해 `copy elision` 이라는 기술을 사용하고 있는데, 이에 관해서는 추후에 이야기 하도록 하겠습니다. 정 궁금하신 분들 . 컴파일러는 불필요한 복사를 막기 위해 `copy elision` 이라는 기술을 사용하고 있는데, 이에 관해서는 추후에 이야기 하도록 하겠습니다. 정 궁금하신 분들은 [http://en.wikipedia.org/wiki/Copy_elision](http://en.wikipedia.org/wiki/Copy_elision) 를 읽어보시기 바랍니다.)



```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <4 - 4. 스타크래프트를 만들자 ② (const, static)>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/135)
```














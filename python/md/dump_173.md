 itguru Top itguru Top

이번 강좌에서는
* 함수의 오버로딩 (function overloading)
* 생성자 (constructor)
* 디폴트 생성자 (default constructor)
에 대해 배웁니다


  안녕하세요 여러분. 이제 본격적으로 객체 지향 프로그래밍을 시작 하도록 하겠습니다. 아마도 지난번 생각해보기를 열심히 하셨던 분들이라면, Date 클래스에서 add_day 함수는 조금 어렵더라도, add_month 나 add_year 정도는 가뿐하게 만드셨을 것이라고 생각합니다. 사실, add_day 도 add_month 함수를 응용해서 만들면 쉬웠을 것입니다. 이번 강좌에서는 저와 함께 다시 새로운 방법으로 Date 클래스를 만들어가면서 객체 지향 프로그래밍에 조금 더 친숙해져 보도록 하겠습니다.



 함수의 오버로딩 (Overloading)


  본격적으로 객체 지향 프로그래밍을 시작하기에 앞서 C++ 에 C 와는 다른 새로운 기능을 잠시 살펴 보도록 하겠습니다. 바로 '함수의 오버로딩' 이라고 하는 것인데요, 사실 오버로드를 사전에서 찾아보면 다음과 같은 뜻이 나옵니다.


```info
1. 과적하다2.~ sb (with sth)너무 많이 주다[부과하다]3.(컴퓨터・전기 시스템 등에) 과부하가 걸리게 하다
```




  음.. 그렇다면 함수의 오버로딩이라는 것은 '함수에 과부하를 주는 것' 인가 라는 생각도 드실 텐데요, 사실 맞는 말씀입니다. 사실 C 언어 에서는 하나의 이름을 가지는 함수는 딱 1 개만 존재할 수 밖에 없기에 과부하라는 말 자체가 성립이 안됬지요. printf 는 C 라이브러리에 단 한 개 존재하고, scanf 도 C 라이브러리에 단 1 개 만 존재하지요. 하지만C++ 에서는 같은 이름을 가진 함수가 여러개 존재해도 됩니다. 즉, 함수의 이름에 '과부하' 가 걸려도 상관이 없다는 것이지요!


  그렇다면 도대체 C++ 에서는 같은 이름의 함수를 호출했을 때 구분을 어떻게 하는 것일까요. 물론 단순합니다. 함수를 호출 하였을 때 사용하는 인자를 보고 결정하게 됩니다.

```cpp

// 함수의 오버로딩

#include <iostream>
using namespace std;


void print (int x)
{
cout << "int : " << x << endl;
}
void print(char x)
{
cout << "char : " << x << endl;
}
void print(double x)
{
cout << "double : " << x << endl;
}
int main()
{
int a = 1;
char b = 'c';
double c = 3.2f;


print(a);
print(b);
print(c);


    return 0;
}
```


성공적으로 컴파일 하였다면




일단 위 소스를 보게 된다면 이름이 'print' 인 함수 3 개가 정의가 되었음을 알 수 있습니다. 고전적인 C 컴파일러에서는 오류가 발생했겠지만 C++ 에서는 '함수의 이름이 같더라도 인자가 다르면 다른 함수' 라고 판단하기 때문에 오류가 발생하지 않는 것입니다.

```cpp

void print (int x)
void print(char x)
void print(double x)
```



위와 같이 정의된 함수들을 main 에서 아래와 같이 호출하게 됩니다.


```cpp

int a = 1;
char b = 'c';
double c = 3.2f;


print(a);
print(b);
print(c);
```



여기서 한 가지 눈여겨 보아야 할 점은 a 는 int, b 는 char, c 는 double 타입이라는 것인데, 이에 따라 각각의 타입에 맞는 함수들, 예를 들어 print(b) 는 b 가 char 이므로 char 형의 인자를 가지는 두 번째 print 가 호출 된 것입니다.


C 언어였을 경우 int, char, double 타입에 따라 함수의 이름을 제각각 다르게 만들어서 호출해 주어야 했던 반면에 C++ 에서는 컴파일러가 알아서 '적합한 인자를 가지는 함수' 를 찾아서 호출해 주게 됩니다.

```cpp

// 함수의 오버로딩


#include <iostream>
using namespace std;


void print (int x)
{
cout << "int : " << x << endl;
}
void print (double x)
{
cout << "double : " << x << endl;
}


int main()
{
int a = 1;
char b = 'c';
double c = 3.2f;


print(a);
print(b);
print(c);


    return 0;
}
```





성공적으로 컴파일 하였다면










이번에는 조금 특이한 경우 입니다. 일단 함수는

```cpp

void print (int x)
void print (double x)
```



int 타입의 인자나 double 타입의 인자를 하나 받는 함수 하나 밖에 없습니다. 하지만 main 에서 각기 다른 타입의 인자들 (int, char, double) 로 print 함수를 호출하게 됩니다. 물론 a 나 c 의 경우 각자 자기를 인자로 하는 정확한 함수들이 있어서 성공적으로 호출 될 수 있겠지만,char 의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 '자신과 최대로 근접한 함수'를 찾게 됩니다.


C++ 컴파일러에서 함수를 오버로딩하는 과정은 다음과 같습니다.


1 단계 : 자신과 타입이 정확히 일치하는 함수를 찾는다.


2 단계 : 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.

* Char, unsigned char, short 는 int 로 변환된다.
* Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
* Float 은 double 로 변환된다.
* Enum 은 int 로 변환된다.


3 단계 : 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.

* 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
* Enum 도 임의의 숫자 타입으로 변환된다 (예를 들어 Enum -> double)
* 0 은 포인터 타입이나 숫자 타입으로 변환된다
* 포인터는 void 포인터로 변환된다.


4 단계 : 유저 정의된 타입 변환으로 일치하는 것을 찾는다 (이 부분에 대해선 나중에 설명!)
(출처 :http://www.learncpp.com/cpp-tutorial/76-function-overloading/)


만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에 '모호하다 (ambiguous)' 라고 판단해서 오류를 발생하게 됩니다.


그렇다면 우리의 소스 코드에서

```cpp

print(b);
```



는 어떻게 될까요. 1 단계에서는 명백하게도 char 타입의 인자를 가진 print 가 없기에 2 단계로 넘어오게 됩니다. 그런데 2 단계에서는 char 이 int 로 변환된다면 print (int x) 를 호출할 수 있기 때문에 결국 print (int x) 가 호출되게 되는 것이지요.

```cpp

// 모호한 오버로딩

#include <iostream>
using namespace std;


void print (int x)
{
cout << "int : " << x << endl;
}
void print (char x)
{
cout << "double : " << x << endl;
}


int main()
{
int a = 1;
char b = 'c';
double c = 3.2f;


print(a);
print(b);
print(c);


    return 0;
}
```





  위 소스를 컴파일 하였다면 오류가 발생함을 알 수 있습니다. 오류를 살짝 보자면


```warning

 error C2668: 'print' : ambiguous call to overloaded function
 could be 'void print(char)'
 or       'void print(int)'
while trying to match the argument list '(double)'
```





와 같이 나오는데요, 왜 오류가 발생하였는지 살펴보도록 합시다. 일단 위 소스에서는 함수가 print (int x) 와 print (char x) 밖에 없으므로 관건은 print(c); 를 했을 때 어떠한 함수가 호출되어야 하는지 결정하는 것인데요, print(c) 를 했을 때 1 단계에서는 명백하게 일치하는 것이 없습니다. 2 단계에서는 마찬가지로 double 의 캐스팅에 관련한 내용이 없기에 일치하는 것이 없고 비로소 3 단계로 넘어오게 됩니다. 3 단계에서는 '임의의 숫자 타입이 임의의 숫자 타입' 으로 변환되서 생각되기 때문에 double 은 char 도, int 도 변환 될 수 있게 되는 것입니다.


따라서 같은 단계에 두 개 이상의 가능한 일치가 존재하므로 오류가 발생하게 되는 것이지요.


위와 같은 C++ 오버로딩 규칙을 머리속에 숙지 하는 일은 매우 중요한 일입니다. 왜냐하면 나중에 복잡한 함수를 오버로딩할 때 여러가개 중복되서 나온다면 눈물없이 볼 수 없는 오류의 향연을 만날 수 있을 것입니다!




 Date 클래스


```cpp

#include <iostream>


using namespace std;
class Date
{
    int year;
    int month;
    int day;

public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year (int inc);
    void show_date();
};

void Date::set_date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}

void Date::add_day(int inc)
{
int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int i = month;


if(month_day[i - 1] - day >= inc)
{
day += inc;
return;
}
else
{
add_month(1);
day = 1;


inc = inc - (month_day[i - 1] - day) - 1;
i ++;
}
while (true)
{
if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
{
month_day[1] = 29; // 윤년
}
else
{
month_day[1] = 28;
}


// 만약에 그 달을 추가할 수 있다면
if(inc - month_day[i - 1] >= 0)
{
add_month(1);
inc = inc - month_day[i - 1];
}
else if(inc - month_day[i - 1] < 0)
{
day = day + inc;
break;
}


i ++;
if(i > 12)
i = i - 12;
}
}


void Date::add_month(int inc)
{
add_year((inc + month - 1) / 12);
month = month + inc % 12;
month = (month == 12 ? 12 : month % 12);
}


void Date::add_year(int inc)
{
    year += inc;
}

void Date::show_date()
{
    cout << "오늘은 " << year << " 년 "
        << month << " 월 "
        << day << " 일 입니다 " << endl;
}
int main()
{
    Date day;
    day.set_date(2011,3,1);
    day.show_date();


    day.add_year(10);
    day.show_date();
    return 0;
}

```

 성공적으로 컴파일 하였다면






위의 코드는 간단한 것들 (add_year, set_date, show_date) 만 만들어 놓은 상태입니다. 그런데, 이상한 것이 있죠? class 내부에는 아래 코드와 같이

```cpp

public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year (int inc);
    void show_date();

```



함수의 정의만 나와 있고, 함수 전체 몸통은

```cpp

void Date::set_date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}
```



처럼 밖에 나와 있습니다. Date:: 을 함수 이름 앞에 붙여주게 되면 이 함수가 "Date 클래스의 정의된 함수" 라는 의미를 부여하게 됩니다. 만일 그냥```cpp

void set_date(int _year, int _month, int _day)
{
// 생략
```


했다면이 함수는 아예 다른 함수가 되는 것이지요. 보통 간단한 함수를 제외하면 대부분의 함수들은 클래스 바깥에서 위와 같이 정의하게 됩니다. 왜냐하면 클래스 내부에 쓸 경우 클래스 크기가 너무 길어져서 보기 좋지 않기 때문이죠. 특히 나중에 클래스 자체만 따로 헤더파일로 뺄 수 도 있는데, 이 때 클래스 코드 길이가 너무 길면 불편하겠지요.

```cpp

    Date day;
    day.set_date(2011,3,1);
    day.show_date();

    day.add_year(10);
    day.show_date();
```


그럼 이제 main 함수를 살펴 봅시다. 위 처럼 day 인스턴스를 생성해서 set_date 로 초기화 한 다음에 show_date 로 내용을 한 번 보여주고, 또 add_year 을 해서 10 년을 증가 시킨뒤 다시 새로운 날짜를 출력하도록 하였습니다. 여기서 가장 중요한 부분은 무엇일까요? 당연하게도, 처음의 set_date 부분 입니다. 만일 set_date 를 하지 않았더라면 초기화 되지 않은 값들에 덧셈 과 출력 명령이 내려져서




위 처럼 이상한 쓰레기 값이 출력되게 되거든요. 그런데 문제는 이렇게 set_date 함수를 사람들이 꼭 뒤에 써주지 않는 다는 말입니다. 물론 훌륭한 프로그래머들은 '생성 → 초기화' 단계를 명확하게 머리속에 박아 넣고 있겠지만 간혹 실수로 초기화를 하지 않는다면 끔찍한 일이 벌어지게 됩니다.

다행이도 C++ 에서는 이를 언어 차원에서 도와주는 장치가 있는데 바로 "생성자(constructor)" 입니다.

 생성자 (Constructor)


```cpp

#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;

public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year (int inc);
    void show_date();

    Date(int _year, int _month, int _day)
    {
        year = _year;
        month = _month;
        day = _day;
    }
};

// 생략

int main()
{
 Date day(2011, 3, 1);
    day.show_date();

    day.add_year(10);
    day.show_date();
    return 0;
}
```


성공적으로 컴파일 하였다면




위와 같이 초기화가 잘 되서 출력됨을 알 수 있습니다.

생성자는 기본적으로 "객체 생성시 자동으로 호출되는 함수" 라고 볼 수 있습니다. 이 때 자동으로 호출 되면서 객체를 초기화 해주는 역할을 담당하게 됩니다. 생성자는 아래와 같이 정의합니다.

```info

// 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다!
(클래스 이름) ( 인자 )
{
}
```



예를 들어서 위 경우 저는 아래와 같이 Date 의 생성자를 정의하였습니다.

```cpp

Date(int _year, int _month, int _day)
```



이렇게 정의가 된 생성자는 객체를 생성할 때 다음과 같이 위 함수에서 정의한 인자에 맞게마치 함수를 호출하듯이 써준다면 위 생성자를 호출하며 객체를 생성할 수 있게 됩니다. 즉, 우리의 경우 아래와 같이 객체를 생성하였지요.

```cpp

    Date day(2011, 3, 1);
```



이는 곧 "Date 클래스의 'day' 객체를 만들면서 생성자 Date(int _year, int _month, int _day) 를 호출한다" 라는 의미가 됩니다. 따라서 Date 의 객체를 생성할 때 생성자의 인자 _year, _month, _day 에 각각 2011, 3, 1 을 전달하며 객체를 생성하게 되는 것이지요. 매우 간단한 원리 입니다. 그러한 맥락에서 볼 때 아래와 같이 객체를 생성하는 것도 동일한 의미 입니다.

```cpp

    Date day = Date(2012, 3, 1);
```



이는 역시 day 객체를 생성하고, 이 때 생성자 Date(2012, 3, 1) 을 호출해서 이를 토대로 객체를 생성하라는 의미가 됩니다. 사실 객체를 정의하는 두 방식에는 각각 이름이 붙어 있는데,

```cpp

    Date day(2011, 3, 1); // 암시적 방법 (implicit)
    Date day = Date(2012, 3, 1); // 명시적 방법 (explicit)
```



마치 함수를 호출하듯이 사용하는 것이 암시적 방법, 명시적으로 생성자를 호출한다는 것을 보여주는 것이 명시적 방법 인데 많은 경우 암시적 방법으로 축약해서 쓸 수 있으므로 이를 선호하는 편입니다.





 디폴트 생성자 (Default constructor)





그런데 한 가지 궁금증이 생겼습니다. 맨 처음에 단순히 set_date 함수를 이용해서 객체를 초기화 하였을 때 우리는 생성자를 명시하지 않았습니다. 즉 처음에 생성자 정의를 하지 않은 채 (set_date 함수를 사용했던 코드)

```cpp

    Date day;
```



로 했을 때 과연 생성자가 호출 될 까요? 답은 Yes 입니다. 생성자가 호출됩니다. 그런데, 우리가 생성자를 정의하지도 않았는데 어떤 생성자가 호출이 될까요? 바로 디폴트 생성자(Default Constructor) 입니다. 디폴트 생성자는 인자를 하나도 가지지 않는 생성자인데, 클래스에서사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자 입니다. (사용자가 어떤 다른 생성자를 추가한 순간 컴파일러는 자동으로 디폴트 생성자를 삽입하지 않는 다는 것을 명심하세요!) 물론 컴파일러가 자동으로 생성할 때에는 아무런 일도 하지 않게 되지요. 그렇기에 맨 처음에 set_date 를 하지 않았을 때 쓰레기 값이 나왔던 것입니다.


물론 여러분이 직접 디폴트 생성자를 정의할 수 도 있습니다. 아래와 같이요.

```cpp

// 디폴트 생성자 정의해보기

#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;


public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year (int inc);
    void show_date();


    Date()
    {
    year = 2012;
    month = 7;
    day = 12;
    }
};


// 생략


int main()
{
    Date day = Date();
    Date day2;


    day.show_date();
    day2.show_date();
    return 0;
}
```



성공적으로 컴파일 하였다면







와 같이 나오게 됩니다. 여러분은 아래와 같이 디폴트 생성자 Date() 를 정의하였습니다.


```cpp

    Date()
    {
    year = 2012;
    month = 7;
    day = 12;
    }
```



즉 year 에는 2012, month 에는 7, day 에는 2 를 집어넣게 되지요.



```cpp

    Date day = Date();
    Date day2;
```



그래서 사용하게 되면 위와 같이 디폴트 생성자를 이용해서 day 와 day2 를 추가할 수 있게 되는 것입니다. 한 가지 주의할 점은 위에서 인자가 있는 생성자에서 적용했던 것 처럼

```cpp

    Date day3();
```



와 하면 day3 객체를 디폴트 생성자를 이용해서 초기화 하는 것이 아니라,리턴값이 Date 이고 인자가 없는 함수 day3 을 정의하게 된 것으로 인식합니다. 이는 암시적 표현으로 객체를 선언할 때 반드시 염두해 두어야 할 사항입니다.




















 생성자 오버로딩

앞서 함수의 오버로딩에 대해 설명을 하였는데요, 생성자 역시 같은 함수이기에 오버로딩이 가능합니다.



```cpp

#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;


public:
    void set_date(int _year, int _month, int _date);
    void add_day(int inc);
    void add_month(int inc);
    void add_year (int inc);
    void show_date();


    Date()
    {
    cout << "기본 생성자 호출!" << endl;
    year = 2012;
    month = 7;
    day = 12;
    }
    Date(int _year, int _month, int _day)
    {
    cout << "인자 3 개인 생성자 호출!" << endl;
    year = _year;
    month = _month;
    day = _day;
    }
};


// 생략
void Date::show_date()
{
    cout << "오늘은 " << year<< " 년 "
        << month << " 월 "
        << day << " 일 입니다 " << endl;
}
int main()
{
    Date day = Date();
    Date day2(2012, 10, 31);


    day.show_date();
    day2.show_date();
    return 0;
}
```

성공적으로 컴파일 하였다면























와 같이 적절히 오버로딩이 되서 사용자가 원하는 생성자를 호출할 수 있게 됩니다.


이것으로 생성자에 대해 간단히 설명을 마치겠습니다. 물론 아직 생성자에 대해 이야기 할 거리는 무궁무진하게 남아 있지만 일단 오늘은 함수의 오버로딩과 생성자에 대한 입문으로 충분히 여러분의 머리가 지끈지끈 달아 올랐을 테니 '생각 해 보기'를 통해 머리를 식히도롭 합시다!


생각 해보기


1. Date 클래스에 여러가지 생성자들을 추가해보세요 (난이도 : 下)


2. 수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 중학생용 기하학 소프트웨워를 만드는 것인데요, 클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 다른 하나는 Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 즉 아래와 같은 두 클래스의 함수들을 모두 정의하세요 (난이도 : 上)


```cpp

class Point
{
int x, y;


public:
Point(int pos_x, int pos_y);
};
class Geometry
{
Point *point_array;
// 현재 공간에 대한 점들의 정보를 담고 있는 배열
// 물론 배열의 크기는 생성자에서 초기화 하고 충분히
// 크게 잡도록 합시다 (점 100 개 정도?)


public:
Geometry(Point *point_list);
Geometry();

void Add_Point(Point &point);


// 모든 점들 간의 거리를 출력하는 함수 입니다.
void Print_Distance();


// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
void Print_Num_Meets();
};




```





```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <4 - 2. 클래스의 세계로 오신 것을 환영합니다. (함수의 오버로딩, 생성자) >>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```





공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++' 카테고리의 다른 글씹어먹는 C++ - <4 - 3. 스타크래프트를 만들자 ① (복사 생성자, 소멸자)>(41)2013.01.06씹어먹는 C++ 토막글 ① - Rvalue(우측값) 레퍼런스에 관해(6)2012.11.03씹어먹는 C++ - <4 - 2. 클래스의 세계로 오신 것을 환영합니다. (함수의 오버로딩, 생성자) >(42)2012.08.04씹어먹는 C++ - <4 - 1. 이 세상은 객체로 이루어져 있다>(50)2012.02.29씹어먹는 C++ - <3. C++ 의 세계로 오신 것을 환영합니다. (new, delete)>(41)2012.01.01씹어먹는 C++ - <2 - 2. C++ 은 C 친구일까?>(27)2012.01.01


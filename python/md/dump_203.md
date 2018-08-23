 itguru Top itguru Top


이번 강좌에서는
* 멤버 함수가 아닌 연산자 함수 오버로딩
* 입출력 연산자 오버로딩 (정확히 보면 <<, >> 연산자)
* 첨자 연산자 [] 오버로딩
* 타입 변환 연산자 오버로딩
* 증감 연산자 ++, -- 오버로딩
에 대해 다룹니다.






안녕하세요 여러분. 잘 지내셨나요? 올해 안으로 C++ 강좌를 끝내기 위한 노력의 일환으로 강좌를 열심히 업로드 하려고 노력중인 Psi 입니다. 그래도 강좌를 읽으시는 여러분들은 꼼꼼히 읽어보시고, 궁금하신 점들은 꼭 댓글로 남겨 주시거나 메일로 질문해 주시기 바랍니다 :)


지난 강좌에서, 마지막에 다음과 같은 문제점을 지적하였습니다.

```cpp

a = a + "-1.1 + i3.923"; // ①
```



는 잘 컴파일 되서 실행되지만

```cpp

a = "-1.1 + i3.923" + a; // ②
```



는 컴파일 되지 않습니다. 왜냐하면, ① 의 경우 a.operator+("i3.923"); 으로 변환될 수 있지만 ② 는 그렇지 못하기 때문이죠. 하지만, 원칙적으로  클래스를 사용하는 사용자의 입장에서① 이 된다면 당연히② 도 수행될 수 있어야 연산자 오버로딩을 하는 명분이 생깁니다. 다행 스럽게도, 사실 컴파일러는 이항 연산자 (피연산자를 두 개를 취하는 연산자 - 예를 들어서 +, -, *, /, ->, = 등이 이항 연산자 이다) 를 다음과 같은 두 개의 방식으로 해석합니다.


어떤 임의의 연산자 @ 에 대해서, a @ b 는

```cpp

* a.operator@(b);
* operator@(a, b);
```



두 가지 방법으로 해석됩니다.


 (* 참고로 이는 일부 연산자들에 대해서는 해당되지 않는데 대표적으로 [] 연산자 (첨자), -> 연산자 (멤버 접근), 대입 연산자 (=), () 함수 호출 연산자들의 경우 멤버 함수로만 존재할 수 있습니다. 즉, 따로 멤버 함수가 아닌 전역 함수로 뺄 수 없다는 의미 입니다. 따라서 이들 함수를 오버로딩 할 때 주의하시기 바랍니다.)


즉, 컴파일 시에 둘 중 하나의 가장 가까운 것을 택해서 처리됩니다. a.operator@(b) 에서의 operator@ 는 a 의 클래스의 멤버 변수로써 사용되는 것이고, operator@(a,b) 에서의 operator@ 는 그냥 일반적인 함수를 의미하게 됩니다. 따라서 이를 처리하기 위해 함수를 정의하여 봅시다.

```cpp

Complex operator+(const Complex& a, const Complex& b)
{
Complex temp(a);
return temp.operator+(b);
}
```



우리의 또 다른 operator+ 는 두 개의 const Complex& 타입의 인자 a,b 를 받게 됩니다. 앞에서도 말했지만 컴파일러는 정확히 일치 하지 않는 경우, 가장 가까운 '가능한' 오버로딩 되는 함수를 찾게 되는데, 마침 우리에게는 Complex(const char *) 타입의 생성자가 있으므로,

```cpp

"-1.1 + i3.923" + a;
```



는

```cpp

operator+(Complex("-1.1 + i3.923"), a);
```



가 되어서 잘 실행되게 됩니다. 실제로 컴파일 해보면

```cpp

#include <iostream>
using namespace std;


class Complex
{
private:
double real, img;


double get_number(const char *str, int from, int to);


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const Complex& c) { real = c.real, img = c.img;}
Complex(const char* str);


Complex operator+(const Complex& c);
Complex operator-(const Complex& c);
Complex operator*(const Complex& c);
Complex operator/(const Complex& c);


Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);


Complex& operator=(const Complex &c);

void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};
Complex operator+(const Complex& a, const Complex& b)
{
Complex temp(a);
return temp.operator+(b);
}
Complex::Complex(const char* str)
{
// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)


int begin = 0, end = strlen(str);
img = 0.0;
real = 0.0;


// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
int pos_i = -1;
for(int i = 0; i != end; i ++) {
if(str[i] == 'i') {
pos_i = i;
break;
}
}


// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
if(pos_i == -1) {
real = get_number(str, begin, end - 1);
return ;
}


// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
real = get_number(str, begin, pos_i - 1);
img = get_number(str, pos_i + 1, end - 1);


if(pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char *str, int from, int to)
{
bool minus = false;
if(from > to) return 0;


if(str[from] == '-') minus = true;
if(str[from] == '-' || str[from] == '+') from ++;


double num = 0.0;
double decimal = 1.0;


bool integer_part = true;
for(int i = from; i <= to; i ++) {
if(isdigit(str[i]) && integer_part) {
num *= 10.0;
num += (str[i] - '0');
}
else if(str[i] == '.') integer_part = false;
else if(isdigit(str[i]) && !integer_part) {
decimal /= 10.0;
num += ((str[i] - '0') * decimal);
}
else break; // 그 이외의 이상한 문자들이 올 경우
}


if(minus) num *= -1.0;


return num;
}
Complex Complex::operator+(const Complex& c)
{
Complex temp(real + c.real, img + c.img);
return temp;
}
Complex Complex::operator-(const Complex& c)
{
Complex temp(real - c.real, img - c.img);
return temp;
}
Complex Complex::operator*(const Complex& c)
{
Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);
return temp;
}
Complex Complex::operator/(const Complex& c)
{
Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img)
, (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );
return temp;
}


Complex& Complex::operator+=(const Complex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
(*this) = (*this) / c;return *this;
}
Complex& Complex::operator=(const Complex &c)
{
real = c.real; img = c.img;
return *this;
}


int main()
{
Complex a(0, 0);
a = "-1.1 + i3.923" + a;
a.println();
}
```



성공적으로 컴파일 하였다면





와 같이 잘 실행됨을 알 수 있습니다. 그런데, 아마 operator+ 를 자세히 살펴보신 분들은 아마 다음과 같은 문제점을 확인할 수 있었을 것입니다.

```cpp

Complex operator+(const Complex& a, const Complex& b)
{
Complex temp(a);
return temp.operator+(b);
}
```



왜 굳이 귀찮게 temp 라는 새로운 Complex 객체를 정의하여서 temp 와의 + 연산을 리턴하느냐 입니다. 그냥 a + b 할 것을 불필요 하게 복사 생성을 한 번 더 하게 되서 성능의 하락이 발생하게 됩니다. 하지만, 그냥 a + b 를 하게 된다면;

```cpp

Complex operator+(const Complex& a, const Complex& b)
{
return a + b;
}
```



위 코드를 컴파일 시에 다음과 같은 경고 메세지를 볼 수 있을 것입니다.

```warning

warning C4717: 'operator+' : recursive on all control paths, function will cause runtime stack overflow
```



즉, a + b 에서 a.operator+(b) 가 호출되는 것이 아니라, operator+(a,b) 가 호출 되기 때문에 재귀적으로 무한히 많이 함수가 호출되어 오류가 발생한다는 것이지요. 실제로 실행해 보아도 프로그램이 강제로 종료되는 모습을 볼 수 있습니다. 따라서 이와 같은 문제를 방지하기 위해서 우리는 다음과 같이 강제로 멤버 함수 operator+ 를 호출하도록 지정하였습니다.

```cpp

Complex operator+(const Complex& a, const Complex& b)
{
return a.operator+(b);
}
```



이 역시 컴파일 되지 않습니다. 아마 오류의 내용은 다음과 같을 것입니다.

```warning

error C2662: 'Complex::operator +' : cannot convert 'this' pointer from 'const Complex' to 'Complex &'
```



이 말은 즉슨, a 가 const Complex 인데, 우리가 호출하고자 하는 멤버 함수 operator+ 는 const 함수가 아니기 때문입니다. 상당히 골치아픈 문제가 아닐 수 없습니다. (참고로const 함수가 무엇인지 기억이 나지 않으시는 분들은 이 강좌를 다시 읽어보시기 바랍니다)const 객체는 언제나 값이 바뀔 수 없으며, 만일 const 객체의 멤버 함수 호출 시에는 그 함수가 객체의 값을 바꾸지 않는 다고 보장할 수 있도록 const 함수여야만 합니다. 하지만 멤버 함수 operator+ 는 const 성이 없으므로, operator+ 를 호출하는 것은 불가능 해지지요.


이 문제를 해결할 수 있는 유일한 방법은Complex operator+(const Complex& a, const Complex& b) 내부에서 다른 함수들을 호출하지 않고 직접 덧셈을 수행하면 됩니다. 다만 이 방법도 문제가 있지요. 멤버 함수가 아닌 외부 함수 operator+ 에서 객체의 private 정보에 접근할 수 있어야만 하는데, 이 것이 불가능 하기 때문입니다. 하지만, 놀랍게도 C++ 에서는 이를 가능케 하는 키워드가 있습니다.





 friend 는 모든 것을 공유한다.



아마 이 글을 읽는 독자 여러분들은 자신의 모든 것을 아낌없이 털어놓을 수 있는 절친한 친구 한 두 명 쯤은 있을 것입니다. 그 친구와 나 사이에는 어떠한 정보도 열람할 수 있는 관계가 되지요.


그런데 재미있는 사실에는 비슷한 역할을 하는 키워드가 C++ 에도 있다는 점입니다. 그 이름도 역시 'friend' 입니다.


```cpp

class Complex
{
private:
double real, img;


double get_number(const char *str, int from, int to);


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const Complex& c) { real = c.real, img = c.img;}
Complex(const char* str);


Complex operator+(const Complex& c);
Complex operator-(const Complex& c);
Complex operator*(const Complex& c);
Complex operator/(const Complex& c);


Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);


Complex& operator=(const Complex &c);


friend Complex operator+(const Complex& a, const Complex& b);

void println() { cout << "( " << real << " , " << img << " ) " << endl;}

};
```



위와 같이 Complex 클래스 안에서

```cpp

friend Complex operator+(const Complex& a, const Complex& b);
```



라 같이 쓰면 우리의Complex operator+(const Complex& a, const Complex& b);  함수는 이제 Complex 의 friend 가 됩니다. 즉, Complex 클래스의 입장에서는 자신의 새로운 친구인 operator+ 에게 마음의 문을 열고 모든 정보에 접근할 수 있도록 허가하는 것입니다. private 냐 public 이냐에 관계 없이Complex operator+(const Complex& a, const Complex& b); 함수는 이제 어떤 Complex 객체라도 그 내부 정보에 접근할 수 있습니다.


따라서, 다음과 같은 코드를 사용하는 것도 가능하지요.

```cpp

Complex operator+(const Complex& a, const Complex& b)
{
Complex temp(a.real + b.real, a.img + b.img);
return temp;

}
```



이제 이 operator+ 함수는 마치 Complex 클래스의 멤버 변수인양, 객체들의 정보에 접근할 수 있게 됩니다. real 변수는 private 이지만, a.real 을 해도 무방하지요. 이렇게 된다면, 이전의 operator+ 에서 불필요하게 temp 객체를 생성했던 것 과는 달리 필요한 것만 사용하면 됩니다.


한 가지 재미 있는 사실은 friend 키워드는 함수에만 적용할 수 있는 것이 아니라, 다른 클래스 자체도 friend 로 지정할 수 있습니다. 예를 들어서,

```cpp

class A
{
private:
int x;


friend B;
};


class B
{
private:
int y;
};
```



와 같이 할 경우, A 는 B 를 friend 로 지정하게 된 것입니다. 한 가지 주의할 사실은, 우리가 흔히 생각하는 'friend' 관계와는 다르게, C++ 에서 friend 는 짝사랑과 비슷합니다. 즉, A 는 자기 생각에 B 가 friend 라고 생각하는 것이므로, B 에게 A 의 모든 것을 공개합니다. 즉 클래스 B 에서 A 의 private 변수인 x 에 접근할 수 있게 됩니다. 하지만 B 에는 A 가 friend 라고 지정하지 않았으므로, B 의 입장에서는 A 에게 어떠한 내용도 공개하지 않습니다 (public 변수들 빼고). 따라서 A 는 B 의 private 변수인 int y 에 접근할 수 없게 됩니다.





 입출력 연산자 오버로딩 하기

아마도, 눈치를 채신 분들이 있겠지만 우리가
```cpp
cout << a;
```

라고 하는 것은 사실 cout.operator<<(a) 를 하는 것과 동일한 명령이었습니다. 즉, 어떤 cout 이라는 객체에 멤버 함수 operator<< 가 정의되어 있어서 a 를 호출하게 되는 것이지요. 그런데, cout 이 int 나 double 변수, 심지어 문자열 까지 자유 자재로 operator<< 하나로 출력할 수 있었던 이유는 그 많은 수의 operator<< 함수들이 오버로딩 되어 있다는 뜻입니다.
실제로 우리가 include 하던 iostream 의 헤더파일의 내용을 살펴보면 (실제로는 ostream 에 정의되어 있습니다. 다만 iostream 이 ostream 을 include 하고 있음) ostream 클래스에

```cpp

ostream& operator<< (bool val);
ostream& operator<< (short val);
ostream& operator<< (unsigned short val);
ostream& operator<< (int val);
ostream& operator<< (unsigned int val);
ostream& operator<< (long val);
ostream& operator<< (unsigned long val);
ostream& operator<< (float val);
ostream& operator<< (double val);
ostream& operator<< (long double val);
ostream& operator<< (void* val);
```



와 같이 엄청난 수의 operator<< 가 정의되어 있는 것을 알 수 있습니다. 이들 덕분에 우리가 편하게 인자의 타입에 관계없이 손쉽게 출력을 사용할 수 있게 되는 것이지요.


그렇다면 한 번 우리의 Complex 클래스에서 ostream 클래스의 연산자 operator<< 를 자유롭게 사용할 수 있으면 어떨까요. 예를 들어서

```cpp

Complex c;
cout << c;
```



를 하게 되면 마치

```cpp

Complex c;
c.println();
```



을 한 것과 같은 효과를 내도록 말이지요. 당연하게도, ostream 클래스에 operator<< 멤버 함수를 새롭게 추가하는 것은 불가능 합니다. 이는 표준 헤더파일의 내용을 수정하는 것과 같기 때문이죠. 대부분의 경우 표준 헤더파일은 읽기만 가능이고, 원칙적으로 표준 라이브러리의 내용을 수정하는 것은 좋지 않습니다 (정확히 말하면 하면 안됩니다!). 따라서, 우리는 ostream 클래스에 Complex 객체를 오버로딩하는 operator<< 연산자 함수를 추가할 수는 없지요.


그 대신에, 여태 까지 배운 내용에 따르면 아예 operator<< 전역 함수 하나를 정해서 Complex 의 friend 로 지정한 다음에 사용할 수 있습니다. 그 함수는 아마 다음과 같이 생겼겟지요.

```cpp

ostream& operator<<(ostream& os, const Complex& c)
{
os << "( " << c.real << " , " << c.img << " ) ";
return os;
}
```



여기서 왜 'cout' 이 아니고 'os' 라고 의문을 가질 수 도 있는데, cout 자체가 iostream 에서 하나 만들어 놓은 ostream 객체 입니다. 따라서 ostream& 타입으로 cout 객체를 받아서 이를 출력하면 됩니다. 마찬가지로, Complex 클래스 내부에서 friend 선언을 해주시면 됩니다. 참고로 opreator<< 에서 ostream& 타입을 리턴하는 이유는 다음과 같은 문장을 처리할 수 있기 위해서입니다.

```cpp

cout << "a 의 값은 : " << a << " 이다. " << endl;
```



<< 연산자는 왼쪽 부터 오른쪽 순으로 실행되기 때문에 가장 먼저 cout.operator<<("a 의 값은?") 이 실행되고, 그 자리에 cout 이 다시 리턴됩니다. 그 다음에는 cout.operator<<(a); 가 되서 쭉쭉 이어질 수 있도록 이와 같이 ostream& 를 리턴하게 되는 것입니다. 참고로, Complex 클래스 내부에는

```cpp

friend ostream& operator<<(ostream& os, const Complex& c);
```



위와 같이 friend 선언을 해주시면 됩니다. 비슷한 방법으로 Complex 객체 c 에 대해 cin >> c; 와 같은 작업을 할 수 있습니다. 다만, 이번에는 cin 은 istream 객체이고, opreator>> 를 오버로딩 해야 된다는 점이 다를 뿐이지요.

```cpp

#include <iostream>
using namespace std;
class Complex
{
private:
double real, img;


double get_number(const char *str, int from, int to);


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const Complex& c) { real = c.real, img = c.img;}
Complex(const char* str);


Complex operator+(const Complex& c);
Complex operator-(const Complex& c);
Complex operator*(const Complex& c);
Complex operator/(const Complex& c);


Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);


Complex& operator=(const Complex &c);


friend Complex operator+(const Complex& a, const Complex& b);
friend ostream& operator<<(ostream& os, const Complex& c);


void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};
ostream& operator<<(ostream& os, const Complex& c)
{
os << "( " << c.real << " , " << c.img << " ) ";
return os;
}
Complex operator+(const Complex& a, const Complex& b)
{
Complex temp(a.real + b.real, a.img + b.img);
return temp;
}
Complex::Complex(const char* str)
{
// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)


int begin = 0, end = strlen(str);
img = 0.0;
real = 0.0;


// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
int pos_i = -1;
for(int i = 0; i != end; i ++) {
if(str[i] == 'i') {
pos_i = i;
break;
}
}


// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
if(pos_i == -1) {
real = get_number(str, begin, end - 1);
return ;
}


// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
real = get_number(str, begin, pos_i - 1);
img = get_number(str, pos_i + 1, end - 1);


if(pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char *str, int from, int to)
{
bool minus = false;
if(from > to) return 0;


if(str[from] == '-') minus = true;
if(str[from] == '-' || str[from] == '+') from ++;


double num = 0.0;
double decimal = 1.0;


bool integer_part = true;
for(int i = from; i <= to; i ++) {
if(isdigit(str[i]) && integer_part) {
num *= 10.0;
num += (str[i] - '0');
}
else if(str[i] == '.') integer_part = false;
else if(isdigit(str[i]) && !integer_part) {
decimal /= 10.0;
num += ((str[i] - '0') * decimal);
}
else break; // 그 이외의 이상한 문자들이 올 경우
}


if(minus) num *= -1.0;


return num;
}
Complex Complex::operator+(const Complex& c)
{
Complex temp(real + c.real, img + c.img);
return temp;
}
Complex Complex::operator-(const Complex& c)
{
Complex temp(real - c.real, img - c.img);
return temp;
}
Complex Complex::operator*(const Complex& c)
{
Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);
return temp;
}
Complex Complex::operator/(const Complex& c)
{
Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img)
, (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );
return temp;
}


Complex& Complex::operator+=(const Complex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
(*this) = (*this) / c;return *this;
}
Complex& Complex::operator=(const Complex &c)
{
real = c.real; img = c.img;
return *this;
}


int main()
{
Complex a(0, 0);
a = "-1.1 + i3.923" + a;
cout << "a 의 값은 : " << a << " 이다. " << endl;
}
```



성공적으로 컴파일 하였다면







와 같이 잘 실행됨을 알 수 있습니다.






 첨자 연산자 (operator[])



이번에는 배열에서 원소를 지정할 때 사용되는 첨자 연산자 [] 를 오버로딩 해보도록 합시다. (참고로 왜 첨자 연산자라고 부르냐면, 배열의 원소를 지정할 때 [] 안에 넣는 수를 첨자(subscript) 라고 부르기 때문입니다)우리가 전에 만들었던 MyString 클래스에서 개개의 문자에 접근하기 위해 [] 를 지원해주어야만 하는데요, [] 를 이용해서 str[10] 과 같이 10 번째 문자에 정확하게 접근할 수 있게 됩니다.


여기서 그렇다면 MyString 클래스의 operator[] 를 추가해보도록 합시다. operator[] 함수는 자명하게도 인자로 몇 번째 문자인지, int 형 변수를 인덱스로 받게 됩니다. 따라서 operator[] 는 다음과 같은 원형을 가집니다.

```cpp

char& operator[] (const int index);
```



index 로 [] 안에 들어가는 값을 받게 됩니다. 그리고 char& 를 인자로 리턴하는 이유는

```cpp

str[10] = 'c';
```



와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를 리턴하게 되는 것이지요. 실제로 opreator[] 의 구현은 아래와 같이 매우 단순합니다.

```cpp

char& MyString::operator[] (const int index)
{
return string_content[index];
}
```



위와 같이 index 번째의 string_content 를 리턴해서, operator[] 를 사용하는 사용자가, 이의 레퍼런스를 가질 수 있게 되지요. 그렇다면, 전체 소스를 한 번 살펴보도록 합시다.

```cpp

#include <iostream>
using namespace std;


class MyString
{
char * string_content; // 문자열 데이터를 가리키는 포인터
int string_length; // 문자열 길이


int memory_capacity; // 현재 할당된 용량


public:
// 문자 하나로 생성
MyString(char c);


// 문자열로 부터 생성
MyString(const char* str);


// 복사 생성자
MyString(const MyString &str);


~MyString();


int length();
int capacity();
void reserve(int size);


void print();
void println();


MyString& assign(MyString& str);
MyString& assign(const char *str);


char at(int i);
char& operator[] (const int index);


MyString& insert(int loc, MyString& str);
MyString& insert(int loc, const char* str);
MyString& insert(int loc, char c);


MyString& erase(int loc, int num);


int find(int find_from, MyString& str);
int find(int find_from, const char* str);
int find(int find_from, char c);


int compare(MyString& str);
};


MyString::MyString(char c)
{
string_content = new char[1];
string_content[0] = c;
memory_capacity = 1;
string_length = 1;
}
MyString::MyString(const char* str)
{
string_length = strlen(str);
memory_capacity = string_length;
string_content = new char[string_length];


for(int i = 0; i != string_length; i ++)
string_content[i] = str[i];
}
MyString::MyString(const MyString &str)
{
string_length = str.string_length;
string_content = new char[string_length];


for(int i = 0; i != string_length; i ++)
string_content[i] = str.string_content[i];
}
MyString::~MyString()
{
delete [] string_content;
}
int MyString::length()
{
return string_length;
}
void MyString::print()
{
for(int i = 0; i != string_length; i ++)
cout << string_content[i];
}
void MyString::println()
{
for(int i = 0; i != string_length; i ++)
cout << string_content[i];


cout << endl;
}


MyString& MyString::assign(MyString& str)
{
if(str.string_length > memory_capacity) {
// 그러면 다시 할당을 해줘야만 한다.
delete [] string_content;


string_content = new char [str.string_length];
memory_capacity = str.string_length;
}
for(int i = 0; i != str.string_length; i ++) {
string_content[i] = str.string_content[i];
}


// 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.


string_length = str.string_length;


return *this;
}
MyString& MyString::assign(const char *str)
{
int str_length = strlen(str);
if(str_length > memory_capacity) {
// 그러면 다시 할당을 해줘야만 한다.
delete [] string_content;


string_content = new char [str_length];
memory_capacity = str_length;
}
for(int i = 0; i != str_length; i ++) {
string_content[i] = str[i];
}


string_length = str_length;


return *this;
}
int MyString::capacity()
{
return memory_capacity;
}
void MyString::reserve(int size)
{
if(size > memory_capacity) {
char *prev_string_content = string_content;


string_content = new char [size];
memory_capacity = size;


for(int i = 0; i != string_length; i ++)
string_content[i] = prev_string_content[i];


delete [] prev_string_content;
}


// 만일 예약하려는 size 가 현재 capacity 보다 작다면
// 아무것도 안해도 된다.
}
char MyString::at(int i)
{
if(i >= string_length || i < 0) return NULL;
else return string_content[i];
}
char& MyString::operator[] (const int index)
{
return string_content[index];
}
MyString& MyString::insert(int loc, MyString& str)
{
// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.


// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
if(loc < 0 || loc > string_length) return *this;


if(string_length + str.string_length > memory_capacity) {
// 이제 새롭게 동적으로 할당을 해야 한다.


if(memory_capacity * 2 > string_length + str.string_length)
memory_capacity *= 2;
elsememory_capacity = string_length + str.string_length;


char *prev_string_content = string_content;
string_content = new char[memory_capacity];


// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
int i;
for(i = 0; i < loc; i ++) {
string_content[i] = prev_string_content[i];
}


// 그리고 새롭에 insert 되는 문자열을 넣는다.
for(int j = 0; j != str.string_length; j ++) {
string_content[i + j] = str.string_content[j];
}


// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
for(; i < string_length; i ++) {
string_content[str.string_length + i] = prev_string_content[i];
}


delete [] prev_string_content;


string_length = string_length + str.string_length;
return *this;
}


// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.


for(int i = string_length - 1; i >= loc; i --) {
// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
string_content[i + str.string_length] = string_content[i];
}
// 그리고 insert 되는 문자 다시 집어넣기
for(int i = 0; i < str.string_length; i ++)
string_content[i + loc] = str.string_content[i];


string_length = string_length + str.string_length;
return *this;
}
MyString& MyString::insert(int loc, const char* str)
{
MyString temp(str);
return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c)
{
MyString temp(c);
return insert(loc, temp);
}


MyString& MyString::erase(int loc, int num)
{
// loc 의 앞 부터 시작해서 num 문자를 지운다.
if(num < 0 || loc < 0 || loc > string_length) return *this;


// 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
// 생각하면 됩니다.


for(int i = loc + num; i < string_length; i ++) {
string_content[i - num] = string_content[i];
}


string_length -= num;
return *this;
}
int MyString::find(int find_from, MyString& str)
{
int i, j;
if(str.string_length == 0) return -1;
for(i = find_from; i < string_length - str.string_length; i ++) {
for(j = 0; j < str.string_length; j ++) {
if(string_content[i + j] != str.string_content[j]) break;
}


if(j == str.string_length) return i;
}


return -1; // 찾지 못했음
}
int MyString::find(int find_from, const char* str)
{
MyString temp(str);
return find(find_from, temp);
}
int MyString::find(int find_from, char c)
{
MyString temp(c);
return find(find_from, temp);
}
int MyString::compare(MyString& str)
{
// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
// 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.


for(int i = 0; i < min(string_length, str.string_length); i ++) {
if(string_content[i] > str.string_content[i]) return 1;
else if(string_content[i] < str.string_content[i]) return -1;
}


// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.


if(string_length == str.string_length) return 0;


// 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
else if(string_length > str.string_length) return 1;


return -1;
}
int main()
{
MyString str("abcdef");
str[3] = 'c';


str.println();
}
```



성공적으로 컴파일 하였다면







와 같이 제대로 str[3] 의 'd' 를 'c' 로 잘 바꾸었음을 알 수 있습니다.


이 정도만 하면 MyString 클래스는 거의 왠만한 문자열 클래스 뺨치게 완전한 모습을 갖추었다고 볼 수 있습니다. 문자열 삽입, 삭제, 대입 뿐만이 아니라 개개의 문자의 조작 까지 원활하게 수행할 수 있는 훌륭한 문자열 클래스라고 할 수 있지요.






 int Wrapper 클래스 - 타입 변환 연산자



Wrapper 라는 것은 원래 우리가 흔히 음식을 포장할 때 '랩(wrap)으로 싼다' 라고 하는 것 처럼, '포장지' 라는 의미의 단어 입니다. 즉 Wrapper 클래스는 무언가를 포장하는 클래스라는 의미인데, C++ 에서 프로그래밍을 할 때 어떤 경우에 기본 자료형들을 객체로써 다루어야 할 때가 있습니다. 이럴 때, 기본 자료형들 (int, float 등등) 을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것을 Wrapper 클래스를 이용한다는 뜻 입니다.


즉, int 자료형을 감싸는 int Wrapper 클래스 Int 는 다음과 같이 구성할 수 있습니다.

```cpp

class Int

{
int data;
// some other data


public:
Int(int data) : data(data) {}
Int(const Int& i) : data(i.data) {}
};
```



위 Int 클래스에 int 형 자료형을 보관하는 data 라는 변수를 정의해 놓았는데, 이렇게 한다면 int 형 데이터를 저장하는 객체로 Int 클래스를 사용할 수 있을 것입니다. 우리는 이 Int 객체가 int 의 Wrapper 클래스의 객체인 만큼, int 와 정확히 똑같이 작동하도록 만들고 싶습니다. 다시 말해서 다음과 같은 명령을 내려도 아무 하자 없이 잘 실행될 수 있도록 말이지요.

```cpp

Int x = 3; // Wrapper 객체
int a = x + 4; // 그냥 평범한 int 형 변수 a
```



이를 잘 수행하기 위해서라면, 여태까지 연산자 오버로딩을 열심히 배워오신 여러분 생각이라면


그렇다면 int 변수에 사용되는 모든 연산자 함수들을 만들어주면 되겠군!


이라고 생각이 들 것입니다. 물론, 이렇게 해도 잘 작동하는 Wrapper 클래스를 만들 수 있을 것입니다. 하지만, 그 수 많은 연산자들을 일일히 오버로딩을 하는 것은 정말로 고통스러운 일이 아닐 수 없습니다. 왜 이러한 일이 고통스러운 것이냐면, Complex 클래스를 만들 때만 해도, Complex 객체에서 + 나 - 연산자가 하는 일 자체가 int 변수 끼리 하는 일과 완전히 달랐기 때문에 반드시 operator+ 나 operator- 등을 만들어주어야만 했을 것입니다. 하지만 이 int Wrapper 클래스 객체끼리 하는 일은 그냥 단순히 int 형 변수 끼리 하는 일과 정확히 똑같기 때문에 굳이 이미 제공하는 기능을 다시 만들어야 한다는 점이지요.


그렇다면, 그냥 이 Wrapper 클래스의 객체를 마치 'int 형 변수' 라고 컴파일러가 생각할 수 는 없는 것일까요. 물론 가능합니다. 왜냐하면 우리에게는 타입 변환 연산자가 있기 때문이지요. 만일 컴파일러가 이 클래스의 객체를 int 형 변수로 변환할 수 있다면, 비록 operator+ 등을 정의하지 않더라도 컴파일러가 가장 이 객체를 int 형 변수로 변환 한 다음에 + 를 수행할 수 있기 때문입니다.


타입 변환 연산자는 다음과 같이 정의합니다.

```info

operator (변환 하고자 하는 타입) ()
```



예를 들어 우리의 int Wrapper 클래스의 경우 다음과 같은 타입 변환 연산자를 정의할 수 있지요.

```cpp

operator int()
```



한 가지 주의할 점은, 생성자 처럼 함수의 리턴 타입을 써주시면 안됩니다. 이는 C++ 에서 변환 연산자를 정의하기 위한 언어 상의 규칙이라고도 볼 수 있습니다. 그렇게 된다면, 우리의 int 변환 연산자는 다음과 같이 간단하게 구성할 수 있겠지요.

```cpp

operator int()
{
return data;
}
```



그냥 단순히 data 를 리턴해주면 됩니다. 그렇게 된다면 우리의 Wrapper 클래스의 객체를 '읽는' 데에는 아무런 문제가 없게 됩니다. 왜냐하면 컴파일러 입장에서 적절한 변환 연산자로 operator int 를 찾아서 결국 int 로 변환해서 처리하기 때문이지요. 다만 문제는 '대입' 시에 발생하는데, 다행이도 디폴트 대입 연산자가 이 역시 알아서 잘 처리할 것이기 때문에 걱정 안하셔도 됩니다.

```cpp

#include <iostream>
using namespace std;


class Int
{
int data;
// some other data


public:
Int(int data) : data(data) {}
Int(const Int& i) : data(i.data) {}


operator int()
{
return data;
}
};
int main()
{
Int x = 3;
int a = x + 4;


x = a * 2 + x + 4;
cout << x << endl;
}
```



성공적으로 컴파일 하였다면







와 같이 Int 객체가 int 변수 처럼 정확히 동일하게 작동되고 있음을 알 수 있습니다.





 전위/후위 증감 연산자



마지막으로 살펴볼 연산자로 우리가 흔히 ++, -- 로 사용하는 전위/후위 증감 연산자들 입니다. 아마, 이 연산자를 오버로딩 하기 전에 한 가지 궁금증이 드셨을 텐데요, 과연 C++ 컴파일러는 전위/후위 증감을 구분 해서 오버로딩 시켜주냐 입니다. 다시 말해;

```cpp

a ++;
++ a;
```



위 두 ++ 연산자들을 구분해서 오버로딩을 시켜주냐 이말이죠. 사실 우리가 흔히 생각하기에 ++ 연산자는 그냥 1 증가 시켜주는 1 개의 연산자라고 볼 수 있겠지만 놀랍게도 C++ 에서는 ++ 연산자를 전위와 후위를 구분해서 오버로딩 할 수 있도록 제공하고 있습니다. 그렇다면요, 이 둘을 도대체 어떻게 구분할 수 있을까요?


C++ 언어에서는 다음과 같은 재미있는 방법으로 구분합니다. 일단;

```cpp

operator++ ()
operator-- ()
```



은 전위 증감 연산자 (++x, --x) 를 오버로딩 하게 됩니다. 그렇다면 후위 증감 연산자 (x ++, x--) 는 어떨까요. 바로

```cpp

operator++ (int x)
operator-- (int x)
```



로 구현하게 됩니다. 물론 인자 x 에는 0 이 들어가게 됩니다. 즉 단순히 전위와 후위를 구별하기 위해 인자로 x 를 넣어주는 것이지요. 실제로 ++ 을 구현하면서 인자로 들어가는 값을 사용하는 경우는 없습니다. 한 가지 주목할 점은 많은 경우 전위 증감이 후위 증감 보다 더 빠르기 때문에 (물론, 엄청나게 빠르다는 것이 아니라 후위 증감 자체가 약간의 연산을 더 수행하게 됩니다) 후위/전위 증감 중 무엇을 사용하던 상관이 없는 경우 (예를 들어서 for 문에서 i ++ 을 한 다던지) 되도록이면 전위 증감을 사용하는 것이 바람직 합니다만, 클래스를 사용하는 사용자의 입장에서는 두 개 모두 지원해야 하므로 우리는 둘 다 만들어야 하겠지요.


따라서 아래와 같은 테스트 클래스를 제작하였습니다.

```cpp

class Test

{
int x;


public:
Test(int x) : x(x) {}
Test& operator++()
{
x ++;
cout << "전위 증감 연산자" << endl;
return *this;
}
Test& operator++(int s)
{
x ++;
cout << "후위 증감 연산자" << endl;
return *this;
}
};
```



클래스 자체에는 별거 없지만 전위와 후위가 호출될 때를 구별하기 위해 메세지를 출력하도록 하였습니다.

```cpp

#include <iostream>
using namespace std;


class Test
{
int x;


public:
Test(int x) : x(x) {}
Test& operator++()
{
x ++;
cout << "전위 증감 연산자" << endl;
return *this;
}
Test& operator++(int s)
{
x ++;
cout << "후위 증감 연산자" << endl;
return *this;
}
};
int main()
{
Test x(3);


x++;
++x;
}
```



성공적으로 컴파일 하였다면







와 같이 제대로 골라서 실행되고 있음을 알 수 있습니다.






 정리

연산자 오버로딩에 대해 다루면서 몇 가지 중요한 포인트 들만 따로 정리해보자면;

* 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌외부 함수로 오버로딩 하는 것이 좋습니다. (예를 들어 Complex 의 operator+(const Complex&, const Complex&) 와 같이 말입니다. )
* 두 개의 객체 사이의 이항 연산자 이지만 한 객체만 값이 바뀐다던지 등의동등하지 않는 이항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다. (예를 들어서 operator+= 는 이항 연산자 이지만 operator+=(const Complex&) 가 낫다)
* 단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다 (예를 들어 operator++ 의 경우 멤버 함수로 오버로딩 합니다)
* 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 합니다 (강좌 앞 부분 참고)


자, 이것으로 가장 많이 사용되는 연산자 함수들에 대해 알아보았습니다. 이제 슬슬 C++ 언어의 강력함이 느껴지시나요? 다음 강좌에서는 여태까지 배운 내용들을 총 망라하는 조그마한 프로젝트를 해볼려고 합니다. 그 프로젝트는 아래 '생각해보기'에 나와 있는데요, 다음 강좌를 보기 전 까지 아래 문제를 한 번 해결해 보시기 (해결은 못해도 최소한 노력은 하시기) 바랍니다.






 생각해보기


1. N 차원 배열을 제공하는 클래스를 만들어보세요. 이는 여러분이 여태까지 배운 내용을 시험할 것입니다. 참고로, 원소에 접근하기 위해서는 a[1][2][3] 과 같은 방법으로 접근하겠지요. 다만 N 차원 배열이기 때문에 (N은 객체 생성시에 사용자가 입력합니다) 2 차원 배열은 a[1][2], 3 차원 배열은 a[1][2][3] 과 같은 방식으로 접근할 것입니다. (난이도 : 最上)


2. 영어를 잘하시는 분들은 연산자 오버로딩에 관해 정리해 놓은 다음 글을 읽어보시기를 추천합니다. 참고로 이 글에서 다루지만 본 강좌에서는 다루지 않는 일부 내용들은 아직 배운 내용이 아니라 생략한 것이므로 너무 걱정하지 마시고 복습하는 느낌으로 천천히 읽어보시면 좋습니다. (난이도 : 中)
>>http://stackoverflow.com/questions/4421706/operator-overloading


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```












공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++' 카테고리의 다른 글씹어먹는 C++ - <6 - 1. C++ 표준 문자열 & 부모의 것을 물려쓰자 - 상속>(10)2014.03.30씹어먹는 C++ - <5 - 3. 연산자 오버로딩 프로젝트 - N 차원 배열>(24)2013.09.04씹어먹는 C++ - <5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩>(5)2013.08.29씹어먹는 C++ - <5 - 1. 내가 만든 연산자 - 연산자 오버로딩>(7)2013.08.25씹어먹는 C++ - <4 - 5. 내가 만드는 String 클래스>(29)2013.08.15씹어먹는 C++ - <4 - 4. 스타크래프트를 만들자 ② (const, static)>(17)2013.05.26


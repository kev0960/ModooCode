


이번 강좌에서는* 산술 연산자 오버로딩비교 연산자 오버로딩대입 연산자 오버로딩에 대해서 다룹니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F24253D3C52177993100B09)



안녕하세요 여러분! 지난 강좌에서 만들었던 MyString 을 손 좀 봐주었나요? 아마도 MyString 을 이용하여 여러가지 작업을 하면서 다음과 같은 생각을 하셨을 수도 있었을 것입니다. 

* if(str1.compare(str2) == 0) 하지 말고 if(str1 == str2) 하면 어떨까?str1.insert(str1.length(), str2) 하지 말고 str1 = str1 + str2; 하면 어떨까?str1[10] = 'c'; 와 같은 것도 할 수 있을까?


물론 C 언어에서는 이러한 것을 상상조차 할 수 없었습니다. +, -, ==, [] 와 같은 기본 연산자들은 모두 C 언어에 기본적으로 정의되어 있는 데이터 타입(int, float 등)에만 사용 가능한 것들 이였기 때문이죠. 이들을 구조체 변수에 사용한다는 것은 불가능하였습니다. 


하지만 놀랍게도 C++ 에서는 사용자 정의 연산자를 사용할 수 있습니다. 어떠한 연산자들이 가능하나면, :: (범위 지정), . (멤버 지정), .* (멤버 포인터로 멤버 지정) 을 제외한 여러분이 상상하는 모든 연산자를 사용할 수 있다는 것입니다. +, -, * 는 물론이고, +=, -= 와 같은 축약형들이나 >=, ==, 와 같은 비교 연산자, && 와 같은 논리 연산자, -> 와 같은 멤버 선택 연산자, ++, -- 증감 연산자, [] 와 심지어 () 까지 (함수 호출 연산자) 도 모두 여러분이 직접 만들 수 있습니다. 


이 때 이러한 기본 연산자들을 직접 사용자가 정의하는 것을 연산자를 오버로딩(overloading) 한다고 부릅니다. 이전에 같은 이름의 함수를 인자만 다르게 사용하는 것을 '함수를 오버로딩 했다' 라고 불렀던 것 처럼, 기본 연산자를 여러분이 설계한 클래스에 맞게 직접 사용하는 것을 '연산자를 오버로딩 했다' 라고 부릅니다.





 MyString 의 == 연산자 오버로딩### 


일단 연산자 오버로딩을 사용하기 위해서는, 다음과 같이 오버로딩을 원하는 연산자 함수를 제작하면 됩니다.

```info

(리턴 타입) operator(연산자) (연산자가 받는 인자)
```



(※ 참고적으로 위 방법 외에는 함수 이름으로 연산자를 절대 넣을 수 없습니다) 예를 들어서 우리가 == 를 오버로딩 하고 싶다면, == 연산자는 그 결과값이 언제나 bool 이고, 인자로는 == 로 비교하는 것 하나만 받게 됩니다. 따라서 다음과 같이 함수를 정의하면 됩니다.

```info

bool operator== (MyString& str);
```



이제, 우리가 str1 == str2 라는 명령을 한다면 이는 str1.operator==(str2) 로 내부적으로 변환되서 처리됩니다. 그리고 그 결과값을 리턴하게 되겠지요. 사실 operator== 를 만드는 것 자체는 별로 어려운 일은 아닙니다. 왜냐하면 이미 MyString 에서 compare 라는 좋은 함수를 제공하고 있기 때문이지요. 간단하게 만들어 보면 다음과 같습니다.

```cpp

bool MyString::operator== (MyString& str)

{
return !compare(str); // str 과 같으면 compare 에서 0 을 리턴한다.
}
```



여기서 !compare(str) 을 리턴하는 이유는 compare 함수에서 str 과 *this 가 같으면 0 을 리턴하도록 하였는데, operator== 은 둘이 같으면 true 를 리턴해야 되기 때문입니다. 따라서 NOT 연산자인 ! 를 앞에 붙여서 리턴하면 올바르게 작동할 수 있습니다. 그럼, 실제로 우리의 새롭게 오버로딩한 == 연산자가 잘 작동하는지 살펴봅시다.

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


MyString& insert(int loc, MyString& str);
MyString& insert(int loc, const char* str);
MyString& insert(int loc, char c);


MyString& erase(int loc, int num);


int find(int find_from, MyString& str);
int find(int find_from, const char* str);
int find(int find_from, char c);


int compare(MyString& str); 


bool operator== (MyString& str);
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
else memory_capacity = string_length + str.string_length;


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
bool MyString::operator== (MyString& str)
{
return !compare(str); // str 과 같으면 compare 에서 0 을 리턴한다.
}
int main()
{
MyString str1("a word");
MyString str2("sentence");
MyString str3("sentence");

if(str1 == str2) cout << "str1 and str2 are same" << endl;
else cout << "st1 and str2 are different" << endl;


if(str2 == str3) cout << "str2 and str3 are same" << endl;
else cout << "st2 and str3 are different" << endl;
}
```

성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F245A6D4B520CF2291D03B6)



와 같이 잘 나옵니다. 위 코드에서도 쉽게 알 수 있지만 str1 과 str2 은 다르고, str2 와 str3 는 같기 때문에 위와 같이 제대로 처리되고 있음을 알 수 있습니다. 






 복소수 (Complex number) 클래스 만들기



MyString 클래스를 이용해서 설명을 계속 하려고 했지만, MyString 자체가 너무 비대한 바람에 좀더 간결하게 설명을 하기 위해 새로운 클래스를 만들어보도록 할 것입니다. 바로 복소수(Complex Number) 클래스 인데요, 아마 이 강좌를 보시는 분들 중에서는 복소수가 정확히 무엇인지 모르시는 분들 도 있을 것입니다. 그 분들을 위해서 간략하게 먼저 설명을 하고 가겠습니다. 
![](http://)

일단 실수의 제곱근에 대해서는 무엇인지 다들 아실 것이라 생각합니다. 그런데 실수의 제곱은 언제나 양수이기 때문에 위와 같이 음수의 제곱근은 실수로 표현할 수 없게 됩니다. 따라서, 음수의 제곱근을 나타내기 위해서 특별한 수를 정의하였는데 이를 허수(imaginary number) 이라 부르며, 실제로 존재하지 않는 수학적으로만 존재하는 수라고 볼 수 있습니다. 그리고 특히 -1 의 제곱근을 위의 수식 처럼 i 로 표기합니다. 


따라서, 이 때문에 예를 들어서 -4 의 제곱근은
![](http://)

와 같이 생각할 수 있겠지요. 그리고 복소수는, 이 허수와 실수를 모두 포함하는 수 체계로, 허수와 실수의 합으로 표현할 수 있습니다. 다시 말해서, 임의의 복소수 z 는 다음과 같은 꼴입니다.![](http://)
물론 여기서 a,b 는 모두 실수 입니다.
우리가 만들고자 하는 것은 이 복소수를 나타내는 클래스를 구성하겠다는 이야기 입니다. 임의의 복소수 하나를 표현하기 위해서 두 개의 값(실수부, 허수부)이 필요하기 때문에 반드시 클래스로 구현을 해야 하겠죠. 따라서, 기본적으로 복소수 클래스 Complex 는 다음과 같이 간단하게 만들 수 있습니다. 
```cpp
class Complex{private:double real, img;
public:Complex(double real, double img) : real(real), img(img) {}};
```

복소수는 언제나 실수부와 허수부로 나뉘어지므로, Complex 클래스 역시 실수부의 값과 허수부의 값을 나타내는 real 과 img 변수가 있습니다. 여기서 문제는 이전에 만들었던 MyString 과는 다르게, 사칙 연산이 엄청나게 자주 쓰인다는 것입니다. 당연하게도 문자열의 덧셈 (+ 연산) 까지는 생각할 수 있었다 해도, 곱셈이나 나눗셈 연산 자체는 고려할 필요가 없는데, 복소수의 경우 당연히 클래스 인터페이스 차원에서 곱셈과 나눗셈을 지원해주어야만 합니다. 
참고로, 복소수의 사칙 연산은 실수부와 허수부 따로 생각하여 진행됩니다. 간단히 말하면![](http://)
와 같은 관계가 성립한다는 이야기 이죠. 곱셈의 경우는 좀더 복잡한데, 사실 분배법칙과 허수 둘을 곱하면 다시 -1 이 된다는 점만 생각하면 아래의 관계식도 어렵지 않게 생각할 수 있습니다.![](http://)
나눗셈의 경우, 이전에 무리수의 유리화를 하셨던 것을 생각하면 간단합니다.![](http://)
즉 분모를 실수화 할 수 있도록 분모의 켤레를 분자와 분모에 곱함으로써 실수로 나누는 것으로 쉽게 바꿀 수 있습니다. (실수로 나누는 것은 실수부, 허수부의 실수값을 그냥 실수로 나누면 됩니다) 
그래서 만일 다음과 같이 연산자의 오버로딩을 모른다고 가정하고 Complex 클래스를 구성하여 봅시다.
```cpp
class Complex{private:double real, img;
public:Complex(double real, double img) : real(real), img(img) {}
Complex plus(const Complex& c);Complex minus(constComplex& c);Complex times(constComplex& c);Complex divide(constComplex& c);};
```

이렇게 된다면 만일 int 형 변수였다면
```cpp
a + b/c + d;
```

로 간단하게 쓸 수 있었던 명령을 
```cpp
a.plus(b.divide(c)).plus(d);
```

와 같이 복잡한 함수식을 이용해서 표현해야만 합니다. 이는, 가독성이 떨어질 뿐더러 위 식을 딱 보고 도대체 무슨 작업을 하려고 하는지도 쉽게 알 수 없습니다. 하지만 연산자 오버로딩을 이용해서 plus 를 operator+ 로, divide 를 operator/ 로, 등등 바꿔준다면 단순히 프로그래머가 a + b/c + d; 게 쓴다고 해도, 컴파일러가 a.operator+(b.operator/(c)).operator+(d); 로 알아서 변환시켜서 처리하기 때문에 속도나 다른 면의 어떠한 차이 없이 뛰어난 가독성과 편리함을 얻을 수 있게 됩니다. 
이를 바탕으로 간단히 Complex 클래스를 만들어본다면 
```cpp
#include <iostream>using namespace std;
class Complex{private:double real, img;
public:Complex(double real, double img) : real(real), img(img) {}Complex(const Complex& c) { real = c.real, img = c.img;}
Complex operator+(constComplex& c);Complex operator-(constComplex& c);Complex operator*(constComplex& c);Complex operator/(constComplex& c);
void println() { cout << "( " << real << " , " << img << " ) " << endl;}};
Complex Complex::operator+(constComplex& c){Complex temp(real + c.real, img + c.img);return temp;}Complex Complex::operator-(constComplex& c){Complex temp(real - c.real, img - c.img);return temp;}Complex Complex::operator*(constComplex& c){Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);return temp;}Complex Complex::operator/(constComplex& c){Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img), (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );return temp;}
int main(){Complex a(1.0, 2.0);Complex b(3.0, -2.0);
Complex c = a*b;
c.println();}
```

성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F2160643D520CFD6F1D18E1)


와 같이 잘 나옴을 알 수 있습니다. 여기서 가장 중요하게 봐야 할 부분은 바로, 사칙연산 연산자 함수들의 리턴 타입 입니다. 


```cpp
Complex operator+(constComplex& c);Complex operator-(constComplex& c);Complex operator*(constComplex& c);Complex operator/(constComplex& c);
```

위 4 개의 연산자 함수 모두 Complex& 가 아닌 Complex 를 리턴하고 있습니다. 간혹가다, 
```cpp
Complex& operator+ (constComplex& c){real += c.real;img += c.img;return *this;}
```



로 잘못 생각하는 경우도 있습니다. 물론 이렇게 설계하였을 경우, Complex 를 리턴하는 연산자 함수는 값의 복사가 일어나기 때문에 속도  저하가 발생하지만 위 처럼 레퍼런스를 리턴하게 되면 값의 복사 대신 레퍼런스만 복사하는 것이므로 큰 속도의 저하는 나타나지 않습니다. 하지만, 위와 같이 operator+ 를 정의할 경우 다음과 같은 문장이 어떻게 처리되는지 생각해봅시다.

```cpp

Complex a = b + c + b;
```



아마도 위 문장을 쓴 사람 입장에서는 결과적으로 a = 2 * b + c; 를 의도하였을 것입니다. 하지만, 실제로 처리되는 것을 보자면, (b.plus(c)).plus(b) 가 되는데, b.plus(c) 를 하면서 b 에는 (b + c) 가 들어가고, 거기에 다시 plus(b) 를 하게 된다면 값 자체만 보자면 (b + c) + (b + c) 가 되서 (왜냐하면 현재 b 에는 b + c 가 들어가 있으니까) a = 2 * b + 2 * c 가 되기 때문입니다. 이러한 문제를 막기 위해서는 반드시 사칙 연산의 경우 반드시 값을 리턴해야 만 합니다.


또한 함수 내부에서 '읽기' 만 수행되고 값이 바뀌지 않는 인자들에 대해서는 const 키워드를 붙여주는 것이 바람직합니다. operator+ 의 경우, c 의 값을 읽기만 하지 c 의 값에 어떠한 변화도 주지 않으므로 const Complex& 타입으로 인자를 받았습니다. 

```warning

인자의 값이 함수 내부에서 바뀌지 않는 다고 확신할 때에는 반드시 const 키워드를 붙여주시기 바랍니다.
```






 대입 연산자 함수




아마 Complex 클래스를 구현하면서 한 가지 빠뜨렸다고 생각하고 있는 것이 있을 것입니다. 바로, 대입 연산자  (=) 이지요. 아마도, 대입 연산자야 말로 가장 먼저 구현했어야 할 연산자 함수가 아니였을까 합니다. 

```cpp

Complex& operator=(constComplex& c);
```



기본적으로 대입 연산자 함수는, 기존의 사칙연산 연산자 함수와는 다르게, Complex& 타입을 리턴합니다. 사실 대입 연산자 자체의 의미를 생각해 볼 때 리턴값을 void 로 해도 무방하지만, 프로그래머들은 종종 if((i = x) < y) 와 같은 문장을 사용하기 때문에 리턴값을 주는 것이 인터페이스 차원에서 더 낫다고 생각합니다. 


이 때 Complex 타입을 리턴하지 않고 굳이 Complex& 타입을 리턴하냐면, 대입 연산 이후에 이 값을 가지고 다른 연산을 수행하지는 않기 때문입니다. 예를 들어서 (i = 3) + 4 와 같은 명령을 내리지는 않기 때문이지요. 그렇기에 값에 의한 복사가 발생하는 것 보다는 레퍼런스를 리턴하는 것이 더 올바른 판단이라고 봅니다. 


이와 같은 사실을 바탕으로 operator= 함수를 완성시켜 보면 아래와 같습니다.

```cpp

Complex& Complex::operator=(constComplex &c)

{
real = c.real; img = c.img;
return *this;
}
```



그럼 제대로 작동하는지 확인해보면

```cpp

#include <iostream>
using namespace std;


class Complex
{
private:
double real, img;


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const Complex& c) { real = c.real, img = c.img;}


Complex operator+(const Complex& c);
Complex operator-(const Complex& c);
Complex operator*(const Complex& c);
Complex operator/(const Complex& c);


Complex& operator=(const Complex& c);
void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};


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
Complex& Complex::operator=(const Complex &c)
{
real = c.real; img = c.img;
return *this;
}


int main()
{
Complex a(1.0, 2.0);
Complex b(3.0, -2.0);
Complex c(0.0, 0.0);
c = a * b + a/b + a + b;
c.println();
}
```



성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F2648ED34520D12320A734A)



와 같이 잘 작동함을 알 수 있습니다. 


한 가지 재미있는 사실은 굳이 operator= 를 만들지 않더라도, 위 소스를 컴파일 하면 잘 작동한다는 점입니다. 이는 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator)를 지원하고 있기 때문인데, 이전에 복사 생성자를 다룰 때 디폴트 복사 생성자가 있었던 것과 일맥상통합니다. 


디폴트 복사 생성자와 마찬가지로 디폴트 대입 연산자 역시 얕은 복사를 수행합니다. 따라서, 깊은 복사가 필요한 클래스의 경우 (예를 들어, 클래스 내부적으로 동적으로 할당되는 메모리를 관리하는 포인터가 있다던지) 대입 연산자 함수를 꼭 만들어주어야 할 필요가 있습니다. 


여담이지만, 이제 여러분은 다음 두 문장의 차이를 완벽히 이해 하실 수 있을 것이라 믿습니다.

```cpp

Some_Class a = b;  // ①
```



와

```cpp

Some_Class a; // ②
a = b;
```



말이지요. 이전에 이에 대해서 이야기 하였을 때 연산자 오버로딩을 배우지 못하였기 때문에 대충 두루뭉실하게 넘어갔지만 이제는 제대로 이해할 수 있습니다. ① 의 경우, 아예 a 의 '복사 생성자' 가 호출되는 것이고, ② 의 경우 a 의 그냥 기본 생성자가 호출 된 다음, 다음 문장에서 대입 연산자 함수가 실행되는 것입니다. 위 두 문장은 비록 비슷해 보이기는 해도 아예 다른 것이지요. 


마찬가지 이유로 대입 사칙연산 함수들인, +=, -= 등을 구현할 수 있습니다. 일단 = 와 마찬가지로 아래와 같이 Complex& 를 리턴하고

```cpp

Complex& operator+=(constComplex& c);
Complex& operator-=(constComplex& c);
Complex& operator*=(constComplex& c);

Complex& operator/=(constComplex& c);
```



그 내부 구현은 간단히 미리 만들어 놓은 operator+, operator- 등을 이용해서 처리하면 됩니다.

```cpp

Complex& Complex::operator+=(constComplex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(constComplex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(constComplex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(constComplex& c)
{
(*this) = (*this) / c;return *this;
}
```



와 같이 말이지요. 전체 소스를 살펴보자면;

```cpp

#include <iostream>
using namespace std;


class Complex
{
private:
double real, img;


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const Complex& c) { real = c.real, img = c.img;}

Complex operator+(constComplex& c);Complex operator-(constComplex& c);Complex operator*(constComplex& c);Complex operator/(constComplex& c);
Complex& operator+=(const Complex& c);Complex& operator-=(const Complex& c);Complex& operator*=(const Complex& c);Complex& operator/=(const Complex& c);


void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};


Complex Complex::operator+(constComplex& c)
{
Complex temp(real + c.real, img + c.img);
return temp;
}
Complex Complex::operator-(constComplex& c)
{
Complex temp(real - c.real, img - c.img);
return temp;
}
Complex Complex::operator*(constComplex& c)
{
Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);
return temp;
}
Complex Complex::operator/(constComplex& c)
{
Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img)
, (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );
return temp;
}
Complex& Complex::operator+=(const Complex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
(*this) = (*this) / c;return *this;
}
int main()
{
Complex a(1.0, 2.0);
Complex b(3.0, -2.0);
a += b;
a.println();
b.println();
}
```



성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F26065741520D14F3047A36)



와 같이 잘 출력됨을 알 수 있습니다. a 의 값만 바뀐 채 b 에는 아무런 영향이 없지요. 



참고로, 연산자 오버로딩을 사용하게 된다면 a+= b 와 a = a + b; 가 같다고 보장되지 않는다는 점을 명심해야 합니다. 컴파일러는 operator+ 와 operator= 를 정의해놓았다고 해서 a+=b 를 자동으로 a = a + b; 로 바꾸어 주지 않습니다. 반드시 operator+= 를 따로 만들어야지 += 를 사용할 수 있게 됩니다. 이와 같은 사실은 ++ 을 += 1 로 바꾸어 주지 않는다던지, -- 를 -= 1 로 바꾸어 주지 않는 다는 사실과 일맥상통합니다. 즉, 연산자 오버로딩을 하게 된다면 여러분이 생각하는 모든 연산자들에 대해 개별적인 정의가 필요합니다.





 문자열로 Complex 수와 덧셈하기### 


이번에는 operator+ 를 개량해서, 꼭 Complex 수를 더하는 것이 아니라, 문자열로도 덧셈을 할 수 있도록 operator+ 함수를 만드려 보려고 합니다. 다시 말해서, 

```cpp

y = z + "3+i2"; 
```



이런 문장을 사용하였을 경우 성공적으로 처리할 수 있게 된다는 의미이지요. 참고로, 문자열로 복소수를 어떻게 표현해야 할 지에 대해서는 모종의 약속이 필요한데, 우리 Complex 클래스의 경우 다음과 같은 꼴로 표현하도록 정합시다.

```info

(부호) (실수부) (부호) i (허수부)
```



예를 들어서 "2+i3" 은 Complex 수 (2 , 3) 을 나타낸 것이라 생각합니다. 또한, "2-i3" 은 (2, -3 ) 을 나타낸 것이 되겠지요. 만일 실수부나 허수부의 값이 0 이라면 굳이 안써주어도 되는데, 예를 들어서 그냥 "3" 은 (3 , 0) 을 나타내며, "-5i" 는 (0, -5) 를 나타내게 됩니다. 참고로 우리의 실수부와 허수부는 double 변수 이기 때문에 문자열로 입력 받을 때 단순히 정수 부분만 받는 것이 아니라 소수점 아래 부분도 처리해 주어야만 할 것입니다. 이를 바탕으로 operator+ 함수를 만들어 보도록 합시다. 

```cpp

Complex Complex::operator+(const char* str)
{
// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)


int begin = 0, end = strlen(str);
double str_img = 0.0, str_real = 0.0; 

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
str_real = get_number(str, begin, end - 1);

Complex temp(str_real, str_img);
return (*this) + temp;
}


// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
str_real = get_number(str, begin, pos_i - 1);
str_img = get_number(str, pos_i + 1, end - 1);


if(pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;


Complex temp(str_real, str_img);
return (*this) + temp;
}
```




일단 문자열을 덧셈의 피연산자로 사용하게 되므로, operator+ 의 인자는 Complex & 가 아니라 const char * 가 됩니다. 저의 경우, 이제 입력 받은 '문자열 복소수' 를 분석하기 위해서 가장 중요한 'i' 의 위치를 먼저 찾도록 하였습니다. 왜냐하면 이 'i' 를 기준으로 복소수의 실수부와 허수부가 나뉘어지기 때문이지요. 

```cpp

// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
int pos_i = -1;
for(int i = 0; i != end; i ++) {
if(str[i] == 'i') {
pos_i = i;
break;
}
}
```



따라서 위와 같이 pos_i 에 str 의 'i' 의 위치를 찾도록 하였습니다. 물론, 입력 받은 문자열에 반드시 'i' 가 있어야만 하는 것은 아닙니다. 왜냐하면 이전에도 말했듯이 복소수가 그냥 실수 라면 굳이 허수 부분을 표현하지 않을 수 있기 때문입니다. 따라서, 아래와 같이 i 가 없을 경우 간단히 따로 처리할 수 있습니다. 

```cpp

// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
if(pos_i == -1) {
str_real = get_number(str, begin, end - 1);

Complex temp(str_real, str_img);
return (*this) + temp;
}
```



참고로 우리가 사용하는 get_number 함수는 특정 문자열에서 수 부분을 double 값으로 반환하는 함수 입니다. 사실 C 언어 표준 라이브러리인 stdlib.h 에서 atof 라는 함수를 제공해서 우리의 get_number 함수와 정확히 똑같은 작업을 하는 함수를 사용할 수 있지만, 한 번 이 함수를 직접 만들어보는 것도 나쁘지 않을 것이라 생각해서 Complex 클래스 내의 멤버 함수로 포함시켰습니다. 다만, 이 get_number 의 경우 operator+ 함수의 내부적으로 사용되는 함수이지, 굳이 인터페이스로 제공할 필요는 없기 때문에 private 으로 설정하였습니다. 

```cpp

// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
str_real = get_number(str, begin, pos_i - 1);
str_img = get_number(str, pos_i + 1, end - 1);
```

자 이제, 다시 operator+ 함수를 돌아와서 살펴보자면 만일 i 가 포함되어 있다면 i 를 기준으로 왼쪽의 실수부와 오른쪽의 허수부로 나뉘게 됩니다. 이 때 str_real 은 get_number 함수를 이용해서 정확히 실수 값을 얻을 수 있습니다. (왜냐하면 맨 뒤에 숫자 뒤에 딸려오는 문자들은 get_number 에서 알아서 무시된다) 하지만 str_img 의 경우 i 앞의 부호 부분이 잘리기 때문에 정확한 실수 값을 얻을 수 없기 때문에 따로
```cpp
if(pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;
```

로 해서 str_img 의 정확한 부호를 처리하도록 하였습니다. 
```cpp
double Complex::get_number(const char *str, int from, int to){bool minus = false; if(from > to) return 0;
if(str[from] == '-') minus = true;if(str[from] == '-' || str[from] == '+') from ++;
double num = 0.0;double decimal = 1.0;
bool integer_part = true;for(int i = from; i <= to; i ++) {if(isdigit(str[i]) && integer_part) {num *= 10.0;num += (str[i] - '0');}else if(str[i] == '.') integer_part = false;else if(isdigit(str[i]) && !integer_part) {decimal /= 10.0; num += ((str[i] - '0') * decimal);}else break; // 그 이외의 이상한 문자들이 올 경우}
if(minus) num *= -1.0;
return num;}
```

저의 경우 get_number 함수를 위와 같이 구현하였습니다. 만일 from 이 to 보다 크다면 당연히, 올바르지 않는 입력으로 0 을 반환하도록 하였습니다. (사실 이렇게 모든 예외적인 경우를 세세하게 처리하는 일도 매우 중요합니다) 그리고, 특별히 부호를 처리하기 위해서 minus 라는 bool 변수를 도입해서 마지막에 minus 가 true 일 경우에 부호를 음수로 바꾸도록 하였습니다. 
```cpp
if(str[from] == '-' || str[from] == '+') from ++;
```

일단 부호 부분은 위와 같이 처리해서 부호 부분 바로 다음 부터 처리하도록 합니다.
```cpp
for(int i = from; i <= to; i ++) {if(isdigit(str[i]) && integer_part) {num *= 10.0;num += (str[i] - '0');}else if(str[i] == '.') integer_part = false;else if(isdigit(str[i]) && !integer_part) {decimal /= 10.0; num += ((str[i] - '0') * decimal);}else break; // 그 이외의 이상한 문자들이 올 경우}
```

double 형 변수로 입력받은 문자열을 처리할 때 유의할 점은, for 문에서 맨 앞자리 수 부터 읽는 다는 점입니다. 예를 들어서 123.456 이라면 1,2,3... 순으로 값을 입력 받게 되는데 이 때문에 소수점 앞 부분과 뒷 부분의 처리를 다르게 해야만 합니다. 소수점 앞 부분을 입력받을 때 (즉, integer_part 변수가 true 일 때) 에는 간단히 
```cpp
num *= 10.0;num += (str[i] - '0');
```

를 해서 문자열 부분의 값을 읽어들일 수 있습니다. 즉 1 -> 12 -> 123 이 되겠지요. 참고로 str[i] - '0' 을 하는 기법은 상당히 자주 쓰이는데, ASCII 테이블 상에서 0 부터 9 까지 숫자들이 크기 순으로 연속적으로 배열되어 있기 때문에 단순히 '0' 을 빼버리면 그 숫자에 해당하는 실제 정수 값을 구할 수 있게 됩니다.
```cpp
else if(isdigit(str[i]) && !integer_part) {decimal /= 10.0; num += ((str[i] - '0') * decimal);}
```

그리고 이번에는 소수점 뒷 부분을 읽어들일 차례 입니다. 소수점 뒷 부분의 경우 decimal 이란 새로운 변수를 도입하여서, 현재 읽어들이는 위치에 해당하는 값을 구할 수 있게 되는데요, 예를 들어 123.456 에서 4 의 경우 decimal 은 0.1, 5 는 0.01 등이 되겠지요. 이와 같은 방식으로 해서 우리는 원래의 문자열을 double 값으로 바꿀 수 있게 됩니다. 

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


Complex operator+(constComplex& c);
Complex operator+(const char *str);


Complex operator-(constComplex& c);
Complex operator*(constComplex& c);
Complex operator/(constComplex& c);


Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);


Complex& operator=(const Complex &c);


void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};


Complex Complex::operator+(constComplex& c)
{
Complex temp(real + c.real, img + c.img);
return temp;
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
Complex Complex::operator+(const char* str)
{
// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)


int begin = 0, end = strlen(str);
double str_img = 0.0, str_real = 0.0; 

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
str_real = get_number(str, begin, end - 1);

Complex temp(str_real, str_img);
return (*this) + temp;
}


// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
str_real = get_number(str, begin, pos_i - 1);
str_img = get_number(str, pos_i + 1, end - 1);


if(pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;


Complex temp(str_real, str_img);
return (*this) + temp;
}
Complex Complex::operator-(constComplex& c)
{
Complex temp(real - c.real, img - c.img);
return temp;
}
Complex Complex::operator*(constComplex& c)
{
Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);
return temp;
}
Complex Complex::operator/(constComplex& c)
{
Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img)
, (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );
return temp;
}
Complex& Complex::operator+=(const Complex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
(*this) = (*this) / c;return *this;
}
Complex& Complex::operator=(const Complex &c)
{
real = c.real; img = c.img;
return *this;
}


int main()
{
Complex a(0, 0);
a = a + "-1.1 + i3.923";
a.println();
}
```



성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F2579DD3B521706FF295ABE)



와 같이 잘 실행되는 것을 알 수 있습니다. 



그런데, + 뿐만이 아니라, -, * 등의 모든 연산자들에 대해 이 기능을 지원하기 위해서 각각의 코드를 반복적으로 쓰는 것은 매우 귀찮은 일이 아닐 수 없습니다. 이와 같은 완전 불편한 작업을 막기 위해 아예 const char * 로 오버로딩되는 Complex 생성자를 추가하는 것도 나쁘지 않다고 생각 됩니다. 


그렇게 된다면 길고 복잡했었던 operator+ (const char * str) 부분을 다음과 같이 간단하게 줄일 수 있기 때문이지요. 

```cpp

Complex Complex::operator+(const char* str)
{
Complex temp(str);
return (*this) + temp;
}
```



그렇다면, 간단히 Complex(const char* str) 을 만들어본다면 아래와 같습니다.

```cpp

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
```



그렇게 된다면, 나머지 함수들도, 

```cpp

Complex Complex::operator-(const char* str)
{
Complex temp(str);
return (*this) - temp;
}
Complex Complex::operator*(const char* str)
{
Complex temp(str);
return (*this) * temp;
}
Complex Complex::operator/(const char* str)
{
Complex temp(str);
return (*this) / temp;
}
```



로 간단하게 구현할 수 있게 됩니다.

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


Complex operator+(constComplex& c);
Complex operator-(constComplex& c);
Complex operator*(constComplex& c);
Complex operator/(constComplex& c);


Complex operator+(const char *str);
Complex operator-(const char *str);
Complex operator*(const char *str);
Complex operator/(const char *str);


Complex& operator+=(constComplex& c);
Complex& operator-=(constComplex& c);
Complex& operator*=(constComplex& c);
Complex& operator/=(constComplex& c);


Complex& operator=(const Complex &c);


void println() { cout << "( " << real << " , " << img << " ) " << endl;}
};
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
Complex Complex::operator+(constComplex& c)
{
Complex temp(real + c.real, img + c.img);
return temp;
}
Complex Complex::operator-(constComplex& c)
{
Complex temp(real - c.real, img - c.img);
return temp;
}
Complex Complex::operator*(constComplex& c)
{
Complex temp(real* c.real - img * c.img, real * c.img + img * c.real);
return temp;
}
Complex Complex::operator/(constComplex& c)
{
Complex temp((real * c.real + img * c.img)/(c.real * c.real + c.img * c.img)
, (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img) );
return temp;
}
Complex Complex::operator+(const char* str)
{
Complex temp(str);
return (*this) + temp;
}
Complex Complex::operator-(const char* str)
{
Complex temp(str);
return (*this) - temp;
}
Complex Complex::operator*(const char* str)
{
Complex temp(str);
return (*this) * temp;
}
Complex Complex::operator/(const char* str)
{
Complex temp(str);
return (*this) / temp;
}
Complex& Complex::operator+=(constComplex& c)
{
(*this) = (*this) + c; return *this;
}
Complex& Complex::operator-=(constComplex& c)
{
(*this) = (*this) - c;return *this;
}
Complex& Complex::operator*=(constComplex& c)
{
(*this) = (*this) * c;return *this;
}
Complex& Complex::operator/=(constComplex& c)
{
(*this) = (*this) / c;return *this;
}
Complex& Complex::operator=(constComplex &c)
{
real = c.real; img = c.img;
return *this;
}


int main()
{
Complex a(0, 0);
a = a + "-1.1 + i3.923";
a.println();
a = a - "1.2 -i1.823";
a.println();
a = a * "2.3+i22";
a.println();
a = a / "-12+i55";
a.println();
}
```



성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F2746124A5217107A221C06)



와 같이 제대로 계산됨을 알 수 있습니다. 



한 가지 재미 있는 점은, Complex(const char *str) 생성자만 남겨놓고, operator+(const char *str) 계열들을 모두 지워보시고 컴파일 해보세요. 다시 말해서;

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
a = a + "-1.1 + i3.923";
a.println();
a = a - "1.2 -i1.823";
a.println();
a = a * "2.3+i22";
a.println();
a = a / "-12+i55";
a.println();
}
```



성공적으로 컴파일 하였다면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F2746124A5217107A221C06)



놀랍게도 정확히 동일하게 나옵니다. 아니 이게 뭔가요. 고생 고생을 해서 


```cpp

Complex operator+(const char *str);
Complex operator-(const char *str);
Complex operator*(const char *str);
Complex operator/(const char *str);
```



들을 모두 만들어 주었더니, 결과적으로 생성자 하나만 만들면 충분하다는 것이였나요? 놀랍게도, 우리의 컴파일러는 매우 똑똑하기 때문에 이와 같은 일이 가능합니다. 우리가 

```cpp

a = a + "-1.1 + i3.923";
```



와 같은 문장을 사용하였을 때, 앞에서 이야기 해왔듯이 컴파일러가 위 문장을

```cpp

a = a.operator+("-1.1 + i3.923");
```



로 바꿔줍니다. 하지만, 우리에게는 operator+(const char *str) 이 없고, operator+(const Complex& c) 밖에 없기 때문에 직접적으로 오버로딩 되지는 않습니다. 그렇지만, 컴파일러는 매우 똑똑하기 때문에 그 다음 순위로 오버로딩 될 수 있는 함수들이 있는지 없는 지 확인해봅니다. 그런데 놀랍게도, 우리에게는 const char * 에서 Complex 를 생성할 수 있는 생성자 

```cpp

Complex(const char* str);
```



가 있기 때문에 컴파일러는 문자열 리터럴로 부터 const Complex 타입의 객체를 새롭게 생성할 수 있게 된다는 것입니다. 즉, 위 문장은 은 다음과 같이 변환됩니다.

```cpp

a = a.operator+(Complex("-1.1 + i3.923"));
```



그럼 이제 const Complex 에 인자로 전달할 수 있게 되어서 제대로 프로그램이 작동을 하게 되지요. 여기서 한 가지 짚고 넘어가야 할 점은, 만일 우리가 operator+ 함수의 인자가 const Complex& c 가 아니라 그냥 Complex& c 로 받도록 하였다면 위와 같은 변환은 이루어지지 않습니다. 왜냐하면 "-1.1 + i3.923" 자체가 문자열 리터럴 이므로, 이를 바탕으로 생성된 객체 역시 상수 여야 하기 때문입니다. 따라서 여러 모로 함수 인자의 값을 변형하지 않는다고 확신이 들면 무조건 const 인자로 받도록 하는 것이 좋습니다. 


이러한 방식으로 여러분의 Complex 클래스의 문자열을 이용해서 복소수 덧셈을 수행할 수 있는 훌륭한 기능을 추가하였습니다. 하지만 문제는 다음과 같은 문장은 실행이 될 까요?

```cpp

a = "-1.1 + i3.923" + a;
```



사실 이 문장이나, 원래의 

```cpp

a = a + "-1.1 + i3.923";
```



문장이나 정확히 동일한 식입니다. 왜냐하면 + 연산자는 교환 법칙이 성립해야만 하기 때문이죠. 하지만 여러분도 이미 짐작하셨겠지만 전자의 경우에는 성공적으로 컴파일 되지 않습니다. 왜냐하면 a + "-1.1+i3.923" 의 경우 이 문장이 a.operator+("-1.1+i3.923") 으로 변환되어서 정확히 수행될 수 있지만 "-1.1 + i3.923" + a 의 경우에는 이 같은 변환이 불가능 하기 때문입니다. 


그렇다면 이러한 문제를 어떻게 해결할 수 있을까요?


이에 대해서는 다음 시간에 다루어 보도록 하겠습니다.


 생각해보기


1. 그렇다면 Complex 클래스의 연산자 오버로딩을 수행하면서 쌓은 지식을 바탕으로 MyString 함수를 완전하게 만들어봅시다. 즉, 강좌 서두에서 지적한 사항들을 모두 구현하시면 됩니다. (난이도 : 下)





```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면 꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요. 

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <5 - 1. 내가 만든 연산자 - 연산자 오버로딩>>> 입니다. 이번 강좌의 모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요 

다음 강좌 보러가기

```



공감sns신고저작자표시'C++' 카테고리의 다른 글씹어먹는 C++ - <5 - 3. 연산자 오버로딩 프로젝트 - N 차원 배열>(24)
2013.09.04씹어먹는 C++ - <5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩>(5)
2013.08.29씹어먹는 C++ - <5 - 1. 내가 만든 연산자 - 연산자 오버로딩>(7)
2013.08.25씹어먹는 C++ - <4 - 5. 내가 만드는 String 클래스>(29)
2013.08.15씹어먹는 C++ - <4 - 4. 스타크래프트를 만들자 ② (const, static)>(17)
2013.05.26씹어먹는 C++ 토막글 ② - 람다(lambda) 함수(12)
2013.01.08


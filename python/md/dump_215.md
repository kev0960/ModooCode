 itguru Top itguru Top


이번 강좌에서는
* ifstream 을 이용한 파일 입력
* ofstream 을 이용한 파일 출력
* 문자열 스트림 (stringstream) 을 이용한 간편한 문자열 간의 변환
에 대해서 알아봅니다.




안녕하세요 여러분! 지난 강좌에서 C++ 에서 표준 스트림과의 입출력에 대해 간단히 다루어보았습니다. 이번에는 이를 이용해서 파일 스트림과의 입출력을 다루어 보도록 하겠습니다. 사실, 파일 입출력은 표준 스트림에서 입출력 하는 것과 크게 다른 점은 없습니다. 다만, 스트림이 화면 혹은 키보드에서 파일로 바뀌었을 뿐이지요.



 fstream




파일 스트림은 기본적인 istream 이나 ostream 클래스 보다 더 지원하는 기능이 더 많기 때문에 이를 상속 받아서 작성되었으며, 각각을 상속 받은 것이 ifstream 과 ofstream 입니다. 이들 클래스를 모두 포함하는 라이브러리로 fstream 을 사용하면 됩니다.

```cpp

// 파일에서의 입출력
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt");
string s;


if (in.is_open()) {
in >> s;
cout << "입력 받은 문자열 :: " << s << endl;
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}
return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 나옵니다. 참고로 test.txt 파일에는 다음과 같이 써 있었습니다.





참고로 test.txt 를 읽어드리는 경로는, 비주얼 스튜디오 상에서 실행하였을 때 소스파일이 들어있는 위치와 동일합니다.







만일 test.txt 를 지워버려서 파일을 찾을 수 없다면 is_open 이 false 를 반환해서





와 같이 파일을 찾을 수 없다고 표시 됩니다.


아마 소스가 매우 간단하므로 그냥 봐도 이해 하실 수 있으리라 생각합니다. 기존의 콘솔에서 사용자 입력을 받는 것과 별반 다를 게 없어 보입니다. 단 한가지 빼고요.

```cpp

// 파일 읽기 준비
ifstream in("test.txt");
```





기존에 cout 이나 cin 을 사용했을 때에는 이미 표준 입출력에 연동이 되어 있는 상황이었지만, 파일 입출력에 경우 어느 파일에 입출력을 해야 할 지 지정 해야 하는데, 이를 ifstream 객체에 생성자에 연동하고자 하는 파일의 경로 ("C:\\a\\b\\c.txt" 와 같이) 를 전달하면 됩니다. 위 경우 편의상 경로를 저렇게 썻지만 (이 경우 실행 파일과 같은 경로에 있는 파일을 찾게 됩니다. 다만 비주얼 스튜디오 상에서 실행할 경우에는 소스 파일과 같은 경로에 있는 것을 찾습니다)


위와 같이 생성자에 파일 경로를 지정하면, 해당하는 파일을 찾고 열게 됩니다. 만일 파일이 존재하지 않는다면 파일을 열 수 없습니다. 따라서 파일이 열렸는지의 유무는 다음과 같이 확인할 수 있습니다.

```cpp

if (in.is_open()) {
```



is_open 은 기존의 istream 에는 없고 ifstream 에서 상속 받으면서 추가된 함수 입니다. 파일이 열렸는지의 유무를 리턴합니다. 만일 해당 경로에 있는 파일이 존재하지 않는다면 false 를 리턴하겠지요.

```cpp

in >> s;
```



마지막으로 마치 cin 을 사용 하는 것 처럼 in 객체를 이용해서 파일로 부터 읽을 수 있습니다. (cin 에서 >> 를 읽을 때 공백 문자가 나올 까지 읽었던 것처럼 여기도 동일합니다)


여기서 한 가지 흥미로운 점이 있습니다. C 언어에서 기억을 되돌려 보자면 파일 입출력을 한 후에 꼭 fclose 를 해주어야 했었습니다. 그런데 여기서하는 신기하게도 그러한 작업을 하지 않습니다. 왜 그렇냐면, 이미 ifstream 객체의 소멸자에서 자동적으로 close 를 해주기 때문입니다.


다만 close 를 직접 해야 되는 경우도 있습니다.

```cpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt");
string s;


if (in.is_open()) {
in >> s;
cout << "입력 받은 문자열 :: " << s << endl;
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


in.close();
in.open("other.txt");


if (in.is_open()) {
in >> s;
cout << "입력 받은 문자열 :: " << s << endl;
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 나옵니다.



```cpp

in.close();
in.open("other.txt");
```



위 처럼 새로운 파일에서 같은 객체가 입력을 받기 위해서는 기존 파일 스트림과의 연결을 종료하고, 새로운 파일과 연결을 시켜주면 됩니다. 기존 파일과의 스트림 종료는 close 함수가, 새로운 파일과의 연결은 open 함수가 수행하고 있습니다. open 함수가 있기에 굳이 ifstream 객체 생성자에서 파일 경로를 바로 지정해줄 필요는 없고, 나중에 open 으로 원하는 파일을 열어도 상관 없습니다.

```cpp

// 이진수로 읽기
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt", ios::binary);
string s;


int x;
if (in.is_open()) {
in.read((char*)(&x), 4);
cout << hex << x << endl;
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


return 0;
}
```



성공적으로 컴파일 하였다면







와 같이 나옵니다.


실제로 Hex 에디터로 test.txt 의 내용을 살펴보아도





와 같이 첫 부분이 일치하는 것으로 나타납니다.


"어 다른데요?"


라고 생각하시는 분들은 엔디안을 간과한 것인데, 우리가 쓰는 CPU 의 경우 리틀 엔디안이라 해서, 높은 주소값에 높은 자리수가 온다고 생각하면 됩니다, 따라서 각각의 바이트가 EF / BB / BF / EC 가 거꾸로 EC / BF / BB / EF 이렇게 int 변수에 기록이 된 것입니다. (이에 대한 내용은 C 강좌에서도 다루었습니다)

```cpp

ifstream in("test.txt", ios::binary);
```



일단 위와 같이 ifstream 객체를 생성할 때 생성자에 옵션으로 binary 형태로 받겠다고 명시할 수 있습니다. 이 말은 문제열 데이터를 받는게 아니라 그냥 이진 그대로의 값을 받아내겠다는 의미 입니다. 만일 아무것도 명시 하지 않는다면 위에서 보았던 것 처럼 문자열 형태로 데이터를 받습니다.


이 binary 는 단순한 숫자로 ios 에 정의되어 있습니다. binary 말고도 설정할 수 있는 여러가지 옵션들이 있는데. 이들을 OR 해서 여러가지 옵션을 조합할 수 있습니다. (http://itguru.tistory.com/129 에서의 비트연산 활용 부분을 생각하시면 됩니다)

```cpp

in.read((char*)(&x), 4);
```



read 함수는 말 그대로, 4 바이트의 내용을 읽으라는 의미로, 첫 번째 인자에 해당하는 버퍼를 전달해주어야 합니다. 우리의 경우 int 변수를 마치 4 바이트 짜리 char 배열이라 생각하게 해서 이를 전달하였습니다. 두 번째 인자로 반드시 몇 바이트를 읽을 지 전달해야 합니다.

```cpp

    char x[10];
in.read(x, 10);
```



실제로 예시 코드 처럼 int 공간에 저장하는 경우는 없고, 위 처럼 그냥 char 배열에 크기를 지정해서 읽어들이면 됩니다.



```cpp

cout << hex << x << endl;
```



참고로 cout 에서 사용한 hex 역시 지난 강좌에서 cin 에서 사용한 hex 와 비슷한 부류로 16 진수로 정수 데이터를 표시해줍니다.



 파일 전체 읽기




```cpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt");
string s;


if (in.is_open()) {
// 위치 지정자를 파일 끝으로 옮긴다.
in.seekg(0, ios::end);


// 그리고 그 위치를 읽는다. (파일의 크기)
int size = in.tellg();


// 그 크기의 문자열을 할당한다.
s.resize(size);


// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
in.seekg(0, ios::beg);


// 파일 전체 내용을 읽어서 문자열에 저장한다.
in.read(&s[0], size);
cout << s << endl;
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 파일 전체의 내용이 잘 나오고 있습니다.



```cpp

// 위치 지정자를 파일 끝으로 옮긴다.
in.seekg(0, ios::end);
```



C 언어에서 fseek 과 같은 함수로, 파일 위치 지정자를 사용자의 입맛에 맞게 이리저리 움직일 수 있습니다. 두 번째 인자는, 파일 내 위치를 의미하고, 첫 번째 인자는 그 위치로 부터 얼마나 만큼 떨어져 있느냐를 의미합니다. 우리의 경우 위치 지정자를 파일의 끝에서 0 만큼 떨어진 것, 즉 파일의 끝으로 이동시켰습니다.

```cpp

// 그리고 그 위치를 읽는다. (파일의 크기)
int size = in.tellg();
```



tellg 함수는 위치 지정자의 위치 (시작 지점으로 부터의) 를 반환합니다. 현재 우리가 위치 지정자를 파일 끝으로 이동 시켜 놓았기 때문에 tellg 함수는 파일의 크기 (바이트 단위)로 반환하겠지요.그리고 문자열에 그 만큼의 크기를 할당해줍니다.



```cpp

// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
in.seekg(0, ios::beg);
```





이제 파일을 읽어야할 텐데, 파일 위치 지정자를 끝으로 옮겨 놓았기 때문에 읽기 위해서는 다시 처음으로 옮겨주어야 합니다. 옮기지 않을 경우 위치 지정자가 파일 끝에 있으므로 아무것도 읽지 못할 것입니다.

```cpp

// 파일 전체 내용을 읽어서 문자열에 저장한다.
in.read(&s[0], size);
```



마지막으로 파일 전체에 내용을 문자열에 저장하면 됩니다.

```cpp

// getline 으로 읽어들이기
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt");
char buf[100];


if (in.is_open()) {
while (!in.eof()) {
// 한 줄 씩 최대 100 자 까지 읽어들인다.
in.getline(buf, 100);
cout << buf << endl;
}
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 나옵니다.



getline 함수는 파일에서 개행문자 (\n) 이 나올 때 가지 최대 지정한 크기 만큼 읽게됩니다. 만일 파일 끝에 도달하게 된다면 eofbit 가 켜지면서

```cpp

in.getline(buf, 100);
```



위 경우 buf 에 최대 100 글자 까지 입력 받습니다. 물론 개행 문자가 나올 때 까지 입력 받는 다는 것은 디폴트 이고, 추가 인자로 지정해주면 해당 문자가 나올 때 가지 입력 받습니다. 예를 들어서

```cpp

in.getline(buf, 100, '.');
```



이런식으로 하면 마침표가 나올 때 까지 입력받게 됩니다.


한 가지 주의할 점은 getline 함수는 개행 문자 (혹은 지정한 문자) 가 나오기 전에 지정한 버퍼의 크기가 다 차게 된다면 failbit 를 키게 됩니다. 따라서 만일 버퍼의 크기를 너무 작게 만든다면 정상적으로 데이터를 받을 수 없게 됩니다. 따라서 getline 을 사용하기 전에 이와 같은 조건을 꼭 확인해야 합니다.



```cpp

// string 에 정의된 getline 사용
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 읽기 준비
ifstream in("test.txt");


string s;
if (in.is_open()) {
while (!in.eof()) {
getline(in, s);
cout << s << endl;
}
}
else {
cout << "파일을 찾을 수 없습니다!" << endl;
}


return 0;
}
```



성공적으로 컴파일 하였다면







와 같이 나옵니다.


이 getline 함수는 ifstream 에 정의되어 있는 것이 아니라, string 에 정의되어 있는 함수로, 첫 번째 인자로 istream 객체를 받고, 두 번째 인자로 입력 받은 문자열을 저장할 string 객체를 받게 됩니다.


기존에 ifstream 의 getline 을 활용할 때 보다 훨신 편리한 것이, 굳이 버퍼의 크기를 지정하지 않아도 알아서 string 의 크기를 조정해서 개행문자 혹은 파일에 끝이 나올 때 까지 입력받게 됩니다.



 파일에 쓰기


```cpp


#include <iostream>

#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 쓰기 준비
ofstream out("test.txt");


string s;
if (out.is_open()) {
out << "이걸 쓰자~~";
}


return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 test.txt 에 내용이 잘 써진 것을 알 수 있습니다.


만일 test.txt 가 존재하지 않을 경우, test.txt 를 생성한 뒤에, 생성이 성공하였다면 출력하게 됩니다. ofstream 은 열려는 파일이 존재하지 않으면 해당 파일을 생성하고 열게 됩니다. 만일, 해당 파일이 이미 존재한다면, 특별한 설정을 하지 않는다면 해당 파일 내용이 다 지워지고 새로운 내용으로 덮어 씌어지게 됩니다.

```cpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
// 파일 쓰기준비
ofstream out("test.txt", ios::app);


string s;
if (out.is_open()) {
out << "덧붙이기";
}


return 0;
}
```



성공적으로 컴파일 하였다면







와 같이 나옵니다.


out 객체를 생성할 때 옵션으로 app 을 주게 되면, 파일에 스트림을 연결할 때 기존 파일의 내용을 지우고 새로 쓰는 것이 아니라 위 사진 처럼 그 뒤에 새로운 내용을 붙여 쓰게 됩니다.


앞서 나왔던 ios::binary 와 ios::app 말고도 4개가 더 있습니다. 이들을 나열해보자면


* ios::ate : 자동으로 파일 끝에서 부터 읽기와 쓰기를 실시합니다. (즉 파일을 열 때 위치 지정자가 파일 끝을 가리키고 있게 됩니다)
* ios::trunc : 파일 스트림을 열면 기존에 있던 내용들이 모두 지워집니다. 기본적으로 ofstream 객체를 생성할 때 이와 같은 설정으로 만들어집니다.
* ios::in, ios::out : 파일에 입력을 할 지 출력을 할 지 지정하며, ifstream 과 ofstream 객체를 생성할 때 각각은 이미 설정되어 있습니다.
참고로 ios::ate 와 ios::app 은 비슷해 보이지만 차이가 있다면 ios::app 의 경우 원본 파일의 내용을 무조건 적으로 보장하지만, ate 는 위치 지정자를 그 이전으로 옮길 수 있습니다.즉 app 의 경우 파일 위치 지정자가 기존 파일의 끝이 시작점이라 생각하여 움직이며 ate 의 경우 기존 파일을 포함해서 움직입니다 (사실 ate 의 경우 사용할 일이 거의 없을 것입니다).
그렇다고 해서 ate 를 이용해서 기존에 있는 파일 데이터 한 가운데에 무언가를 끼워 넣을 수 있는 것은 아닙니다.
```cpp
// ate 와 app#include <iostream>#include <string>#include <fstream>using namespace std;
int main(){// 두 파일에는 모두 abc 라고 써 있었습니다.ofstream out("test.txt", ios::app);ofstream out2("test2.txt", ios::ate);
out.seekp(3, ios::beg);out2.seekp(3, ios::beg);
out << "추가";out2 << "추가";
return 0;}
```

성공적으로 컴파일 하였다면







app 을 사용한 경우 위와 같이 abc 바로 뒤에 '추가' 문자열에 붙어 있는 것으로 나타납니다. 비록 파일 위치 지정자를 앞에서 3 칸 떨어진 곳으로 이동하였음에도, app 모드로 읽었을 때 현재 파일은 빈 파일이라 생각되어 위치 지정자라 움직일 공간이 없기에, 실제로 위치 지정자는 움직이지 않고 출력되었습니다.





반면에 ate 를 사용한 경우 앞에서 3 칸 띄어진 곳에 '추가' 라고 문자열이 출력된 반면 기존의 abc 라는 데이터는 지워졌습니다. 즉 ate 모드로 파일을 열게 되면 비록 스트림 위치 지정자는 움직여서 3칸 뒤에 출력되기는 하였지만 기존에 써져 있던 내용은 모두 지워집니다. (ate 는 기존 파일의 내용을 보존하지 않습니다)



 ofstream 연산자 오버로딩 하기



```cpp

#include <iostream>

#include <string>
#include <fstream>
using namespace std;


class Human
{
string name;
int age;


public:
Human(const string& name, int age) : name(name), age(age) {}
string get_info() {
return "Name :: " + name + " / Age :: " + to_string(age);
}


friend ofstream& operator<<(ofstream& o, Human& h);
};


ofstream& operator<< (ofstream& o, Human& h) {
o << h.get_info();
return o;
}
int main()
{
// 파일 쓰기 준비
ofstream out("test.txt");

Human h("이재범", 60);
out << h << endl;


return 0;
}
```



성공적으로 컴파일 하였다면











와 같이 나옴을 알 수 있습니다. 이전 강좌에서 입출력 연산자 오버로딩을 한 번 해보았는데, ofstream 이라고 해서 달라지는 것은 없습니다. 단순히 ofstream 객체의 레퍼런스를 받고, 다시 이를 리턴하는 operator<< 함수를 정의해주면 됩니다.



 문자열 스트림 (stringstream)






```cpp

#include <iostream>
#include <sstream>
using namespace std;
int main()
{
istringstream ss("123");
int x;
ss >> x;


cout << "입력 받은 데이터 :: " << x << endl;

return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 나옵니다.


sstream 에는 stringstream 이 정의되어 있는데 이는 마치 문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치라고 보시면 됩니다.

```cpp

istringstream ss("123");
```



예를 들어서 우리는 위를 통해서 문자열 "123" 이 기록되어 있는 입력 스트림을 생성하였습니다. 마치 파일에 123 이라 기록해놓고 거기서 입력 받는 것과 동일하다고 생각하면 됩니다.

```cpp

int x;
ss >> x;
```



그래서 마치 파일에서 숫자를 읽어내는 것 처럼 stringstream 을 통해서 123 을 읽어낼 수 있습니다.


이를 활용하면 atoi 와 같은 함수를 사용할 필요 없이 간편하게 문자열에서 숫자로 변환하는 함수를 만들 수 있습니다.

```cpp

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


double to_number(string s)
{
istringstream ss(s);
double x;


ss >> x;
return x;
}
int main()
{
cout << "변환:: 1 + 2 = " << to_number("1") + to_number("2") << endl;

return 0;
}
```



성공적으로 컴파일 하였다면





위와 같이 간편하게 문자열을 숫자로 변환할 수 있습니다.

```cpp

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string to_str(int x)
{
ostringstream ss;
ss << x;


return ss.str();
}
int main()
{
cout << "문자열로 변환:: 1 + 2 = " << to_str(1 + 2) << endl;

return 0;
}
```



성공적으로 컴파일 하였다면





와 같이 나옵니다.


이번에는 거꾸로 데이터를 출력할 수 있는 ostringstream 이 있습니다. 위와 비슷한 방법으로 이번애는 거꾸로 숫자에서 ㅁ누자열로 바꾸는 함수를 제작할 수 있습니다.

```cpp

ostringstream ss;
ss << x;
```

위와 같이 int 변수 x 의 값을 문자열 스트림에 출력하였습니다. 이 과정에서 자동으로 숫자에서 문자열로의 변환이 있겠지요.
```cpp
return ss.str();
```

이제  str 함수로 현재 문자열 스트림에 쓰여 있는 값을 불러오기만 하면 끝납니다.

이상으로 이번 강좌를 마치도록 하겠습니다. 다음 강좌에서는 여태 까지 배운 내용들을 총 종합하여 큰 프로젝트 하나를 만들도록 하겠습니다. 다음 강좌에서 제작하기 전에, 아래 생각해보기를 통해서 먼저 여러분 스스로 구현해 보는 것도 좋을 것 같습니다.



 생각 해보기



여러분은 콘솔 용 엑셀을 만들 것입니다. 물론 진짜 엑셀 처럼 엄청 거대한 프로그램을 만들 겠다는 것은 아니고, 기본적인 것들만 구현한 엑셀 프로그램이 될 것입니다.


#1 (난이도 :中)


일단 엑셀의 셀들의 정보 (일단 단순한 string 이라고 생각합시다) 에 대한 Cell 클래스가 있고 이 Cell 객체들을 모아두는 Table 클래스가 있습니다. Table 클래스에는 2차원 배열로 Cell 객체들에 대한 정보 (참고로 Cell 객체가 생성 될 때 마다 동적으로 Cell 객체를 생성합니다.) 가 보관되어 있습니다. 또한 Table 클래스에 전체 데이터를 출력하는 print_table 함수가 가상으로 정의되어 있습니다.


여러분은 Table 클래스를 상속 받는 TextTable, CSVTable, HTMLTable 클래스를 만들어서 print_table 함수를 오버라이드 할 함수들을 제작할 것입니다. 예를 들엇 TextTable 클래스의 print_table 함수는 텍스트 형식으로, CSVTable 은 CSV 파일 형식으로 등등 만들어야 겠지요?


제가 아래 대충 프로그램의 골격을 잡아 놓았으니 여러분들은 이를 채우기만 하면 됩니다.

```cpp

class Table;
class Cell

{
Table* table; // 어느 테이블에 속해있는지
string data;
int x, y; // 테이블 에서의 위치
public:
Cell(const string& data) : data(data) {};
};
class Table
{
Cell*** data_base; // 왜 3중 포인터 인지 잘 생각해보세요!
public:
Cell();
virtual string print_table() = 0;
void reg_cell(Cell* c, int row, int col); // Cell 을 등록한다
string get_cell_string(int row, int col); // 해당 위치의 Cell 데이터를 얻는다.
~Table();
};
ostream& operator<< (ostream& o, Table& t) {
o << t.print_table();
return o;
}
class TextTable : public Table
{


};
class CSVTable : public Table
{


};
class HTMLTable : public Table
{


};
```






#2 (난이도 :最上 - 위의 문제와 이어집니다)


하지만 실제 엑셀의 경우 셀이 문자열 데이터만 들어가는 것이 아니라, 숫자나 날짜 심지어 수식 까지도 들어갈 수 있습니다. 따라서 우리는 Cell 을 상속 받는 4 개의 StringCell. NumberCell, DateCell, ExprCell 클래스들을 만들어야 합니다.


또한 Cell 클래스에 to_numeric (데이터를 숫자로 바꾼다)과 stringify (데이터를 문자열로 바꾼다) 함수들을 가상으로 정의하고, 4개의 클래스들이 이를 상속 받아서 구현할 수 있게 해야 합니다. (참고로 문자열을 숫자로 변환하면 그냥 0 이 되게 하면 됩니다)


또한 ExprCell 의 경우 간단한 수식에 대한 정보를 가지는 객체로, Cell 들 간의 연산을 사용할 수 있습니다. 에를 들어서 "A1+B2+C6-6" 와 같은 데이터가 들어 있는 ExprCell 에 to_numeric 함수를 호출하면A1, B2, C6 의 값을 더하고 (각 셀에 to_numeric 을 해서), 6 을 빼준 결과값이 나와야 합니다.


참고로 프로그래밍의 편의를 위해서 ExprCell 의 경우, 셀을 지칭하는 것은 딱 두 글자 (A1, Z9 처럼) 로 하고, 숫자는 오직 한 자리 수 정수, 그리고 가능한 연산자는 +, -, *, / 로 하겠습니다.


아마도 여태 까지 강좌에서 한 프로그래밍 중에 가장 도전적인 것이 아닌가 싶습니다. 참고로 위를 구현하기 위해서 여러가지 자료형이 필요할 텐데 (있으면 편리합니다!), 대표적으로 벡터와 스택이 있습니다. 벡터는 가변 길의 배열로, 배열 처럼 사용하면서 사용자가 임의의 위치에 자료를 넣다 뺏다 할 수 있는 구조고, 스택은 pop 과 push 밖에 없는 자료형으로, push 을 하면 새로운 데이터가 맨 위에 삽입되고, pop 을 하면 맨 위에 있는 것 부터 제거되어 나오게 됩니다. (즉 먼저 넣은것이 나중에 나오는 자료구조 입니다) 저는 이들 자료 구조를 새롭게 만들어서 사용하였습니다. 여러분들도 아마 필요하실 것입니다.


아마 여러분이 이 강좌에서 여태 까지 구현했던 프로그램 중에 가장 복잡할 것입니다. 많은 시간이 필요한 만큼 재미가 있을 테니 한 번 다음 강좌를 보기 전 까지 도전해보시기 바랍니다!


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <7 - 2. C++ 에서 파일 입출력 - ifstream. ofstream, stringstream>>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```





공감10sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++' 카테고리의 다른 글씹어먹는 C++ - <8 - 2. Excel 만들기 프로젝트 2부>(6)2016.07.19씹어먹는 C++ - <8 - 1. Excel 만들기 프로젝트 1부>(0)2016.07.18씹어먹는 C++ - <7 - 2. C++ 에서 파일 입출력 - ifstream. ofstream, stringstream>(13)2016.07.14씹어먹는 C++ - <7 - 1. C++ 에서의 입출력 (istream, ostream)>(35)2015.05.04씹어먹는 C++ - <6 - 3. 가상함수와 상속에 관련한 잡다한 내용들>(14)2014.04.13씹어먹는 C++ - <6 - 2.  가상(virtual) 함수와 다형성>(35)2014.03.31


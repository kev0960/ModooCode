----------------
title : 씹어먹는 C++ - <7 - 1. C++ 에서의 입출력 (istream, ostream)>
cat_title: 7 - 1. C++ 에서의 입출력 (istream, ostream)
next_page : 215
publish_date : 2015-05-04
--------------


이번 강좌에서는

* C++ 입출력 라이브러리에 대한 간단한 소개
* `istream` 과 `ostream` 클래스
* `>>` 연산자와 `<<` 연산자
* `streambuf` (스트림) 클래스

에 대해서 알아봅니다.


![](/img/ChewingCpplogo.png)

안녕하세요! 여러분. 정말 오래간만에 강좌를 올리는 것 같습니다. 그 동안 제가 여러가지 하는 일이 매우 많았는데, 물론 아직도 강좌 쓸 시간은 거의 없지만 없는 시간을 짜내며 좋은 강좌를 쓰기 위해서 노력 중입니다. 아무튼, 제가 자주 댓글도 못 달아 드리고 업데이트도 엄청 느리게 하지만 (결코 죽은 것이 아닙니다!!),언제나 제 블로그를 방문해주셔서 강의를 보시는 분들에게 감사의 말을 전하고 싶습니다.


쉽진 않을 것 같지만 적어도 2016년 안에는 완결하는게 목표 입니다.


이번 강좌에서는 여태 까지 우리가 크게 관심을 가지지 않았던 C++ 의 입출력 라이브러리에 대해서 알아보도록 하겠습니다. 맨날 `cout` 과 `cin` 을 쓰면서도, 정작 `cout` 과 `cin` 이 무엇인지는 한 번도 관심을 가지지 않았지요 :(

C++ 을 공부한 사람이라면 입출력 라이브러리를 한 번 쯤은 사용해 보았겠지만, 사실 정확히 어떻게 돌아가는지 이해하는 사람들은 드뭅니다. 그래서 이번 강좌를 시작으로 아마 3 개 강의에 걸쳐서 C++ 입출력 라이브러리에 대해서 자세히 알아보는 시간을 갖도록 할 것입니다.



###  C++ 입출력 라이브러리


C++ 의 입출력 라이브러리는 다음과 같은 클래스 들로 구성되어 있습니다 C++ 의 입출력 라이브러리는 다음과 같은 클래스 들로 구성되어 있습니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F2361DC4954A0CB38040ED8)

C++ 의 모든 입출력 클래스는 `ios_base` 를 기반 클래스로 하게 됩니다. `ios_base` 클래스는 많은 일은 하지 않고, 스트림의 입출력 형식 관련 데이터를 처리 합니다. 예를 들어서 실수 형을 출력할 때 정밀도를 어떤 식으로 할 것인지에 대해, 혹은 정수형을 출력 시에 10진수로 할지 16진수로 할지 등을 이 클래스에서 처리 합니다 C++ 의 모든 입출력 클래스는 `ios_base` 를 기반 클래스로 하게 됩니다. `ios_base` 클래스는 많은 일은 하지 않고, 스트림의 입출력 형식 관련 데이터를 처리 합니다. 예를 들어서 실수 형을 출력할 때 정밀도를 어떤 식으로 할 것인지에 대해, 혹은 정수형을 출력 시에 10진수로 할지 16진수로 할지 등을 이 클래스에서 처리 합니다.

그 다음으로 `ios` 클래스가 있습니다. 이 클래스에서는 실제로 스트림 버퍼를 초기화 합니다. 스트림 버퍼란, 데이터를 내보내거나 받아들이기 전에 임시로 저장하는 곳이라 볼 수 있습니다. 쉽게 설명하자면, 예를 들어서 우리가 하드디스크에서 파일을 하나 읽는다고 해봅시다. 만일 사용자가, 1 바이트 씩 읽는 다고 했을 때, 실제로 프로그램은 `1 byte` 씩 읽는 것이 아닙니다.

실제로는 한 뭉터기 (예를 들어서 512 바이트) 를 한꺼번에 읽어서 스트림 버퍼에 잠시 저장해 놓은 뒤에 사용자가 요청할 때 마다 1 바이트 씩 꺼내는 것이지요. 만일 버퍼를 다 읽는다면 다시 하드에서 512 바이트를 읽게 되는 것입니다. 이렇게 수행하는 이유는, 하드디스크에서 읽어오는 작업이 매우 느리기 때문에, 한 번 읽을 때 1 바이트 읽으면 엄청난 딜레이가 발생하게 됩니다. 이는 쓰는 작업에서도 마찬가지 입니다. 쓸 때도 우리가 1 문자를 출력 하게 되면, 하드에 바로 쓰는 것이 아니라 일단 버퍼에 보관한 후, 어느 정도 모인 뒤에 출력하게 됩니다.

`ios` 클래스에선 그 외에도, 현재 입출력 작업의 상태를 처리 합니다. 예를 들어, 파일을 읽다가 끝에 도달했는지 안했는지 확인하려면, `eof` 함수를 호출하면 됩니다. 또, 현재 입출력 작업을 잘 수행할 수 있는지 확인하려면 `good` 함수를 호출하면 됩니다.


###  istream 클래스



여태까지 `ios_base` 와 `ios` 클래스들이 입출력 작업을 위해 바탕을 깔아주는 클래스 였다면, `istream` 은 실제로 입력을 수행하는 클래스 입니다. 대표적으로 우리가 항상 사용하던 `operator>>` 가 이 `istream` 클래스에 정의되어 있는 연산자 입니다. 또, `cin` 은 `istream` 클래스의 객체 중 하나 입니다. 그렇기 때문에 우리는
```cpp-formatted
cin >> a;
```



와 같은 작업을 할 수 있었던 것이지요. 우리가, 어떤 타입에 대해서도 `cin` 을 사용할 수 있었던 이유는 (`a` 가 `char` 이냐 `int` 이냐에 상관없이) 바로 `opeartor>>` 가 그런 모든 기본 타입들에 대해서는 정의가 되어있기 때문입니다.

```cpp-formatted
istream& operator>>(bool& val);

istream& operator>>(short& val);

istream& operator>>(unsigned short& val);

istream& operator>>(int& val);

istream& operator>>(unsigned int& val);

istream& operator>>(long& val);

istream& operator>>(unsigned long& val);

istream& operator>>(long long& val);

istream& operator>>(unsigned long long& val);

istream& operator>>(float& val);

istream& operator>>(double& val);

istream& operator>>(long double& val);

istream& operator>>(void*& val);
```



그렇다고 해서, 우리가 언제나 위 타입들 빼고는 `operator>>` 로 받을 수 없는 것이 아닙니다. 실제로 `istream` 클래스의 멤버 함수로는 없지만;

```cpp-formatted
string s;

cin >> s;
```



`string` 클래스의 객체 `s` 도 `cin` 으로 입력 받을 수 있습니다. 이와 같은 일이 가능한 이유는 [이전에 연산자 오버로딩 강좌에서 배웠듯이](http://itguru.tistory.com/203), 멤버 함수를 두는 것 말고도, 외부 함수로 연산자 오버로딩을 할 수 있기 때문입니다.


이 경우에는

```cpp-formatted
istream& operator>>(istream& in, string& s)

{
  // 구현한다
}
```



와 같이 하면 되겠습니다.


`operator>>` 의 또 다른 특징으로는, 모든 공백문자 (띄어쓰기나 엔터, 탭 등)을 입력시에 무시해버린다는 점입니다. 그렇기 때문에, 만일 `cin` 을 통해서 문장을 입력 받는 다면, 첫 단어 만 입력 받고 나머지를 읽을 수 없습니다. 예제로 간단히 살펴보자면

```cpp-formatted
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  while (true) {
    cin >> s;
    cout << "word : " << s << endl;
  }
}
```




성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F2330864554A0F4663941FA)



와 같이 문장을 입력하더라도, 공백문자에 따라서 각각을 분리해서 입력받게 되는 것입니다.
위와 같이 비록 `operator>>` 가 매우 편리해보이지만, 반드시 주의해야 할 점이 있는 점이 있습니다.

```cpp-formatted
// 주의할 점
#include <iostream>
usingnamespace std;
int main() {
  int t;
  while (true) {
    cin >> t;
    cout << "입력 :: " << t << endl;
    if (t == 0) break;
  }
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F2714DC4054A0F54E1E1225)



그냥 평범하게 숫자를 잘 입력 받는 프로그램 입니다. 만일 사용자가 숫자만 꼬박 꼬박 잘 입력하면 정말 좋겠지만 문제는 그렇지 않는다는 것입니다. 프로그래머는 언제나 사용자의 기괴한 행동들에 대해서 모두 대응할 수 있어야만 합니다. 만일 사용자가, 숫자가 아니라 문자를 입력했다고 합시다. 그렇다면;


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F26385A3654A0F64C0EEDDB)



위와 같이 기괴한 결과를 보여줌을 알 수 있습니다. (참고로 저는 단순히 'c' 하나만 쳤을 뿐입니다)  왜 이런 무한 루프에 빠지는 것일까요. 그 이유는 `operator>>` 가 어떻게 이를 처리하는지 이해하면 알 수 있습니다.


앞서 `ios` 클래스에서 스트림의 상태를 관리한다고 하였습니다. 이 때, 스트림의 상태를 관리하는 플래그 (flag - 그냥 비트 1 개라 생각하면 됩니다) 는 4 개가 정의되어 있습니다. 이 4 개의 플래그들이 스트림이 현재 어떠한 상태인지에 대해서 정보를 보관한다는 뜻입니다. 이 4 개의 플래그는 각각 `goodbit, badbit, eofbit, failbit` 이렇게 4 개 종류가 있습니다. 각각의 비트들이 켜져있는지, 꺼져있는지 (즉 1 인지 0 인지에 따라)  우리는 스트림의 상태를 알 수 있게 됩니다.



각각의 비트들에 대해 간단히 설명해보자면
* `goodbit` : 스트림에 입출력 작업이 가능할 때

* `badbit`   : 스트림에 복구 불가능한 오류 발생시

* `failbit`    : 스트림에 복구 가능한 오류 발생시

* `eofbit`   :  입력 작업시에 `EOF` 도달시

위와 같은 상황 일 때 각각의 비트들이 켜지는 것입니다. 만일 위와 같이 문자를 입력할 경우 `operator>>` 가 어떤 비트를 켜게 될까요? 일단 `eofbit` 는 확실히 아닙니다. 끝에 도달한 것이 아니니까요. 그렇다면 `badbit` 일까요? `badbit` 는 스트림 상에서 복구할 수 없는 문제시 켜지는데 위 경우는 그렇게 심각한 것은 아닙니다. 그냥 현재 스트림 버퍼에 들어가 있는 'c\n' 이 문자열을 제거해버리면 되기 때문이지요. 위와 같이 타입에 맞지 않는 값을 넣어서 오류가 발생하는 경우에는 `failbit` 가 켜지게 됩니다. 그리고, 입력값을 받지 않고 리턴해버립니다.


문제는 이렇게 그냥 리턴해버리면서 버퍼에 남아 있는 'c\n' 이 문자열에는 손대지 않는다는 것입니다. 그렇기 때문에 다음에 또 읽고, 또 읽고, ... 결국 위와 같은 문제를 일으키게 됩니다.

```cpp-formatted
// 해결 방안
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  while (cin >> t) {
    cout << "입력 :: " << t << endl;
    if (t == 0) break;
  }
}
```

성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F271D064B54A0FA2911A2A5)




위와 같이 무한 루프에 빠지지 않고 제대로 처리됨을 알 수 있습니다. 어떻게 가능한 것일까요? 일단, `while` 문의 조건에 들어가 있는 저 식의 의미 부터 이해를 해봅시다.

```cpp-formatted
while (cin >> t) {
```



위 식을 보기에 앞서, `ios` 에 정의되어 있는 함수들을 살펴보자면 다음과 같은 함수가 있음을 알 수 있습니다.

```cpp-formatted
operator void*() const;
```

이 함수는 `ios` 객체를 `void*` 로 변환해줍니다. 이 때, `NULL` 포인터가 아닌 값을 리턴하는 조건이, `failbit` 와 `badbit` 가 모두 `off` 일 때 입니다. 즉, 스트림에 정상적으로 입출력 작업을 수행 할 수 있을 때 말입니다.

그럼 다시 `while` 문을 살펴보자면, 만일 우리가 '`s`' 를 입력한다면 `operator>>` 는 `cin` 객체의 `failbit` 를 켜게 됩니다. 그리고, `cin >> t` 후에 `cin` 이 리턴되는데 (`operator>>` 는 호출한 자신을 리턴!), 리턴값이 `while` 문의 조건식으로 들어가기 때문에 컴파일러는 적절한 타입 변환을 찾게 되고, 결국 `ios` 객체 -> `void*` -> `bool` 로 가는 2단 변환을 통해서`while` 문을 잘 빠져나오게 됩니다. (※ `NULL` 포인터는 `bool` 상 `false` 입니다)


위와 같이 문제를 해결할 수 있었지만, 입력을 계속 진행 할 수는 없습니다. 왜냐하면 현재 `cin` 에 `fail` 비트가 켜진 상태이므로, 플래그를 초기화해버리지 않는 한 `cin` 을 이용하여 입력 받을 수 없게 됩니다.

```cpp-formatted
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;  // 고의적으로 문자를 입력하면 failbit 가 켜진다
  cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다" << endl;
  string s;
  cin >> s;
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F2520414754A0FCFC15F20C)



그렇다면 이 문제를 어떻게 해결 할 수 있을까요?

```cpp-formatted
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  while (true) {
    cin >> t;
    cout << "입력 :: " << t << endl;
    if (cin.fail()) {
      cout << "제대로 입력해주세요" << endl;
      cin.clear();            // 플래그들을 초기화 하고
      cin.ignore(100, '\n');  // 개행문자가 나올 때 까지 무시한다
    }
    if (t == 0) break;
  }
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F264A894254A0FE1E2ADE3E)



위와 같이 잘 처리됩니다. 위 과정이 어떻게 가능한지 자세히 살펴보도록 합시다.


```cpp-formatted
if (cin.fail()) {
```



먼저 `fail` 함수는 `ios` 에 정의되어 있으며, `failbit` 가 `true` 거나 `badbit` 가 `true` 면 `true` 를 리턴합니다. 만일 숫자가 아닌 것을 입력한다면 `failbit` 가 `true` 이므로, `cin.fail()` 은 `true` 가 되어 조건문을 실행하게 됩니다.

```cpp-formatted
cin.clear();  // 플래그들을 초기화 하고

cin.ignore(100, '\n');  // 버퍼를 비워버린다
```



그리고 `clear()` 역시 `ios` 에 정의되어 있으며, 인자를 주지 않을 경우 플래그를 `goodbit` 으로 초기화 시켜 버립니다. 따라서 `fail` 상태를 지울 수 있게 되지요. 그 다음에 `ignore` 함수는 `istream` 에 정의되어 있는데, 최대 첫번째 인자 만큼 (100), 두 번째 인자가 나올 때 까지 ('\n'), 버퍼에서 무시합니다 (두 번째 인자를 포함). 

따라서, 만일 제가 *this is a very bad input* 을 입력하였다면 버퍼에는

```info
this is a very bad input\n
```



이렇게 들어가 있고, `ignore` 함수를 통해 (최대 100 자 까지) 개행문자가 나올 때 까지 무시할 수 있게 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F212B393A54A100292F4FA5)





만일 버퍼에 100자 이상을 집어 넣는다면 위와 같이 `ignore` 함수가 총 3번 호출됨을 알 수 있습니다. (버퍼에 남아 있는 문자들이 다 지워질때 까지)





###  형식 플래그(format `flag)` 와 조작자 (Manipulator)


앞서 `ios_base` 클래스에서, 스트림의 입출력 형식을 바꿀 수 있다고 하였습니다. 예를들어서, 여태까지 수를 입력하면 10진수로 처리되었지만, 이번에는 16진수로 처리할 수 있는 법입니다. 이를 어떻게 가능하게 하는지 아래의 예제로 보여드리겠습니다.
```cpp-formatted
#include <string>
using namespace std;
int main() {
  int t;
  while (true) {
    cin.setf(ios_base::hex, ios_base::basefield);
    cin >> t;
    cout << "입력 :: " << t << endl;
    if (cin.fail()) {
      cout << "제대로 입력해주세요" << endl;
      cin.clear();  // 플래그들을 초기화 하고 cin.ignore(100,'n');//개행문자가
                    // 나올 때까지 무시한다
    }
    if (t == 0) break;
  }
}
```

성공적으로 컴파일 하였다면
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F272CC74454A10BD31ADFCB)


위와 같이 16진수 입력을 잘 받는 다는 것을 볼 수 있습니다. (출력 형식은 바꾸지 않았으므로, 10진수로 출력됩니다) 이 처럼 입력 받는 형식을 16진수로 바꿔준 함수는 보시다 싶이, 아래와 같은 스트림의 설정을 바꾸는 `setf` 함수 덕분입니다.
```cpp-formatted
cin.setf(ios_base::hex, ios_base::basefield);
```



`setf` 함수의 버전은 2 개가 있는데, 하나는 인자를 1 개만 받는 것이고, 다른 하나는 위 처럼 인자를 2개 취하는 것입니다. 인자 1 개를 받는 `setf` 는 그냥 인자로 준 형식 플래그를 적용하는 것이지만, 2 개 취하는 것은, 두 번째 인자 (위에서 `basefield`) 의 내용을 초기화 하고, 첫 번째 인자 (hex) 를 적용하는 것입니다. 위 경우, 수를 처리하는 방식은 1 가지 진수 만 한 번에 처리할 수 있으므로, 몇 진법으로 수를 처리할 지 보관하는 `basefield` 의 값을 초기화 하고, 16진법 (hex) 플래그를 적용시킨 것입니다.


물론, 여러분이 16 진법을 처리하는 함수를 그냥 만들어도 됩니다. 수 대신에 문자열로 입력받아서 처리해도 되지요. 그렇지만, 사용자가 `0x` 를 앞에 붙일 수 도 있고 안 붙일 수 도 있고, `a123` 이라 쓸 수도 있고 `A123` 이라 쓸 수 도 있고 등 여러가지 경우가 있기 때문에 차라리 마음 편하게 `IO` 라이브러리에서 지원하는 방식을 사용하는 것이 좋은 것 같습니다.


그런데 흥미롭게도, 비슷하지만 또 다른 방식으로 16진수를 받을 수 있습니다.

```cpp-formatted
// 조작자의 사용
#include <iostream>
#include <string>
usingnamespace std;
int main() {
  int t;
  while (true) {
    cin >> hex >> t;
    cout << "입력 :: " << t << endl;
    if (cin.fail()) {
      cout << "제대로 입력해주세요" << endl;
      cin.clear();           // 플래그들을 초기화 하고
      cin.ignore(100, 'n');  //개행문자가 나올 때까지 무시한다
    }
    if (t == 0) break;
  }
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F272CC74454A10BD31ADFCB)





위와 같이 16진수를 잘 입력받는다는 사실을 알 수 있습니다. 이게 어떻게 된 일 일까요?

```cpp-formatted
cin >> hex >> t;
```



바로 위에서 `hex` 가 `cin` 에서 수를 받는 방식을 바꿔버렸기 때문입니다. 이 때문에 `hex` 와 같이, 스트림을 조작하여 입력 혹은 출력 방식을 바꿔주는 함수를 조작자라고 부릅니다 (그렇습니다! `hex` 는 함수 입니다).참고로, 위에서 사용하였던 형식 플래그 `hex` 와 이 `hex` 는 이름만 같지 아예 다른 것입니다. (그렇기에, 위에서는 `ios_base::hex` 로 사용하였죠)

위의 형식 플래그 `hex` 는 `ios_base` 에 선언되어 있는 단순한 상수 '값' 입니다. 반면에 조작자 `hex` 의 경우 `ios` 에 정의되어 있는 '함수' 입니다. 이 조작자 hex 의 정의를 살펴보자면, 아래와 같이 `ios_base` 객체를 레퍼런스로 받고, 다시 그 객체를 리턴하도록 정의 되어 있습니다.

```cpp-formatted
std::ios_base& hex(std::ios_base& str);
```



그렇다면, `operator>>` 중에서 위 함수를 인자로 가지는 경우도 있을까요? 물론 있습니다.

```cpp-formatted
istream& operator>>(ios_base& (*pf)(ios_base&));
```



이렇게, `operator>>` 에서 조작자를 받는다면 많은 일을 하는 것이 아니라 단순히 `pf(*this)` 를 호출하게 됩니다. 호출된 hex 함수가 하는 일 또한 별로 없습니다. 단순히,

```cpp-formatted
str.setf(std::ios_base::hex, std::ios_base::basefield)
```



를 수행해주는 것이지요.


이렇게, `setf` 를 사용하지 않더라도, 간단하게 조작자를 사용하면 훨씬 쉽게 입력 형식을 바꿀 수 있게 됩니다. 조작자들의 종류는 위에서 설명한 `hex` 말고도, 꽤 많은데, `true` 나 `false` 를 1 과 0 으로 처리하는 대신 문자열 그대로 입력 받는 `boolalpha` 도 있고, 출력 형식으로 왼쪽 혹은 오른쪽으로 정렬 시키는 `left` 와 `right` 조작자 등 여러가지가 있습니다.


그 외에도 우리가 여태까지 아무 생각없이 사용하였던 `endl` 도 있습니다. endl 은 `hex` 와는 달리 출력을 관장하는 `ostream` 에 정의되어 있는 조작자로, 한 줄 개행문자를 출력하는 것 말고도, 버퍼를 모두 내보내는(flush) 역할도 수행합니다. 앞서 말했듯이, 문자 1 개를 내보낸다고 해서 화면에 바로 출력되는 것이 아니라, 버퍼에 모은 다음에 버퍼에 어느 정도 쌓이면 비로소 출력하게 됩니다. 이렇게 한다고 해서 대부분의 경우 문제되지는 않습니다. 하지만 예를 들어 정해진 시간에 딱딱 맞춰서 화면에 출력해야 한다면 어떨까요? 이 경우 버퍼에 저장할 필요없이 화면에 바로 내보내야 할 것입니다.



이럴 경우를 위해서, 버퍼에 데이터가 얼마나 쌓여있든지 간에 바로 출력을 해주는 `flush` 함수가 있습니다. 따라서, `endl` 조작자는, 스트림에 '\n' 을 출력하는 것과 더불어 `flush` 를 수행해준다는 사실을 알 수 있습니다.






###  스트림 버퍼에 대해




모든 입출력 객체들은 이에 대응되는 스트림 객체를 가지고 있게 됩니다. 따라서 C++ 의 입출력 라이브러리에는 이에 대응되는 스트림 버퍼 클래스도 있는데, 이름이 `streambuf` 클래스 입니다. 사실, 스트림이라 하면 그냥 쉽게 말해서 문자들의 순차적인 나열이라 보시면 됩니다. 그냥 문자들이 순차적으로 쭈르륵 들어오는 것이 (마치 냇가에서 물이 졸졸 흐르듯이 **stream** 단어의 사전적 의미는 시냇물입니다) 스트림이라 생각하시면 됩니다.

예를 들어서, 우리가 화면에 입력하는 문자도 스트림을 통해서 프로그램에 전달되는 것이고, 하드디스크에서 파일을 읽는 것도, 다른 컴퓨터와 `TCP/IP` 통신하는 것도 (결국 문자들을 쭈루륵 주고받는 것이니까), 모두 스트림을 통해 이루어진다는 것입니다. 심지어 C++ 에서는 `stringstream` 을 통해서평범한문자열을 마치 스트림인 것 처럼 이용할 수 도 있게 해줍니다.

`streambuf` 클래스는 스트림에 대한 가장 기본적인 제어를 담당하고 있습니다.
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F2659F647554622FA21A515)

위 사진은 `streambuf` 클래스에서 스트림을 어떤 식으로 추상화하고 있는지 보여주는 그림입니다. `streambuf` 는 그림과 같이 맨 아래에 나타나있는 스트림에서 입력을 받던지, 출력을 하던지, 혹은 입력과 출력을 동시에 (파일 입출력에서 "rw" 옵션을 생각해보세요) 수행할 수 도 있습니다.

`streambuf` 클래스는 스트림의 상태를 나타내기 위해서 세 개의 포인터를 정의하고 있습니다. 먼저 버퍼의 시작 부분을 가리키는 시작 포인터와, 다음으로 읽을 문자를 가리키고 있는 포인터 (우리가 흔히 말하는 스트림 위치 지정자), 그리고 버퍼의 끝 부분을 가리키고 있는 끝 포인터가 있습니다. `streambuf` 클래스는 입력 버퍼와 출력 버퍼를 구분해서 각각 `get area` 와 `put area` 라 부르는데, 이에 따라 각각을 가리키는 포인터도 `g` 와 `p` 를 붙여서 표현하게 됩니다.

아래 예제를 통해 `streambuf` 를 어떻게 하면 간단히 조작할 수 있는지 보여드리도록 하겠습니다.

```cpp-formatted
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (이 때는 움직이지 않음)
  char peek = cin.rdbuf()->snextc();
  if (cin.fail()) cout << "Failed";
  cout << "두 번째 단어 맨 앞글자 : " << peek << endl;
  cin >> s;
  cout << "다시 읽으면 : " << s << endl;
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F246E6D4D554635332B1532)



위와 같이 나옴을 알 수 있습니다.

```cpp-formatted
char peek = cin.rdbuf()->snextc();
```



입력 객체 `cin` 의 `rdbuf` 를 호출하게 되면, `cin` 객체가 입력을 수행하고 있던 `streambuf` 객체를 가리키는 포인터를 리턴하게 됩니다. 이 때, `cin` 객체가 `istream` 객체 이므로, 오직 입력만을 수행하고 있기에, 이 `streambuf` 객체에는 오직 `get area` 만 있음을 알 수 있습니다.


`snextc` 함수는, 스트림 위치 지정자를 한 칸 전진시킨 후, 그 자리에 해당하는 문자를 엿봅니다 (읽는 것이 아닙니다). 엿보는 것과 읽는 것의 차이점은, 보통 `streambuf` 객체에서 읽게 되면,스트림 위치 지정자를 한 칸 전진시켜서 다음 읽기 때 다음 문자를 읽을 수 있도록 준비해줍니다. 하지만 엿본다는 것은, 해당 문자를 읽고도 스트림 위치 지정자를 움직이지 않는다는 것이지요. 따라서 다음 읽기 때 엿본 문자를 읽을 수 있게 됩니다.


그렇다면 왜 `peek` 의 결과가 `w` 가 나올까요? 아래 그림을 통해 이해하시면 쉽습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F2105593355463709016936)

일단, 우리가 `hello world` 를 친 다음, `cin >> s` 를 한 이후의 `streambuf` 의 상태 입니다. 문자열의 경우 공백문자가 나오기 전 까지 읽어들이기 때문에 위와 같은 상태가 됩니다. 이제, `snextc()` 함수를 호출 했을 때 상태를 보자면;
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F247A463355463704084800)

`snextc` 함수가 스트림 위치 지정자를 한 칸 전진시키므로, 공백 문자를 띄어넘고, `w` 를 가리키게 됩니다. 그리고, 이에 해당하는 문자인 `w` 를 리턴하게 됩니다. 이 때 `snextc` 함수는 스트림 위치 지정자를 건드리지 않기 때문에,

```cpp-formatted
cin >> s;
cout << "다시 읽으면 : " << s << endl;
```



에서 `world` 전체가 나오게 되지요.


`streambuf` 에는 `snextc` 함수 말고도 수 많은 함수들이 정의되어 있습니다. 물론 이 함수들을 직접 사용할 일은 거의 없겠지만, C++ 입출력 라이브러리는 스트림 버퍼도 추상화해서 클래스로 만들었다는 것 정도로만 기억하시면 좋을 것 같습니다. 또한, C++ 에서 `streambuf` 를 도입한 중요한 이유 한 가지는, 1 바이트 짜리 문자 뿐만이 아니라,`wchar_t,` 즉 다중 바이트 문자들 (우리가 흔히 말하는 `UTF-8` 같은 것이지요)에 대한 처리도 용이하게 하기 위해서 입니다.


예를 들어서, 다중 바이트 문자의 경우, 사용자가 문자 한 개만 요구했음에도 스트림에서는 1 바이트만 읽을 수 있고, 2 바이트, 심지어 4 바이트 까지 필요한 경우가 있습니다. C++ 에서는 이러한 것들에 대한 처리를 스트림 버퍼 객체 자체에서 수행하도록 해서, 사용자가 입출력 처리를 이용하는데 훨씬 용이하게 하였습니다.



이상으로 C++ 에서의 입출력 라이브러리에 대해 간단히 알아보았습니다. 다음 강좌에서는 이제 이 라이브러리를 가지고 파일에서 어떠한 방식으로 입출력을 수행할 수 있는지 알아보도록 하겠습니다.

##@ chewing-cpp-end



이번 강좌에서는

* `Visual Studio 2010` 을 설치한다.

* 첫 번째 C++ 프로그램을 만든다.






![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F21453A4A578CC5F4035D76)



안녕하세요~ 여러분. 흥미롭고도 신기한 C++ 의 세계에 오신 것을 진심으로 환영합니다. 사실 C 언어를 접해본 여러분들이 생각하기에 C++ 은 C 의 확장판 정도라 생각하는 분들이 있는데 이는 결코 사실이 아닙니다. 스타크래프트로 따지면 오리지날과 브로드워 개념이 아니라 스타 1 과 스타 2 정도의 차이 일까요. C++ 은 말 그대로 C 언어의 문법만을 차용한 새로운 언어라고 보시면 됩니다. 왜냐하면 언어를 만들어낸 기본 개념이 다르기 때문이지요. 이 기본 개념이 어떻게 다른 지에 대해서는 나중에설명하도록 하겠습니다.
자 그렇다면, 신나는 C++ 의 세계로 `gogogo~`



###  준비물




이전 처럼 C++ 을 배우기 위해서는 다음과 같은 준비물들이 필요합니다.


1. 인터넷이 되는 컴퓨터. 특히 http://itguru.tistory.com 이 수월하게 들어가져야 함

1. 뇌

1. 개념

1. 씹어먹는 C 언어를 다 배움으로써 얻을 수 있는 지식

1. 컴파일러

여기서 가장 중요한 것은 4 번 씹어먹는 C 언어를 다 배움으로써 얻을 수 있는 지식인데,왜냐하면 이 강좌는 오직 전적으로 여러분이 C 를 충분히 알고 있다는 전제 하에서 진행될 것이기 때문입니다. 물론 C++ 을 배우기 위해서 반드시 C 언어를 먼저 배워야 하는 것은 아니지만, C++ 이 C 의 문법을 그대로 따르고 있고 제가 이미 C 강좌를 작성한 관계로 문법에 대한 설명(for 문, `if` 문 등등)은 대부분 생략할 것이기 때문입니다.
만일 프로그래밍이 처음이시거나 C 언어 문법을 잘 모르시는 분들의 경우 [어서 여기를 누르셔서](http://itguru.tistory.com/notice/15)` C` 언어 부터 정복 하고 오시기 바랍니다. 그럼 이제 필요한 것은 5 번, 컴파일러가 되겠네요.
```warning

 [참고로 아래 설치하는 비주얼 스튜디오는 2010 년 버전이고 현재 마이크로소프트에서 2017 년 버전을 제공하고 있습니다. 여기를 눌러서 따라 설치하시면 됩니다.](http://itguru.tistory.com/220)
```


사실 여러분들은 C++ 컴파일러를 이미 다 컴퓨터에 설치하고 계실 것입니다. 왜냐구요? 이전에 C 언어를 배울 때 설치하였던 `Visual Studio 2008` 에 C 및 C++ 컴파일러가 모두 다 들어있기 때문이지요. 하지만 제가 씹어먹는 C 언어 강좌를 썼을 때가 바야흐로 2 년 전인 2009 년으로 최신 버전이 2008 이였지만 이제는 2011 년으로 최신 버전이 2010 으로 올라갔지요. 2008 하고 2010 의 버전 차이는 하늘과 땅 차인데, 무엇보다도 코딩 하기가 매우 편리해 져서 여러분들이게 설치하기를 강력 추천 합니다. (왠지 이 강좌를 끝낼 즘에 2012 버전이 곧 나올 듯한 안좋은 느낌이 드네요ㅎ)

일단

 [ http://www.microsoft.com/visualstudio/en-us/products/2010-editions/visual-cpp-express](http://www.microsoft.com/visualstudio/en-us/products/2010-editions/visual-cpp-express)

로 들어갑니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F1157F0514D731DC51F6D47)

그리고 왼쪽에 `DOWNLOAD` 를 누르신 뒤 오른쪽에 언어를 `Korean` 으로 선택하시고 `INSTALL NOW` 를 누르시면 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F157C1E524D731E9B1A62B3)

다음을 누르시고,


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F130354524D731E9B117976)

동의를 누른 뒤, 다시 다음을 누르고


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F177E5A524D731E9C168775)

이것은 우리가 앞으로 배울 수준의 프로그래밍에서는 결코 필요한 것이 아니기 때문에 체크를 해제하고 다음을 누르고


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F197909524D731E9D1F292D)
역시 다음..


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F1376FF524D731E9D23D09F)

자 이제, 위와 같이 온라인 상으로 전체 프로그램을 다운받게 됩니다. 그리고 조금만 기다리다 보면 완료되었다는 표시가 납니다. 그렇다면 이제 실행해봅시다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F126BBC354D7320DB1C20A5)

아주 멋있네요~


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F186396374D732157248B16)
이제 새 프로젝트를 누른 후, 이전에 2008 때 처럼 `Win32` 콘솔 응용 프로그램을 눌러줍니다. 만일 다른 것을 눌렀을 경우 예상치 못한 오류들이 나오게 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F172172414D7321BA09E0CF)

그리고 아래쪽에 이름을 아무거나 씁니다. 저의 경우 `My first program` 이라고 적어주었습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F124476424D7322071D8E04)

다음을 누르시고


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F14446A424D7322081EF8AA)

빈 프로젝트에 체크를 한 뒤, 마침을 누르면 마침내 새로운 프로젝트가 만들어지게 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F18152C464D73226008DB1C)

소스파일을 누른 후 마우스 오른쪽 클릭을 한 후, 추가로 들어가서 새 항목을 누르시면 아래와 같이 나옵니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F1777E83E4D73320B13AF46)

여기서 C++ 파일을 선택 한 후, 아래에 원하는 이름.cpp 로 적으면 됩니다. 저의 경우 `hello.cpp` 라 적었습니다. 이전에 C 언어에서는 원하는 이름.c 로 적었던 것이 기억이 나지요? 파일의 확장자를 `c` 로 하면 C 컴파일러가, `cpp` 로 하면 C++ 컴파일러가 프로그램을 컴파일 해줍니다.

자 그럼 왼쪽에 생긴 `hello.cpp` 를 클릭 한 뒤, 나타나는 창에 아래와 같이 코드를 씁니다.


```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!!!" << endl;
    return 0;
}
```


성공적으로 컴파일 하였다면 (이전과 똑같이 `Ctrl + F5` 를 누르면 컴파일 후 빌드까지 하여 프로그램을 출력해줍니다)


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F185243334D73330C3AE117)
우와!!

여러분은 드디어 첫번째 C++ 프로그램을 작성하였습니다. 위 소스가 어떠한 의미를 가지고 있는지는 다음 강좌에서 다루어 보도록 하겠습니다.


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <1. 자~ C++ 의 세계로>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/135)
```






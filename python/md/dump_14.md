----------------
title : 씹어 먹는 C 언어 - <8. 우분투 리눅스에서 C 프로그래밍 하기>
cat_title: 8. 우분투 리눅스에서 C 프로그래밍 하기
next_page : 16
--------------


이번 강좌에서는...

* 우분투
에서 `GCC` 설치

* 기초적인 `VIM` 사용법

* `GCC` 로 컴파일 한 후 실행하기.





![우분투 리눅스의 로고 입니다.](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1721750B4A43B0A903BD87)

안녕하세요, 여러분. 이번 강좌에서는 우분투 리눅스 상에서 C 프로그래밍을 하는 법에 대해서 알아 봅시다. 일단, 우분투 리눅스 상에서 C 프로그래밍을 하는 법을 안다면, 다른 배포판에서도 비슷한 방법으로 따라 할 수 있으므로 도움이 될 것입니다.

일단, C 프로그래밍을 하려면 컴파일러가 있어야 되는데, 아시다 시피 리눅스 상에서는 `Visual Studio` 계열을 사용할 수 없습니다. 왜냐하면 그것들은 모두 `Microsoft` 사의 제품이기 때문이죠. 하지만, 훌륭한 오픈 소스 개발자들이 리눅스 용 컴파일러를 개발하였는데, 그 이름하여 유명한 `GCC (GNU Compiler Collection)` 입니다. 사실, 초기의 `GCC` 는 `GNU C Compiler` 의 약자로, C 언어 컴파일만 지원하였으나, 후에 `Ada, C++, JAVA, Fotran, Objective-C` 와 같은 언어들도 컴파일 할 수 있게 되여 현재의 이름으로 바뀌었습니다.

대부분의 우분투 배포판에는 기본적으로 `GCC` 가 설치되어 있습니다. 터미널을 열어서 `gcc` 를 쳐보세요


![gcc : no input files 라고 화면에 나옵니다. ](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F19169B194A43A2E3E4C0F8)

아마, 십중팔구 위 그림과 같이 나올 것입니다. 하지만 간혹 가다 `gcc` 가 설치되어 있지 않아 아래와 같은 결과가 나타나는 사람들도 있습니다.


![화면에 The program 'gcc' can be found in the following packages 가 나오며 apt-get 을 통해 설치하라고 나올 것입니다. ](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F1839C50D4A43A6E30B04B5)

이럴 때 에는 다음과 같이 입력합니다.


```cpp
sudo su
```

그리고 비밀번호를 요구하면, 자신이 처음에 설정한 `root` 의 비밀번호를 입력합니다. 만약 자신이 설정한 `root` 의 비밀번호가 무엇인지 모른다면 현재 사용자의 비밀번호를 입력해 보세요. 대부분 현재 사용자의 비밀번호와 `root` 의 비밀번호가 일치 할 것입니다. 만약 입력했다면 아래와 같이


![sudo su 를 입력합니다. ](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F1761FA254A43A7F2BEA041)

(사용자 이름)@(컴퓨터이름): 에서 root@(컴퓨터이름): 으로 바뀐 것을 볼 수 있습니다. 이제, 여러분은 아래의 명령어를 입력해서 `gcc` 를 설치하시면 됩니다.

```cpp
apt-get install gcc
```

입력하면 아래와 같이 나옵니다.


![뭐가뭐가 주르륵 나오게 됩니다. ](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F12502E254A43A86315AB7A)

  만약 `Y/N` 을 요구한다면 `Y` 를 눌러주시면 되고 저처럼 물어보지 않는다면 그냥 기다리세요. 조금만 기다리다가 위 처럼 다시 명령어 입력을 기다리는 상태가 되었다면 설치가 완료 된 것입니다. 이제, `gcc` 를 쳐보세요. 그렇다면 'gcc: `no input` files' 가 출력되게 되죠.

  이제, 한번 `gcc` 를 통해 C 프로그램을 컴파일 해봅시다. 일단 가장 쉬운 `Hello, World` 를 출력하는 프로그램으로 하기로 하죠. 일단 'vim helloworld.c' 를 입력하여 `helloworld.c` 라는 파일을 만듭니다. (간혹 가다 `vim` 이 설치되지 않은 경우가 종종 있는데 이는 위에서 `gcc` 를 설치했던 방법처럼 `apt-get install vim` 이라 쳐서 `vim` 을 설치하시면 됩니다.)


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F121ED6174A43AA8D3490A6)

실행하면 아래 화면을 볼 수 있습니다.


![물결 무늬가 쭉 나와있는 빈 화면이 나옵니다. ](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F185BD0214A43AB0A762264)

`vim` 은 우리가 흔히 아는 에디터와 다르게 글을 입력하면 바로 내용이 써지는 것이 아닙니다. 일단,`i`를 눌러서 입력모드(insert `mode)` 에 들어가야 합니다. `i` 를 누른다면 아래에 `INSERT` 라고 뜨게 되죠.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F151CAF164A43AC108A523C)

이제, 드디어 글을 입력할 수 있습니다.  그냥 보통 편집기 처럼 프로그램을 작성하면 됩니다. 한가지 유의해야 할 점은 `Visual Stdio` 처럼 자동으로 `indentation` 을 해주는 것이 아닙니다. (물론 `vim` 설정파일에서 `autoindent` 로 설정하면 가능하지만 여기서는 짧은 프로그램이므로 손으로 직접 해도 상관 없습니다. 자세한 내용은 다음 사이트를 참조하세요 : [http://kevin0960.tistory.com/entry/VIM-Vi-iMproved-%EC%9D%98-%EB%AA%85%EB%A0%B9%EC%96%B4-%EB%AA%A8%EC%9D%8C](http://kevin0960.tistory.com/entry/VIM-Vi-iMproved-%EC%9D%98-%EB%AA%85%EB%A0%B9%EC%96%B4-%EB%AA%A8%EC%9D%8C%20))

다 입력한다면 아래와 같은 모습이 됩니다.


![화면에 #include 로 쭉 해서 Hello, World 를 출력하는 소스를 짜세요!](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F1543F3194A43AD6968433C)

이제, `Esc` 키를 눌러서 명령 모드(Command `Mode)` 로 들어간 후, :wq 를 입력하세요. 이는 저장(w) 하고 종료(q) 하라는 뜻 입니다. 입력한다면 프로그램을 빠져나가게 되죠.

프로그램을 빠져 나갔다면 이제 `gcc` 를 통해 프로그램을 컴파일 `+` 링크 해야 겠군요.

```cpp
gcc -o helloworld helloworld.c
```

라고 입력하세요. 여기서 `-o` 는 출력파일의 이름을 지정하는 것입니다. 즉 `-o helloworld` 는 출력파일의 이름을 `helloworld` 로 하라는 뜻이지요. 만약 그냥 `-o` (출력파일 이름) 을 통해 출력파일 이름을 지정하지 않고 그냥 `gcc helloworld.c` 로 하게 되면 출력파일 이름이 `a.out` 으로 만들어 지게 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F183F86194A43AE1E757BAE)

위 명령어를 입력 한 후 , 아무 내용이 뜨지 않는다면 애러없이 성공적으로 컴파일 된 것입니다.  이제,

```cpp
./helloworld
```

를 입력해서 만든 프로그램을 실행시켜 보세요.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F17649D224A43AF4176F9B3)

위 처럼 `Hello, World!` 가 출력되었다면 대 성공 입니다. 축하합니다.

참고해서 읽어 볼 만한 자료

`VIM` 설정 및 명령어 모음
 [http://kevin0960.tistory.com/entry/VIM-Vi-iMproved-의-명령어-모음](http://kevin0960.tistory.com/entry/VIM-Vi-iMproved-%EC%9D%98-%EB%AA%85%EB%A0%B9%EC%96%B4-%EB%AA%A8%EC%9D%8C)
 [http://www.linuxconfig.org/Vim_Tutorial](http://www.linuxconfig.org/Vim_Tutorial)
 [http://blog.interlinked.org/tutorials/vim_tutorial.html](http://blog.interlinked.org/tutorials/vim_tutorial.html)

`gcc` 및 `Makefile` 강좌
 [http://wiki.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make-2.html](http://wiki.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make-2.html)


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는 <<씹어 먹는 C 언어 - <8. 우분투 리눅스에서 C 프로그래밍 하기>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```






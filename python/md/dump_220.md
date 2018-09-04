----------------
title : 비주얼 스튜디오 2017 커뮤니티에서 C/C++ 프로그래밍 하기
--------------




```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```







```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```



안녕하세요 여러분. 2013년에 비주얼 스튜디오 2010 버전에서 `C/C++` 프로그래밍 하는 것을 업데이트 랍시고 올렸는데, 이제 시간이 많이 흘러서 이번에 새로 출시된 비주얼 스튜디오 2017 커뮤니티 버전에서 프로그래밍을 시작하는 방법에 대해 간단히 알아보도록 하겠습니다.


마이크로소프트에서 소프트웨어 개발 툴로 지원하는 프로그램은 크게 2 종류가 있는데요, 하나는 그냥 비주얼 스튜디오 이고, 다른 하나는 비주얼 스튜디오에서 몇 가지 기능을 뺀 비주얼 스튜디오 커뮤니티 버전입니다. 비주얼 스튜디오 커뮤니티 버전이 비주얼 스튜디오에서 몇 가지 기능이 빠졌다고 하지만, 여러분이 `C/C++` 프로그래밍 하는데 있어서 전혀 지장이 없습니다. (약간 회사에서 사용할 법 한 기능들이 빠졌지요).


비주얼 스튜디오 커뮤니티 버전은


 [https://www.visualstudio.com/vs/community/](https://www.visualstudio.com/vs/community/)


에서 받으실 수 있습니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F2676893E58DC5A6402106D)

위와 같이 사이트에 들어가서 `Download VS Community 2017` 을 누르시면 됩니다. (제가 지금 미국에서 있어서 영어로 뜨지만 아마 한국에 계신 분들은 한국말로 뜰 것입니다 :)



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F2763604A58DC5A642C5115)





다운로드 된 실행파일을 실행하면 위와 같이 뜹니다. `Continue` 를 눌러주세요


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F2377554B58DC5A652B7F90)



이제 어떠한 것들을 설치할 지 선택할 수 있는데, 일단 여러분은 `C/C++` 을 배우는 것이 목적이므로 화면에 `Desktop development with C++` 만 선택해 주시면 됩니다. 혹시 내가 나중에 C# 이나 기타 등등으로 더 많은 코딩을 하고 싶다 그러시는 분들은 다른 것들을 선택해서 설치해주셔도 상관 없지만, 설치 용량이 엄청 커지게 됩니다. 저거 하나만 선택했는데에도 벌써 `5.61 GB` 네요.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F27334D3C58DC5A6531172A)



그럼 이제 알아서 필요한 것들을 다운 받아서 설치하게 됩니다. 인터넷 상황에서 따라서 30분에서 1시간 정도 기다려야 합니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F2758FB3858DC67FF0302F0)



설치가 다 되었으면 컴퓨터를 재시작 해야 합니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F27716B4C58DC67FE24EA96)



뭔가 가입하라고 나오는데 그냥 나중에 한다고 하고 무시하면 됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F2313A24658DC67FE212176)





그 다음으로 어떤 테마를 고를지 정하면 됩니다. 저의 경우 그냥 디폴트인 파란색 바탕을 사용하는데, 사람들에 따라서 어두운 테마를 좋아하는 경우도 있습니다 :)


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F240BEE3958DC67FE073364)



이제 메인 화면에서 새로운 프로젝트를 만들어봅시다.


간단히 `Ctrl + Shift + N` 을 누르면 새 프로젝트를 만드는 창을 띄울 수 있습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F2437B54058DC67FE25378A)



다음으로 프로젝트 선택 화면에서 `Win32 Console Application (Win32 콘솔 어플리케이션)` 을 선택합니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F2729344C58DCF43435069B)



'다음' 을 눌러줍니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F2528FF3558DCF4342BD1FB)



빈 프로젝트에 체크해 주시면 프로젝트 생성이 완료됩니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F2325A94F58DCF4351586CA)



이제 프로젝트에 소스 파일을 추가해야 합니다.


기본적으로 왼쪽에 보시면 솔루션 탐색기에서 소스 파일을 쉽게 추가할 수 있는데, 솔루션 탐색기가 안보인다면, `Ctrl + Alt + L` 을 눌러서 띄울 수 있습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F2445D24D58DCF435315473)



이제 C 프로그래밍을 하고 싶다면 이름에 `Hello.c` 처럼 확장자 명을 `.c` 로 명시해야 하고, C++ 로 프로그래밍 하고 싶다면 위 사진 처럼 그냥 확장자를 빼면 알아서 `cpp` 파일로 만들어줍니다.


`C` 프로그래밍 시에 `.c` 로 명시하지 않으면 C++ 컴파일러가 컴파일 하게 되므로 주의하셔야 합니다 C 프로그래밍 시에 `.c` 로 명시하지 않으면 C++ 컴파일러가 컴파일 하게 되므로 주의하셔야 합니다.


그럼 즐거운 프로그래밍 하세요!







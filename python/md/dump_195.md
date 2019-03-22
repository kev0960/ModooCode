----------------
title : 비주얼 스튜디오 2010 에서 C 및 C++ 프로그래밍 하기
publish_date : 2013-01-05
--------------

```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```


```info-text
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```


안녕하세요 여러분! 제가 [첫 씹어먹는 C 언어 강좌](http://itguru.tistory.com/5)를 올렷을 때가 벌써 2009년 초 일때, 그러니까 한창 마이크로소프트에서 `Visual Studio 2008 Express` 버전을 공개해서 시끌시끌 했을 때 였습니다. 그 후로 시간이 무려 4년 이나 흘렀네요. 이제는 `Visual Studio 2008` 이 아니라, `Visual Studio 2012` 를 바라볼 시간이 되었습니다.


하지만 안타까운 일은 `Visual Studio 2012 Express` 버전이 애석하게도윈도우 8 에서만 돌아간다는 점 윈도우 7 이상에서만 돌아간다는 점입니다. 아마도 이 글을 읽고 계신 여러분 대부분은 윈도우 8 을 설치하지 않으셨을 텐데요, 하지만 걱정하지는 마세요. 저희에게는 `Visual Studio 2012` 만큼이나 강력한 `Visual Studio 2010 Express` 버전이 있으니까요. 적어도 C++ 컴파일러로써의 역할로는 두 소프트웨어가 거의 비슷하다고 볼 수 있습니다. 그렇기에, 혹시라도 '헉 2년이나 전 버전을 쓰는게 꿀리는거 아니야?' 라는 생각은 버려두세요.


제가 이 강좌를 쓰는 이유는 씹어먹는 C 언어 첫 강좌에서 비주얼 스튜디오 2008 버전을 설치하는 것으로 시작하였는데 많은 여러분들이 링크가 깨졌고 너무 오래된 것 아니냐라는 문의가 계속 들어와서 새롭게 업데이트를 하기로 하였습니다. (참고로 2008 버전은 [여기서 다운 받을 수 있습니다](http://www.microsoft.com/en-us/download/details.aspx?id=6506)`. )`


일단 다음 [링크를 클릭하셔서 들어가시기 바랍니다.](http://www.microsoft.com/visualstudio/eng/downloads)
 [http://www.microsoft.com/visualstudio/eng/downloads](http://www.microsoft.com/visualstudio/eng/downloads)


아래로 조금 스크롤 하다보면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F193DED3850E7D22524EF0E)



위와 같이 `Visual Studio 2010 Express` 라고 큼지막하게 써져 있는 것을 보실 수 있는데, 여기서 `Visual Studio C++ 2010 Express` 를 클릭해주시기 바랍니다. 그러면, 아래와 같이 밑에 쭈르륵 나옵니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F2054B73550E7D2B513AE75)





참고로 언어를 한국어로 바꿀 수 있지만 그냥 영어 버전으로 설치하시기 바랍니다. 그게 나중에 더 편하고, 또 여러 옵션 설정할 때 영어 버전 기준으로 설명해 놓은 것이 많기 때문에 영어버전으로 택하는 것이 도움이 됩니다. 그래서 `Install now` 를 누르시면 프로그램을 다운 받을 수 있고 그 프로그램을 실행시키면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F112EDC3850E7D2252B340C)





위와 같이 `Visual Studio C++ 2010` 을 설치한다는 화면이 뜨게 됩니다. `Next` 를 누르면




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F212E443850E7D2252CE10D)



여러가지 약관 이야기가 나오는데 물론 읽었다고 표시하고 `Next` 를 누릅니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F1529293850E7D225317C72)



`Microsoft SQL Server 2008 Express` 를 받을 것이냐고 물어보는데, 받지 맙시다. C++ 이나 C 공부에는 아무 상관 없는 프로그램이므로 공간만 차지할 뿐입니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F222FC93850E7D2262B4F44)



그래서 `Install` 을 누르면 실제 웹에서 프로그램을 다운로드 하게 됩니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F202D9B3850E7D2262C8B6A)



위와 같은 인스톨 화면이 끝나게 되면, 이제 프로그램을 실행할 수 있게 됩니다.





![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F0239843450E7FC560AE84B)



프로그램을 실행 시킨 후 위와 같이 메뉴바에서 `File` → `New` → `Project` 를 클릭하면





![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F02154F3450E7FC57358833)



위와 같이 왼쪽의 `Templates` 에서 `Win32` 를 누른 뒤, `Win 32 Console Application` 을 선택하고 (반드시 `Console Application),` 하단에 `Name` 에 자신의 프로젝트 이름을 입력해주세요. 저의 경우 `Hello` 를 입력하였습니다. 그리고 마지막으로 `OK` 를 누르면 프로젝트가 생성됩니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F021B1F3450E7FC552B4726)



`Next` 를 누릅니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F0215093450E7FC55347D9D)



여기서는 프로젝트 설정을 하는 곳인데요, 일단 `Application Type` 에 `Console application` 이 선택되었을 것이고, `Additional Options` 에 `Empty Project` 를 눌러줍니다. 그리고 `Finish` 를 누르면 프로젝트가 생성됩니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F131DAA3450E7FC552988BA)



프로젝트가 생성되었다면 위와 같이 왼쪽 사이드바에 `Solution` 'Hello' 라고 생성되었고 여러 폴더들이 있는 것을 볼 수 있는데요, `Source Files` 를 택한 뒤 마우스 오른쪽 클릭을 해서 `Add` → `New Item` 을 해서 소스 파일을 만들어줍시다.



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F023D683450E7FC5604530B)



왼쪽에서 `Code` 를 선택한 뒤에 `C++ File` 을 누르고, 아래 `Name` 에 소스 파일 이름을 적어주면 됩니다. 저는 그냥 `new` 라고 적었습니다. `Add` 를 누르면 소스 파일이 새로 추가됩니다.




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F213F513450E7FC56025B8D)



여기서 주의해야 할 부분은, C++ 프로그래밍하는 분들은 그냥 나두고C 언어 프로그래밍 하는 분들은 위와 같이 파일을 누르고 오른쪽 클릭을 해서 `Rename` 을 눌러 확장자를 `.c` 로 바꿔주어야 한다는  C 언어 프로그래밍 하는 분들은 위와 같이 파일을 누르고 오른쪽 클릭을 해서 `Rename` 을 눌러 확장자를 `.c` 로 바꿔주어야 한다는 것입니다. 그냥 `.cpp` 로 하면 C++ 컴파일러가, `.c` 로 하면 C 컴파일러가 컴파일 하므로, C 언어를 습득하고자 하는 분은 꼭 `.c` 로 확장자를 변경해야 합니다.


그럼 여러분 모두 즐거운 프로그래밍 하시기 바랍니다.
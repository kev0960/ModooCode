----------------
title : C++ 레퍼런스 - ios::good 함수
cat_title :  ios::good
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios::good

```info
bool good ( ) const;
```


스트림이 입출력 작업이 가능한 상태인지 확인한다.
이 함수는 스트림의 오류 상태 플래그(eofbit, `failbit, badbit)` 이 모두 설정되지 않을 때 `true` 를 리턴한다.

한 가지 주의할 점은 이 함수는 `bad()` 함수와 정 반대가 아니라는 사실이다. `bad` 함수는 `badbit` 플래그가 설정되어 있는지의 여부만 확인하는 함수이다.

오류 상태 플래그들은 `eof, fail, bad` 함수들을  이용해서 독립적으로 체크할 수  있다.

이 함수가 리턴하는 값은 아래의 작업의 결과와 동일하다.

```cpp
(rdstate() == 0)
```




###  인자




없다.



###  리턴값




  만일 스트림의 어떠한 오류 상태 플래그(eofbit, `failbit, badbit)` 이 설정되어 있지 않다면 `true` 를 리턴한다. 그렇지 않으면 `false` 를 리턴한다.



###  템플릿 멤버 선언





```cpp



( basic_ios<charT,traits> )bool good () const;
```




###  연관된 함수

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::bad](http://itguru.tistory.com/166)  :  `badbit` 이 설정되어 있는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
*  [ios::setstate](http://itguru.tistory.com/179)  :  오류 상태 플래그를 설정한다.

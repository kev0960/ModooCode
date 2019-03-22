----------------
title : C++ 레퍼런스 - ios::bad 함수
cat_title :  ios::bad
ref_title : bad
publish_date : 2011-10-23
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 *The C++ Programming Language* 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info-text
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios::bad

```info-format
bool bad ( ) const;
```


`badbit` 가 설정되어 있는지 확인한다.

만일 이전의 입출력 작업으로 인해 스트림의 오류 상태 플래그인 `badbit` 가 설정되어 있는지 확인한다. 이 플래그는 입력 작업 중 스트림의 완전성이 손상되었을 때 발생한다. 완전성이 손상되었다는 말은, 한 개의 스트림의 여러개의 입출력 작업이 동시에 일어날 때를 일컫는다.

한 가지 조심할 점은 이 함수는 [good](http://itguru.tistory.com/164)함수의 정 반대가 아니라는 점이다. [good](http://itguru.tistory.com/164)함수는 3 개의 오류 상태 플래그(`eofbit, failbit, badbit`) 모두가 설정되지 않았을 때 `true` 를 리턴한다.



###  인자




없다



###  리턴값




  `badbit` 이 설정되어 있을 때 `true` 를 리턴하고 아니면 `false`



###  템플릿 멤버 선언



```cpp-formatted
(basic_ios<charT, traits>)bool bad() const;
```



###  연관된 함수

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::good](http://itguru.tistory.com/164):  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
*  [ios::clear](http://itguru.tistory.com/180)  :  오류 상태 플래그를 설정한다.
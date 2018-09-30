----------------
title : C++ 레퍼런스 - ios::setstate 함수
cat_title :  ios::setstate
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios::setstate

```info
void setstate (iostate state);
```


오류 상태 플래그를 설정한다.
인자로 전달된 오류 상태 플래그와 현재의 오류 상태 플래그를 합친다. (비트 OR 연산을 수행한다) 따라서 `setstate` 함수는 현재 이미 켜져 있는 오류 비트는 끌 수 없다. 만일, 켜져 있는 오류 비트를 끄고 싶다면 `clear` 함수를 이용하여 현재 설정된 오류 상태 플래그 값을 모두 지우고 사용자가 새롭게 설정할 수 있다.

이 함수는

```cpp
clear ( rdstate() | state );
```


를 하는 것과 동일하다고 볼 수 있다.



###  인자





`state`

ios_base::iostate 타입의 객체로 다음과 같은 멤버 상수들의 조합(비트 `OR` 연산) 으로 구성되어 있다.

|플래그 값|의미|
|-------|----|
|`eofbit`|스트림으로부터 추출 작업(extracting operation)을 수행 중 End Of File 에 도달하는 경우|
|`failbit`|마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을 경우|
|`badbit`|스트림 버퍼의 입출력 작업이 실패하여 발생한 오류|
|`goodbit`|오류가 없다|


###  리턴값



없다



###  템플릿 멤버 정의





```cpp


( basic_ios<charT,traits> )void setstate ( iostate state );
```




###  연관된 함수

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::bad](http://itguru.tistory.com/166)  :  `badbit` 이 설정되어 있는지 확인한다.
*  [ios::good](http://itguru.tistory.com/164):  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
*  [ios::clear](http://itguru.tistory.com/180)  :  오류 상태 플래그를 설정한다.
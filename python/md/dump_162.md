----------------
title : C++ 레퍼런스 - ios_base::xalloc 함수
cat_title :  ios_base::xalloc
publish_date : 2011-10-22
ref_title : xalloc, ios_base::xalloc
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 *The C++ Programming Language* 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info-text
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios_base::xalloc  (static member function)

```info-format
int xalloc ( );
```


내부 확장 가능 배열(internal extensible array) 의 새로운 인덱스를 리턴한다.
이 인덱스(index) 를 통해서 다른 멤버 함수들(pword, [iword](http://itguru.tistory.com/161)) 들의 작업에 사용될 수 있다. 이 인덱스는 매 호출 마다 1 씩 증가하게 된다.

내부 확장 가능 배열은 `word` 들을 원소를 가지는 배열이다.

이 함수는 정적 함수 이다.



###  리턴값


  새로운 인덱스를 리턴하며, 이 인덱스는 [iword](http://itguru.tistory.com/161)나 `pword` 멤버 함수들을 통해 참조될 수 있다.



###  연관된 함수

*  [ios_base::iword](http://itguru.tistory.com/161)  :  내부 확장 가능 배열의 정수 원소의 레퍼런스를 얻는다.
*  [ios_base::pword](http://itguru.tistory.com/163):  내부 확장 가능 배열을 가리키는 포인터의 레퍼런스를 얻는다.
----------------
title : C++ 레퍼런스 - ios::good 함수
cat_title :  ios::good
ref_title : good, ios::good
publish_date : 2011-10-23
--------------



##@ cpp-ref-start

#@ ios::good

```info-format
bool good ( ) const;
```


스트림이 입출력 작업이 가능한 상태인지 확인한다.

이 함수는 스트림의 오류 상태 플래그(`eofbit`, `failbit`, `badbit`) 이 모두 설정되지 않을 때 `true` 를 리턴한다.

한 가지 주의할 점은 이 함수는 `bad` 함수와 정 반대가 아니라는 사실이다. `bad` 함수는 `badbit` 플래그가 설정되어 있는지의 여부만 확인하는 함수이다.

오류 상태 플래그들은 `eof`, `fail`, `bad` 함수들을  이용해서 독립적으로 체크할 수  있다.

이 함수가 리턴하는 값은 아래의 작업의 결과와 동일하다.

```cpp-formatted
(rdstate() == 0)
```




###  인자




없다.



###  리턴값


만일 스트림의 어떠한 오류 상태 플래그(`eofbit`, `failbit`, `badbit`) 이 설정되어 있지 않다면 `true` 를 리턴한다. 그렇지 않으면 `false` 를 리턴한다.


###  템플릿 멤버 선언


```cpp-formatted
(basic_ios<charT, traits>)bool good() const;
```

###  참고 자료

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::bad](http://itguru.tistory.com/166)  :  `badbit` 이 설정되어 있는지 확인한다.
*  [ios::eof](http://itguru.tistory.com/167)  :  `eofbit` 이 설정되어 있는지 확인한다.
*  [ios::rdstate](http://itguru.tistory.com/171)  :  오류 상태 플래그를 얻는다.
*  [ios::setstate](http://itguru.tistory.com/179)  :  오류 상태 플래그를 설정한다.
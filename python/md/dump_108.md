


```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`time.h (ctime)`




이는 C 언어에서 시간 관련 함수를 모아놓은 라이브러리이다.


시간 관련 함수들


*  [clock](http://itguru.tistory.com/110)  :  시계 프로그램



*  [difftime](http://itguru.tistory.com/111)  :  두 개 시간의 차이를 구한다.



*  [mktime](http://itguru.tistory.com/112)  :  `tm` 구조체를 `time_t` 로 바꾼다.

*  [time](http://itguru.tistory.com/114)  :  현재 시간을 구한다.


변환 관련


*  [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 바꾼다.



*  [ctime](http://itguru.tistory.com/118)  :  `time_t` 값을 문자열로 바꾼다.



*  [gmtime](http://itguru.tistory.com/119)  :  `time_t` 를 `UTC` 시간으로 하여 `tm` 으로 바꾼다.



*  [localtime](http://itguru.tistory.com/120)  :  `time_t` 를 현지 시간으로 하여 `tm` 으로 바꾼다.

*  [strftime](http://itguru.tistory.com/122)  :  특정한 형식(사용자가 지정한 형식 문자열)으로 시간을 출력한다.




매크로


* CLOCKS_PER_SEC  :  1 초 당 클록 수



* NULL  :  널 포인터




타입


* clock_t  :  클록 타입



* size_t  :  부호 없는 정수형



*  [time_t](http://itguru.tistory.com/113)  :  시간 타입



*  [struct tm](http://itguru.tistory.com/109)  :  시간 구조체








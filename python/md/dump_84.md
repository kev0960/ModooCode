----------------
title : C 언어 레퍼런스 - memcmp 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`memcmp`




```info
#include <string.h> // C++ 에서는 <cstring>

int memcmp ( const void * ptr1, const void * ptr2, size_t num );
```


두 개의 메모리 블록을 비교한다.
`ptr1` 이 가리키는 처음 `num` 바이트의 데이터와 `ptr2` 가 가리키는 처음 `num` 바이트의 데이터를 비교하여 이들이 같다면 0 을 리턴하고 다르다면 0 이 아닌 값을 리턴한다. 이 때 리턴되는 값은 아래를 참고해라



###  인자




`ptr1`

메모리 블록을 가리키는 포인터

`ptr2`

메모리 블록을 가리키는 포인터

`num`

비교할 바이트 수



###  리턴값




두 개의 메모리 블록의 관계에 따라 아래와 같이 정수 값을 리턴한다.
만일 두 메모리 블록이 정확히 같다면 0 을 리턴한다.
만일 두 메모리 블록이 다를 경우, `ptr1` 과 `ptr2` 가 가리키는 메모리 블록에서 앞에서 부터 처음으로 다른 바이트를 살펴 보는데, 그 바이트를 `unsigned char` 로 해석하였을 때, 그 값이 `ptr1` 이 더 크면 0 보다 큰 값을, 아니면 0 보다 작은 값을 리턴한다.



###  실행 예제




```cpp
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/memcmp/
에서 가져왔습니다.

참고로 아래의 예제는 단어를 순서대로 배열하는데 요긴하게 이용될 수 있습니다. (예: 사전)

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[256];
    char str2[256];
    int n;
    size_t len1, len2;

    printf ("Enter a sentence: ");
    gets(str1);

    printf ("Enter another sentence: ");
    gets(str2);

    len1=strlen(str1);
    len2=strlen(str2);

    n=memcmp ( str1, str2, len1>len2?len1:len2 );

    if (n>0)
    {
        printf ("'%s' is greater than '%s'.\n",str1,str2);
    }
    else if (n<0)
    {
        printf ("'%s' is less than '%s'.\n",str1,str2);
    }
    else
    {
        printf ("'%s' is the same as '%s'.\n",str1,str2);
    }
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F161811194C24B767A228D0)


위에서 `abcde` 와 `adecd` 를 입력하였을 때, `abcde` 가 `adecd` 보다 작게 나온다. 이는 `memcmp` 가 앞에서 부터 처음으로 다른 바이트 (abcde 의 경우 두 번째인 'b', adecd 에서는 두 번째인 'd' ) 를 비교하는데 'b' 가 'd' 보다 아스키 코드 값이 작으므로 0 보다 작은 값이 리턴된다.



###  연관된 함수





* 
 [memchr](http://itguru.tistory.com/92)  :  메모리 블록에서 특정한 문자를 찾는다.



*  [memcpy](http://itguru.tistory.com/77)`` :  메모리 블록을 복사한다.



*  [memset](http://itguru.tistory.com/104)  :  메모리 블록을 채운다.

*  [strncmp](http://itguru.tistory.com/90)  :  두 개의 문자열의 일부분을 비교한다.

*  [strlen](http://itguru.tistory.com/106)`` : 문자열의 길이를 리턴한다.








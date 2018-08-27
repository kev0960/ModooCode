----------------
title : 씹어먹는 C 언어 - <18 - 1. 파일 뽀개기 (헤더파일과 #include) >
--------------


이번 강좌에서는

* 모듈화 프로그래밍 (파일 나누기)

* #include 전처리기에 대한 이해



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F194C3F154C4076333A0245)


안녕하세요 여러분. 저도 강좌를 쓰는 것이 참으로 오래간만 입니다. 현재 저는 강좌를 모두 모두 모아 하나의 pdf 파일로 만드려고 노력중입니다. 이를 위해 Latex 를 사용하고 있는데 한국 Latex 커뮤니티 (KTUG) 분들께서 훌륭하게 만들어주신 kotex 덕분에 수월하게 파일 제작이 가능합니다. 아무튼 감사하다는 말씀을 드리며 강좌를 시작해 나가보도록 하겠습니다.   

현재까지 여러분은 모든 소스 코드를 하나의 소스 파일에서 작성하였습니다. 사실 이는 큰 문제가 아니였습니다. 왜냐하면 우리가 여태 까지 만들었던 프로그램의 총 소스 길이는 그다지 길지 않았고 또 나 혼자 만들기 때문에 하나의 파일에 모조리 작성해도 상관이 없었습니다. 하지만 여러분이 프로그래머가 되어서 회사에서 프로그래밍을 한다면 소스의 길이도 수천~ 수만줄에 이르고, 여러 사람들이 만들기 때문에 파일을 여러개로 나누어야 할 필요성이 있습니다. 물론 파일을 나눌 때 에는 비슷한 작업을 하는 것 끼리 나누는 것이 좋겠죠.   

```cpp
/* 평범한 문장 */   #include <stdio.h>   char compare(char *str1, char *str2);   int main()   {       char str1[20];       char str2[20];       scanf("%s", str1);       scanf("%s", str2);       if(compare(str1, str2))       {           printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);       }       else       {           printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);       }        return 0;}   char compare(char *str1, char *str2)   {       while (*str1)       {           if(*str1 != *str2)           {               return 0;           }           str1++;           str2++;       }       if(*str2 == '\0')           return 1;       return 0;   }   
```


성공적으로 컴파일 하였다면   



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F130E31144C40527F9208AF)


와 같이 나옵니다.   

만일 같은 두 문장을 사용하였다면 같다는 메세지가 뜨겠지요. 위 소스 코드는 아주아주 쉬운 내용으로 여태까지 내용을 잘 이수하였다면 잘 이해하실 수 있을 것입니다. 다만,   

```cpp
    if(compare(str1, str2))   
```


이 부분에서 살짝 갸우뚱 하시는 분들이 있으실 텐데 우리가 만든 compare 함수는 두 문자열이 같으면 1, 다르면 0 을 리턴합니다. 그런데 if 문의 경우 괄호 안의 값이 0 이면 '거짓' 으로, 0 이 아니면 '참' 으로 판단하기 때문에 (이는 이전 강좌에서 이야기 했던 바 입니다. 기억이 안나면 http://itguru.tistory.com/10 를 보세요) 우리가 원하는 결과를 얻을 수 있었던 것이지요.   

그렇다면 이번에는 이 강좌의 주제에 맞게 파일을 분할해봅시다. compare 함수는 상당히 다른 일을 하고 있기 때문에 굳이 main 함수와 같은 파일에 둘 필요가 없습니다. 따라서 다른 파일에 만들어 보겠습니다.   



###  파일 나누기






![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F190193344C4053CBBD99BB)
먼저 위의 그림과 같이 오른쪽 파일 목록이 나와 있는 부분에서 '소스 파일' 폴더를 클릭한 후 마우스 오른쪽 클릭을 한 후, '새 항목' 을 위와 같이 누릅니다.   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F172A08344C4053CC2CB431)

그러면 위와 같이 새 항목을 추가할 수 있는 화면이 뜨는데 우리는 'C++ 파일(.cpp)' 을 선택하고, 이름에 str 을 적습니다. str 을 적은 이유는 우리가 만든 compare 함수는 문자열을 처리하므로 이에 맞게 str 이라는 이름을 붙여 주었습니다.   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F160643374C40544BC789F8)
하지만 우리가 하려는 것이 C 언어 이지 C++ 이 아니므로 파일 이름을 str.c 로 변경해줍니다. 이는 파일을 클릭한 후 F2 를 누르면 파일이름을 변경할 수 있습니다. (또는 마우스 오른쪽 클릭 후 이름 바꾸기를 누른다)   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F112028344C4053CC733B8F)

이제, test.c (저의 기존 소스를 보관했던 파일 명 입니다. 여러분의 경우 다를 수 있습니다. ) 에 쓰여 있던 기존의 compare 함수 소스를 잘라옵니다. 즉, test.c 에 있던 compare 함수 소스는 사라지고 str.c 에 compare 함수 소스를 넣는 것입니다.   

위 작업이 끝나게 된다면 각 파일에는 다음과 같이 소스가 들어가 있을 것입니다.   

```cpp
/*   test.c   여러분과 파일 이름은 다를 수 있습니다.   */   #include <stdio.h>   char compare(char *str1, char *str2);   int main()   {       char str1[20];       char str2[20];       scanf("%s", str1);       scanf("%s", str2);       if(compare(str1, str2))       {           printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);       }       else       {           printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);       }        return 0;}   
```


```cpp
/*   str.c   */   char compare(char *str1, char *str2)   {       while (*str1)       {           if(*str1 != *str2)           {               return 0;           }           str1++;           str2++;       }       if(*str2 == '\0')           return 1;       return 0;   }   
```


성공적으로 컴파일 하였다면   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F130E31144C40527F9208AF)

아까와 동일한 결과를 얻을 수 있었습니다.   

일단 위 프로그램이 어떻게 작동하는지 살펴 봅시다.   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F13697A0E4C406E8688A9DF)


아마 예전에 배워서 까먹었을 가능성이 있는데 우리가 실행 파일을 만들기 위해서는 먼저 C 코드를 컴퓨터가 이해할 수 있는 언어로 바꿔주는 컴파일(compile) 이라는 과정이 진행됩니다. 이는 단일 소스 코드 전체를 어셈블리어 (기계어와 1 : 1 대응이 되어 있음) 로 변환해 줍니다 (이 때, 목적코드라 불리는 확장자가 .o 인 파일이 생성됩니다) . 이 과정이 끝나게 되면 링킹(linking) 이라는 과정이 진행되는데 말그대로 각기 다른 파일에 위치한 소스 코드들을 한데 엮어서 하나의 실행 파일로 만들어지는 과정이라 생각하시면 됩니다.   

링킹 과정에서 특정한 소스 파일에 있는 함수들이 어디어디에 있는지 찾는 과정을 거치게 되는데 예를 들어서 test.c 의 경우 compare 함수가 어디있는지 찾게 됩니다. (눈치가 빠른 독자라면 printf 함수 역시 찾아야 함을 알 수 있는데 이에 대한 설명은 나중에 하겠습니다) 우리의 예제의 경우 compare 함수는 str.c 에 있기 때문에 링커(링킹을 해주는 것, 컴파일을 해주는 것이 컴파일러인 것과 일맥 상통하다) 는 'test.c 에서 compare 함수를 호출하는 경우 str.c 에서 찾아라' 정도로 처리해 주게 됩니다. 덕분에 우리는 test.c 에서 compare 함수를 호출하더라도 str.c 의 compare 함수를 이용할 수 있게 되는 것이지요.   

만일 test.c 에서   

```cpp
char compare(char *str1, char *str2);   
```


부분을 지워버리면 어떨까요? 이렇게 된다면 컴파일러는 'main 함수에서 compare 함수를 호출하였는데, 도대체 compare 함수는 어떻게 생긴 모양이야!' 가 되어 컴파일 시에 오류가 발생하게 됩니다. 물론 링커의 경우도 compare 함수의 정확한 모양이 무엇인지 알 수 없으므로 오류가 발생하게 되죠.   

따라서 이렇게 언제나 함수의 선언을 명시해 주는 것은 매우 중요한 일입니다.   

하지만 compare 라는 함수 말고도 copy 라는 함수가 str.c 에 추가되었습니다. 이 함수는 두 문자열을 복사해주는 역할을 합니다. copy 라는 함수를 test.c 에서 이용하기 위해선 역시 copy 함수의 원형을 써주어야 합니다. 이는 상당히 귀찮은 일이지요. 뿐만 아니라 다른 파일에서도 compare 함수와 copy 함수를 이용할 수 있는데 이 파일 역시 이 두 함수의 원형을 써주어야 합니다.   

이렇게 귀찮은 작업을 막기 위해 C 에서는 아주 놀라운 해결책을 제시하였는데 바로 헤더파일 (header file) 을 이용하는 것입니다. 헤더파일은 다음과 같은 방법으로 만들 수 있습니다.   



###  헤더 파일







![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F160941104C4069157ABB63)
먼저 기존에 str.c 파일을 추가했을 때 했던 것 처럼 하되 이번에는 헤더파일 폴더에 파일을 추가해보도록 합시다.   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F206DC2104C4069211A9828)

헤더파일을 추가하는 것이므로 '헤더파일' 을 선택한 후, 이름에 str 을 적습니다.   



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1367AB104C40696025CB87)

그리고 헤더파일에는 위와 같이 내용을 기록합니다. 그 후, 각 소스 코드를 다음과 같이 수정해줍니다.   

```cpp
/* test.c */   #include <stdio.h>   #include "str.h"   int main()   {       char str1[20];       char str2[20];       scanf("%s", str1);       scanf("%s", str2);       if(compare(str1, str2))       {           printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);       }       else       {           printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);       }        return 0;}   
```




```cpp
/* str.c */   #include "str.h"   char compare(char *str1, char *str2)   {       while (*str1)       {           if(*str1 != *str2)           {               return 0;           }           str1++;           str2++;       }       if(*str2 == '\0')           return 1;       return 0;   }   

```



```cpp
/* str.h */   char compare(char *str1, char *str2);   
```



  성공적으로 컴파일 하였다면   


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F15681B1C4C406A05628C04)

역시 위와 같이 잘 작동하고 있음을 알 수 있습니다.   

먼저 test.c 부터 살펴봅시다.   

```cpp
#include <stdio.h>   #include "str.h"   
```

#include 와 같은 명령들은 '전처리기(Preprocessor)' 명령이라고 부르는데 이러한 명령들의 특징은 컴파일 이전에 실행된다는 점 입니다. 이 명령은 우리가 지칭하는 파일의 내용을 정확히 100% 복사해서 붙여 넣는다는 점입니다. 따라서 #include "str.h" 라는 명령은 str.h 에 있었던 내용, 즉 char compare(char *str1, char *str2); 로 컴파일이 시작하기 전에 바뀌어 버립니다.   

그렇다면 #include <stdio.h> 는 어떨까요? 이 역시 똑같습니다. stdio.h 에 써있는 내용들이 정확히 복사되어 컴파일 이전에 코드에 붙어버립니다. 그런데 한 가지 이상한 점은 stdio.h 는 <> 로 감쌌는데, str.h 는 왜 " " 로 감쌌을까요? 그 이유는 단순한데, < > 로 감싸는 헤더파일은 컴파일러에서 기본으로 지원하는 헤더파일의 경우이고 " " 로 감싸는 헤더파일은 사용자가 직접 제작한 헤더파일의 경우 입니다.   

여러분은 stdio.h 에 무엇이 써져 있는지 궁금하지 않으세요? 한 번 제가 그 내용을 올려드리겠습니다.   

stdio.h 내용 보기
/***

*stdio.h - definitions/declarations for standard I/O routines

*

*       Copyright (c) Microsoft Corporation. All rights reserved.

*

*Purpose:

*       This file defines the structures, values, macros, and functions

*       used by the level 2 I/O ("standard I/O") routines.

*       [ANSI/System V]

*

*       [Public]

*

****/


#if     _MSC_VER > 1000

#pragma once

#endif


#ifndef _INC_STDIO

#define _INC_STDIO


#include <crtdefs.h>

#ifdef  _MSC_VER

/*

 * Currently, all MS C compilers for Win32 platforms default to 8 byte

 * alignment.

 */

#pragma pack(push,_CRT_PACKING)

#endif  /* _MSC_VER */


#ifdef  __cplusplus

extern "C" {

#endif



/* Buffered I/O macros */


#define BUFSIZ  512



/*

 * Default number of supported streams. _NFILE is confusing and obsolete, but

 * supported anyway for backwards compatibility.

 */

#define _NFILE      _NSTREAM_


#define _NSTREAM_   512


/*

 * Number of entries in _iob[] (declared below). Note that _NSTREAM_ must be

 * greater than or equal to _IOB_ENTRIES.

 */

#define _IOB_ENTRIES 20


#define EOF     (-1)



#ifndef _FILE_DEFINED

struct _iobuf {

        char *_ptr;

        int   _cnt;

        char *_base;

        int   _flag;

        int   _file;

        int   _charbuf;

        int   _bufsiz;

        char *_tmpfname;

        };

typedef struct _iobuf FILE;

#define _FILE_DEFINED

#endif



/* Directory where temporary files may be created. */


#ifdef  _POSIX_

#define _P_tmpdir   "/"

#define _wP_tmpdir  L"/"

#else

#define _P_tmpdir   "\\"

#define _wP_tmpdir  L"\\"

#endif


/* L_tmpnam = length of string _P_tmpdir

 *            + 1 if _P_tmpdir does not end in "/" or "\", else 0

 *            + 12 (for the filename string)

 *            + 1 (for the null terminator)

 * L_tmpnam_s = length of string _P_tmpdir

 *            + 1 if _P_tmpdir does not end in "/" or "\", else 0

 *            + 16 (for the filename string)

 *            + 1 (for the null terminator)

 */

#define L_tmpnam   (sizeof(_P_tmpdir) + 12)

#if __STDC_WANT_SECURE_LIB__

#define L_tmpnam_s (sizeof(_P_tmpdir) + 16)

#endif


#ifdef  _POSIX_

#define L_ctermid   9

#define L_cuserid   32

#endif



/* Seek method constants */


#define SEEK_CUR    1

#define SEEK_END    2

#define SEEK_SET    0



#define FILENAME_MAX    260

#define FOPEN_MAX       20

#define _SYS_OPEN       20

#define TMP_MAX         32767  /* SHRT_MAX */

#if __STDC_WANT_SECURE_LIB__

#define TMP_MAX_S       _TMP_MAX_S

#define _TMP_MAX_S      2147483647 /* INT_MAX */

#endif


/* Define NULL pointer value */

#ifndef NULL

#ifdef __cplusplus

#define NULL    0

#else

#define NULL    ((void *)0)

#endif

#endif


/* Declare _iob[] array */


#ifndef _STDIO_DEFINED

_CRTIMP FILE * __cdecl __iob_func(void);

#endif  /* _STDIO_DEFINED */



/* Define file position type */


#ifndef _FPOS_T_DEFINED

#undef _FPOSOFF


#if     defined (_POSIX_)

typedef long fpos_t;

#define _FPOSOFF(fp) ((long)(fp))

#else   /* _POSIX_ */


#if     !__STDC__

/* At this point we could switch both to long long, but we won't do that till next version to avoid any potential compat issues */

typedef __int64 fpos_t;

#define _FPOSOFF(fp) ((long)(fp))

#else

typedef long long fpos_t;

#define _FPOSOFF(fp) ((long)(fp))

#endif

#endif  /* _POSIX_ */


#define _FPOS_T_DEFINED

#endif


#ifndef _STDSTREAM_DEFINED

#define stdin  (&__iob_func()[0])

#define stdout (&__iob_func()[1])

#define stderr (&__iob_func()[2])

#define _STDSTREAM_DEFINED

#endif 


#define _IOREAD         0x0001

#define _IOWRT          0x0002


#define _IOFBF          0x0000

#define _IOLBF          0x0040

#define _IONBF          0x0004


#define _IOMYBUF        0x0008

#define _IOEOF          0x0010

#define _IOERR          0x0020

#define _IOSTRG         0x0040

#define _IORW           0x0080

#ifdef  _POSIX_

#define _IOAPPEND       0x0200

#endif


/* constants used by _set_output_format */

#define _TWO_DIGIT_EXPONENT 0x1


/* Function prototypes */


#ifndef _STDIO_DEFINED


_Check_return_ _CRTIMP int __cdecl _filbuf(_Inout_ FILE * _File );

_Check_return_opt_ _CRTIMP int __cdecl _flsbuf(_In_ int _Ch, _Inout_ FILE * _File);


#ifdef  _POSIX_

_Check_return_ _CRTIMP FILE * __cdecl _fsopen(_In_z_ const char * _Filename, _In_z_ const char * _Mode);

#else

_Check_return_ _CRTIMP FILE * __cdecl _fsopen(_In_z_ const char * _Filename, _In_z_ const char * _Mode, _In_ int _ShFlag);

#endif


_CRTIMP void __cdecl clearerr(_Inout_ FILE * _File);

#if __STDC_WANT_SECURE_LIB__

_Check_return_wat_ _CRTIMP errno_t __cdecl clearerr_s(_Inout_ FILE * _File );

#endif

_Check_return_opt_ _CRTIMP int __cdecl fclose(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fcloseall(void);


#ifdef  _POSIX_

_Check_return_ _CRTIMP FILE * __cdecl fdopen( _In_ int _FileHandle, _In_z_ const char * _Mode);

#else

_Check_return_ _CRTIMP FILE * __cdecl _fdopen(_In_ int _FileHandle, _In_z_ const char * _Mode);

#endif


_Check_return_ _CRTIMP int __cdecl feof(_In_ FILE * _File);

_Check_return_ _CRTIMP int __cdecl ferror(_In_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl fflush(_Inout_opt_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl fgetc(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fgetchar(void);

_Check_return_opt_ _CRTIMP int __cdecl fgetpos(_Inout_ FILE * _File , _Out_ fpos_t * _Pos);

_Check_return_opt_ _CRTIMP char * __cdecl fgets(_Out_z_cap_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);


#ifdef  _POSIX_

_Check_return_ _CRTIMP int __cdecl fileno(_In_ FILE * _File);

#else

_Check_return_ _CRTIMP int __cdecl _fileno(_In_ FILE * _File);

#endif


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma push_macro("_tempnam")

#undef _tempnam

#endif


_Check_return_ _CRTIMP char * __cdecl _tempnam(_In_opt_z_ const char * _DirName, _In_opt_z_ const char * _FilePrefix);


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma pop_macro("_tempnam")

#endif


_Check_return_opt_ _CRTIMP int __cdecl _flushall(void);

_Check_return_ _CRT_INSECURE_DEPRECATE(fopen_s) _CRTIMP FILE * __cdecl fopen(_In_z_ const char * _Filename, _In_z_ const char * _Mode);

#if __STDC_WANT_SECURE_LIB__

_Check_return_wat_ _CRTIMP errno_t __cdecl fopen_s(_Deref_out_opt_ FILE ** _File, _In_z_ const char * _Filename, _In_z_ const char * _Mode);

#endif

_Check_return_opt_ _CRTIMP int __cdecl fprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl fprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP int __cdecl fputc(_In_ int _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fputchar(_In_ int _Ch);

_Check_return_opt_ _CRTIMP int __cdecl fputs(_In_z_ const char * _Str, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP size_t __cdecl fread(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP size_t __cdecl fread_s(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _DstSize, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

#endif

_Check_return_ _CRT_INSECURE_DEPRECATE(freopen_s) _CRTIMP FILE * __cdecl freopen(_In_z_ const char * _Filename, _In_z_ const char * _Mode, _Inout_ FILE * _File);

#if __STDC_WANT_SECURE_LIB__

_Check_return_wat_ _CRTIMP errno_t __cdecl freopen_s(_Deref_out_opt_ FILE ** _File, _In_z_ const char * _Filename, _In_z_ const char * _Mode, _Inout_ FILE * _OldFile);

#endif

_Check_return_ _CRT_INSECURE_DEPRECATE(fscanf_s) _CRTIMP int __cdecl fscanf(_Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fscanf_s_l) _CRTIMP int __cdecl _fscanf_l(_Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

#pragma warning(push)

#pragma warning(disable:6530)

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl fscanf_s(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const char * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP int __cdecl _fscanf_s_l(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl fsetpos(_Inout_ FILE * _File, _In_ const fpos_t * _Pos);

_Check_return_opt_ _CRTIMP int __cdecl fseek(_Inout_ FILE * _File, _In_ long _Offset, _In_ int _Origin);

_Check_return_ _CRTIMP long __cdecl ftell(_Inout_ FILE * _File);


_Check_return_opt_ _CRTIMP int __cdecl _fseeki64(_Inout_ FILE * _File, _In_ __int64 _Offset, _In_ int _Origin);

_Check_return_ _CRTIMP __int64 __cdecl _ftelli64(_Inout_ FILE * _File);


_Check_return_opt_ _CRTIMP size_t __cdecl fwrite(_In_count_x_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);

_Check_return_ _CRTIMP int __cdecl getc(_Inout_ FILE * _File);

_Check_return_ _CRTIMP int __cdecl getchar(void);

_Check_return_ _CRTIMP int __cdecl _getmaxstdio(void);

#if __STDC_WANT_SECURE_LIB__

_CRTIMP char * __cdecl gets_s(_Out_z_cap_(_Size) char * _Buf, _In_ rsize_t _Size);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(char *, gets_s, char, _Buffer)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(char *, __RETURN_POLICY_SAME, _CRTIMP, gets, _Pre_notnull_ _Post_z_ _Out_z_cap_c_(((size_t)-1)), char, _Buffer)

_Check_return_ int __cdecl _getw(_Inout_ FILE * _File);

#ifndef _CRT_PERROR_DEFINED

#define _CRT_PERROR_DEFINED

_CRTIMP void __cdecl perror(_In_opt_z_ const char * _ErrMsg);

#endif

_Check_return_opt_ _CRTIMP int __cdecl _pclose(_Inout_ FILE * _File);

_Check_return_ _CRTIMP FILE * __cdecl _popen(_In_z_ const char * _Command, _In_z_ const char * _Mode);

_Check_return_opt_ _CRTIMP int __cdecl printf(_In_z_ _Printf_format_string_ const char * _Format, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl printf_s(_In_z_ _Printf_format_string_ const char * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP int __cdecl putc(_In_ int _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl putchar(_In_ int _Ch);

_Check_return_opt_ _CRTIMP int __cdecl puts(_In_z_ const char * _Str);

_Check_return_opt_ _CRTIMP int __cdecl _putw(_In_ int _Word, _Inout_ FILE * _File);

#ifndef _CRT_DIRECTORY_DEFINED

#define _CRT_DIRECTORY_DEFINED

_Check_return_ _CRTIMP int __cdecl remove(_In_z_ const char * _Filename);

_Check_return_ _CRTIMP int __cdecl rename(_In_z_ const char * _OldFilename, _In_z_ const char * _NewFilename);

_Check_return_ _CRTIMP int __cdecl _unlink(_In_z_ const char * _Filename);

#if !__STDC__

_Check_return_ _CRT_NONSTDC_DEPRECATE(_unlink) _CRTIMP int __cdecl unlink(_In_z_ const char * _Filename);

#endif

#endif

_CRTIMP void __cdecl rewind(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _rmtmp(void);

_Check_return_ _CRT_INSECURE_DEPRECATE(scanf_s) _CRTIMP int __cdecl scanf(_In_z_ _Scanf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_scanf_s_l) _CRTIMP int __cdecl _scanf_l(_In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl scanf_s(_In_z_ _Scanf_s_format_string_ const char * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _scanf_s_l(_In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_CRT_INSECURE_DEPRECATE(setvbuf) _CRTIMP void __cdecl setbuf(_Inout_ FILE * _File, _Inout_opt_cap_c_(BUFSIZ) _Post_count_c_(0) char * _Buffer);

_Check_return_opt_ _CRTIMP int __cdecl _setmaxstdio(_In_ int _Max);

_Check_return_opt_ _CRTIMP unsigned int __cdecl _set_output_format(_In_ unsigned int _Format);

_Check_return_opt_ _CRTIMP unsigned int __cdecl _get_output_format(void);

_Check_return_opt_ _CRTIMP int __cdecl setvbuf(_Inout_ FILE * _File, _Inout_opt_z_bytecap_(_Size) char * _Buf, _In_ int _Mode, _In_ size_t _Size);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snprintf_s(_Out_z_bytecap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, ...);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snprintf_s, _vsnprintf_s, char, _Dest, _In_ size_t, _MaxCount, _In_z_ _Printf_format_string_ const char *,_Format)

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl sprintf_s(_Out_z_bytecap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format, ...);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, sprintf_s, vsprintf_s, char, _Dest, _In_z_ _Printf_format_string_ const char *, _Format)

_Check_return_ _CRTIMP int __cdecl _scprintf(_In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_ _CRT_INSECURE_DEPRECATE(sscanf_s) _CRTIMP int __cdecl sscanf(_In_z_ const char * _Src, _In_z_ _Scanf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_sscanf_s_l) _CRTIMP int __cdecl _sscanf_l(_In_z_ const char * _Src, _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl sscanf_s(_In_z_ const char * _Src, _In_z_ _Scanf_s_format_string_ const char * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _sscanf_s_l(_In_z_ const char * _Src, _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snscanf_s) _CRTIMP int __cdecl _snscanf(_In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snscanf_s_l) _CRTIMP int __cdecl _snscanf_l(_In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snscanf_s(_In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_s_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snscanf_s_l(_In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_ _CRT_INSECURE_DEPRECATE(tmpfile_s) _CRTIMP FILE * __cdecl tmpfile(void);

#if __STDC_WANT_SECURE_LIB__

_Check_return_wat_ _CRTIMP errno_t __cdecl tmpfile_s(_Out_opt_ _Deref_post_valid_ FILE ** _File);

_Check_return_wat_ _CRTIMP errno_t __cdecl tmpnam_s(_Out_z_cap_(_Size) char * _Buf, _In_ rsize_t _Size);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, tmpnam_s, _Deref_post_z_ char, _Buf)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(char *, __RETURN_POLICY_DST, _CRTIMP, tmpnam, _Pre_maybenull_ _Post_z_, char, _Buffer)

_Check_return_opt_ _CRTIMP int __cdecl ungetc(_In_ int _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl vfprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl vfprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#endif

_Check_return_opt_ _CRTIMP int __cdecl vprintf(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl vprintf_s(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#endif

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(vsnprintf_s) _CRTIMP int __cdecl vsnprintf(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl vsnprintf_s(_Out_z_cap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#endif

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnprintf_s(_Out_z_cap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnprintf_s, char, _Dest, _In_ size_t, _MaxCount, _In_z_ _Printf_format_string_ const char *, _Format, va_list, _Args)

#pragma warning(push)

#pragma warning(disable:4793)

__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX(int, __RETURN_POLICY_SAME, _CRTIMP, _snprintf, _vsnprintf, _Pre_notnull_ _Post_maybez_ char, _Out_cap_(_Count) _Post_maybez_, char, _Dest, _In_ size_t, _Count, _In_z_ _Printf_format_string_ const char *, _Format)

#pragma warning(pop)

#if __STDC_WANT_SECURE_LIB__

_CRTIMP_ALTERNATIVE int __cdecl vsprintf_s(_Out_z_cap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _Dest, _In_z_ _Printf_format_string_ const char *, _Format, va_list, _Args)

#pragma warning(push)

#pragma warning(disable:4793)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST(int, __RETURN_POLICY_SAME, _CRTIMP, sprintf, vsprintf, _Pre_notnull_ _Post_z_, char, _Dest, _In_z_ _Printf_format_string_ const char *, _Format)

#pragma warning(pop)

_Check_return_ _CRTIMP int __cdecl _vscprintf(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _snprintf_c(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_c(_Out_cap_(_MaxCount) char *_DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _fprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _printf_p(_In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _sprintf_p(_Out_z_cap_(_MaxCount) char * _Dst, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vfprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vprintf_p(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vsprintf_p(_Out_z_cap_(_MaxCount) char * _Dst, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

_Check_return_ _CRTIMP int __cdecl _scprintf_p(_In_z_ _Printf_format_string_ const char * _Format, ...);

_Check_return_ _CRTIMP int __cdecl _vscprintf_p(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);

_CRTIMP int __cdecl _set_printf_count_output(_In_ int _Value);

_CRTIMP int __cdecl _get_printf_count_output();


_Check_return_opt_ _CRTIMP int __cdecl _printf_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _printf_p_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _printf_s_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vprintf_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vprintf_s_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _fprintf_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _fprintf_p_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _fprintf_s_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vfprintf_l(_Inout_ FILE * _File, _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vfprintf_p_l(_Inout_ FILE * _File, _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vfprintf_s_l(_Inout_ FILE * _File, _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_sprintf_s_l) _CRTIMP int __cdecl _sprintf_l(_Pre_notnull_ _Post_z_ char * _DstBuf, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _sprintf_p_l(_Out_z_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _sprintf_s_l(_Out_z_bytecap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsprintf_s_l) _CRTIMP int __cdecl _vsprintf_l(_Pre_notnull_ _Post_z_ char * _DstBuf, _In_z_ const char * _Format, _In_opt_ _locale_t, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vsprintf_p_l(_Out_z_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char* _Format, _In_opt_ _locale_t _Locale,  va_list _ArgList);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsprintf_s_l(_Out_z_cap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _scprintf_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _scprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vscprintf_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vscprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snprintf_s_l) _CRTIMP int __cdecl _snprintf_l(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _snprintf_c_l(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snprintf_s_l(_Out_z_cap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnprintf_s_l) _CRTIMP int __cdecl _vsnprintf_l(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_c_l(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, const char *, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_s_l(_Out_z_cap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char* _Format,_In_opt_ _locale_t _Locale, va_list _ArgList);


#ifndef _WSTDIO_DEFINED


/* wide function prototypes, also declared in wchar.h  */


#ifndef WEOF

#define WEOF (wint_t)(0xFFFF)

#endif


#ifdef  _POSIX_

_Check_return_ _CRTIMP FILE * __cdecl _wfsopen(_In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode);

#else

_Check_return_ _CRTIMP FILE * __cdecl _wfsopen(_In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _In_ int _ShFlag);

#endif


_Check_return_opt_ _CRTIMP wint_t __cdecl fgetwc(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wint_t __cdecl _fgetwchar(void);

_Check_return_opt_ _CRTIMP wint_t __cdecl fputwc(_In_ wchar_t _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wint_t __cdecl _fputwchar(_In_ wchar_t _Ch);

_Check_return_ _CRTIMP wint_t __cdecl getwc(_Inout_ FILE * _File);

_Check_return_ _CRTIMP wint_t __cdecl getwchar(void);

_Check_return_opt_ _CRTIMP wint_t __cdecl putwc(_In_ wchar_t _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wint_t __cdecl putwchar(_In_ wchar_t _Ch);

_Check_return_opt_ _CRTIMP wint_t __cdecl ungetwc(_In_ wint_t _Ch, _Inout_ FILE * _File);


_Check_return_opt_ _CRTIMP wchar_t * __cdecl fgetws(_Out_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ int _SizeInWords, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl fputws(_In_z_ const wchar_t * _Str, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wchar_t * __cdecl _getws_s(_Out_z_cap_(_SizeInWords) wchar_t * _Str, _In_ size_t _SizeInWords);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(wchar_t *, _getws_s, wchar_t, _String)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(wchar_t *, __RETURN_POLICY_SAME, _CRTIMP, _getws, _Pre_notnull_ _Post_z_, wchar_t, _String)

_Check_return_opt_ _CRTIMP int __cdecl _putws(_In_z_ const wchar_t * _Str);


_Check_return_opt_ _CRTIMP int __cdecl fwprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl fwprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP int __cdecl wprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl wprintf_s(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

#endif

_Check_return_ _CRTIMP int __cdecl _scwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl vfwprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl vfwprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

#endif

_Check_return_opt_ _CRTIMP int __cdecl vwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl vwprintf_s(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

#endif


#if __STDC_WANT_SECURE_LIB__

_CRTIMP_ALTERNATIVE int __cdecl swprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, swprintf_s, vswprintf_s, wchar_t, _Dest, _In_z_ _Printf_format_string_ const wchar_t *, _Format)

#if __STDC_WANT_SECURE_LIB__

_CRTIMP_ALTERNATIVE int __cdecl vswprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

#endif

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswprintf_s, wchar_t, _Dest, _In_z_ _Printf_format_string_ const wchar_t *, _Format, va_list, _Args)


_Check_return_opt_ _CRTIMP int __cdecl _swprintf_c(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vswprintf_c(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);


_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snwprintf_s, _vsnwprintf_s, wchar_t, _Dest, _In_ size_t, _Count, _In_z_ _Printf_format_string_ const wchar_t *, _Format)

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnwprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnwprintf_s, wchar_t, _Dest, _In_ size_t, _Count, _In_z_ _Printf_format_string_ const wchar_t *, _Format, va_list, _Args)

#pragma warning(push)

#pragma warning(disable:4793)

__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX(int, __RETURN_POLICY_SAME, _CRTIMP, _snwprintf, _vsnwprintf, _Pre_notnull_ _Post_maybez_ wchar_t, _Out_cap_(_Count) _Post_maybez_, wchar_t, _Dest, _In_ size_t, _Count, _In_z_ _Printf_format_string_ const wchar_t *, _Format)

#pragma warning(pop)


_Check_return_opt_ _CRTIMP int __cdecl _fwprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _wprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _swprintf_p(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vswprintf_p(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

_Check_return_ _CRTIMP int __cdecl _scwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);

_Check_return_ _CRTIMP int __cdecl _vscwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _wprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _wprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _wprintf_s_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vwprintf_s_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _fwprintf_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _fwprintf_p_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _fwprintf_s_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_p_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_s_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRTIMP int __cdecl _swprintf_c_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _swprintf_p_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _swprintf_s_l(_Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP int __cdecl _vswprintf_c_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP int __cdecl _vswprintf_p_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vswprintf_s_l(_Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_ _CRTIMP int __cdecl _scwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_ _CRTIMP int __cdecl _scwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_ _CRTIMP int __cdecl _vscwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);


_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwprintf_s_l) _CRTIMP int __cdecl _snwprintf_l(_Out_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwprintf_s_l(_Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnwprintf_s_l) _CRTIMP int __cdecl _vsnwprintf_l(_Out_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnwprintf_s_l(_Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);



#ifndef _CRT_NON_CONFORMING_SWPRINTFS


#define _SWPRINTFS_DEPRECATED _CRT_DEPRECATE_TEXT("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")


#else


#define _SWPRINTFS_DEPRECATED 


#endif /* ifndef _CRT_NON_CONFORMING_SWPRINTFS */


/* we could end up with a double deprecation, disable warnings 4141 and 4996 */

#pragma warning(push)

#pragma warning(disable:4141 4996 4793)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(int, __RETURN_POLICY_SAME, _SWPRINTFS_DEPRECATED _CRTIMP, _swprintf, _swprintf_s, _vswprintf, vswprintf_s, _Pre_notnull_ _Post_z_, wchar_t, _Dest, _In_z_ _Printf_format_string_ const wchar_t *, _Format)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(int, __RETURN_POLICY_SAME, _SWPRINTFS_DEPRECATED _CRTIMP, __swprintf_l, __vswprintf_l, _vswprintf_s_l, _Pre_notnull_ _Post_z_ wchar_t, , wchar_t, _Dest, _In_z_ _Printf_format_string_ const wchar_t *, _Format, _locale_t, _Plocinfo)

#pragma warning(pop)


#if !defined(RC_INVOKED) && !defined(__midl)

#include <swprintf.inl>

#endif


#ifdef _CRT_NON_CONFORMING_SWPRINTFS

#ifndef __cplusplus

#define swprintf _swprintf

#define vswprintf _vswprintf

#define _swprintf_l __swprintf_l

#define _vswprintf_l __vswprintf_l

#endif

#endif


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma push_macro("_wtempnam")

#undef _wtempnam

#endif


_Check_return_ _CRTIMP wchar_t * __cdecl _wtempnam(_In_opt_z_ const wchar_t * _Directory, _In_opt_z_ const wchar_t * _FilePrefix);


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma pop_macro("_wtempnam")

#endif


_Check_return_ _CRTIMP int __cdecl _vscwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);

_Check_return_ _CRTIMP int __cdecl _vscwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);

_Check_return_ _CRT_INSECURE_DEPRECATE(fwscanf_s) _CRTIMP int __cdecl fwscanf(_Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fwscanf_s_l) _CRTIMP int __cdecl _fwscanf_l(_Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP int __cdecl fwscanf_s(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP int __cdecl _fwscanf_s_l(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_ _CRT_INSECURE_DEPRECATE(swscanf_s) _CRTIMP int __cdecl swscanf(_In_z_ const wchar_t * _Src, _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_swscanf_s_l) _CRTIMP int __cdecl _swscanf_l(_In_z_ const wchar_t * _Src, _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl swscanf_s(_In_z_ const wchar_t *_Src, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _swscanf_s_l(_In_z_ const wchar_t * _Src, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwscanf_s) _CRTIMP int __cdecl _snwscanf(_In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwscanf_s_l) _CRTIMP int __cdecl _snwscanf_l(_In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwscanf_s(_In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwscanf_s_l(_In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount, _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

_Check_return_ _CRT_INSECURE_DEPRECATE(wscanf_s) _CRTIMP int __cdecl wscanf(_In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);

_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_wscanf_s_l) _CRTIMP int __cdecl _wscanf_l(_In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

#if __STDC_WANT_SECURE_LIB__

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl wscanf_s(_In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);

#endif

_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _wscanf_s_l(_In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);

#pragma warning(pop)


_Check_return_ _CRTIMP FILE * __cdecl _wfdopen(_In_ int _FileHandle , _In_z_ const wchar_t * _Mode);

_Check_return_ _CRT_INSECURE_DEPRECATE(_wfopen_s) _CRTIMP FILE * __cdecl _wfopen(_In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode);

_Check_return_wat_ _CRTIMP errno_t __cdecl _wfopen_s(_Deref_out_opt_ FILE ** _File, _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode);

_Check_return_ _CRT_INSECURE_DEPRECATE(_wfreopen_s) _CRTIMP FILE * __cdecl _wfreopen(_In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _Inout_ FILE * _OldFile);

_Check_return_wat_ _CRTIMP errno_t __cdecl _wfreopen_s(_Deref_out_opt_ FILE ** _File, _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _Inout_ FILE * _OldFile);


#ifndef _CRT_WPERROR_DEFINED

#define _CRT_WPERROR_DEFINED

_CRTIMP void __cdecl _wperror(_In_opt_z_ const wchar_t * _ErrMsg);

#endif 

_Check_return_ _CRTIMP FILE * __cdecl _wpopen(_In_z_ const wchar_t *_Command, _In_z_ const wchar_t * _Mode);

_Check_return_ _CRTIMP int __cdecl _wremove(_In_z_ const wchar_t * _Filename);

_Check_return_wat_ _CRTIMP errno_t __cdecl _wtmpnam_s(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords);

__DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wtmpnam_s, _Deref_post_z_ wchar_t, _Buffer)

__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(wchar_t *, __RETURN_POLICY_DST, _CRTIMP, _wtmpnam, _Pre_maybenull_ _Post_z_, wchar_t, _Buffer)


_Check_return_opt_ _CRTIMP wint_t __cdecl _fgetwc_nolock(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wint_t __cdecl _fputwc_nolock(_In_ wchar_t _Ch, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP wint_t __cdecl _ungetwc_nolock(_In_ wint_t _Ch, _Inout_ FILE * _File);


#undef _CRT_GETPUTWCHAR_NOINLINE


#if !defined(__cplusplus) || defined(_M_CEE_PURE) || defined(_CRT_GETPUTWCHAR_NOINLINE)

#define getwchar()      fgetwc(stdin)

#define putwchar(_c)    fputwc((_c),stdout)

#else   /* __cplusplus */

inline wint_t __CRTDECL getwchar()

        {return (fgetwc(stdin)); }   /* stdin */

inline wint_t __CRTDECL putwchar(wchar_t _C)

        {return (fputwc(_C, stdout)); }       /* stdout */

#endif  /* __cplusplus */


#define getwc(_stm)             fgetwc(_stm)

#define putwc(_c,_stm)          fputwc(_c,_stm)

#define _putwc_nolock(_c,_stm)     _fputwc_nolock(_c,_stm)

#define _getwc_nolock(_stm)        _fgetwc_nolock(_stm)


#if defined(_CRT_DISABLE_PERFCRIT_LOCKS) && !defined(_DLL)

#define fgetwc(_stm)            _getwc_nolock(_stm)

#define fputwc(_c,_stm)         _putwc_nolock(_c,_stm)

#define ungetwc(_c,_stm)        _ungetwc_nolock(_c,_stm)

#endif


#define _WSTDIO_DEFINED

#endif  /* _WSTDIO_DEFINED */


#define _STDIO_DEFINED

#endif  /* _STDIO_DEFINED */



/* Macro definitions */


#if defined(_CRT_DISABLE_PERFCRIT_LOCKS) && !defined(_DLL)

#define feof(_stream)     ((_stream)->_flag & _IOEOF)

#define ferror(_stream)   ((_stream)->_flag & _IOERR)

#define _fileno(_stream)  ((_stream)->_file)

#define fgetc(_stream)     (--(_stream)->_cnt >= 0 \

                ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))

#define putc(_c,_stream)  (--(_stream)->_cnt >= 0 \

                ? 0xff & (*(_stream)->_ptr++ = (char)(_c)) :  _flsbuf((_c),(_stream)))

#define getc(_stream)    fgetc(_stream)

#define getchar()         getc(stdin)

#define putchar(_c)       putc((_c),stdout)

#endif



#define _fgetc_nolock(_stream)       (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))

#define _fputc_nolock(_c,_stream)    (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (char)(_c)) :  _flsbuf((_c),(_stream)))

#define _getc_nolock(_stream)       _fgetc_nolock(_stream)

#define _putc_nolock(_c, _stream)   _fputc_nolock(_c, _stream)

#define _getchar_nolock()           _getc_nolock(stdin)

#define _putchar_nolock(_c)         _putc_nolock((_c),stdout)

#define _getwchar_nolock()          _getwc_nolock(stdin)

#define _putwchar_nolock(_c)        _putwc_nolock((_c),stdout)


#ifdef _MT

_CRTIMP void __cdecl _lock_file(_Inout_ FILE * _File);

_CRTIMP void __cdecl _unlock_file(_Inout_ FILE * _File);

#else

#define _lock_file(c)

#define _unlock_file(c)

#endif



_Check_return_opt_ _CRTIMP int __cdecl _fclose_nolock(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fflush_nolock(_Inout_opt_ FILE * _File);

_Check_return_opt_ _CRTIMP size_t __cdecl _fread_nolock(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP size_t __cdecl _fread_nolock_s(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _DstSize, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fseek_nolock(_Inout_ FILE * _File, _In_ long _Offset, _In_ int _Origin);

_Check_return_ _CRTIMP long __cdecl _ftell_nolock(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _fseeki64_nolock(_Inout_ FILE * _File, _In_ __int64 _Offset, _In_ int _Origin);

_Check_return_ _CRTIMP __int64 __cdecl _ftelli64_nolock(_Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP size_t __cdecl _fwrite_nolock(_In_bytecount_x_(_Size*_Count) const void * _DstBuf, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);

_Check_return_opt_ _CRTIMP int __cdecl _ungetc_nolock(_In_ int _Ch, _Inout_ FILE * _File);


#if defined(_CRT_DISABLE_PERFCRIT_LOCKS) && !defined(_DLL)

#define fclose(_stm)                                            _fclose_nolock(_stm)

#define fflush(_stm)                                            _fflush_nolock(_stm)

#define fread(_DstBuf, _ElementSize, _Count, _File)             _fread_nolock(_DstBuf, _ElementSize, _Count, _File)

#define fread_s(_DstBuf, _DstSize, _ElementSize, _Count, _File) _fread_nolock_s(_DstBuf, _DstSize, _ElementSize, _Count, _File)

#define fseek(_stm,_offset,_origin)                             _fseek_nolock(_stm,_offset,_origin)

#define ftell(_stm)                                             _ftell_nolock(_stm)

#define _fseeki64(_stm,_offset,_origin)                         _fseeki64_nolock(_stm,_offset,_origin)

#define _ftelli64(_stm)                                         _ftelli64_nolock(_stm)

#define fwrite(_buf,_siz,_cnt,_stm)                             _fwrite_nolock(_buf,_siz,_cnt,_stm)

#define ungetc(_c,_stm)                                         _ungetc_nolock(_c,_stm)

#endif


#if     !__STDC__ && !defined(_POSIX_)


/* Non-ANSI names for compatibility */


#define P_tmpdir  _P_tmpdir

#define SYS_OPEN  _SYS_OPEN


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma push_macro("tempnam")

#undef tempnam

#endif


_CRT_NONSTDC_DEPRECATE(_tempnam) _CRTIMP char * __cdecl tempnam(_In_opt_z_ const char * _Directory, _In_opt_z_ const char * _FilePrefix);


#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)

#pragma pop_macro("tempnam")

#endif


_Check_return_opt_ _CRT_NONSTDC_DEPRECATE(_fcloseall) _CRTIMP int __cdecl fcloseall(void);

_Check_return_ _CRT_NONSTDC_DEPRECATE(_fdopen) _CRTIMP FILE * __cdecl fdopen(_In_ int _FileHandle, _In_z_ const char * _Format);

_Check_return_opt_ _CRT_NONSTDC_DEPRECATE(_fgetchar) _CRTIMP int __cdecl fgetchar(void);

_Check_return_ _CRT_NONSTDC_DEPRECATE(_fileno) _CRTIMP int __cdecl fileno(_In_ FILE * _File);

_Check_return_opt_ _CRT_NONSTDC_DEPRECATE(_flushall) _CRTIMP int __cdecl flushall(void);

_Check_return_opt_ _CRT_NONSTDC_DEPRECATE(_fputchar) _CRTIMP int __cdecl fputchar(_In_ int _Ch);

_Check_return_ _CRT_NONSTDC_DEPRECATE(_getw) _CRTIMP int __cdecl getw(_Inout_ FILE * _File);

_Check_return_opt_ _CRT_NONSTDC_DEPRECATE(_putw) _CRTIMP int __cdecl putw(_In_ int _Ch, _Inout_ FILE * _File);

_Check_return_ _CRT_NONSTDC_DEPRECATE(_rmtmp) _CRTIMP int __cdecl rmtmp(void);


#endif  /* __STDC__ */


#ifdef  __cplusplus

}

#endif


#ifdef  _MSC_VER

#pragma pack(pop)

#endif  /* _MSC_VER */


#endif  /* _INC_STDIO */


만일 헤더 파일이라는 것이 존재하지 않았더라면 우리는 printf 함수를 이용하기 위해서 위 모든 내용은 아니지만 적어도 printf 함수의 원형을 써주어야 하는데 이는   

```cpp
_Check_return_opt_ _CRTIMP int __cdecl printf(_In_z_ _Printf_format_string_ const char * _Format, ...);   
```


로 무지하게 복잡합니다. 아무튼, 이렇게 printf, scanf 함수와 같이 매 함수를 쓰기 위해서 위 모든 내용을 쓰는 것 대신에 헤더파일 include 하나로 간단하게 해결할 수 있습니다.   

보통 헤더파일을 만들 때 에는 그 헤더파일에 있는 함수들이 정의되어 있는 소스 파일의 이름을 따서 짓는 것이 보통입니다. 위 경우 str.h 에 선언되어 있는 함수들이 모두 str.c 에 정의되어 있으므로 헤더파일의 이름을 str.h 로 하였습니다. 또한 한 가지 흥미로운 점은 str.c 에서도 str.h 를 include 하고 있다는 점입니다.   

이는 다음과 같은 상황을 방지할 수 있습니다.   

```info
/* something.c */   int A()   {       B();       return 0;   }   int B()   {       return 1;   }   
```


만일 something.c 라는 파일에 위와 같은 소스가 있다고 합시다. 이는 100% 오류가 발생됩니다. 왜냐하면 A() 함수에서 B() 를 호출할 때 B 가 무엇인지 뭔지 모르므로 오류가 발생하게 되는 것이지요. (이는 함수 단원에서 공부한 한 바 입니다) 다시 말해 B() 를 위에 선언 해주어야 합니다. 아래와 같이요.   

```info
/* something.c */   int B();   int A()   {       B();       return 0;   }   int B()   {       return 1;   }   
```


하지만 헤더파일을 배웠으니 차라리 이렇게 할 바에는 아래와 같이 하는 것이 훨씬 낫을 것이라는 거죠.   

```info
/* something.c */   #include "something.h"   int A()   {       B();       return 0;   }   int B()   {       return 1;   }   
```





```info
/* something.h*/   int A();   int B();   
```


이와 같은 이유로 str.c 에서도 (이 경우 꼭 필요는 없었지만) str.h 를 include 해준 것입니다.   

도서 관리 프로그램 리모델링

그렇다면 이번에는 여태까지 쌓은 지식을 바탕으로 이전에 만들었던 도서 관리 프로그램을 파일을 나누어서 깔끔하게 만들어봅시다.   

아래는 기존의 소스 입니다.   

```cpp
#include <stdio.h>   int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],                int *borrowed, int *num_total_book);   int search_book(char (*book_name)[30], char (*auth_name)[30],                   char (*publ_name)[30], int num_total_book);   char compare(char *str1, char *str2);   int borrow_book(int *borrowed);   int return_book(int *borrowed);   int main ()   {       int user_choice; /* 유저가 선택한 메뉴 */       int num_total_book = 0; /* 현재 책의 수 */       /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/       char book_name[100][30], auth_name[100][30], publ_name[100][30];       /* 빌렸는지 상태를 표시 */       int borrowed[100];       while (1)       {           printf("도서 관리 프로그램 \n");           printf("메뉴를 선택하세요 \n");           printf("1. 책을 새로 추가하기 \n");           printf("2. 책을 검색하기 \n");           printf("3. 책을 빌리기 \n");           printf("4. 책을 반납하기 \n");           printf("5. 프로그램 종료 \n");           printf("당신의 선택은 : ");           scanf("%d", &user_choice);           if(user_choice == 1)           {               /* 책을 새로 추가하는 함수 호출 */               add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);           }           else if(user_choice == 2)           {               /* 책을 검색하는 함수 호출 */               search_book(book_name, auth_name, publ_name, num_total_book);           }           else if(user_choice == 3)           {               /* 책을 빌리는 함수 호출 */               borrow_book(borrowed);           }           else if(user_choice == 4)           {               /* 책을 반납하는 함수 호출 */               return_book(borrowed);           }           else if(user_choice == 5)           {               /* 프로그램을 종료한다. */               break;           }       }       return 0;   }   /* 책을 추가하는 함수*/   int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],                int *borrowed, int *num_total_book)   {       printf("추가할 책의 제목 : ");       scanf("%s", book_name[*num_total_book]);       printf("추가할 책의 저자 : ");       scanf("%s", auth_name[*num_total_book]);       printf("추가할 책의 출판사 : ");       scanf("%s", publ_name[*num_total_book]);       borrowed[*num_total_book] = 0; /* 빌려지지 않음*/       printf("추가 완료! \n");       (*num_total_book)++;       return 0;   }   /* 책을 검색하는 함수 */   int search_book(char (*book_name)[30], char (*auth_name)[30],                   char (*publ_name)[30], int num_total_book)   {       int user_input; /* 사용자의 입력을 받는다. */       int i;       char user_search[30];       printf("어느 것으로 검색 할 것인가요? \n");       printf("1. 책 제목 검색 \n");       printf("2. 지은이 검색 \n");       printf("3. 출판사 검색 \n");       scanf("%d", &user_input);       printf("검색할 단어를 입력해주세요 : ");       scanf("%s", user_search);       printf("검색 결과 \n");       if(user_input == 1)       {           /*           i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을           사용자가 입력한 검색어와 비교하고 있다.           */           for(i = 0;i < num_total_book; i++)           {               if(compare(book_name[i], user_search))               {                   printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                       i, book_name[i], auth_name[i], publ_name[i] );               }           }       }       else if(user_input == 2)       {           /*           i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을           사용자가 입력한 검색어와 비교하고 있다.           */           for(i = 0;i < num_total_book; i++)           {               if(compare(auth_name[i], user_search))               {                   printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                       i, book_name[i], auth_name[i], publ_name[i] );               }           }       }       else if(user_input == 3)       {           /*           i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를           사용자가 입력한 검색어와 비교하고 있다.           */           for(i = 0;i < num_total_book; i++)           {               if(compare(publ_name[i], user_search))               {                   printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                       i, book_name[i], auth_name[i], publ_name[i] );               }           }       }       return 0;   }   char compare(char *str1, char *str2)   {       while (*str1)       {           if(*str1 != *str2)           {               return 0;           }           str1++;           str2++;       }       if(*str2 == '\0')           return 1;       return 0;   }   int borrow_book(int *borrowed)   {       /* 사용자로 부터 책번호를 받을 변수*/       int book_num;       printf("빌릴 책의 번호를 말해주세요 \n");       printf("책 번호 : ");       scanf("%d", &book_num);       if(borrowed[book_num] == 1)       {           printf("이미 대출된 책입니다! \n");       }       else       {           printf("책이 성공적으로 대출되었습니다. \n");           borrowed[book_num] = 1;       }       return 0;   }   int return_book(int *borrowed)   {       /* 반납할 책의 번호 */       int num_book;       printf("반납할 책의 번호를 써주세요 \n");       printf("책 번호 : ");       scanf("%d", &num_book);       if(borrowed[num_book] == 0)       {           printf("이미 반납되어 있는 상태입니다\n");       }       else       {           borrowed[num_book] = 0;           printf("성공적으로 반납되었습니다\n");       }       return 0;   }   
```

파일들로 나누기 전에 가장 먼저 고려해야 할 사실은 바로 '어떠한 파일들로 나눌 것인가?’ 입니다. 파일을 나눌 때 가장 먼저 살펴보아야 할 점은 각 파일들을 특정한 역할을 가지도록 나누는 것인데 우리의 프로그램의 경우 다음과 같이 나누면 될 것 같습니다.main 함수를 가지는 test.c , 도서 관리 함수들을 가지는 book_function.c, 그리고 문자열 관리 함수를 가지는 str.c 로 나누면 될 것 같습니다. 따라서 book_function.h 와 str.h 라는 헤더파일도 가지겠네요. 
먼저 가장 단순한 str.c 부터 봅시다. str.c 에는 compare 함수가 들어가면 적당할 것 같습니다.```cpp

/* str.c */
#include "str.h" 
char compare(char *str1, char *str2)    {         while (*str1)         {             if(*str1 != *str2)             {                 return 0;             } 
        str1++;            str2++;         } 
    if(*str2 == '\0')            return 1; 
    return 0;    }
```



또한 str.h 에는 compare 함수의 원형이 선언되어 있죠.

```cpp

/* str.h */
char compare(char *str1, char *str2);
```



그럼 이제, 책들을 처리하는 함수들을 모아놓은 book_function.c 를 살펴봅시다. 단순하게 생각해보면 아래와 같이 하면 될 것 같습니다. 

```cpp

#include "book_function.h" 
/* 책을 추가하는 함수*/   int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],                 int *borrowed, int *num_total_book)    {        printf("추가할 책의 제목 : ");        scanf("%s", book_name[*num_total_book]); 
    printf("추가할 책의 저자 : ");       scanf("%s", auth_name[*num_total_book]); 

    printf("추가할 책의 출판사 : ");       scanf("%s", publ_name[*num_total_book]); 
    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/       printf("추가 완료! \n");        (*num_total_book)++; 
    return 0;   }    /* 책을 검색하는 함수 */    int search_book(char (*book_name)[30], char (*auth_name)[30],                    char (*publ_name)[30], int num_total_book)    {        int user_input; /* 사용자의 입력을 받는다. */        int i;        char user_search[30]; 
    printf("어느 것으로 검색 할 것인가요? \n");       printf("1. 책 제목 검색 \n");        printf("2. 지은이 검색 \n");        printf("3. 출판사 검색 \n");        scanf("%d", &user_input); 
    printf("검색할 단어를 입력해주세요 : ");       scanf("%s", user_search); 
    printf("검색 결과 \n"); 
    if(user_input == 1)       {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(book_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            } 
    }       else if(user_input == 2)        {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(auth_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            } 

    }       else if(user_input == 3)        {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(publ_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            }        } 
    return 0;   }    int borrow_book(int *borrowed)    {        /* 사용자로 부터 책번호를 받을 변수*/        int book_num; 
    printf("빌릴 책의 번호를 말해주세요 \n");       printf("책 번호 : ");        scanf("%d", &book_num); 
    if(borrowed[book_num] == 1)       {            printf("이미 대출된 책입니다! \n");        }        else        {            printf("책이 성공적으로 대출되었습니다. \n");            borrowed[book_num] = 1;        } 
    return 0;   }    int return_book(int *borrowed)    {        /* 반납할 책의 번호 */        int num_book; 
    printf("반납할 책의 번호를 써주세요 \n");       printf("책 번호 : ");        scanf("%d", &num_book); 
    if(borrowed[num_book] == 0)       {            printf("이미 반납되어 있는 상태입니다\n");        }        else        {            borrowed[num_book] = 0;            printf("성공적으로 반납되었습니다\n");        } 
    return 0;   }
```



그런데 이렇게 하게 되면 100% 오류가 발생하게 됩니다. 왜냐하면 add_book 함수의 경우만 보아도 printf 함수와 scanf 함수를 사용하고 있기 때문이죠. 이 함수들을 사용하기 위해서는 stdio.h 를 꼭 include 해주어야 합니다. 뿐만 아니라 search_book 함수의 경우 compare 함수를 호출하고 있는데 이 때문에 역시 str.h 를 include 해주어야 합니다. 따라서 올바른 book_function.c 의 모습은 아래와 같이 되어야 합니다. 

```cpp

/* book_function.c  */
#include <stdio.h>   #include "str.h"    #include "book_function.h" 
/* 책을 추가하는 함수*/   int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],                 int *borrowed, int *num_total_book)    {        printf("추가할 책의 제목 : ");        scanf("%s", book_name[*num_total_book]); 

    printf("추가할 책의 저자 : ");       scanf("%s", auth_name[*num_total_book]); 
    printf("추가할 책의 출판사 : ");       scanf("%s", publ_name[*num_total_book]); 
    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/       printf("추가 완료! \n");        (*num_total_book)++; 
    return 0;   }    /* 책을 검색하는 함수 */    int search_book(char (*book_name)[30], char (*auth_name)[30],                    char (*publ_name)[30], int num_total_book)    {        int user_input; /* 사용자의 입력을 받는다. */        int i;        char user_search[30]; 
    printf("어느 것으로 검색 할 것인가요? \n");       printf("1. 책 제목 검색 \n");        printf("2. 지은이 검색 \n");        printf("3. 출판사 검색 \n");        scanf("%d", &user_input); 
    printf("검색할 단어를 입력해주세요 : ");       scanf("%s", user_search); 
    printf("검색 결과 \n"); 
    if(user_input == 1)       {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(book_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            } 
    }       else if(user_input == 2)        {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(auth_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            } 
    }       else if(user_input == 3)        {            /* 
        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를           사용자가 입력한 검색어와 비교하고 있다. 
        */           for(i = 0;i < num_total_book; i++)            {                if(compare(publ_name[i], user_search))                {                    printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                        i, book_name[i], auth_name[i], publ_name[i] );                }            }        } 
    return 0;   }    int borrow_book(int *borrowed)    {        /* 사용자로 부터 책번호를 받을 변수*/        int book_num; 
    printf("빌릴 책의 번호를 말해주세요 \n");       printf("책 번호 : ");        scanf("%d", &book_num); 
    if(borrowed[book_num] == 1)       {            printf("이미 대출된 책입니다! \n");        }        else        {            printf("책이 성공적으로 대출되었습니다. \n");            borrowed[book_num] = 1;        } 
    return 0;   }    int return_book(int *borrowed)    {        /* 반납할 책의 번호 */        int num_book; 
    printf("반납할 책의 번호를 써주세요 \n");       printf("책 번호 : ");        scanf("%d", &num_book); 
    if(borrowed[num_book] == 0)       {            printf("이미 반납되어 있는 상태입니다\n");        }        else        {            borrowed[num_book] = 0;            printf("성공적으로 반납되었습니다\n");        } 
    return 0;   }
```



또한 당연하게도 book_function.h 의 모습은 아래와 같겠죠.

```cpp

/* book_function.h */
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],                int *borrowed, int *num_total_book);    int search_book(char (*book_name)[30], char (*auth_name)[30],                    char (*publ_name)[30], int num_total_book); 
int borrow_book(int *borrowed);   int return_book(int *borrowed);
```



이제 마지막으로 main 함수가 있는 test.c 를 살펴볼 차례 입니다.

main 함수에서는 printf 와 scanf 등과, book_function 에 정의되어 있는 함수들을 사용하고 있고 compare 함수는 사용하지 않으므로 다음과 같이만 해주면 됩니다.

```cpp

/* test.c */
#include <stdio.h>   #include "book_function.h" 
int main ()   {        int user_choice; /* 유저가 선택한 메뉴 */        int num_total_book = 0; /* 현재 책의 수 */ 
    /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/       char book_name[100][30], auth_name[100][30], publ_name[100][30];        /* 빌렸는지 상태를 표시 */        int borrowed[100]; 
    while (1)       {            printf("도서 관리 프로그램 \n");            printf("메뉴를 선택하세요 \n");            printf("1. 책을 새로 추가하기 \n");            printf("2. 책을 검색하기 \n");            printf("3. 책을 빌리기 \n");            printf("4. 책을 반납하기 \n");            printf("5. 프로그램 종료 \n"); 
        printf("당신의 선택은 : ");           scanf("%d", &user_choice); 
        if(user_choice == 1)           {                /* 책을 새로 추가하는 함수 호출 */                add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);            }            else if(user_choice == 2)            {                /* 책을 검색하는 함수 호출 */                search_book(book_name, auth_name, publ_name, num_total_book);            }            else if(user_choice == 3)            {                /* 책을 빌리는 함수 호출 */                borrow_book(borrowed);            }            else if(user_choice == 4)            {                /* 책을 반납하는 함수 호출 */                return_book(borrowed);            }            else if(user_choice == 5)            {                /* 프로그램을 종료한다. */                break;            }        } 
    return 0;   }
```



어때요? 꽤 간단하지요. 이 작업을 한 후 컴파일 후 실행하면 역시나 잘 작동됨을 알 수 있습니다. 이렇게 여러분은 파일을 나누는 방법에 대해서 알게 되었습니다. 이렇게 파일을 나누어서 처리하게 되면 상당히 체계적으로 프로그래밍을 할 수 있는데 이렇게 하는 프로그래밍을 모듈화 프로그래밍 (modular programming) 이라고 합니다. 즉 프로그램의 각 부분 부분을 나누어서 따로 처리 한다는 의미지요. 

우리는 여태까지 헤더 파일에는 함수의 선언 밖에 쓰지 않았지만 사실 헤더파일에도 많은 것들이 올 수 있습니다. 이에 대해서는 다음 시간에 알아보도록 합시다.

생각해 볼 문제


1. 위 도서 관리 프로그램을 구조체를 이용하여 만든 것이 있을 것입니다. (http://itguru.tistory.com/60 생각해 볼 문제 참조) 이 역시 위와 같이 파일로 쪼개 보세요. 




```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면 꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요. 현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <18 - 1. 파일 뽀개기 (헤더파일과 #include) >>> 입니다. 이번 강좌의 모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요 
다음 강좌 보러가기
```





공감sns신고
저작자표시

'C' 카테고리의 다른 글씹어먹는 C 언어 - <19. main 함수의 인자, 텅 빈 void 형>(32)
2010.08.02씹어먹는 C 언어 - <18 - 2. 파일 뽀개기 (# 친구들, 라이브러리)>(13)
2010.07.20씹어먹는 C 언어 - <18 - 1. 파일 뽀개기 (헤더파일과 #include) >(24)
2010.07.16씹어먹는 C 언어 - <17. 변수의 생존 조건 및 데이터 세그먼트의 구조>(14)
2010.06.19씹어먹는 C 언어 - <16 - 3. 구조체와 친구들(공용체(union), 열거형(enum))>(20)
2010.06.13씹어먹는 C 언어 - <16 - 2. 모아 모아 구조체(struct) - 구조체 인자로 가진 함수>(41)
2010.04.11


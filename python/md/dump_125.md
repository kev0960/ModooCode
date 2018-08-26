

이번 강좌에서는
* 지난 도서 관리 프로그램의 완성
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F141419474D331BC506AB6C)


  안녕하세요 여러분! 이제 슬슬 파일 입출력도 마무리를 해가며 저의 C 언어 강좌도 끝을 향해 달려갑니다. 이번 강좌에서는 파일 입출력을 이용한 여러 가지 프로그램을 만들어보면서 파일 입출력에 대해 조금 더 친해지도록 하지요 :)   

  지난 강좌에서 여러분들과 함께 도서 관리 프로그램을 열심히 만들었었습니다. 그리고 제가 여러분들께 '생각해보기' 로 입력을 받는 형태로 바꿔보자고 이야기 했었죠. 여러분들은 모두 해보셨나요? 아직 오랜 시간 고민을 하지 안 하신 분들은 살포시 뒤로가기를 눌러주시기 바랍니다.   

```cpp
/* 도서 관리 프로그램의 전체 소스 코드*/   
#include <stdio.h>   
#include <string.h>   
#include <stdlib.h>   

struct BOOK   
{   
    char book_name[30];   
    char auth_name[30];   
    char publ_name[30];   
    int borrowed;   
};   

typedef struct BOOK BOOK;   
int register_book(BOOK *book_list, int *nth);   
int search_book(BOOK *book_list, int total_num_book);   
int borrow_book(BOOK *book_list);   
int return_book(BOOK *book_list);   
int print_book_list(BOOK *book_list, int total_num_book);   
int retrieve_book_info(BOOK **book_list, int *total_num_book);   
char compare(char *str1, char *str2);   

int main ()   
{   
    int user_choice; /* 유저가 선택한 메뉴 */   
    int num_total_book = 0; /* 현재 책의 수 */   

    BOOK *book_list;   
    int i;   

    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");   
    scanf("%d", &user_choice);   

    book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);   

    while (1)   
    {   
        printf("도서 관리 프로그램 \n");   
        printf("메뉴를 선택하세요 \n");   
        printf("1. 책을 새로 추가하기 \n");   
        printf("2. 책을 검색하기 \n");   
        printf("3. 책을 빌리기 \n");   
        printf("4. 책을 반납하기 \n");   
        printf("5. 프로그램 종료 \n");   
        printf("6. 책들의 내용을 book_list.txt 에 출력 \n");   
        printf("7. 책들의 내용을 book_list.txt 에서 불러옴 \n");   
        printf("8. 책들의 목록을 출력 \n");   

        printf("당신의 선택은 : ");   
        scanf("%d", &user_choice);   

        if(user_choice == 1)   
        {   
            /* 책을 새로 추가하는 함수 호출 */   
            register_book(book_list, &num_total_book);   
        }   
        else if(user_choice == 2)   
        {   
            /* 책을 검색하는 함수 호출 */   
            search_book(book_list, num_total_book);   
        }   
        else if(user_choice == 3)   
        {   
            /* 책을 빌리는 함수 호출 */   
            borrow_book(book_list);   
        }   
        else if(user_choice == 4)   
        {   
            /* 책을 반납하는 함수 호출 */   
            return_book(book_list);   
        }   
        else if(user_choice == 5)   
        {   
            /* 프로그램을 종료한다. */   
            break;   
        }   
        else if(user_choice == 6)   
        {   
            /* book_list.txt 에 책들의 목록을 출력한다*/   
            print_book_list(book_list, num_total_book);   
        }   
        else if(user_choice == 7)   
        {   
            /* book_list.txt 에서 책들의 목록을 가져온다*/   
            retrieve_book_info(&book_list, &num_total_book);   
        }   
        else if(user_choice == 8)   
        {   
            /* 책들의 목록을 화면에 출력한다. */   
            for(i = 0; i < num_total_book; i++)   
            {   
                printf("%s // %s // %s // ", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
                if(book_list[i].borrowed == 0)   
                    printf("NO\n");   
                else   
                    printf("YES\n");   
            }   
        }   
    }   

    free(book_list);   
    return 0;   
}   
int print_book_list(BOOK *book_list, int total_num_book)   
{   
    FILE *fp = fopen("book_list.txt", "w");   
    int i;   

    if(fp == NULL)   
    {   
        printf("출력 오류 ! \n");   
        return -1;   
    }   

    fprintf(fp, "%d\n", total_num_book);   

    for(i = 0; i < total_num_book; i++)   
    {   
        fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
        if(book_list[i].borrowed == 0)   
            fprintf(fp, "NO\n");   
        else   
            fprintf(fp, "YES\n");   
    }   

    printf("출력 완료! \n");   
    fclose(fp);   

    return 0;   
}   
char compare(char *str1, char *str2)   
{   
    while (*str1)   
    {   
        if(*str1 != *str2)   
        {   
            return 0;   
        }   

        str1++;   
        str2++;   
    }   

    if(*str2 == '\0')   
        return 1;   

    return 0;   
}   

/* 포인터인 book_list 의 값을 바꿔야 하므로 더블 포인터 형태 */   
int retrieve_book_info(BOOK **book_list, int *total_num_book)   
{   
    FILE *fp = fopen("book_list.txt", "r");   
    int total_book;   
    int i;   
    char str[10];   

    if(fp == NULL)   
    {   
        printf("지정한 파일을 찾을 수 없습니다! \n");   
        return -1;   
    }   

    /* 찾았다면 전체 책의 개수를 읽어온다. */   
    fscanf(fp, "%d", &total_book);   
    (*total_num_book) = total_book;   

    /* 기존의 book_list 데이터를 삭제 */   
    free(*book_list);   
    /* 그리고 다시 malloc 으로 재할당 한다. */   
    (*book_list) = (BOOK *)malloc(sizeof(BOOK)*total_book);   

    if(*book_list == NULL)   
    {   
        printf("\n ERROR \n");   
        return -1;   
    }   
    for(i=0;i<total_book;i++)   
    {   
        /* book_list[i]->book_name 이 아님에 유의!! */   
        fscanf(fp, "%s", (*book_list)[i].book_name);   
        fscanf(fp, "%s", (*book_list)[i].auth_name);   
        fscanf(fp, "%s", (*book_list)[i].publ_name);   
        fscanf(fp, "%s", str);   

        if(compare(str, "YES"))   
        {   
            (*book_list)[i].borrowed = 1;   
        }   
        else if(compare(str, "NO"))   
        {   
            (*book_list)[i].borrowed = 0;   
        }   
    }   

    fclose(fp);   
    return 0;   

}   
/* 책을 추가하는 함수*/   
int register_book(BOOK *book_list, int *nth)   
{   
    printf("책의 이름 : ");   
    scanf("%s", book_list[*nth].book_name);   

    printf("책의 저자 : ");   
    scanf("%s", book_list[*nth].auth_name);   

    printf("책의 출판사 : ");   
    scanf("%s", book_list[*nth].publ_name);   

    book_list[*nth].borrowed = 0;   
    (*nth)++;   

    return 0;   
}   
/* 책을 검색하는 함수 */   
int search_book(BOOK *book_list, int total_num_book)   
{   
    int user_input; /* 사용자의 입력을 받는다. */   
    int i;   
    char user_search[30];   

    printf("어느 것으로 검색 할 것인가요? \n");   
    printf("1. 책 제목 검색 \n");   
    printf("2. 지은이 검색 \n");   
    printf("3. 출판사 검색 \n");   
    scanf("%d", &user_input);   

    printf("검색할 단어를 입력해주세요 : ");   
    scanf("%s", user_search);   

    printf("검색 결과 \n");   

    if(user_input == 1)   
    {   
        /*   

        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을   
        사용자가 입력한 검색어와 비교하고 있다.   

        */   
        for(i = 0;i < total_num_book; i++)   
        {   
            if(compare(book_list[i].book_name, user_search))   
            {   
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",   
                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
            }   
        }   

    }   
    else if(user_input == 2)   
    {   
        /*   

        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을   
        사용자가 입력한 검색어와 비교하고 있다.   

        */   
        for(i = 0;i < total_num_book; i++)   
        {   
            if(compare(book_list[i].auth_name, user_search))   
            {   
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",   
                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
            }   
        }   

    }   
    else if(user_input == 3)   
    {   
        /*   

        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를   
        사용자가 입력한 검색어와 비교하고 있다.   

        */   
        for(i = 0;i < total_num_book; i++)   
        {   
            if(compare(book_list[i].publ_name, user_search))   
            {   
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",   
                    i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
            }   
        }   
    }   

    return 0;   
}   
int borrow_book(BOOK *book_list)   
{   
    /* 사용자로 부터 책번호를 받을 변수*/   
    int book_num;   

    printf("빌릴 책의 번호를 말해주세요 \n");   
    printf("책 번호 : ");   
    scanf("%d", &book_num);   

    if(book_list[book_num].borrowed == 1)   
    {   
        printf("이미 대출된 책입니다! \n");   
    }   
    else   
    {   
        printf("책이 성공적으로 대출되었습니다. \n");   
        book_list[book_num].borrowed = 1;   
    }   

    return 0;   
}   
int return_book(BOOK *book_list)   
{   
    /* 반납할 책의 번호 */   
    int num_book;   

    printf("반납할 책의 번호를 써주세요 \n");   
    printf("책 번호 : ");   
    scanf("%d", &num_book);   

    if(book_list[num_book].borrowed == 0)   
    {   
        printf("이미 반납되어 있는 상태입니다\n");   
    }   
    else   
    {   
        book_list[num_book].borrowed = 0;   
        printf("성공적으로 반납되었습니다\n");   
    }   

    return 0;   
}   
```


성공적으로 컴파일 하였다면   

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F126815394D2F31B9209A2B)

와 같이 여러가지 기능들이 잘 작동함을 알 수 있습니다.   

일단, 저는 지난번 강좌의 '생각해보기' 에서 일컫은대로 print_book_list 함수의 파일 출력 형태를 수정하였습니다.   

```cpp
int print_book_list(BOOK *book_list, int total_num_book)   
{   
    FILE *fp = fopen("book_list.txt", "w");   
    int i;   

    if(fp == NULL)   
    {   
        printf("출력 오류 ! \n");   
        return -1;   
    }   

    fprintf(fp, "%d\n", total_num_book);   

    for(i = 0; i < total_num_book; i++)   
    {   
        fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);   
        if(book_list[i].borrowed == 0)   
            fprintf(fp, "NO\n");   
        else   
            fprintf(fp, "YES\n");   
    }   

    printf("출력 완료! \n");   
    fclose(fp);   

    return 0;   
}   
```


  일단 출력을 위해 fprintf 함수를 사용하고 있는데 문자열을 하나 출력할 때 마다 \n 을 넣어서 나중에 파일에서 입력받을 때 구분을 용이하게 하였습니다. print_book_list 함수는 상당히 간단하므로 설명은 이 정도에서 마치도록 하겠고요, 이제 가장 중요한 부분인 retrieve_book_list 함수에 대해 살펴봅시다.   

```cpp
/* 포인터인 book_list 의 값을 바꿔야 하므로 더블 포인터 형태 */   
int retrieve_book_info(BOOK **book_list, int *total_num_book)   
{   
    FILE *fp = fopen("book_list.txt", "r");   
    int total_book;   
    int i;   
    char str[10];   

    if(fp == NULL)   
    {   
        printf("지정한 파일을 찾을 수 없습니다! \n");   
        return -1;   
    }   

    /* 찾았다면 전체 책의 개수를 읽어온다. */   
    fscanf(fp, "%d", &total_book);   
    (*total_num_book) = total_book;   

    /* 기존의 book_list 데이터를 삭제 */   
    free(*book_list);   
    /* 그리고 다시 malloc 으로 재할당 한다. */   
    (*book_list) = (BOOK *)malloc(sizeof(BOOK)*total_book);   

    if(*book_list == NULL)   
    {   
        printf("\n ERROR \n");   
        return -1;   
    }   
    for(i=0;i<total_book;i++)   
    {   
        /* book_list[i]->book_name 이 아님에 유의!! */   
        fscanf(fp, "%s", (*book_list)[i].book_name);   
        fscanf(fp, "%s", (*book_list)[i].auth_name);   
        fscanf(fp, "%s", (*book_list)[i].publ_name);   
        fscanf(fp, "%s", str);   

        if(compare(str, "YES"))   
        {   
            (*book_list)[i].borrowed = 1;   
        }   
        else if(compare(str, "NO"))   
        {   
            (*book_list)[i].borrowed = 0;   
        }   
    }   

    fclose(fp);   
    return 0;   
}   
```


이 함수를 처음에 만들때 저는 살짝 실수를 했었는데요, 그것은 바로 인자의 형태를 잘못 생각하였기 때문입니다. 일단 이 함수에서 하는 일들을 살펴보자면   

1. 기존의 프로그램상에 저장되어 있던 book_list 정보를 없앤다. (간단히 메모리를 free 한다고 생각하시면 됩니다) 파일에서 입력받은 책의 수 많큼 malloc 으로 book_list 에 할당한다. 파일에 책들에 관한 데이터들을 입력받는다.      

으로 보실 수 있습니다. 먼저 1 번 작업을 하는 부분을 살펴봅시다.    

```cpp
int retrieve_book_info(BOOK **book_list, int *total_num_book)     
{     
    /*  ...(생략) ...*/     

    /* 찾았다면 전체 책의 개수를 읽어온다. */     
    fscanf(fp, "%d", &total_book);     
    (*total_num_book) = total_book;     

    /* 기존의 book_list 데이터를 삭제 */     
    free(*book_list);     
```


함수의 인자 부분이 굵은 글씨체로 되어 있는데 아마도 여러분들 중 많은 분들이 간과했을 부분 입니다. 우리는 이 함수에서 malloc 을 통해 book_list 를 다시 할당 하면서 book_list 의 값을 바꿔야 하는데요, 이전의 저의 함수 강좌를 잘 보신 분들은 알겠지만 다른 함수에서 또다른 함수 내부에서 정의된 변수의 값을 바꾸기 위해서는 그 변수의 포인터를 인자로 전달해야 한다고 했습니다. 즉, book_list 를 가리키는 포인터, 이 때 book_list 가 BOOK* 형이므로 우리는 인자를 BOOK ** 형으로 잡아야 한다는 것을 알 수 있지요.     

이제 인자로 book_list 를 받았다면 위와 같이 free 를 통해 메모리 공간을 반환 함으로써 이전에 저장되어 있는 책 목록 데이터를 없앨 수 있습니다.     

```cpp
    /* 그리고 다시 malloc 으로 재할당 한다. */     
    (*book_list) = (BOOK *)malloc(sizeof(BOOK)*total_book);     

    if(*book_list == NULL)     
    {     
        printf("\n ERROR \n");     
        return -1;     
    }     
```


이제 두 번째 단계를 살펴보도록 합시다. 아까 위에서 free 함수를 통해 우리가 동적으로 할당하였던 Heap 공간에 있었던 데이터들은 날라가버렸습니다. 이제 다시 malloc 을 통해 책 목록에서 입력받는 total_book 의 크기 만큼 다시 할당 해야 겠지요? 따라서 위와 같이 malloc 함수를 통해 할당할 수 있게 됩니다.

여기서 중요한 부분은 위와 같이 *book_list == NULL 을 통해 malloc 으로 메모리 할당이 제대로 이루어졌는지 확인할 수 있습니다. 이는 마치 파일 입출력에서 fp == NULL 로 검사하는 것과 비슷한 이치 입니다. 
```cpp
      for(i=0;i<total_book;i++)   
    {   
        /* book_list[i]->book_name 이 아님에 유의!! */   
        fscanf(fp, "%s", (*book_list)[i].book_name);   
        fscanf(fp, "%s", (*book_list)[i].auth_name);   
        fscanf(fp, "%s", (*book_list)[i].publ_name);   
        fscanf(fp, "%s", str);   

        if(compare(str, "YES"))   
        {   
            (*book_list)[i].borrowed = 1;   
        }   
        else if(compare(str, "NO"))   
        {   
            (*book_list)[i].borrowed = 0;   
        }   
    }   
```



마지막으로 for 문을 통해서 파일로 부터 입력 받는 부분을 살펴봅시다. 여기서 fscanf 를 통해 문자열을 파일로 부터 입력을 받고 있는데 재미있는 부분은 book_list 의 구조체 변수들을 참조하는 과정 입니다. 왜 저렇게 어렵게 표현을 했을까요? 

일단 *book_list 를 통해서 원래 main 함수의 book_list 배열을 가리킬 수 있습니다. 그리고 (*book_list)[i] 를 통해 그 배열의 i 번째 원소를 가리킬 수 있지요. 이 때 그 원소는 구조체 변수 입니다. 따라서 우리는 (*book_list)[i].book_name 을 통해 main 함수의 특정 책의 책 이름에 대한 정보를 지칭할 수 있게 되지요. 이를 전개해서 표현 시켜 보면

```cpp
(*(*book_list) + i)).book_name
```



이라 쓴 것과 동일한 표현이 됩니다. 그런데 문제는 이와 같이 포인터를 이용할 때 간혹 다음과 같이 쓰는 사람들이 있기 마련이죠.

```cpp
book_list[i]->book_name
```



사실 저도 처음에 이렇게 썼다가 봉변을 맞았었는데 이렇게 사용하면 컴파일 시에 오류가 나지도 않고 디버깅 해도 도대체 뭐가 문제인지 알기 어렵습니다. 원래는 (*book_lsit)[i].book_name 이라고 머리 속에 생각은 하고 위와 같은 코드가 튀어 나왔지요. 그런데 이 둘은 완전히 다른 문장 입니다. 무엇이 다른지는 말그대로 전개를 시켜보면 알 수 있습니다.

```cpp

(*book_list)[i].book_name == ( *( *book_list + i)).book_name
book_list[i]->book_name == (  *( *(book_list + i))).book_name
```



무엇이 다른지 확 눈에 보이시나요? 위의 식에서는 book_list 에 먼저 * 이 붙었고 아래 식에서는 book_list + i 에 먼저 * 이 붙었습니다. 우리가 원하던 내용은 book_list 에 * 이 붙어서 main 함수의 실제 book_list 를 의미한 뒤 + i 를 해서 원소를 참조하는 것이지 후자 처럼 존재하지도 않는 book_list 의 i 번째 원소를 참조하여 말도 안되는 식을 의도하는 것은 아닙니다.

아무튼 이렇게 해서 성공적으로 도서 관리 프로그램에 대한 파일 입출력을 수행 할 수 있게 됩니다. 



  이것으로 해서 파일 입출력에 관한 강좌는 끝내도록 하겠습니다. 기타 파일 입출력에 관한 함수들에 대해 설명하는 것은 무의미한 행동이므로 파일 입출력에 관련한 함수들을 더욱 알고 싶다면 C 언어 레퍼런스를 참조하시기 바랍니다 (특히 보셔야 할 부분은 stdio.h 부분이지요).


  이제 여기 까지 도달하셨다면 여러분은 C 언어에 대한 기초적인 모든 부분을 
학습하셨다고 해도 과언이 아닙니다. 여러분의 손에는 이제 훌륭한 조각칼이 들려있는 셈입니다. 이 조각칼로 여러분의 능력에 따라 멋진 조각품을 만들어 
낼 수 있듯이 C 언어라는 훌륭한 도구를 통해서 최고의 프로그램을 만들 수 있게 될 것입니다. 

  저의 C 언어 강좌는 이제 마지막 강좌를 남겨두고 있습니다. 사실 여기서 강좌를 끝내도 무방하고, 여러분들은 여기까지 강좌를 읽으셨다면 
축하 파티를 하셔도 됩니다! 마지막 강좌는 여러분들이 실제로 프로그래밍을 하면서 여러가지 실수들을 하실 텐데 이를 대비하기 위한 오류 해결책들에 
대해 이야기 해보려고 합니다. 여러 골치 아픈 오류들을 만났을 때 꽤 도움이 많이 될 듯 합니다.  여러분들이 실제로 프로그래밍을 하면서 피가 되고 살이 될 '코드 최적화' 에
 대해서 이야기 하고자 합니다. 우리가 흔히 느끼기에 똑같은 한국말을 해도 어떤 사람은 말을 참 잘하지만 어떠한 
사람은 말을 참 못한다고 생각 하는 경우가 있습니다. C 언어도 마찬가지 입니다. 저의 C 언어 강좌는 여기서 끝났지만 C 언어 자체를 안다고 해도 모두다 훌륭한 코드를 쓸 수 있는 것은 아닙니다. 따라서 다음 
강좌에서는 여러분이 훌륭한 코드에 조금이니마 근접한 코드를 쓸 수 있도록 도와 줄 코드 최적화에 대해서 이야기 할 것입니다. 

생각해보기

1. 책들의 목록을 html 형식에 맞게 출력하여 표로 깔끔하게 보여질 수 있게 해보세요. html 문법은 http://www.w3schools.com/html/default.asp 에서 배우실 수 있습니다. (난이도 : 上)


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면 꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요. 

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <23 - 3. 파일 하고 이야기 하기 (파일 입출력 - 마무리)>>> 입니다. 이번 강좌의 모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요 

다음 강좌 보러가기

```
공감sns신고저작자표시'C' 카테고리의 다른 글초보자를 위한 C 언어 강좌 - 씹어먹는 C 언어 (완결)(139)
2011.01.20씹어먹는 C 언어 - <24. 더 빠르게 실행되는 코드를 위하여 (C 코드 최적화)>(46)
2011.01.18씹어먹는 C 언어 - <23 - 3. 파일 하고 이야기 하기 (파일 입출력 - 마무리)>(19)
2011.01.17씹어먹는 C 언어 - <23 - 2. 파일 하고 이야기 하기 (파일 입출력)>(28)
2011.01.10씹어먹는 C 언어 - <23 - 1. 파일 하고 이야기 하기 (파일 입출력에 대한 기본적 이해)>(34)
2010.12.28씹어먹는 C 언어 - <22. C 언어의 잡다한 키워드들 (typedef, volatile, #pragma)>(23)
2010.12.25


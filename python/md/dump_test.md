
.이번 강좌에서는* 의존 타입 (dependent type)Unit 라이브러리 만들기auto 키워드에 대해서 배웁니다.
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F2634C0465958BE17369176)



안녕하세요 여러분! 지난 강좌에서 왜 TMP 를 활용하여 힘들게 힘들게 Ratio 클래스를 만들었는데, 아직 아마 이걸 왜 굳이 TMP 로 만들었는지는 설명하지 않았었습니다.


그에 앞서, 이번 강좌에서 왜 Ratio 클래스를 만들었는지 설명하기 전에 지난 강좌의 생각 해보기에 대해서 짚고 넘어가보자 합니다. 



 지난 강의 생각해보기 문제



지난번 생각해보기 문제는 아래와 같습니다.


```info

1. TMP 를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어보세요. (난이도 : 상)


int main()
{
cout << boolalpha;
cout << "Is prime ? :: " << is_prime<2>::result << endl; // true
cout << "Is prime ? :: " << is_prime<10>::result << endl; // false
cout << "Is prime ? :: " << is_prime<11>::result << endl; // true
cout << "Is prime ? :: " << is_prime<61>::result << endl; // true
}
```



사실 처음에 딱 보았을 때 도대체 어떻게 TMP 로 구현할 것인지 감이 안잡혔을 것입니다. 하지만 만약에 소수 인지 아닌지 판별하라는 '함수' 를 작성하게 하였다면 잘 작성하였겠지요. 아마 여러분은 아래와 같은 코드를 쓰셨을 것입니다.


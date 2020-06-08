----------------
title : 씹어먹는 C++ - <8 - 2. Excel 만들기 프로젝트 2부>
cat_title: 8 - 2. Excel 만들기 프로젝트 2부
next_page : 219
publish_date : 2016-07-19
tex_title : 엑셀 만들기 프로젝트 2부
--------------

이번 강좌에서는

* Excel 만들기 프로젝트 완성.
* 중위 표기법(Infix notation), 후위 표기법(postfix notation) 간의 변환


![](/img/ChewingCpplogo.png)




안녕하세요 여러분. 지난 강좌에 이어서 Excel 만들기 프로젝트를 계속 진행해 보도록 하겠습니다. 지난 강좌에서는 셀에 문자열 데이터만 넣을 수 있지만, 테이블을 여러가지 형태 (텍스트, HTML, CSV)로 출력할 수 있는 엑셀을 제작하였습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F2327BB39578FA96F053529)





하지만 시간에 만들었던 엑셀은 아직 엑셀이라 하기에는 기능이 조금 부족하였습니다. 실제 엑셀을 살펴보자면 셀에 문자열만 넣을 수 있는 것이 아니라 숫자 데이터도 넣을 수 있고 날짜도 넣을 수 있고, 심지어는 수식도 넣어서 연산 까지 할 수 있는 만능 셀입니다.



###  Cell 클래스 확장


앞서 말했듯이, `Cell` 클래스에는 `string` 데이터만 저장할 수 있기 때문에 이를 상속 받는 클래스들을 만들어서 셀에 다양한 데이터들을 보관할 수 있게 할 것입니다.
```cpp-formatted
class Cell {
 protected:
  int x, y;
  Table* table;

 public:
  virtual string stringify() = 0;
  virtual int to_numeric() = 0;

  Cell(int x, int y, Table* table);
};
```



일단 기존의 `Cell` 클래스에서 문자열 데이터를 보관했던 것과는 달리 아예 그 항목을 빼버리고, 이를 상속 받는 클래스에서 데이터를 보관하도록 하였습니다. 또한, `stringify` 함수와 `to_numeric` 을 순수 가상 함수로 정의해서 이를 상속 받는 클래스에서 이 함수들을 반드시 구현 토록 하였습니다.

```cpp-formatted
class StringCell : public Cell {
  string data;

 public:
  string stringify();
  int to_numeric();

  StringCell(string data, int x, int y, Table* t);
};
class NumberCell : public Cell {
  int data;

 public:
  string stringify();
  int to_numeric();

  NumberCell(int data, int x, int y, Table* t);
};
class DateCell : public Cell {
  time_t data;

 public:
  string stringify();
  int to_numeric();

  DateCell(string s, int x, int y, Table* t);
};
```



일단 위 셋은 각각 문자열, 정수, 시간 정보를 보관하는 클래스들 입니다. 사실 이들을 구현하는 것은 그렇게 어렵지 않습니다. 단순히 데이터를 문자열이나 정수 형으로 바꾸기만 해주면 되기 때문이지요. 참고로 `DateCell` 의 경우에는 편의를 위해서 `yyyy-mm-dd` 형식으로만 입력을 받는 것으로 정하였습니다.그 결과 다음과 같습니다.

```cpp-formatted
Cell::Cell(int x, int y, Table* table) : x(x), y(y), table(table) {}

StringCell::StringCell(string data, int x, int y, Table* t)
    : data(data), Cell(x, y, t) {}
string StringCell::stringify() { return data; }
int StringCell::to_numeric() { return 0; }

/*


NumberCell


*/
NumberCell::NumberCell(int data, int x, int y, Table* t)
    : data(data), Cell(x, y, t) {}

string NumberCell::stringify() { return to_string(data); }
int NumberCell::to_numeric() { return data; }

/*


DateCell


*/
string DateCell::stringify() {
  char buf[50];
  tm temp;
  localtime_s(&temp, &data);

  strftime(buf, 50, "%F", &temp);

  return string(buf);
}
int DateCell::to_numeric() { return static_cast<int>(data); }

DateCell::DateCell(string s, int x, int y, Table* t) : Cell(x, y, t) {
  // 입력받는 Date 형식은 항상 yyyy-mm-dd 꼴이라 가정한다.
  int year = atoi(s.c_str());
  int month = atoi(s.c_str() + 5);
  int day = atoi(s.c_str() + 8);

  tm timeinfo;

  timeinfo.tm_year = year - 1900;
  timeinfo.tm_mon = month - 1;
  timeinfo.tm_mday = day;
  timeinfo.tm_hour = 0;
  timeinfo.tm_min = 0;
  timeinfo.tm_sec = 0;

  data = mktime(&timeinfo);
}
```



참고로 `DateCell` 의 경우 구현이 조금 복잡한데 자세히 살펴보도록 하겠습니다.


```cpp-formatted
// 입력받는 Date 형식은 항상 yyyy-mm-dd 꼴이라 가정한다.
int year = atoi(s.c_str());
int month = atoi(s.c_str() + 5);
int day = atoi(s.c_str() + 8);
```



일단 위 처럼 입력 받은 문자열을 연도, 월, 일로 구분하게 됩니다.

```cpp-formatted
tm timeinfo;

timeinfo.tm_year = year - 1900;
timeinfo.tm_mon = month - 1;
timeinfo.tm_mday = day;
timeinfo.tm_hour = 0;
timeinfo.tm_min = 0;
timeinfo.tm_sec = 0;

data = mktime(&timeinfo);
```



이를 바탕으로 `timeinfo` 객체를 초기화 합니다. `tm` 클래스는 일월년 시분초 단위로 데이터를 보관하는 클래스 입니다. 하지만 우리의 `DateCell` 은 `time_t` 형태로 데이터를 보관하고 있는데 그 변환을 위해 `mktime` 에 `timeinfo` 를 전달하면 변환할 수 있습니다. 참고로 `time_t` 타입은 1970년 부터 현재 시간 까지 몇 초가 흘렀는지 보관하는 정수형 변수라고 생각하시면 됩니다.

```cpp-formatted
class ExprCell : public Cell {
  string data;
  string* parsed_expr;

  Vector exp_vec;

  // 연산자 우선 순위를 반환합니다.
  int precedence(char c);

  // 수식을 분석합니다.
  void parse_expression();

 public:
  ExprCell(string data, int x, int y, Table* t);

  string stringify();
  int to_numeric();
};
```



그렇다면 이제 대망의 `ExprCell` 을 살펴볼 차례입니다. 일단 `to_numeric()` 에 다 넣을 수 없어서 두 개의 함수를 새로 만들었습니다. `precedence` 함수는 입력받은 연산자의 우선순위를 반환하고, `parse_expression` 함수는 수식을 분석해서 계산하기 편하게 해주는 함수 입니다. 계산하기 편하게 한다는게 무슨 말이냐고요? 아래를 봐주시기 바랍니다.




###  수식 계산하기 `-` 중위 표기법과 후위 표기법

우리는 흔히 수식을 나타내기 위해 다음과 같이 써 왔습니다.

```info
3 + 4 * 5 + 4 * (7 - 2)
```



이렇게 표기하는 방식을 중위 표기법이라고 합니다. 사실 우리는 위 방식에 익숙해서 어떠한 순서로 계산하는지 쉽게 알 수 있지만 컴퓨터에 경우 이를 계산하는데 조금 어려울 수 있습니다. 일단 고려해야할 점들이 먼저 괄호를 우선으로 계산하고, 그 다음에 `*` 와 `/ ,` 그리고 `+` 와 `-` 의 우선 순위로 나누어서 계산해야 합니다.


쉽게 말해 위 수식의 경우 비록 맨 앞에 `3 + 4` 이 있지만 사실은 `4 * 5` 를 먼저 계산해야 됩니다. 즉, 컴퓨터가 이 수식을 계산하기 위해서는계산하는 위치를 우선 순위에 맞게 이러 저리 옮겨다녀야 합니다.



위 처럼 피연산자와 피연산자 사이에 연산자를 넣는 형태로 수식을 표현하는 방법을 중위 표기법(infix notation) 이라고 부릅니다. 쉽게 말해 연산자가 '중간' 에 들어가서 중위 표기법이지요.


반면에 아래의 수식을 살펴보도록 합시다.


```info
3 4 5 * + 4 7 2 - * +
```



우리가 흔히 생각하는 수식의 모습이랑 사뭇 다릅니다. 사실 위 수식은 앞서 말한 수식과 정확히 동일한 수식인데, 그 표현 방식이 다를 뿐입니다. 이러한 형태로 수식을 표현하는 방식을 후위 표기법(postfix notation)이라고 합니다. 자세히 보자면 이전 수식과 다른 점을 두 가지 찾을 수 있는데, 하나는 이전과는 달리 연산자들이 피연산자 뒤쪽에 위치해 있다는 점과, 또 하나는 괄호가 사라졌다는 점입니다.


괄호가 사라졌다는 것이 무슨 의미가 있을까요?


기존의 중위 표현법이 컴퓨터가 해석하기에 불편했었던 점이 바로 연산자의 우선 순위나 괄호에 따라 이리 저리 계산하는 부분을 찾아다녀야 했던 점이었습니다. 하지만 후위 표기법에서는 놀랍게도 이리 저리 계산할 위치를 찾으러 돌아다닐 필요 없이, 읽어들이는 순서 대로 계산을 쭉 할 수 있습니 . 하지만 후위 표기법에서는 놀랍게도 이리 저리 계산할 위치를 찾으러 돌아다닐 필요 없이, 읽어들이는 순서 대로 계산을 쭉 할 수 있습니다


물론 사람이 보기에는 조금 불편하지만 컴퓨터의 입장에서는, 즉 프로그래머의 입장에서는 코딩하기에 매우 편리한 표기 방법 입니다.


그렇다면 이 후위 표기법으로 표현된 식을 컴퓨터가 어떻게 해석하는지 살펴보겠습니다. 컴퓨터는 아래와 같은 과정으로 위 후위 표기법으로 변환된 식을 계산합니다.

1. 피연산자를 만나면 스택에 `push` 합니다.
2. 연산자를 만나면 스택에서 두 개를 `pop` 한 뒤에 그 둘에 해당 연산을 한 후, 그 결과를 다시 스택에 `push` 합니다.



이와 같은 방식으로 위 수식을 계산해보도록 하겠습니다.

```html-only
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F24246334578EC0EE1DABA0)
```
```latex-only
![](/img/cpp/8.2.1.png)
```

실제로 `3 + 4 * 5 + 4 * (7 - 2)` 을 계산 했을 때와 그 결과가 같음을 알 수 있습니다.


이를 바탕으로 후위 표기법으로 된 수식을 계산하는 `is_numeric` 함수를 살펴보도록 하겠습니다.

```cpp-formatted
int ExprCell::to_numeric() {
  double result = 0;
  NumStack stack;

  for (int i = 0; i < exp_vec.size(); i++) {
    string s = exp_vec[i];

    // 셀 일 경우
    if (isalpha(s[0])) {
      stack.push(table->to_numeric(s));
    }
    // 숫자 일 경우 (한 자리라 가정)
    else if (isdigit(s[0])) {
      stack.push(atoi(s.c_str()));
    } else {
      double y = stack.pop();
      double x = stack.pop();
      switch (s[0]) {
        case '+':
          stack.push(x + y);
          break;
        case '-':
          stack.push(x - y);
          break;
        case '*':
          stack.push(x * y);
          break;
        case '/':
          stack.push(x / y);
          break;
      }
    }
  }
  return stack.pop();
}
```



일단 우리는 `parse_expression` 함수를 통해서 입력 받은 중위 표기법으로 되어 있는 수식이, 후위 표기법으로 변환되어 있고, 그 결과가 `exp_vec` 에 저장되어 있다고 생각해봅시다. `exp_vec` 은 벡터 클래스 객체로, 각각의 원소가 후위 표기법으로 변환된 수식의 각각의 토큰이 됩니다. 즉, 앞선 예제의 경우 `exp_vec` 은 `3, 4, 5, *, +, 4, 7, 2, -, *, +` 으로 이루어진 배열 이라 보시면 됩니다.

```cpp-formatted
string s = exp_vec[i];
```

따라서 위와 같이 `for` 문을 통해 각각의 토큰(`exp_vec` 의 각 원소들)에 접근할 수 있습니다.

```cpp-formatted
// 셀 일 경우
if (isalpha(s[0])) {
  stack.push(table->to_numeric(s));
}
// 숫자 일 경우 (한 자리라 가정)
else if (isdigit(s[0])) {
  stack.push(atoi(s.c_str()));
}
```

그리고 각각의 토큰에 대해서, 셀 이름 (A3, B2 이렇게) 이나 숫자일 경우 스택에 `push` 하게 됩니다.

```cpp-formatted
else {
  double y = stack.pop();
  double x = stack.pop();
  switch (s[0]) {
    case '+':
      stack.push(x + y);
      break;
    case '-':
      stack.push(x - y);
      break;
    case '*':
      stack.push(x * y);
      break;
    case '/':
      stack.push(x / y);
      break;
  }
}
```

아니면 연산자를 만날 경우 스택에서 두 번 `pop` 을 해서 해당하는 피연산자들에 해당 연산자를 적용해서 다시 스택에 `push` 하게 됩니다.

```cpp-formatted
return stack.pop();
```



그리고 모든 계산이 끝나면 스택에 최종 결과값을 `pop` 하며 이를 리턴하게 됩니다.


자 그럼 이제 우리가 해야할 일은 중위 표기법으로 표기된 수식을 후위 표기법으로 변환하는 작업만 수행하면 됩니다.



###  중위 표기법을 후위 표기법으로 변환하기 (parse_expression 함수)




중위 표기법을 후위 표기법으로 변환하는 것은 다음의 방식을 따릅니다.

1. 피연산자 (셀 이름이나 숫자) 일 경우 그냥 `exp_vec` 에 넣습니다.
1. 여는 괄호( `(, [, {` 와 같은 것들 ) 을 만날 경우 스택에 `push` 합니다.
1. 닫는 괄호( `), ], }` 와 같은 것들 `)` 을 만날 경우 여는 괄호가 `pop` 될 때 까지 `pop` 되는 연산자들을 `exp_vec` 에 넣습니다.
1. 연산자일 경우 자기 보다 우선순위가 낮은 연산자가 스택 최상단에 올 때 까지 (혹은 스택이 빌 때 까지) 스택을 `pop` 하고 (낮은 것은 `pop` 하지 않습니다), `pop` 된 연산자들을 `exp_vec` 에 넣습니다. 그리고 마지막에 자신을 스택에 `push` 합니다.

그리고 연산자들의 우선 순위는 아래의 함수에 의해 정의됩니다.

```cpp-formatted
int ExprCell::precedence(char c) {
  switch (c) {
    case '(':
    case '[':
    case '{':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
  }
  return 0;
}
```


괄호들이 가장 낮고, 그 다음이 `+` 와 `-,` 그리고 최상위 우선순위가 `*` 와 `/` 입니다.


그렇다면 `3 + 4 * 5 + 4 * (7 - 2)` 가 어떻게 변환되는지 그림으로 살펴보도록 하겠습니다.

```html-only
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F2779ED44578F2D81123CD3)
```
```latex-only
![](/img/cpp/8.2.2.png)
```

이제 위 방식으로 그대로 코드로만 옮기면 됩니다. 여기서는  코딩의 편의를 위해서 사용자가 입력하는 숫자는 1 자리 정수이고, 셀 이름 역시 2자 로 제한하였습니다. 이를 확장하는 것은 크게 어렵지 않으니 여러분들이 직접 해보시기 바랍니다.


```cpp-formatted
void ExprCell::parse_expression() {
  Stack stack;

  // 수식 전체를 () 로 둘러 사서 exp_vec 에 남아있는 연산자들이 push 되게
  // 해줍니다.
  data.insert(0, "(");
  data.push_back(')');

  for (int i = 0; i < data.length(); i++) {
    if (isalpha(data[i])) {
      exp_vec.push_back(data.substr(i, 2));
      i++;
    } else if (isdigit(data[i])) {
      exp_vec.push_back(data.substr(i, 1));
    } else if (data[i] == '(' || data[i] == '[' ||
               data[i] == '{') {  // Parenthesis
      stack.push(data.substr(i, 1));
    } else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
      string t = stack.pop();
      while (t != "(" && t != "[" && t != "{") {
        exp_vec.push_back(t);
        t = stack.pop();
      }
    } else if (data[i] == '+' || data[i] == '-' || data[i] == '*' ||
               data[i] == '/') {
      while (!stack.is_empty() &&
             precedence(stack.peek()[0]) >= precedence(data[i])) {
        exp_vec.push_back(stack.pop());
      }
      stack.push(data.substr(i, 1));
    }
  }
}
```



위 코드를 보면 변환 알고리즘을 그대로 옮겨놓았다고 생각하면 됩니다.

```cpp-formatted
if (isalpha(data[i])) {  // 셀 이름의 경우 첫 번째 글자가 알파벳이다.
  exp_vec.push_back(data.substr(i, 2));
  i++;
} else if (isdigit(data[i])) {  // 첫번째 글자가 숫자라면 정수 데이터
  exp_vec.push_back(data.substr(i, 1));
}
```

일단 피연산자를 만날 경우 `exp_vec` 에 무조건 집어넣으면 됩니다.

```cpp-formatted
else if (data[i] == '(' || data[i] == '[' || data[i] == '{') {  // Parenthesis
  stack.push(data.substr(i, 1));
}
else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
  string t = stack.pop();
  while (t != "(" && t != "[" && t != "{") {
    exp_vec.push_back(t);
    t = stack.pop();
  }
}
```

반면에 괄호의 경우 여는 괄호를 만나면 스택에 `push` 하고, 닫는 괄호를 만나면 위 처럼 여는 괄호가 스택에서 나올 때 까지 `pop` 하고, 그 `pop` 한 연산자들을 벡터에 넣으면 됩니다. 주의할 점은 `pop` 한 연산자가 괄호일 경우 넣지 않는다는 점입니다.

```cpp-formatted
else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/') {
  while (!stack.is_empty() &&
         precedence(stack.peek()[0]) >= precedence(data[i])) {
    exp_vec.push_back(stack.pop());
  }
  stack.push(data.substr(i, 1));
}
```

마지막으로 연산자일 경우를 살펴봅시다. `peek` 의 경우 스택의 최상단 원소를 `pop` 하지는 않고 무엇인지만 살펴보는 것입니다. 만일 최상단 원소의 우선 순위가 현재 연산자의 우선순위 보다 높다면 이를 스택에서 `pop` 하고 이를 `exp_vec` 에 넣어야 겠지요. 위 `while` 문은 그 과정을 나타내고 있습니다.


그리고 맨 마지막에 스택에 현재 연산자를 넣습니다.


위 과정을 모두 마치면 후기 표기법으로 변환을 마칠 수 있을 것이라 생각되지만 사실 한 가지 빼먹은 사실이 있습니다. 마지막에 스택에 남아있는 연산자들을 모두 `pop` 해야 되기 때문이죠. 이를 `for` 문이 끝난 후에 `while` 문을 하나 더 넣어서 연산자를 `pop` 하는 과정을 넣을 수 도 있지만 아래 처럼 좀 더 간단하게 처리할 수 도 있습니다.

```cpp-formatted
// 수식 전체를 () 로 둘러 사서 exp_vec 에 남아있는 연산자들이 push 되게
// 해줍니다.
data.insert(0, "(");
data.push_back(')');
```



바로 수식 전체를 ( ) 로 한 번 감싸는 것입니다. 그렇게 된다면 맨 마지막 괄호를 처리하면서 스택에 남아 있던 모든 연산자들이 `pop` 되겠지요.


그렇다면 실제로 잘 작동하는지 살펴보도록 합시다.

```cpp-formatted
// 생략
int main() {
  MyExcel::TxtTable table(5, 5);
  table.reg_cell(new NumberCell(2, 1, 1, &table), 1, 1);
  table.reg_cell(new NumberCell(3, 1, 2, &table), 1, 2);

  table.reg_cell(new NumberCell(4, 2, 1, &table), 2, 1);
  table.reg_cell(new NumberCell(5, 2, 2, &table), 2, 2);
  table.reg_cell(new ExprCell("B2+B3*(C2+C3-2)", 3, 3, &table), 3, 2);
  table.reg_cell(new StringCell("B2 + B3 * ( C2 + C3 - 2 ) = ", 3, 2, &table),
                 3, 1);

  std::cout << table;
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F274EDE3F578F605425EA74)



와 같이 잘 작동하고 있음을 알 수 있습니다.





###  엑셀 프로그램





그렇다면 이제 실제로 사용자의 입력을 받아서 비록 마우스는 쓸 수 없더라도 키보드로 명령을 처리하는 엑셀 프로그램을 만들어보도록 하겠습니다.

```cpp-formatted
class Excel {
  Table* current_table;

 public:
  Excel(int max_row, int max_col, int choice);

  int parse_user_input(string s);
  void command_line();
};
```



위 클래스는 사용자의 입력을 받아서 실제 테이블을 생성하고 이를 관리해주는 클래스 입니다. 또한 `parse_user_input` 함수의 경우 사용자의 입력을 인자로 받아서, 이를 처리하는 역할을 수행합니다.

```cpp-formatted
Excel::Excel(int max_row, int max_col, int choice = 0) {
  switch (choice) {
    case 0:
      current_table = new TxtTable(max_row, max_col);
      break;
    case 1:
      current_table = new CSVTable(max_row, max_col);
      break;
    default:
      current_table = new HtmlTable(max_row, max_col);
  }
}
```



위는 Excel 객체의 생성자로 어떠한 형태의 테이블을 형성할 지 결정합니다.

```cpp-formatted
int Excel::parse_user_input(string s) {
  int next = 0;
  string command = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      command = s.substr(0, i);
      next = i + 1;
      break;
    } else if (i == s.length() - 1) {
      command = s.substr(0, i + 1);
      next = i + 1;
      break;
    }
  }

  string to = "";
  for (int i = next; i < s.length(); i++) {
    if (s[i] == ' ' || i == s.length() - 1) {
      to = s.substr(next, i - next);
      next = i + 1;
      break;
    } else if (i == s.length() - 1) {
      to = s.substr(0, i + 1);
      next = i + 1;
      break;
    }
  }

  // Cell 이름으로 받는다.
  int col = to[0] - 'A';
  int row = atoi(to.c_str() + 1) - 1;

  string rest = s.substr(next);

  if (command == "sets") {
    current_table->reg_cell(new StringCell(rest, row, col, current_table), row,
                            col);
  } else if (command == "setn") {
    current_table->reg_cell(
      new NumberCell(atoi(rest.c_str()), row, col, current_table), row, col);
  } else if (command == "setd") {
    current_table->reg_cell(new DateCell(rest, row, col, current_table), row,
                            col);
  } else if (command == "sete") {
    current_table->reg_cell(new ExprCell(rest, row, col, current_table), row,
                            col);
  } else if (command == "out") {
    ofstream out(to);
    out << *current_table;
    std::cout << to << " 에 내용이 저장되었습니다" << std::endl;
  } else if (command == "exit") {
    return 0;
  }

  return 1;
}
```



그리고 `parse_user_input` 함수는 사용자의 입력을 받아서 적절한 명령을 처리하게 됩니다. 예를 들어서

```info

setn A1 10
```



이렇게 치면, `A1` 셀을 `NumberCell` 로 생성하며, 10 의 값으로 초기화 시켜줍니다.


혹은

```info

sets B2 hello world!
```



의 경우 `B2` 셀을 `StringCell` 로 생성하며 "hello world!" 로 초기화 시켜줍니다.


날짜와 수식의 경우도 마찬가지이며, 각각 `setd` 와 `sete` 의 명령어를 사용하고 있습니다. 그 외에도, `out` 을 통해서 원하는 파일에 출력할 수 도 있고, `exit` 를 하면 프로그램을 종료할 수 있습니다.

```cpp-formatted
void Excel::command_line() {
  string s;
  std::getline(cin, s);

  while (parse_user_input(s)) {
    std::cout << *current_table << std::endl << ">> ";
    getline(cin, s);
  }
}
```

따라서 `main` 함수 에서는

```cpp
int main() {
  std::cout << "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요"
       << std::endl;
  std::cout << "* 참고 * " << std::endl;
  std::cout << "1 : 텍스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블" << std::endl;

  int type, max_row, max_col;
  std::cin >> type >> max_row >> max_col;
  MyExcel::Excel m(max_row, max_col, type - 1);
  m.command_line();
}
```



마지막으로 `command_line` 함수는 사용자의 입력을 계속 기다리면서 내용이 업데이트 될 때 마다 화면에 표를 출력해주게 됩니다. 실제로 사용하는 예시는 아래와 같습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F265A9C33578FA1FC0BD04C)



이상으로 위와 같이 나만의 미니 엑셀을 완성하였습니다!


사실 앞서 쭉 이야기 해 왔지만 제가 구현한 미니 엑셀은 코딩의 간소화를 위해서 몇 가지 제약들이 있습니다. 이러한 부분은 여러분들이 자유롭게 코딩하면서 더 확장 해 나가셨으면 좋겠습니다.



###  생각해보기

#### 문제 1

`ExprCell` 의 쉭에서 셀의 이름은 `A3` 과 같이 단 두 글자만 가능하다는 제약 조건이 있었습니다. 이를 임의의 크기의 이름도 가능하게 확장해보세요. (난이도 : 下)

#### 문제 2

마찬가지로 가능한 숫자도 임의의 길이가 상관없게 확장해보세요. (난이도 : 下)

#### 문제 3

사실 위와 같이 수식을 계산하는 경우 한 가지 문제가 있습니다. 바로 셀들이 서로를 참조할 수 있다는 것입니다. 예를 들어서 `A1 = B1` 이고 `B1 = A1` 으로 설정하였다면 `B1` 의 값을 알기 위해 `A1` 의 값을 알아야 하고, 그럼 `A1` 의 값을 알기 위해 `B1` 의 값을 알아야 하고... 와 같은 순환 참조 문제가 발생합니다.

따라서 사용자가 타의든 자의든 순환 참조가 있는 식을 입력하였을 때 이를 감지하고 입력을 방지하는 루틴을 제공해야 합니다. (실제 Excel 에서도 순환 참조되는 식을 입력하면 오류가 발생합니다) (난이도 : 上)

#### 문제 4

실제 Excel 의 경우 수식에서 여러가지 함수들을 지원합니다. 여기서도 수식에서 간단한 함수들을 지원하게 해보세요.. (난이도 : 上)

##@ chewing-cpp-end
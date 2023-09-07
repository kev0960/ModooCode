declare const grecaptcha: any;

interface Comment {
  comment_id: number;
  article_url: string;
  reply_ids: number[];
  comment_date: string;
  author_name?: string;
  image_link: string;
  content: string;
  is_md: boolean;
}

interface GetCommentResponse {
  comments: Comment[];
}

class CommentManager {
  constructor() {
    this.last_comment_index_ = 0;
    this.comments_ = new Map();
    this.root_comments_ = [];

    // @ts-ignore
    this.num_total_comments_ = getNumTotalComments();
  }

  public async LoadComments() {
    let url = window.location.pathname;
    let article_url = url.substr(url.lastIndexOf("/") + 1);

    let response = await fetch("/get-comment", {
      method: "POST",
      mode: "cors",
      cache: "no-cache",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        article_url,
        index_start: this.last_comment_index_,
      }),
    });

    let get_comment_response2: GetCommentResponse = await response.json();
    let get_comment_response = {
      "comments": [
          {
              "comment_id": 11759,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2023-04-11 05:00:45.274",
              "author_name": "포아송분포",
              "image_link": "https://lh3.googleusercontent.com/a/AGNmyxbAiE-IgcjQq8IsXH4STd3nYVBFjRPIjcl7FgYG=s96-c",
              "content": "utils.h 에서 namespace MyExcel 전 using std::string을 ;로 닫아주지 않으면 컴파일 오류",
              "is_md": true
          },
          {
              "comment_id": 11747,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2023-04-04 06:32:27.184",
              "author_name": "사람",
              "image_link": "",
              "content": "#include <iostream>\n#include <fstream>\n#include <string>\n\nusing str =  std::string;\n\n\nnamespace MyExcel {\n    \nclass Cell;\nclass Table;\nclass TxtTable;\n\n헤더를 이렇게 바꾸니까 됐어요!\n그리고 Cell이랑 Table에 친구선언도 해줬습니다!\nfriend class Table;\n",
              "is_md": true
          },
          {
              "comment_id": 11746,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2023-04-04 06:27:09.446",
              "author_name": "사람",
              "image_link": "",
              "content": "#include <fstream>\n이거 헤더에 추가해보세요!",
              "is_md": true
          },
          {
              "comment_id": 11735,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2023-03-29 05:14:02.378",
              "author_name": "Taejoo Kim",
              "image_link": "https://lh3.googleusercontent.com/a/AGNmyxbfO8PmC61j77fBNOTJWE__1hHGFwUesg61JFh8=s96-c",
              "content": "몇번의 에러를 거쳐 성공적으로 컴파일 되고, 실행되었습니다.\nclass 상호참조, operator<< 에러 등의 해결이 또 하나의 공부가 되네요\n감사합니다.",
              "is_md": true
          },
          {
              "comment_id": 11710,
              "article_url": "217",
              "reply_ids": [
                  11746
              ],
              "comment_date": "2023-03-05 04:50:00.660",
              "author_name": "변종길",
              "image_link": "",
              "content": "typing 은 다했는데 error 나네요.\nstd::ofstream out(\"test.txt\"); 에서 \nout이 정의되어 있지 않았다고 하네요.",
              "is_md": true
          },
          {
              "comment_id": 11557,
              "article_url": "217",
              "reply_ids": [
                  11603
              ],
              "comment_date": "2022-12-16 14:37:45.301",
              "author_name": "변종길",
              "image_link": "",
              "content": "terminate called after throwing an instance of 'std::bad_array_new_length'\n  what():  std::bad_array_new_length 와 같은 메시지는 \n무엇인지 모르겠습니다. \nMinGW 에서 나온 컴파일 완료 후의 a.exe 를 실행시키니\n위와 같은 메시지가 나왔는데, \n출력을 기대했는데 결과는 안 나오고 뭔지 모르겠습니다. ",
              "is_md": true
          },
          {
              "comment_id": 11555,
              "article_url": "217",
              "reply_ids": [
                  11557
              ],
              "comment_date": "2022-12-15 13:25:02.757",
              "author_name": "변종길",
              "image_link": "",
              "content": "MinGW 에서는 불가 하답니다. \nofstream out(\"test.txt\");도 못한다 하기에 아예 지워보니,\nCell의 소멸자도 요구합니다.",
              "is_md": true
          },
          {
              "comment_id": 11554,
              "article_url": "217",
              "reply_ids": [
                  11555
              ],
              "comment_date": "2022-12-15 13:15:15.017",
              "author_name": "변종길",
              "image_link": "",
              "content": "main() 가 닫힐 때는 Cell 의 소멸자 없어도 되나요.\ndelete Cell; 이런 것... ",
              "is_md": true
          },
          {
              "comment_id": 11535,
              "article_url": "217",
              "reply_ids": [
                  11747
              ],
              "comment_date": "2022-12-06 12:38:32.052",
              "author_name": "뉴비",
              "image_link": "",
              "content": "해결했습니다 제가 사용한 방법은 아래와 같습니다(msvc 환경)\n1.Table.h에 Table Class와 Cell Class 둘 다 선언합니다\n2.저는 헤더파일에 이렇게 적었습니다\nTable.h\n#pragma once\n#include <string>\n#include <iostream>\n#include <fstream>\nusing namespace std;\n\nclass Cell;\nclass Table;\n\nnamespace MyExcel {....\n\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\nTable.cpp\n#include \"Table.h\"\n\nnamespace MyExcel {\n...\n\n3. 클래스 선언 순서를 위에서 아래로 Cell -> Table -> TxtTable 순으로 했습니다\n\n4. 생성자 정의는 cpp가 아니라 헤더 파일에 했습니다\n\n5. operator<< 관련 부분은 main()에 \nstd::ostream& operator<<(std::ostream & o, MyExcel::Table & table);\n집어 넣었습니다\n\n\n잘 되는줄 알았는데 main()에서 \ntable.reg_cell(new MyExcel::Cell(\"Hello~\", 0, 0, &table),0,0); \n\n여기서 인수 형식을 변환할 수 있는 오버로드 함수가 없다고 에러 뜨네요..\nMyExcel::TxtTable *'에서 'Table *'(으)로 변환할 수 없습니다\n가리킨 형식이 관련이 없습니다\n\n전방선언 때문에 클래스를 모호하게 찾아서 그런지 잘 모르겠네요\n",
              "is_md": true
          },
          {
              "comment_id": 11531,
              "article_url": "217",
              "reply_ids": [
                  11532,
                  11533,
                  11534,
                  11535
              ],
              "comment_date": "2022-12-06 10:57:04.873",
              "author_name": "뉴비",
              "image_link": "",
              "content": "Table 클래스와 Cell 클래스를 같이 합쳐서 적어도 상호참조 에러가 나고\n따로 분리하여 전방선언(Table.h에 class Cell; // Cell.h에 class Table;)해도 컴파일이 안되네요.\n한쪽에만 전방선언하면 정의에서 다른 클래스가 모호하다고 나오고\n두 클래스에서 양쪽을 전방선언하면 Table.cpp에서 정의되지 않는 \"Cell\"을 사용했다고 나옵니다 (ex : data_table[i][j]->stringify(); ) ",
              "is_md": true
          },
          {
              "comment_id": 10793,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2021-11-18 03:00:24.861",
              "author_name": "plz",
              "image_link": "",
              "content": "현재 가장 큰 오류로는 상호 참조로 인해 식별자 Cell을 읽지 못한다는 오류(C2143)가 해결이 되지 않습니다.",
              "is_md": true
          },
          {
              "comment_id": 10792,
              "article_url": "217",
              "reply_ids": [
                  10793
              ],
              "comment_date": "2021-11-18 02:58:19.652",
              "author_name": "plz",
              "image_link": "",
              "content": "4일을 고민해도 컴파일을 못하겠습니다.\n혹시 복붙해서 바로 비교해볼 수 있게 따로 코드 올려주실 수 있나요?",
              "is_md": true
          },
          {
              "comment_id": 10546,
              "article_url": "217",
              "reply_ids": [
                  10749
              ],
              "comment_date": "2021-08-13 07:53:12.693",
              "author_name": "Juni",
              "image_link": "",
              "content": "class Cell이랑 class Table이 서로를 가리키는 멤버 포인터를 갖고 있는데, 이게 컴파일이 되나요...?\n\n저는 class Cell을 위에 선언하면 'Table' has not been declared 에러가 발생하고, class Table을 위에 선언하면 'Class' has not been declared 에러가 발생하는데 말이죠...\n",
              "is_md": true
          },
          {
              "comment_id": 10491,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2021-07-29 08:45:50.397",
              "author_name": "왕초보",
              "image_link": "",
              "content": "Vector 클래스 코드 중\nvoid Vector::remove(int x) {\n  for (int i = x + 1; i < length; i++) {\n    data[i - 1] = data[i];\n  }\n  length--;\n}\n부분에서 int i = x+1 부분이 이해가 안되서 왜 이렇게 설정한건지 이유가 궁금합니다!",
              "is_md": true
          },
          {
              "comment_id": 9617,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2021-01-03 04:27:13.190",
              "author_name": "JUDE KIM",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GjPKZKvax1q8kC4ByUPpUNdrXMtASr0oaMlVACemQ=s96-c",
              "content": "저도 똑같이 4번에서 막혔네요... 아직 해결책을 찾지 못했는데 찾으면 답글 달겠습니다.!",
              "is_md": true
          },
          {
              "comment_id": 9614,
              "article_url": "217",
              "reply_ids": [
                  9617
              ],
              "comment_date": "2021-01-02 20:49:04.695",
              "author_name": "오류",
              "image_link": "",
              "content": "1. #include <iostream> / #include <fstream> \n2. out-of-line definition 오류 -> Cell 클래스 메소드의 정의를 선언부에 써줌. \n3. 상호참조문제 -> class Table; 을 위에 써줌 \n4. candidate constructor not viable: no known conversion from 'MyExcel::TxtTable *' to 'Table *' for 4th argument \n-> 바꿔봐도 해결이 안됨...\n\n고치면서도 많이 배운 것 같네요. 아직 오류는 못잡았는데 계속 해보겠습니다",
              "is_md": true
          },
          {
              "comment_id": 9596,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2020-12-29 23:29:55.701",
              "author_name": "C코드",
              "image_link": "",
              "content": "상호참조때문에 실행이 안되시는분들은 헤더파일의 class 정의 앞에 class forward declaration (전방선언이라고 하나요) 하면 되는것같습니다.\n즉 class Table과 class Cell이 상호참조하고있으니까, 헤더의 MyExcel namespace영역 제일 위에\nclass Table;\nclass Cell;\n이렇게 미리 선언해두면 제대로 작동하네요. C언어에서 배웠던 함수 원형 선언하는것처럼요.\n무조건 제일 위에 해야하는지는 모르겠습니다..",
              "is_md": true
          },
          {
              "comment_id": 8043,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2020-02-27 07:56:46.087",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "네 그냥 current = new Node(current, s); 로 해도 됩니다.",
              "is_md": true
          },
          {
              "comment_id": 8041,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2020-02-27 07:56:12.623",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "네 그건 콘솔 설정에 가셔서 폰트를 바꾸는 수 밖에 없어요",
              "is_md": true
          },
          {
              "comment_id": 8018,
              "article_url": "217",
              "reply_ids": [
                  8042,
                  8043
              ],
              "comment_date": "2020-02-26 08:17:23.001",
              "author_name": "ㅇㅇ",
              "image_link": "",
              "content": "Stack 클래스에서 push 함수를 만들때요,\n  Node* n = new Node(current, s);\n  current = n;\n얘를\n  Node* current = new Node(current, s);\n이렇게 만들어도 똑같이 작동하나요?\n중요한건 아닌데 궁금하네요..ㅜ",
              "is_md": true
          },
          {
              "comment_id": 8014,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2020-02-24 04:41:56.371",
              "author_name": "ㅇㅇㅇ",
              "image_link": "",
              "content": "상호참조 때문에 여기저기서 에러가 많이 나는데 어떻게 해결을 해야하는지 잘 모르겠습니다,, 상호참조에 대한 설명도 추가해주세요!",
              "is_md": true
          },
          {
              "comment_id": 7937,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2020-01-20 13:11:44.488",
              "author_name": "2323",
              "image_link": "",
              "content": "operator<<함수가 정의된 파일에 iostream헤더파일을 include 안하신건 아닐까요??",
              "is_md": true
          },
          {
              "comment_id": 7930,
              "article_url": "217",
              "reply_ids": [
                  8041
              ],
              "comment_date": "2020-01-16 06:50:22.265",
              "author_name": "주원띠",
              "image_link": "https://lh3.googleusercontent.com/-mKM_Lb9gTQw/AAAAAAAAAAI/AAAAAAAAAAA/ACHi3rf_xtCPBO427mzANmlOcA43RoCDog/s50/photo.jpg",
              "content": "글꼴마다 띄어쓰기나 특수문자의 길이가 다른건 어쩔수 없는건가요?? ",
              "is_md": true
          },
          {
              "comment_id": 7754,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-12-23 17:03:41.517",
              "author_name": "0524",
              "image_link": "",
              "content": "std::ostream& operator<<(std::ostream &out, MyExcel::Table &table);\n\n아마 이 함수를 만들기만 하고 table.h상에서 선언을 안해줘서 그런 걸 껍니다. 저도 왕만두님과 같은 방식으로 다 cpp랑 헤더랑 나눠서 실행했거든요",
              "is_md": true
          },
          {
              "comment_id": 7471,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-10-21 23:26:56.307",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "코드를 봐야지 도와드릴 수 있을 것 같네요 ㅠ",
              "is_md": true
          },
          {
              "comment_id": 7470,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-10-21 23:26:43.941",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "data_table[i][j] 가 가리키는 객체의 stringify() 함수를 호출한다는 의미 입니다.",
              "is_md": true
          },
          {
              "comment_id": 7422,
              "article_url": "217",
              "reply_ids": [
                  7471,
                  7754,
                  7937
              ],
              "comment_date": "2019-10-17 09:47:35.173",
              "author_name": "왕만두",
              "image_link": "",
              "content": "전체 소스를 하나의 파일로 묶어서 할 때는 operator << 오버로딩 부분에서 아무 문제가 없었는데 소스파일을 나누고 하니까 이 부분에서 오류가 나더라고요\nutil.h, util.cpp, cell.h, cell.cpp, table.h, table.cpp, main.cpp\n이렇게 나누고 컴파일 하는데 \n‘operator<<’ (operand types are ‘std::basic_ostream<char>::__ostream_type {aka std::basic_ostream<char>}’ and ‘MyExcel::TxtTable’)\n\n이런 오류 포함해서 수백줄 오류가 나오더라고요 뭐가 문제인지 몰라 계속 헤맸는데...\n\n단순히 메인의 오브젝트 파일 main.o를 만드는 과정에서 해당 오버로딩에 대한 정보가 없어서 그런거더라고요 (main.cpp가 각 헤더파일(선언) 정보만 알고있음) 그래서 table.h에 오버로딩하는 소스를 넣어봤는데 다중 정의 에러가 나오고 table.cpp에 있으면 메인서 못찾고;; \n결국\nmain.cpp파일 main 함수 위쪽에 오버로딩 함수만 넣으니까 잘 되기는 합니다 바람직한 위치는 아닌 것 같은데 어디에 놓아야할지 모르겠다는..ㅠ ",
              "is_md": true
          },
          {
              "comment_id": 7406,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-10-14 07:41:17.625",
              "author_name": "왕만두",
              "image_link": "",
              "content": "악 헷갈려 ㅠㅠ 이름공간이랑 클래스 사용하니까 너무 복잡하네요 자꾸  a::b 빼먹고.. 쨋든 잘 배웠습니다 감사합니다!",
              "is_md": true
          },
          {
              "comment_id": 7405,
              "article_url": "217",
              "reply_ids": [
                  7470
              ],
              "comment_date": "2019-10-14 02:15:32.359",
              "author_name": "nn",
              "image_link": "",
              "content": "data_table[i][j]->stringify() 이부분은 어떤 뜻인가요",
              "is_md": true
          },
          {
              "comment_id": 7402,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-10-13 05:18:55.496",
              "author_name": "1234",
              "image_link": "",
              "content": "class Table;를 class Cell{내용}; 위에 넣어주세요. 상호참조라는 키워드로 검색해보시면 됩니다.",
              "is_md": true
          },
          {
              "comment_id": 6557,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2019-05-16 10:58:30.636",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "제 생각에는 Table 이 정의가 안되어 있는 것 같네요.. 위 코드들이 부분 부분 포함하고 있는 것이라서 전체 코드는 조금 다릅니다.",
              "is_md": true
          },
          {
              "comment_id": 6539,
              "article_url": "217",
              "reply_ids": [
                  6557,
                  7402
              ],
              "comment_date": "2019-05-15 13:41:12.045",
              "author_name": "ㅜㅜ",
              "image_link": "",
              "content": "Cell 클래스의 Table* table에서 \n\"형식 지정자가 없습니다. int로 가정합니다\" 오류가 계속 나네요...\n어떻게 해야되나요? ",
              "is_md": true
          },
          {
              "comment_id": 5947,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2018-12-21 08:46:03.137",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "아하 넵 알겠습니다",
              "is_md": true
          },
          {
              "comment_id": 5946,
              "article_url": "217",
              "reply_ids": [],
              "comment_date": "2018-12-21 08:45:07.812",
              "author_name": "Jaebum Lee",
              "image_link": "https://lh3.googleusercontent.com/a-/AOh14GiGD6_xA3lRUslvzDd2zyR3cfeOYd0npkH2dOlp0A",
              "content": "delete data_table[i][j] 는 해당 Cell 을 지우는 과정이고,\n\nfor (int i = 0; i < max_row_size; i++) {\n\t\tdelete[] data_table[i];\n\t}\n\ndelete[] data_table;\n\n이 부분은 동적으로 할당된 포인터들의 배열을 지우는 과정입니다.\n",
              "is_md": true
          },
          {
              "comment_id": 5943,
              "article_url": "217",
              "reply_ids": [
                  5946
              ],
              "comment_date": "2018-12-20 00:32:45.749",
              "author_name": "chicchicken",
              "image_link": "",
              "content": "궁금한 것이 있습니다.\n\nTable::~Table() {\n\tfor (int i = 0; i < max_row_size; i++) {\n\t\tfor (int j = 0; j < max_col_size; j++) {\n\t\t\tif (data_table[i][j]) {\n\t\t\t\tdelete data_table[i][j];\n\t\t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < max_row_size; i++) {\n\t\tdelete[] data_table[i];\n\t}\n\tdelete[] data_table;\n}\n에서 \nif (data_table[i][j]) {\n   delete data_table[i][j];\n}\n는 왜 하는지 이유가 궁금합니다.\n밑에 배열에서 지울때 어차피 지워지지 않나요??\n따로 data_table[i][j]가 NULL 값이 아니면 한번 더 delete해주는 이유를 모르겠네요 ㅠㅠ",
              "is_md": true
          },
          {
              "comment_id": 5942,
              "article_url": "217",
              "reply_ids": [
                  5947
              ],
              "comment_date": "2018-12-19 23:07:51.443",
              "author_name": "chicchicken",
              "image_link": "",
              "content": "Cell Class 와 Table class가 상호참조(?)하는거 때문에 컴파일 에러가 뜨네요. 상호참조에 대한 설명도 추가하면 좋을 거 같습니다. :)",
              "is_md": true
          }
      ]
  };
    let comments = get_comment_response.comments;
    for (let comment of comments) {
      this.comments_.set(comment.comment_id, comment);
    }

    this.last_comment_index_ += 50;
  }

  public async PostComment(
    content: string,
    password: string,
    name: string,
    parent_id?: number
  ) {
    const url = window.location.href;
    let article_url = url.substr(url.lastIndexOf("/") + 1);

    grecaptcha.ready(function () {
      grecaptcha
        .execute("6LeE_nYUAAAAAGm9qTa71IwvvayWV9Q7flqNkto2", {
          action: "Comment",
        })
        .then(function (token: string) {
          fetch("/write-comment", {
            method: "POST",
            mode: "cors",
            cache: "no-cache",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify({
              parent_id: parent_id,
              content: content,
              password: password || "",
              author_name: name,
              article_url: article_url,
              captcha_token: token,
            }),
          }).then((data) => {
            console.log(data);
            document.getElementById("adding-comment").hidden = true;
            location.reload();
          });
        });
    });
  }

  ComputeRootComments() {
    let comment_ids = Array.from(this.comments_.keys()).sort((a, b) => a - b);
    let visited_comments = new Set<number>();

    this.root_comments_ = [];

    // Find the root comments.
    for (let comment_id of comment_ids) {
      if (visited_comments.has(comment_id)) {
        continue;
      }

      this.root_comments_.push(this.comments_.get(comment_id)!);
      this.VisitAllChildComments(comment_id, visited_comments);
    }

    this.root_comments_ = this.root_comments_.reverse();
  }

  VisitAllChildComments(comment_id: number, visited_comments: Set<number>) {
    let comment = this.comments_.get(comment_id);
    if (!comment) {
      return;
    }

    visited_comments.add(comment_id);
    for (let child_comment_id of comment.reply_ids || []) {
      this.VisitAllChildComments(child_comment_id, visited_comments);
    }

    return;
  }

  CreateCommentList() {
    let root_comment_list = document.createElement("ul");
    root_comment_list.classList.add("comment-list");
    root_comment_list.id = "root-comment-list";

    for (const comment of this.root_comments_) {
      for (const comment_elem of this.CreateComment(comment.comment_id)) {
        root_comment_list.appendChild(comment_elem);
      }
    }

    return root_comment_list;
  }

  CreateComment(comment_id: number) {
    let comment = this.comments_.get(comment_id);
    if (!comment) {
      return [];
    }

    let comment_elem = document.createElement("li");
    comment_elem.classList.add("comment");

    let comment_profile = document.createElement("div");
    comment_profile.classList.add("comment-profile");

    let image_link = document.createElement("img");
    if (comment.image_link) {
      image_link.src = comment.image_link;
      image_link.alt = "프로필 사진";
    } else {
      image_link.src = "./img/unknown_person.png";
      image_link.alt = "프로필 사진 없음";
    }

    comment_profile.appendChild(image_link);
    comment_elem.appendChild(comment_profile);

    let comment_info = document.createElement("div");
    comment_info.classList.add("comment-info");

    // Comment header.
    let comment_header = document.createElement("div");
    comment_header.classList.add("comment-header");

    let createSimpleSpan = (class_name: string, text: string) => {
      let elem = document.createElement("span");
      elem.classList.add(class_name);
      elem.textContent = text;
      return elem;
    };

    comment_header.appendChild(
      createSimpleSpan("comment-author", comment.author_name || "")
    );
    comment_header.appendChild(
      createSimpleSpan("comment-date", comment.comment_date || "")
    );

    comment_info.appendChild(comment_header);

    // Comment content.
    let comment_content = document.createElement("div");
    comment_content.classList.add("comment-content");
    comment_content.textContent = comment.content;
    comment_info.appendChild(comment_content);

    let comment_action = document.createElement("div");
    comment_action.classList.add("comment-action");
    comment_action.id = "comment-id-" + comment_id;

    const commentReplyAction = createSimpleSpan("comment-reply", "답글 달기");
    commentReplyAction.onclick = () => {
      this.CreateCommentReply(comment_id);
    };
    comment_action.appendChild(commentReplyAction);

    const commentDeleteAction = createSimpleSpan("comment-delete", "답글 삭제");
    comment_action.appendChild(commentDeleteAction);
    comment_info.appendChild(comment_action);

    comment_elem.appendChild(comment_info);

    if (!comment.reply_ids) {
      return [];
    }

    if (!comment.reply_ids?.length) {
      return [comment_elem];
    }

    let child_comments = document.createElement("ul");
    child_comments.classList.add("comment-list");

    for (const reply_id of comment.reply_ids) {
      let elems = this.CreateComment(reply_id);
      for (const elem of elems) {
        child_comments.append(elem);
      }
    }

    return [comment_elem, child_comments];
  }

  GetNumTotalComments() {
    return this.num_total_comments_;
  }

  GetLastCommentIndex() {
    return this.last_comment_index_;
  }

  CreateCommentReply(comment_id: number) {
    if (this.current_reply_comment_box) {
      this.current_reply_comment_box.remove();
    }

    // Create a comment box for the comment reply.
    let reply_box = document
      .getElementById("comment-post-section")
      .cloneNode(true) as HTMLElement;
    reply_box.id = "reply-post-section";

    let comment_to_add_reply = document.getElementById(
      "comment-id-" + comment_id
    ).parentElement.parentElement;

    comment_to_add_reply.insertAdjacentElement("afterend", reply_box);

    (
      reply_box.getElementsByClassName("comment-btn")[0] as HTMLButtonElement
    ).onclick = () => {
      let name = "",
        password = "";
      if (reply_box.getElementsByClassName("comment-box-name").length > 0) {
        name = (
          reply_box.getElementsByClassName(
            "comment-box-name"
          )[0] as HTMLInputElement
        ).value;

        password = (
          reply_box.getElementsByClassName(
            "comment-box-name"
          )[0] as HTMLInputElement
        ).value;
      }

      let content = (
        reply_box.getElementsByClassName(
          "comment-textarea"
        )[0] as HTMLInputElement
      ).value;

      this.PostComment(content, password, name, /*parent_id=*/ comment_id).then(
        (res) => {
          console.log(res);
        }
      );
    };
    this.current_reply_comment_box = reply_box;
  }

  private last_comment_index_: number;
  private comments_: Map<number, Comment>;
  private root_comments_: Comment[];
  private num_total_comments_: number;

  // Reply comment box that exists.
  private current_reply_comment_box?: HTMLElement;
}

export function CreateCommentManager(): CommentManager {
  let comment = new CommentManager();
  return comment;
}

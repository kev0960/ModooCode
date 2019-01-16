# 모두의 코드

[모두의 코드](https://modoocode.com) 코드 저장소 입니다. 

## 사용 방법

### 준비물

* Postgres 9 or 10.
* NodeJS 8 or above.
* cmake
* libzmq3
* clang-format 6 or above.

### 설치 과정

1. .env 파일에 PGHOST, PGPORT, PGUSER, PGPASSWORD, HASH_ROUNDS, SESSION_SECRET 등등을 정의합니다. server.js 파일을 참조하면 무엇이 필요한지 자세히 알 수 있습니다. 만약에 .env 파일을 사용하는것이 싫다면 환경 변수에 직접 정의해도 됩니다.
2. Postgres 에 modoocodedb 라는 데이터베이스를 추가합니다.
3. /db 폴더의 sql 파일들을 db 에 추가합니다.
4. npm start 로 서버를 시작할 수 있습니다. 디폴트로 8080 포트에서 listen 하고 있습니다.
5. sudo ./remo-code 로 원격 코드 실행 서버를 실행합니다. 이는 8081 포트에서 listen 하고 있습니다.

### 새 글 쓰기

혹시라도 제 플랫폼에서 글을 추가하고 싶은 분들은 /md 폴더에 새 md 파일을 작성해주면 됩니다. 참고로 제 마크 다운은 원래의 마크 다운 문법과 거의 유사하지만, 몇 가지 새로운 문법들을 정의하고 있습니다.

새 글 추가한 후에 /md-parser/md-parser 에 -md 를 인자로 주시면 해당 마크 다운을 파싱한 html 파일을 static 폴더에 생성합니다. 그 후에 서버를 재시작 하면 됩니다.
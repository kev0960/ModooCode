/*myfile.txt 와 myfile2.txt 를 각각 쓰기 모드 와 덧붙이기(append) 모드로 열어서
 * buffer 을 버퍼로 사용한다. 이 때, pFIle1 의 경우 buffer 를 버퍼로 사용하지만
 * pFile2 는 버퍼를 사용하지 않는다. */
#include <stdio.h>
int main() {
 char buffer[BUFSIZ];
 FILE *pFile1, *pFile2;
 pFile1 = fopen("myfile.txt", "w");
 pFile2 = fopen("myfile2.txt", "a");
 setbuf(pFile1, buffer);
 fputs("This is sent to a buffered stream\n", pFile1);
 fflush(pFile1);
 setbuf(pFile2, NULL);
 fputs("This is sent to an unbuffered stream\n", pFile2);
 fclose(pFile1);
 fclose(pFile2);
return 0;
}

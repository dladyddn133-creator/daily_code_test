#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    char word[1001];
    int ch;
    int i=0;

    ch = getchar();
    while(ch != '\n')
    {
        word[i] = ch;
        i++;
        ch = getchar();
    }
    word[i]='\0';
    int num;
    scanf("%d",&num);
    printf("%c",word[num-1]);

    return 0;
}
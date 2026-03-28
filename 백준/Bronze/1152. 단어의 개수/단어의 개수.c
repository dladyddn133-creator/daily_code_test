#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

int main(void)
{
    int c;
    char temp = 0;
    int count=1;

    c = getchar();
    while(c!='\n')
    {
        if(c==' ' && temp!=0)
        {
            count++;
        }
        temp = c;
        c=getchar();
        if(c=='\n' && temp == ' ')
        {
            count--;
        }
    }
    printf("%d",count);

    return 0;
}

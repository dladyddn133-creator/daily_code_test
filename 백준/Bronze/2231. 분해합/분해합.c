#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 


int main(void)
{
    int N;
    scanf("%d",&N);
    int result=0;
    char str_num[8];
    int i;

    for(i=0;i<N;i++)
    {
        sprintf(str_num,"%d",i);
        result = i;
        for(int j=0;j<strlen(str_num);j++)
        {
            result += ((int)str_num[j]-48);
        }
        if(N==result)
        {
            break;
        }
        result=0;
    }
    if (i==N)
    {
        i=0;
    }
    printf("%d",i);

    return 0;
}

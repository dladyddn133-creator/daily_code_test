#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        for(int j=num-i-2; j>=0;j--)
        {
            printf(" ");
        }
        for(int j=0;j<i+1;j++)
        {
            printf("*");
        }
        printf("\n");
        
    }

    return 0;
}
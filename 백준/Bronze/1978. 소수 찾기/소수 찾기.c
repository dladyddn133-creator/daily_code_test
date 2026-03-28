#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 


int main(void)
{
    int N;
    scanf("%d",&N);
    int num;
    int count=0;

    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        for(int j=2;j<=num/2;j++)
        {
            if(num%j==0)
            {
                break;
            }
            if(j==num/2)
            {
                count++;
            }
        }
        if(num==2 || num==3)
        {
            count++;
        }
    }
    printf("%d",count);

    return 0;
}

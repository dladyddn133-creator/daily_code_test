#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 


int main(void)
{
    int N;
    scanf("%d",&N);
    int result_count=1;
    int plus_count=0;
    int size=1;
    for(int i=1;i<=N;i++)
    {   
        if(size<i)
        {
            plus_count += 1; 
            size += plus_count*6;
            result_count++;
        }
    }
    printf("%d",result_count);

    return 0;
}
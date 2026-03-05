#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 


int main(void)
{
    int N;
    scanf("%d",&N);

    int T_size[6];
    for(int i=0;i<6;i++)
    {
        scanf("%d",&T_size[i]);
    }
    int T,P;
    scanf("%d %d", &T, &P);

    int total_T=0;
    for(int i=0;i<6;i++)
    {
        if(T_size!=0 && T_size[i]%T != 0)
        {
            T_size[i] = T_size[i]/T + 1;
        }
        else if(T_size!=0 && T_size[i]%T == 0)
        {
            T_size[i] = T_size[i]/T;
        }
        else
        {
            T_size[i] = 0;
        }
        total_T += T_size[i];
    }
    int count_P;
    int remain_P;

    count_P = N / P;
    remain_P = N % P;

    printf("%d\n", total_T);
    printf("%d %d", count_P, remain_P);

    return 0;
}

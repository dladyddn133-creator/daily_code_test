#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

int main(void)
{
    int T;
    scanf("%d",&T);
    int input_num;
    scanf("%d",&input_num);
    int max, min;
    max = input_num;
    min = input_num;
    for(int i=0;i<T-1;i++)
    {
        scanf("%d",&input_num);
        if(input_num > max)
        {
            max = input_num;
        }
        if(input_num < min)
        {
            min = input_num;
        }
    } 
    printf("%d %d",min, max);

    return 0;
}

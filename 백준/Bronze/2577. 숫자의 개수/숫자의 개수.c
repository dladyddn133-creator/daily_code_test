#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 



int main(void)
{
    int A,B,C;
    int nums[10]= {0};

    char str_nums[20];


    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);

    int multi_result;
    multi_result = A*B*C;

    sprintf(str_nums,"%d",multi_result);
    int length = strlen(str_nums);

    for(int i=0;i<length;i++)
    {
        nums[(int)str_nums[i]-48]++;
    }
    //printf("%d",strlen(str_nums));
    for(int i=0;i<10;i++)
    {
        printf("%d\n",nums[i]);
    }



    return 0;
}

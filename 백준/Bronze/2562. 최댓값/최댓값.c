#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int array[9];
    for(int i=0;i<9;i++)
    {
        scanf("%d",&array[i]);
    }
    int max=array[0];
    int max_index=0;

    for(int i=1;i<9;i++)
    {
        if(array[i]>max)
        {
            max = array[i];
            max_index=i;
        }
    }
    printf("%d\n",max);
    printf("%d",max_index+1);

    return 0;
}
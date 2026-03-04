#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int array[42]={0};
    int num;
    int count=0;

    for(int i=0;i<10;i++)
    {
        scanf("%d",&num);
        array[(num%42)]++;
    }
    for(int i=0;i<42;i++)
    {
        if(array[i]>0)
        {
            count++;
        }
    }
    printf("%d",count);
    
    return 0;
}

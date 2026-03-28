#include <stdio.h>
#include<stdlib.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int T;
    scanf("%d",&T);
    int num1, num2;
    int *result =(int*)malloc(T * sizeof(int));

    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &num1, &num2);
        result[i] = num1 + num2;
    }
    for(int i=0;i<T;i++)
    {
        printf("%d\n",result[i]);
    }
    free(result);

    return 0;
}
#include <stdio.h>
#include<stdlib.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int N, X;
    scanf("%d %d",&N, &X);

    int *array = (int*)malloc(N * sizeof(int));
    int num;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&num);
        array[i] = num;
    }
    for(int i = 0; i<N; i++)
    {
        if (array[i]<X)
        {
            printf("%d ",array[i]);
        }
    }

    free(array);

    return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int N;
    scanf("%d", &N);

    char* array=(char*)malloc(N*sizeof(char));

    scanf("%s",array);

    int sum=0;

    for(int i=0;i<N;i++)
    {
        sum += (array[i] - 48);
    }

    printf("%d",sum);
    free(array);

    


    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    char A[5],B[5];
    int C;
    char temp[9];

    int result=0;

    scanf("%s",A);
    scanf("%s",B);
    scanf("%d",&C);

    strcpy(temp,A);
    strcat(temp,B);

    int a = atoi(A);
    int b = atoi(B);

    int k = atoi(temp);
    result = k - C;
    printf("%d\n",a+b-C);
    printf("%d",result);

    return 0;
}
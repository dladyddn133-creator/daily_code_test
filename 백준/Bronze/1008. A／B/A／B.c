#include<stdio.h>
//두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
int main(void)
{
    double A, B;
    scanf("%lf %lf", &A, &B);
    double result =0;
    result = A/B;
    printf("%.10lf",result);

    return 0;
}
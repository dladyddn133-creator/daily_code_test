#include<stdio.h>
//두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
    int result =0;
    result = A+B;
    printf("%d",result);

    return 0;
}
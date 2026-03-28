#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    while(num1 != 0 && num2 != 0)
    {
        printf("%d\n", num1+num2);
        scanf("%d %d", &num1, &num2);

    }
    return 0;
}
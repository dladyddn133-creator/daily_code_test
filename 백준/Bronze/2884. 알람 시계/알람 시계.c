#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int H, M;
    scanf("%d",&H);
    scanf("%d",&M);

    if(M>=45)
    {
        M-=45;
    }
    else if(H!=0)
    {
        H-=1;
        M+=15;
    }
    else
    {
        H=23;
        M+=15;
    }
    printf("%d %d",H,M);


    
    return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int T;
    scanf("%d",&T);

    char s[20];
    

    int re_num;
    int length;
    for(int i=0;i<T;i++)
    {
        scanf("%d %s",&re_num, s);
        length = strlen(s);

        for(int j=0;j<length;j++)
        {   
            for(int k=0;k<re_num;k++)
            {
                printf("%c",s[j]);
            }
        }
        printf("\n");
    }


    return 0;
}

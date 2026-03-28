#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int T;
    scanf("%d",&T);

    int score = 0;
    int plus=1;

    char OX_array[80];
    for(int i=0;i<T;i++)
    {
        scanf("%s",OX_array);
        int length=strlen(OX_array);
        for(int j=0;j<length;j++)
        {
            if(OX_array[j]=='O')
            {
                score += plus++;
            }
            else
            {
                plus = 1;
            }
        }
        printf("%d\n",score);
        score=0;
        plus = 1;
    }
    

    return 0;
}

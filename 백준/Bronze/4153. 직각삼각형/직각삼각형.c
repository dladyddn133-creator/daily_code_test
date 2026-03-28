#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 


int main(void)
{
    int triple[3];

    while(1)
    {    
        scanf("%d",&triple[0]);
        for(int i=1;i<3;i++)
        {
            scanf("%d",&triple[i]);
            if(triple[i]>triple[0])
            {
                int temp = triple[0];
                triple[0]=triple[i];
                triple[i]=temp;
            }
        }
        if(triple[0]==0 && triple[1]==0 && triple[2]==0){
            break;
        }
        if(triple[0]>=(triple[1]+triple[2]))
        {
            printf("wrong\n");
        }
        else if((triple[0]*triple[0])!=((triple[1]*triple[1])+(triple[2]*triple[2])))
        {
            printf("wrong\n");
        }
        else
        {
            printf("right\n");
        }
    }


    return 0;
}

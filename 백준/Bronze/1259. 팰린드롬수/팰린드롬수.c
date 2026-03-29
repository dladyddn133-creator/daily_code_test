#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char input_num[6];
    int num_size;
    int num;

    while(1)
    {
        scanf("%s", input_num);
        num = atoi(input_num);
        num_size = strlen(input_num);

        int yorn=1;
        if(num == 0)
        {
            break;
        }
        for(int i=0; i<num_size/2;i++)
        {
            if(input_num[i]!=input_num[(num_size-1)-i])
            {
                yorn=0;
            }
        }
        if(yorn)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}
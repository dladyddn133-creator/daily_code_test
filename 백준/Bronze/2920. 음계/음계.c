#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int c;
    char nums[9];
    char*ascending="12345678";
    char*descending="87654321";
    
    c= getchar();
    int i=0;
    while(c!='\n')
    {
        if(c!=' ')
        {
            nums[i] = c;
            i++;
        }
        c= getchar();
        
    
    }
    nums[8]='\0';
    if(strcmp(nums,ascending)==0)
    {
        printf("ascending");
    }
    else if(strcmp(nums,descending)==0)
    {
        printf("descending");
    }
    else
    {
        printf("mixed");
    }
    
    return 0;
}

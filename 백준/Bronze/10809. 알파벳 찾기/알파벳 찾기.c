#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
int main(void)
{
    int alph[26];
    for(int i=0;i<26;i++)
    {
        alph[i]=-1;
    }
    char word[100]={0};
    scanf("%s",word);
    int length= strlen(word);
    for(int i=0;i<length;i++)
    {
        if(alph[(int)word[i]-97] == -1)
        {
            alph[(int)word[i]-97]=i;
        }
    }
    for(int i=0;i<26;i++)
    {
        printf("%d ",alph[i]);
    }

    return 0;
}

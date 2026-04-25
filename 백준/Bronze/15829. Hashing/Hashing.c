#include<stdio.h>
#include<stdlib.h>
#define RANGE 1234567891

int main(void)
{
    int N;
    scanf("%d", &N);

    long long hashing_31[50];
    long long range = RANGE;
    hashing_31[0]=1;
    for(int i=1;i<50;i++)
    {
        hashing_31[i] = (hashing_31[i-1]*31)% range;
    }
    #if 0
    for(int i=0;i<50;i++)
    {
        printf("%lld\n",hashing_31[i]);
    }
    #endif

    char hashing_str[51];
    scanf("%s",hashing_str);
    long long hashing_total=0;
    #if 1
    for(int i=0;i<N;i++)
    {
        hashing_total += (((long long)hashing_str[i]-96)*hashing_31[i])%range; 
    }
    #endif
    long long mod = 1234567891;
    long long result = hashing_total % mod;
    printf("%llu",result); 

    return 0;
}
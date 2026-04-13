#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int M,N;
    scanf("%d %d", &M,&N);

    int prime_index=0;
    int *prime_nums= (int*)malloc(N*sizeof(int));
    prime_nums[prime_index++] = 2;

    int count=0;
    for(int i=3;i<=N;i+=2)
    {
        while(count<prime_index && (long long)prime_nums[count]*prime_nums[count]<=i)
        {
            if(i%prime_nums[count]==0)
            {
                break;
            }
            count++;
        }
        if(count == prime_index || (long long)prime_nums[count]*prime_nums[count] > i)
        {
            prime_nums[prime_index++] = i;
        }
        count=0;
    }
    int result_index=0;
    for(int i=0;i<prime_index;i++)
    {
        if(prime_nums[result_index]>=M)
        {
            printf("%d\n",prime_nums[result_index]);
        }
        result_index++;
    }

    free(prime_nums);
    return 0;
}
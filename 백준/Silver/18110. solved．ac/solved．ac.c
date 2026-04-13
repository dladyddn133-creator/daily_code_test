#include<stdio.h>
#include<stdlib.h>

int compare(const void*a, const void*b);
int main(void)
{
    float N;
    scanf("%f",&N);
    int trimed = (N * 3 / 20 + 0.5)/1;
    // printf("%d",trimed);
    int *nums = (int*)malloc((int)N * sizeof(int));
    
    for(int i=0;i<(int)N;i++)
    {
        scanf("%d",&nums[i]);
    }
    qsort(nums,(int)N,sizeof(int), compare);

    int sum=0;
    for(int i = trimed;i<(int)N-trimed;i++)
    {
        sum+=nums[i];
    }
    int result=0;
    if(N!=0)
        result = (((float)sum / (N-(2*(float)trimed)))+0.5)/1;
    
    printf("%d",result);

    return 0;
}
int compare(const void*a, const void*b)
{
    int *num_1 = (int*)a;
    int *num_2 = (int*)b;
    if (*num_1 < *num_2) return -1;
    else if(*num_1 > *num_2) return 1;
    else return 0;
}

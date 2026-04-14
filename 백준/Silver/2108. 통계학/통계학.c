#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int data;
    int count;
    /* data */
}mode_count;

int compare(const void*a, const void*b);
int mode_compare(const void*a, const void*b);
int main(void)
{
    int N;
    scanf("%d",&N);

    int * input_nums = (int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
    {
        scanf("%d", &input_nums[i]);
    }
    qsort(input_nums, N, sizeof(int), compare);

    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum += input_nums[i];
    }
    int arith_mean;

    if(sum>=0) arith_mean = (((double)sum/N)+0.5) / 1;
    else arith_mean = (((double)sum/N)-0.5) / 1;
    printf("%d\n",arith_mean);

    int median;
    median = input_nums[N/2];
    printf("%d\n",median);

    int mode;
    int mode_index=1;
    mode_count*mode_arr = (mode_count*)calloc(N,sizeof(mode_count));
    mode_arr[0].data=input_nums[0];
    mode_arr[0].count=1;

    for(int i=1;i<N;i++)
    {
        if(input_nums[i-1]==input_nums[i])
        {
            mode_arr[mode_index-1].count++;
        }
        else
        {
            mode_arr[mode_index].count=1;
            mode_arr[mode_index++].data = input_nums[i];
        }
    }
    qsort(mode_arr, mode_index, sizeof(mode_count), mode_compare);
    if(mode_arr[0].count == mode_arr[1].count) mode = mode_arr[1].data;
    else mode = mode_arr[0].data;

    printf("%d\n", mode);

    int range;
    range = input_nums[N-1] - input_nums[0];
    printf("%d",range);


    free(input_nums);
    free(mode_arr);
    return 0;
}
int compare(const void*a, const void*b)
{
    int *num1 = (int*)a;
    int *num2 = (int*)b;

    if(*num1<*num2) return -1;
    else if(*num1>*num2) return 1;
    else return 0;
}
int mode_compare(const void*a, const void*b)
{
    mode_count*num1 = (mode_count*)a;
    mode_count*num2 = (mode_count*)b;
    if(num1->count > num2->count) return -1;
    else if(num1->count < num2->count) return 1;
    else if(num1->data < num2->data) return -1;
    else return 1;
}

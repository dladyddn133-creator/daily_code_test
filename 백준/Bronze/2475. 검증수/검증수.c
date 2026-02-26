#include <stdio.h>


int sq_result(int *num);
int main(void)
{
    int nums[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d", nums+i);
    }

    int result =sq_result(nums);
    printf("%d",result);

    return 0;
}
int sq_result(int *num)
{
    int exam_array[5];
    for(int i=0; i<5; i++)
    {
        exam_array[i] = num[i]*num[i]; 
    }
    int exam_sum=0;
    for(int i=0; i<5; i++)
    {
        exam_sum += exam_array[i];
    }
    int exam_result = 0;
    exam_result = exam_sum % 10;

    return exam_result;
}
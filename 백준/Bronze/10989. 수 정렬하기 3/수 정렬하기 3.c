#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    int nums[10001] = {0};
    nums[0]=0;
    int input_num;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&input_num);
        nums[input_num]++;
    }
    for(int i=1;i<10001;i++)
    {
        if(nums[i] != 0)
        {
            for(int j=0;j<nums[i];j++)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;

}
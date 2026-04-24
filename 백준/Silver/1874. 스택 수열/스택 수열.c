#include<stdio.h>
#include<stdlib.h>


typedef struct 
{
    int num[100000];
    int top;
    /* data */
}sqc_stack;
void push_stack(sqc_stack*sqc_arr, int input_num);
int pop_stack(sqc_stack*sqc_arr);
int main(void)
{
    int n;
    scanf("%d",&n);

    sqc_stack num_arr;
    num_arr.top = -1;

    for(int i=n;i>0;i--)
    {
        push_stack(&num_arr, i);
    }

    sqc_stack stack_arr;
    stack_arr.top = -1;

    char push_pop_arr[200000];
    int push_pop_arr_index=0;

    int flag=0;
    char *no = "NO";

    int nth_num;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&nth_num);
        while(num_arr.top != -1 &&nth_num >= num_arr.num[num_arr.top])
        {
            push_stack(&stack_arr, pop_stack(&num_arr));
            push_pop_arr[push_pop_arr_index++] = '+';
        }
        if(nth_num == stack_arr.num[stack_arr.top])
        {
            pop_stack(&stack_arr);
            push_pop_arr[push_pop_arr_index++]= '-';
        }
        else
        {
            flag=1;
        }
    }

    if (flag == 0)
    {
        for(int i=0;i<push_pop_arr_index;i++)
        {
            printf("%c\n",push_pop_arr[i]);
        }
    }
    else
    {
        printf("%s",no);
    }

    return 0;
}
void push_stack(sqc_stack*sqc_arr, int input_num)
{
    sqc_arr->top++;
    sqc_arr->num[sqc_arr->top] = input_num;
}
int pop_stack(sqc_stack*sqc_arr)
{
    sqc_arr->top--;
    return sqc_arr->num[sqc_arr->top + 1];
}

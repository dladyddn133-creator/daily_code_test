#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int value;
    int priority;
}prior_nums;

typedef struct 
{
    prior_nums nums[101];
    int front;
    int rear;
}queue;
void push_queue(queue*queue_arr, prior_nums priority, int queue_size);
prior_nums pop_queue(queue*queue_arr);
int main(void)
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        queue queue_arr;
        queue_arr.front = 0;
        queue_arr.rear = 0;

        int N,M;
        scanf("%d %d",&N,&M);

        int prioriy_count[9]={0};

        prior_nums prior;
        for(int i=0;i<N;i++)
        {   
            scanf("%d",&prior.priority);
            prioriy_count[prior.priority-1]++;
            prior.value=0;
            push_queue(&queue_arr,prior,N);
        }
        queue_arr.nums[M].value=1;

        int count=0;
        int target_priority = queue_arr.nums[M].priority;
        int priority_index=8;
        while(target_priority < priority_index+1)
        {
            if(prioriy_count[priority_index] == 0)
            {
                priority_index--;
            }
            else if((priority_index+1)!=queue_arr.nums[queue_arr.front].priority)
            {
                push_queue(&queue_arr,pop_queue(&queue_arr),N);
            }
            else
            {
                prioriy_count[priority_index]--;
                count++;
                pop_queue(&queue_arr);
            }

        }
        while (queue_arr.nums[queue_arr.front].value != 1)
        {
            if(queue_arr.nums[queue_arr.front].priority == target_priority)
            {
                pop_queue(&queue_arr);
                count++;
            }
            else
            {
                push_queue(&queue_arr,pop_queue(&queue_arr),N);
            }
        
        }
        printf("%d\n",count+1);
    }

    return 0;
}
void push_queue(queue*queue_arr, prior_nums priority, int queue_size)
{
    queue_arr->nums[queue_arr->rear].priority = priority.priority;
    queue_arr->nums[queue_arr->rear].value = priority.value;
    queue_arr->rear++;
    if(queue_arr->rear == 101 && queue_arr->front != 0) queue_arr->rear = 0;
}
prior_nums pop_queue(queue*queue_arr)
{
    prior_nums pop_priority = queue_arr->nums[queue_arr->front++];
    if(queue_arr->front == 101) queue_arr->front = 0;
    return pop_priority;
}

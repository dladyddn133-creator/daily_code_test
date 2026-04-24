#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int num[10001];
    int front;
    int back;
}queue;
void push_X(queue*queue_arr, int X);
int pop(queue*queue_arr);
int size(queue*queue_arr);
int empty(queue*queue_arr);
int front(queue*queue_arr);
int back(queue*queue_arr);

int main(void)
{
    int N;
    scanf("%d",&N);

    queue queue_arr = {0, 0, 0};
    int num;
    char command[6];
    for(int i=0;i<N;i++)
    {
        scanf("%s",command);
        if(strcmp("push",command) == 0)
        {
            scanf("%d",&num);
            push_X(&queue_arr,num);
        }
        else if(strcmp("pop",command) == 0) printf("%d\n",pop(&queue_arr));
        else if(strcmp("size",command) == 0) printf("%d\n",size(&queue_arr));
        else if(strcmp("empty",command) == 0) printf("%d\n",empty(&queue_arr));
        else if(strcmp("front",command) == 0) printf("%d\n",front(&queue_arr));
        else printf("%d\n",back(&queue_arr));
    }

    return 0;
}
void push_X(queue*queue_arr, int X)
{
    queue_arr->num[queue_arr->back++]=X;
}
int pop(queue*queue_arr)
{
    if(queue_arr->front != queue_arr->back)
        return queue_arr->num[queue_arr->front++];
    else return -1; 
}
int size(queue*queue_arr)
{
    return (queue_arr->back - queue_arr->front);
}
int empty(queue*queue_arr)
{
    if(queue_arr->front == queue_arr->back) return 1;
    else return 0;
}
int front(queue*queue_arr)
{
    if(queue_arr->front != queue_arr->back)
        return queue_arr->num[queue_arr->front];
    else return -1;
}
int back(queue*queue_arr)
{
    if(queue_arr->front != queue_arr->back)
        return queue_arr->num[queue_arr->back -1];
    else return -1;
}

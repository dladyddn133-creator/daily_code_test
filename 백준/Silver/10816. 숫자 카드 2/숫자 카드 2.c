#include<stdio.h>
#include<stdlib.h>

typedef struct 
{   
    int num;
    int count;
    /* data */
}card_count;
int card_compare(const void*a, const void*b);
int card_binary_search(card_count*set_card_arr, int target, int left, int right);
int main(void)
{
    int N, M;
    scanf("%d", &N);
    card_count * card_arr = (card_count*)calloc(N,sizeof(card_count));
    for(int i=0;i<N;i++)
    {
        scanf("%d", &card_arr[i].num);
    }
    qsort(card_arr, N, sizeof(card_count), card_compare);
    
    card_count * set_card_arr = (card_count*)calloc(N,sizeof(card_count));
    set_card_arr[0].num = card_arr[0].num;
    set_card_arr[0].count = 1; 
    int set_index = 0;

    for(int i=1;i<N;i++)
    {
        if(set_card_arr[set_index].num == card_arr[i].num) set_card_arr[set_index].count++;
        else 
        {
            set_card_arr[++set_index].num = card_arr[i].num;
            set_card_arr[set_index].count = 1;
        }
        
    }

    #if 0
    for(int i=0;i<=set_index;i++)
    {
        printf("%d, %d\n",set_card_arr[i].num, set_card_arr[i].count);
    }
    #endif
    scanf("%d",&M);

    card_count * target_card_arr = (card_count*)calloc(M,sizeof(card_count));
    for(int i=0;i<M;i++)
    {
        scanf("%d", &target_card_arr[i].num);
        target_card_arr[i].count = card_binary_search(set_card_arr, target_card_arr[i].num, 0, set_index+1);
    }
    for(int i=0;i<M;i++)
    {
        printf("%d ",target_card_arr[i].count);
    }

    free(card_arr);
    free(set_card_arr);
    free(target_card_arr);
    return 0;
}
int card_compare(const void*a, const void*b)
{
    card_count *num1 = (card_count*)a;
    card_count *num2 = (card_count*)b;
    
    if (num1->num < num2->num) return -1;
    else if(num1->num > num2->num) return 1;
    else return 0;
}
int card_binary_search(card_count*set_card_arr, int target, int left, int right)
{
    if ((right-left) == -1) return 0;
    int mid = (left+right)/2;
    if (target == set_card_arr[mid].num) return set_card_arr[mid].count;
    else if (target < set_card_arr[mid].num) 
        return card_binary_search(set_card_arr, target, left, mid-1);
    else if (target > set_card_arr[mid].num)
        return card_binary_search(set_card_arr, target, mid+1, right);
}

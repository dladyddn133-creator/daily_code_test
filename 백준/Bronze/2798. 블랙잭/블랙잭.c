#include<stdio.h>
#include<stdlib.h>

void input_card(int N, int* arr);
int black_jack(int N, int M, int*arr);
int main(void)
{
    int N, M;
    scanf("%d %d",&N, &M);
    int *card_array= (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&card_array[i]);
    }
    input_card(N,card_array);
    int result =black_jack(N,M,card_array);
    printf("%d",result);

    free(card_array);
    return 0;
}
void input_card(int N, int* arr)
{
    for(int i=0;i<N;i++)
    {
        for(int j=N-1;j>i;j--)
        {
            if(arr[j]>arr[j-1])
            {
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }

}
int black_jack(int N, int M, int*arr)
{
    int result=0;

    for(int i=0;i<N-2;i++)
    {
        for(int j=i+1;j<N-1;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                int temp =arr[i]+arr[j]+arr[k];
                if((temp<=M)&&(temp>result))
                {
                    result =temp;
                }
            }
        }
    }
    return result;
}
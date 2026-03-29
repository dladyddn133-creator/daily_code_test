#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int N;
    float max_score;
    scanf("%d",&N);

    float*score = (float*)malloc(sizeof(float)*N);
    scanf("%f",score);
    max_score=*score;
    for(int i=1;i<N;i++)
    {
        scanf("%f",&score[i]);
        if(score[i]>max_score)
        {
            max_score=score[i];
        }
    }

    float total=0;

    for(int i=0;i<N;i++)
    {
        score[i] = (score[i]/max_score)*100;
        total += score[i];
    }

    float avg = total/N;

    printf("%f",avg);
    

    free(score);
    return 0;
}
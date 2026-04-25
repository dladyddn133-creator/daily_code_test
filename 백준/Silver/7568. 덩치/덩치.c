#include<stdio.h>
#include<stdlib.h>

typedef struct 
{   
    int wei;
    int hei;
    int rank;
    /* data */
}size_rank;

int main(void)
{
    int N;
    scanf("%d",&N);

    size_rank*students = (size_rank*)calloc(N, sizeof(size_rank));
    for (int i=0;i<N;i++)
    {
        scanf("%d %d",&students[i].wei,&students[i].hei);
        students[i].rank=1;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(students[j].wei > students[i].wei && students[j].hei > students[i].hei)
                students[i].rank++;
        }
    }
    for(int i=0;i<N;i++)
    {
        printf("%d ",students[i].rank);
    }

    free(students);
    return 0;
}
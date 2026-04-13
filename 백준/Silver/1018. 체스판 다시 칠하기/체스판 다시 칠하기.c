#include<stdio.h>
#include<stdlib.h>


int black_kernal[8][8]={{1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1}};
int white_kernal[8][8]={{0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1},
                        {1,0,1,0,1,0,1,0}};

int main(void)
{
    int N,M;
    scanf("%d %d",&N, &M);
    getchar();
    int board[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(getchar()=='B')
            {
                board[i][j]=1;
            }
            else
            {
                board[i][j]=0;
            }
        }
        getchar();
    }

    int min=64;
    int count=0;
    for(int i=0;i<=N-8;i++)
    {
        for(int j=0;j<=M-8;j++)
        {
            for(int k=0;k<8;k++)
            {
                for(int l=0;l<8;l++)
                {
                    if(board[i+k][j+l] != black_kernal[k][l])
                    {
                        count++;
                    }

                }
            }
            if(count<min)
            {
                min = count;
            }
            count = 0;
        }
    }

    for(int i=0;i<=N-8;i++)
    {
        for(int j=0;j<=M-8;j++)
        {
            for(int k=0;k<8;k++)
            {
                for(int l=0;l<8;l++)
                {
                    if(board[i+k][j+l] != white_kernal[k][l])
                    {
                        count++;
                    }

                }
            }
            if(count<min)
            {
                min = count;
            }
            count = 0;
        }
    }
    printf("%d",min);

    return 0;
}

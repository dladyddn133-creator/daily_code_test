#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N,K;

    scanf("%d %d",&N, &K);

    int* N_pac=(int*)malloc(sizeof(int) * (N+1));

    N_pac[0]=1;
    
    for (int i=1;i<N+1;i++)
    {
        N_pac[i] = N_pac[i-1] * i;
    }

    int result = N_pac[N]/(N_pac[N-K]*N_pac[K]);

    printf("%d",result);

    free(N_pac);
    return 0;

}
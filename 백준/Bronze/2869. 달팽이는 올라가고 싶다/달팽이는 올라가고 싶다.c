#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int A, B, V;
    scanf("%d %d %d",&A, &B, &V);

    int goal_V = V-A;
    int day = goal_V/(A-B);

    int day_frac = goal_V % (A-B);
    if (day_frac == 0)
    {
        day +=1;
    }
    else if (day_frac > 0)
    {
        day +=2;
    }
    printf("%d\n", day);

    return 0;
}
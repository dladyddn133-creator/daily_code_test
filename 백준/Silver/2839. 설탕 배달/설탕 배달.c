#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    int moc = N / 5;
    int namuz = N % 5;

    int result;

    if(namuz == 0)
    {
        result = moc;
    }
    else if((moc >= 1) && (namuz == 1))
    {
        result = (moc - 1) + 2;
    }
    else if((moc >= 2) && (namuz == 2))
    {
        result = (moc - 2) + 4;
    }
    else if((moc >= 0) && (namuz == 3))
    {
        result = moc + 1;
    }
    else if((moc >= 1) && (namuz == 4))
    {
        result = (moc-1) + 3;
    }
    else
    {
        result = -1;
    }
    printf("%d",result);

    return 0;
}
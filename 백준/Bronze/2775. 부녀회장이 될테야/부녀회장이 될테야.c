#include<stdio.h>
#include<stdlib.h>

int floor_dy(int*arr, int n, int k);
int main(void)
{
    int T;
    scanf("%d",&T);
    int floor_0[14];
    for(int i=0;i<14;i++)
    {
        floor_0[i] = i+1;
    }
    int k, n;
    int result;
    for(int i=0; i<T;i++)
    {
        scanf("%d %d", &k, &n);
        result =floor_dy(floor_0, k, n);
        printf("%d\n",result);
    }

    return 0;
}
int floor_dy(int*arr, int k, int n)
{
    int floor_n[n]; 
    int floor=k-1;
    floor_n[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        floor_n[i] = arr[i]+floor_n[i-1];
    }
    if(floor>0)
    {
        return floor_dy(floor_n, floor, n);
    }
    else 
        return floor_n[n-1];
}

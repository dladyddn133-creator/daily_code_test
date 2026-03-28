#include<stdio.h>
#define SQR(x) ((x)*(x))

void sort_triangle(int*arr);
void print_right_triangle(int*arr);

int main(void)
{ 
    int input_triangle[3];
    while(1)
    {
        for(int i=0;i<3;i++)
        {
            scanf("%d",&input_triangle[i]);
        }
        if(input_triangle[0]==0&&input_triangle[1]==0&&input_triangle[2]==0)
        {
            break;
        }
        sort_triangle(input_triangle);
        print_right_triangle(input_triangle);
    }

    return 0;
}
void sort_triangle(int*arr)
{
    for(int i=1;i<3;i++)
    {
        if(arr[i]>arr[0])
        {
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
        }
    }

}
void print_right_triangle(int*arr)
{
    if(SQR(arr[0]) == SQR(arr[1])+SQR(arr[2]))
    {
        printf("right\n");
    }
    else
    {
        printf("wrong\n");
    }
}

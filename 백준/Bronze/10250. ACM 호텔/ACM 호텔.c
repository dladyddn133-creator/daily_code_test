#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
typedef struct{
    int H;
    int W;
    int N;
}hotel_choice;

int room_number(int H, int W, int N);
int main(void)
{
    int T;
    scanf("%d",&T);
    hotel_choice* hotel = (hotel_choice*)malloc(T*sizeof(hotel_choice));
    int result=0;

    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d",&hotel[i].H, &hotel[i].W, &hotel[i].N);    
    }
    for(int i=0;i<T;i++)
    {
        result = room_number(hotel[i].H, hotel[i].W, hotel[i].N);
        printf("%d\n",result);
    }

    return 0;
}

int room_number(int H, int W, int N)
{
    int YY_result=0;
    int XX_result=0;

    YY_result = N % H;
    XX_result = N / H +1;
    if (YY_result==0)
    {
        YY_result=H;
        XX_result-=1;
    }
    

    int result = (YY_result*100) + XX_result;

    return result;
}
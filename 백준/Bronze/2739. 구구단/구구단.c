#include <stdio.h>


void gugudan(int num);
int main(void)
{
    int num;
    scanf("%d", &num);
    gugudan(num);

    return 0;
}
void gugudan(int num)
{
    for(int i=1; i<10; i++)
    {
        printf("%d * %d = %d\n", num, i, num*i);
    }
}
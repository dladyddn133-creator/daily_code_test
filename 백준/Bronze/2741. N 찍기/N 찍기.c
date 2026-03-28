#include <stdio.h>


void num_print(int num);
int main(void)
{
    int num;
    scanf("%d", &num);
    num_print(num);

    return 0;
}
void num_print(int num)
{
    for(int i=1; i<num+1; i++)
    {
        printf("%d\n", i);
    }
}
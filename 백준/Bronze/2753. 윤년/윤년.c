#include <stdio.h>

int leap_year_print(int num);
int main(void)
{
    int num;
    scanf("%d", &num);
    int result = leap_year_print(num);
    printf("%d", result);

    return 0;
}
int leap_year_print(int num)
{
    if (num % 4 != 0)
    {
        return 0;
    }
    else if (num % 100 == 0)
    {
        if (num % 400 == 0)
        {
            return 1;
        }
        return 0;
    }
    else{
        return 1;    
    }
}
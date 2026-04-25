#include<stdio.h>
#include<string.h>


typedef struct 
{
    char paren[100];
    int top;
    /* data */
}paren_stack;

void paren_push(paren_stack*paren_arr, char paren);
char paren_pop(paren_stack*paren_arr);
int main(void)
{
    paren_stack paren_arr;
    paren_arr.top = -1;
    int c;

    int count = 0;
    int flag = 0;
    while(1)
    {
        c = getchar();
        while(c != '.')
        {
            if(c == '(' || c == '[') paren_push(&paren_arr, c);
            else if(c == ']' && (paren_arr.paren[paren_arr.top] == '(' || paren_arr.top== -1))
                flag = 1;
            else if(c == ')' && paren_arr.paren[paren_arr.top] == '(')
                paren_pop(&paren_arr);
            else if(c == ')' && (paren_arr.paren[paren_arr.top] == '[' || paren_arr.top== -1))
                flag = 1;
            else if(c == ']' && paren_arr.paren[paren_arr.top] == '[')
                paren_pop(&paren_arr);

            c = getchar();
            count++; 
        }
        if (count == 0) break;
        else if(paren_arr.top == -1 && flag ==0)
        {
            printf("%s\n","yes");
        }
        else 
        {
            printf("%s\n","no");
            paren_arr.top = -1;
            flag = 0;
        }
        getchar();
        count = 0;
    }
    return 0;
}
void paren_push(paren_stack*paren_arr, char paren)
{
    paren_arr->paren[++paren_arr->top]=paren;
}
char paren_pop(paren_stack*paren_arr)
{
    paren_arr->top--;
    return paren_arr->paren[paren_arr->top + 1];
}

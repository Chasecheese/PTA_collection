#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30 /* max size of expression */

ElementType EvalPostfix(char *expr);

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix(expr);
    if (v < Infinity)
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
char GetChar(char *expr, int i);

ElementType EvalPostfix(char *expr)
{
    ElementType stack[Max_Expr];
    int top = 0;

    while (1)
    {
        char str[Max_Expr];
        int pos, j;
        pos =0;
        char temp;
        while (1)
        {
            temp = GetChar(expr, pos++);
            if (temp == '#')
            {
                break;
            }
            else if (temp == ' ')
            {
                continue;
            }
            else if (temp == '+' || temp == '/' || temp == '*')
            {
                ElementType res;
                ElementType b = stack[--top];
                ElementType a = stack[--top];
                switch (temp)
                {
                    case '+':
                        res = a + b;
                        break;
                    case '/':
                        if(b == 0){
                            return Infinity;
                        }
                        res = a / b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    default:
                        break;
                }
                stack[top++] = res;
            }
            else if (temp == '-')
            {
                temp = GetChar(expr, pos++);
                if (temp >= '0' && temp <= '9')
                {
                    int i = 1;
                    ElementType num;
                    while (temp == '.' || (temp >= '0' && temp <= '9'))
                    {
                        str[i++] = temp;
                        temp = GetChar(expr, pos++);
                    }
                    str[i] = '\0';
                    str[0] = '-';
                    num = atof(str);
                    stack[top++] = num;
                }
                else if (temp == ' ' || temp == '#')
                {
                    ElementType res;
                    ElementType b = stack[--top];
                    ElementType a = stack[--top];
                    res = a-b;
                    stack[top++] = res;
                }
                pos --;
            }
            else if (temp >= '0' && temp <= '9')
            {
                int i = 0;
                ElementType num;
                while (temp == '.' || (temp >= '0' && temp <= '9'))
                {
                    str[i++] = temp;
                    temp = GetChar(expr, pos++);
                }
                str[i] = '\0';
                num = atof(str);
                stack[top++] = num;
                pos --;
            }
        }
        if(top != 1) return Infinity;
        return stack[--top];
    }
}

char GetChar(char *expr, int i)
{
    if (expr[i] >= '0' && expr[i] <= '9')
    {
        return expr[i];
    }
    if (expr[i] == '.' || expr[i] == '-' || expr[i] == '+' || expr[i] == '/' || expr[i] == '*' || expr[i] == ' ')
    {
        return expr[i];
    }
    return '#';
}
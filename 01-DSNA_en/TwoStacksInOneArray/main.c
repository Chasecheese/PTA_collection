#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
Stack CreateStack( int MaxElements )
{
    Stack S = (Stack)malloc(sizeof(Stack));
    S->Array = (ElementType*)malloc(MaxElements*sizeof(ElementType));
    S->Capacity = MaxElements;
    S->Top1 = 0;
    S->Top2 = S->Capacity-1;
    return S;
}
int IsEmpty( Stack S, int Stacknum )
{
    switch (Stacknum)
    {
        case 1:
            if(S->Top1 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        case 2:
            if(S->Top2 == S->Capacity-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        default:
            return ERROR;
    }
}
int IsFull( Stack S )
{
    if(S->Top1 == S->Top2 + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Push( ElementType X, Stack S, int Stacknum )
{
    if(IsFull(S)) return 0;
    switch (Stacknum)
    {
        case 1:
            S->Array[S->Top1] = X;
            (S->Top1)++;
            return 1;
            break;
        case 2:
            S->Array[S->Top2] = X;
            (S->Top2)--;
            return 1;
            break;
        default:
            return ERROR;
    }
}
ElementType Top_Pop( Stack S, int Stacknum )
{
    if(IsEmpty(S, Stacknum)) return ERROR;
    switch (Stacknum)
    {
        case 1:
            return S->Array[--(S->Top1)];
            break;
        case 2:
            return S->Array[++(S->Top2)];
            break;
        default:
            return ERROR;
    }
}
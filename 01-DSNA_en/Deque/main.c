#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
Deque CreateDeque()
{
    Deque d = (struct DequeRecord*)malloc(sizeof(struct DequeRecord));
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    header->Last = NULL;
    header->Next = NULL;
    d->Front = header;
    d->Rear = header;
    return d;
}
int Push( ElementType X, Deque D )
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 0;
    }
    p->Element = X;
    p->Last = D->Front;
    if(D->Front != D->Rear)
    {
        D->Front->Next->Last = p;
        p->Next = D->Front->Next;
        D->Front->Next = p;
    }
    else
    {
        D->Front->Next = p;
        p->Last = D->Front;
        D->Rear = p;
    }
    return 1;
}
ElementType Pop( Deque D ){
    if(D->Front == D->Rear)
    {
        return ERROR;
    }
    if(D->Front->Next == D->Rear)
    {
        ElementType temp = D->Front->Next->Element;
        free(D->Front->Next);
        D->Rear = D->Front;
        D->Front->Next = NULL;
        return temp;
    }
    else
    {
        struct Node* p = D->Front->Next;
        ElementType p_elm = p->Element;
        D->Front->Next->Next->Last = D->Front;
        D->Front->Next = D->Front->Next->Next;
        free(p);
        p = NULL;
        return p_elm;
    }
}
int Inject( ElementType X, Deque D )
{
    D->Rear->Next = (struct Node*)malloc(sizeof(struct Node));
    if(D->Rear->Next == NULL)
    {
        return 0;
    }
    D->Rear->Next->Last = D->Rear;
    D->Rear = D->Rear->Next;
    D->Rear->Next = NULL;
    D->Rear->Element = X;
    return 1;
}
ElementType Eject( Deque D )
{
    if(D->Rear == D->Front)
    {
        return ERROR;
    }
    struct Node* p = D->Rear;
    D->Rear = p->Last;
    ElementType p_elm =p->Element;
    free(p);
    p = NULL;
    D->Rear->Next = NULL;
    return p_elm;
}
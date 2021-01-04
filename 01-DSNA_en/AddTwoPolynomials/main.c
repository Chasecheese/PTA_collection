#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Add( Polynomial a, Polynomial b )
{
    Polynomial poly = (PtrToNode)malloc(sizeof(struct Node));
    PtrToNode p = poly;
    p->Next = NULL;
    PtrToNode p_a = a->Next;
    PtrToNode p_b = b->Next;
    while(p_a != NULL && p_b != NULL){
        if(p_a->Exponent == p_b->Exponent){
            if(p_a->Coefficient + p_b->Coefficient != 0)
            {
                p->Next = (PtrToNode)malloc(sizeof(struct Node));
                p = p->Next;
                p->Coefficient = p_a->Coefficient + p_b->Coefficient;
                p->Exponent = p_a->Exponent;
                p->Next = NULL;
            }
            p_a = p_a->Next;
            p_b = p_b->Next;
        }
        else if(p_a->Exponent > p_b->Exponent){
            p->Next = (PtrToNode)malloc(sizeof(struct Node));
            p = p->Next;
            p->Coefficient = p_a->Coefficient;
            p->Exponent = p_a->Exponent;
            p->Next = NULL;
            p_a = p_a->Next;
        }
        else if(p_b->Exponent > p_a->Exponent){
            p->Next = (PtrToNode)malloc(sizeof(struct Node));
            p = p->Next;
            p->Coefficient = p_b->Coefficient;
            p->Exponent = p_b->Exponent;
            p->Next = NULL;
            p_b = p_b->Next;
        }
    }
    while(p_a!=NULL)
    {
        p->Next = (PtrToNode)malloc(sizeof(struct Node));
        p = p->Next;
        p->Coefficient = p_a->Coefficient;
        p->Exponent = p_a->Exponent;
        p->Next = NULL;
        p_a = p_a->Next;
    }
    while(p_b!=NULL)
    {
        p->Next = (PtrToNode)malloc(sizeof(struct Node));
        p = p->Next;
        p->Coefficient = p_b->Coefficient;
        p->Exponent = p_b->Exponent;
        p->Next = NULL;
        p_b = p_b->Next;
    }
    return poly;
}
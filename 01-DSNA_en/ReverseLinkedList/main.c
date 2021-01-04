#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */

// List Read()
// {
//     int count;
//     scanf("%d", &count);
//     struct Node* L = malloc(sizeof(struct Node));
//     L->Next = NULL;
//     int i;
//     ElementType num;
//     struct Node* p = L;
//     for(i=0; i<count; i++)
//     {
//         scanf("%d", &num);
//         p->Next = malloc(sizeof(struct Node));
//         p->Next->Element = num;
//         p->Next->Next = NULL;
//         p = p->Next;
//     }
//     return L;
// }

// void Print( List L )
// {
//     struct Node* p = L;
//     p = p->Next;
//     while(p!=NULL){
//         printf("%d ", p->Element);
//         p = p->Next;
//     }
//     printf("\n");
// }

List Reverse( List L )
{
    if(L->Next == NULL || L == NULL){
        return L;
    }
    struct Node* p_pre = NULL;
    struct Node* p = L->Next;
    struct Node* p_next = p->Next;

    while(p->Next != NULL)
    {
        p->Next = p_pre;
        p_pre = p;
        p = p_next;
        p_next = p_next->Next;
    }
    p->Next = p_pre;
    L -> Next = p;
    return L;
}
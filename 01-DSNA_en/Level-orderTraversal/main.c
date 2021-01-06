#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    // Tree T = BuildTree();
    Tree T;
    T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->Element = 0;
    T->Left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->Right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->Left->Element =1;
    T->Right->Element = 2;
    T->Left->Left = NULL;
    T->Left->Right = NULL;
    T->Right->Left =NULL;
    T->Right->Right = NULL;
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

/* Your function will be put here */
void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    struct TreeNode* queue[MaxTree];
    struct TreeNode* temp;
    int front = 0;
    int back = 0;
    if(T) queue[back++] = T;
    while(front < back){
        temp = queue[front++];
        visit(temp);
        if(temp->Left != NULL){
            queue[back++] = temp->Left;
        }
        if(temp->Right != NULL){
            queue[back++] = temp->Right;
        }
    }
}
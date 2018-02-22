#include <stdio.h>
#include <stdlib.h>

// prototype of functional nodes

#define FuncNode_BASE \
        struct FuncNode* lhs; \
        struct FuncNode* rhs; \
        Type type;

#define FuncNode_NULLIFY(fnode) \
        fnode->lhs = NULL; \
        fnode->rhs = NULL

//type of node
typedef enum
{
        Type_Add,
        Type_Int,
        Type_Caller
} Type;

// Multi-typed node object
// Has base type for casting.
struct FuncNode
{
        FuncNode_BASE
};

typedef struct FuncNode FuncNode;

//int type
typedef struct
{
        FuncNode_BASE
        int i;
} IntNode;

//add type
typedef struct
{
        FuncNode_BASE
} AddNode;

typedef struct
{
        FuncNode_BASE
        struct FuncNode* params[1]; //max parameters
} CallerNode;

// Allocates and constructs an add node
FuncNode* FuncNode_make_add(int lhi, int rhi)
{
        AddNode* newnode = malloc(sizeof(AddNode));
        IntNode* lhn = malloc(sizeof(IntNode));
        IntNode* rhn = malloc(sizeof(IntNode));
        FuncNode_NULLIFY(newnode);
        FuncNode_NULLIFY(lhn);
        FuncNode_NULLIFY(rhn);
        newnode->type = Type_Add;
        lhn->type = Type_Int;
        rhn->type = Type_Int;
        lhn->i = lhi;
        rhn->i = rhi;
        newnode->rhs = (FuncNode*)rhn;
        newnode->lhs = (FuncNode*)lhn;
        return (FuncNode*)newnode;
}

FuncNode* FuncNode_make_call(void)
{
        CallerNode* newnode = malloc(sizeof(CallerNode));
        FuncNode_NULLIFY(newnode);
        newnode->type = Type_Caller;
        return (FuncNode*)newnode;
}


// Evaluates function nodes
int FuncNode_Eval(FuncNode* fPtr)
{
        if(fPtr->type == Type_Int) return ((IntNode*)fPtr)->i;
        else if(fPtr->type == Type_Add) return FuncNode_Eval(fPtr->lhs) + FuncNode_Eval(fPtr->rhs);
        else return 0;
}

int main(int argc, char const *argv[]) {
        FuncNode* foon = FuncNode_make_add(80, 80);
        free(foon->rhs);
        foon->rhs = FuncNode_make_add(80, 80);
        printf("The sum is %d\n", FuncNode_Eval(foon));
        // 240
        return 0;
}

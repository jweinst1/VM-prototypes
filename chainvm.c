#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chain - style VM
// Works off of linked blocks of marked data

#define Block_INT_SIZE (sizeof(Block) + sizeof(int) + sizeof(unsigned char))

typedef enum
{
        BlockType_Int
} BlockType;

struct Block
{
        struct Block* next;
        struct Block* prev;
        size_t len;
        unsigned char obj[0];
};
typedef struct Block Block;


Block* Block_new(size_t length)
{
        Block* newb = malloc(sizeof(Block) + (length * sizeof(unsigned char)));
        newb->next = NULL;
        newb->prev = NULL;
        newb->len = length;
        return newb;
}

Block* Block_new_int(int num)
{
        Block* newb = malloc(Block_INT_SIZE);
        newb->next = NULL;
        newb->prev = NULL;
        newb->len = sizeof(int) + sizeof(unsigned char);
        newb->obj[0] = BlockType_Int;
        *(int*)(newb->obj + 1) = num;
        return newb;
}

void Block_del(Block* blocks)
{
        while(blocks != NULL)
        {
                free(blocks);
                blocks = blocks->next;
        }
}

void Block_debug(Block* b)
{
        puts("___Block_Debug____");
        printf("next @ %p;\nprev @ %p;\nlength = %lu\n", b->next, b->prev, b->len);
        for (size_t i = 0; i < b->len; i++) {
                printf("byte %lu: = %u\n", i, b->obj[i]);
        }
        puts("__________________");
}

void Block_con(Block* b1, Block* b2)
{
        b1->next = b2;
        b2->prev = b1;
}

void Block_dis(Block* b1, Block* b2)
{
        b1->next = NULL;
        b2->prev = NULL;
}

int main(int argc, char const *argv[]) {
        puts("test\n");
        return 0;
}

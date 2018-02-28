#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chain - style VM
// Works off of linked blocks of marked data

typedef struct
{
        struct Block* next;
        struct Block* prev;
        size_t len;
        unsigned char obj[0];
} Block;

int main(int argc, char const *argv[]) {
        /* code */
        return 0;
}

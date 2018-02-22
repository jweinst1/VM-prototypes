#include <stdio.h>
#include <stdlib.h>

/*
   Implementation of function machine,
   Works like a function but is a tangible object, like a VM.
   Instead of being all instructions, has slots for return value, parameters, statements, etc.
   works off a linear format.
   Can facilitate recursion without blowing up call stack.
 */

typedef struct
{
        unsigned char retVal[0];
} FnMach;

int main(int argc, char const *argv[]) {
        /* code */
        return 0;
}

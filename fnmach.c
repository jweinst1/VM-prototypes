#include <stdio.h>
#include <stdlib.h>
/*
   Implementation of function machine,
   Works like a function but is a tangible object, like a VM.
   Instead of being all instructions, has slots for return value, parameters, statements, etc.
   works off a linear format.
   Can facilitate recursion without blowing up call stack.
 */

#define FnMach_ALLOC calloc(1, sizeof(FnMach))

#define FnMach_PCOUNT 3
#define FnMach_INS_COUNT 200

// Function Machine Structure
// For this impl, only integers are used as types.
// Also uses fixed number of params and ins for testing.
typedef struct
{
        unsigned char ins[FnMach_INS_COUNT];
        int params[FnMach_PCOUNT];
        int retVal;
} FnMach;

// Function to print debug format of function machine.
void FnMach_debug(FnMach* mach)
{
        puts("____Func_Machine_____");
        printf("Param Count: %d\n", FnMach_PCOUNT);
        for (int i = 0; i < FnMach_PCOUNT; i++) {
                printf("(Param %d) = %d\n", i, mach->params[i]);
        }
        puts("Instructions:::::");
        for (int j = 0; j < FnMach_INS_COUNT; j++) {
                printf("{Ins %d} : %u\n", j, mach->ins[j]);
        }
        printf("Return Value: %d\n", mach->retVal);
        puts("_____________________");
}


int main(int argc, char const *argv[]) {
        FnMach* machtest = FnMach_ALLOC;
        FnMach_debug(machtest);
        free(machtest);
        return 0;
}

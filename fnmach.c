#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/*
   Implementation of function machine,
   Works like a function but is a tangible object, like a VM.
   Instead of being all instructions, has slots for return value, parameters, statements, etc.
   works off a linear format.
   Can facilitate recursion without blowing up call stack.
 */

#define FnMach_ALLOC calloc(1, sizeof(FnMach))

#define FnMach_PCOUNT 2
#define FnMach_INS_COUNT 200

// Instruction Enumeration
//
typedef enum
{
        FnInst_Stop, // Ends the execution
        FnInst_Param, // Indicates a parameter
        FnInst_Int, // Indicates inlined integer argument
        FnInst_SetR, // Sets return value
        FnInst_AddI, // Adds an integer
        FnInst_SubI // Subtracts an integer
} FnInst;

// selection for running functional machine
typedef enum
{
        FnMode_ret,
        FnMode_recursive
} FnMode;

// Function Machine Structure
// For this impl, only integers are used as types.
// Also uses fixed number of params and ins for testing.
typedef struct
{
        unsigned char ins[FnMach_INS_COUNT];
        int params[FnMach_PCOUNT];
        int retVal;
        int recursVal; // Used for recursive calcuations
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
        printf("Recurs Value: %d\n", mach->recursVal);
        puts("_____________________");
}

// Loads arguments into paramter slots of functional machine.
void FnMach_load_params(FnMach* mach, int* args)
{
        for (int i = 0; i < FnMach_PCOUNT; i++) {
                mach->params[i] = args[i];
        }
}

// Loads an entire suite of instructions onto the functional machine.
void FnMach_load_ins(FnMach* mach, unsigned char* inst, size_t n)
{
        memcpy(mach->ins, inst, n % FnMach_INS_COUNT);
}

// Combo function to create new functional machine.
FnMach* FnMach_create(unsigned char* inst, size_t inst_n, int* args)
{
        FnMach* newmach = FnMach_ALLOC;
        FnMach_load_params(newmach, args);
        FnMach_load_ins(newmach, inst, inst_n);
        return newmach;
}

// Variadic function that packs arguments into instructions for a function machine.
// Returns 0 if error, 1 if success
int FnMach_pack(FnMach* mach, const char* fmt, ...)
{
        unsigned char* writer = mach->ins;
        va_list fnargs;
        va_start(fnargs, fmt);
        while(*fmt)
        {
                switch(*fmt)
                {
                case 'b':
                        *writer++ = va_arg(fnargs, int);
                        fmt++;
                        break;
                case 'i':
                        *(int*)writer = va_arg(fnargs, int);
                        writer += sizeof(int);
                        fmt++;
                        break;
                default:
                        fprintf(stderr, "Format Err:, unknown specifier %c\n", *fmt);
                        va_end(fnargs);
                        return 0;
                }
        }
        va_end(fnargs);
        return 1;
}

int FnMach_run(FnMach* mach, FnMode mode)
{
        return 1;
}


int main(int argc, char const *argv[]) {
        FnMach* machtest = FnMach_ALLOC;
        FnMach_pack(machtest, "bi", 5, 500);
        FnMach_debug(machtest);
        free(machtest);
        return 0;
}

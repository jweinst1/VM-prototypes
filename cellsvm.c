#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * VM that uses a fixed amount of cells and a head pointer of the current cell being evaluated.
 * Works as a combination between stack and register machines.
 * Has stack depth limit.
 * Each cell contains slot for value.
 */

#define CELL_COUNT 1000

// Vm functional - const macros
#define VM_SPACE (CELL_COUNT - VM_HEAD)
#define VM_HPTR (VM_TABLE + VM_HEAD)

// Denotes type of a cell.
typedef enum
{
        CellType_Int
} CellType;

// Structure of a single cell in the machine.
typedef struct
{
        CellType type;
        void* val;
} VmCell;

// Main table of cells for VM
static VmCell VM_TABLE[CELL_COUNT];
// Index of current machine head.
static int VM_HEAD = 0;

int main(int argc, char const *argv[]) {
        /* code */
        return 0;
}

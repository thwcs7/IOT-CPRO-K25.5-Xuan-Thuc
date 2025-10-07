#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*  Function Prototypes */
void make_stack_ovf();
void make_mem_leak();

void make_stack_ovf()
{
    printf("make_stack_ovf \n");
    uint8_t foo[10 * 1024 * 1024];
}

void make_mem_leak()
{
    printf("make_mem_leak \n");
    uint8_t *pNumber = (uint8_t *)malloc(25 * sizeof(uint8_t));
    // free(pNumber);
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "stack_overflow") == 0) {
        make_stack_ovf();
    } else if (strcmp(argv[1], "memory_leak") == 0) {
        make_mem_leak();
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        fprintf(stderr, "Allowed options: stack_overflow, memory_leak\n");
        return 1;
    }

    return 0;
}
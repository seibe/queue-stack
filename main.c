#include <assert.h>
#include <stdlib.h>
#include "seibe_list.h"

#define TEST_SIZE 1024

int main(int argc, char const* argv[]) {
    SeibeList queue;
    SeibeList stack;
    int i, *popped;

    queue = SeibeList_create();
    stack = SeibeList_create();

    for(i = 0; i < TEST_SIZE; ++i) {
        int *data1 = (int *)malloc(sizeof(int));
        int *data2 = (int *)malloc(sizeof(int));
        *data1 = *data2 = i;
        SeibeList_push(queue, (void *)data1);
        SeibeList_push(stack, (void *)data2);
    }

    popped = (int *)SeibeList_remove(queue, 100);
    assert(popped);
    assert(*popped == 100);
    SeibeList_insert(queue, 100, (void *)popped);

    for(i = 0; i < TEST_SIZE; ++i) {
        popped = (int *)SeibeList_shift(queue);
        assert(popped);
        assert(*popped == i);
        free(popped);
        popped = (int *)SeibeList_pop(stack);
        assert(popped);
        assert(*popped == TEST_SIZE - 1 - i);
        free(popped);
    }

    assert(!SeibeList_shift(queue));
    assert(!SeibeList_pop(stack));

    SeibeList_destroy(queue);
    SeibeList_destroy(stack);
    
    return EXIT_SUCCESS;
}

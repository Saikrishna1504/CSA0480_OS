#include <stdio.h>

#define NUM_BLOCKS 5
#define NUM_REQUESTS 10

struct Block {
    int size;
    int allocated;
};

struct Request {
    int size;
};

void allocateMemory(struct Block blocks[], struct Request requests[], int (*fitFunction)(struct Block[], struct Request, int)) {
    for (int i = 0; i < NUM_REQUESTS; ++i) {
        int blockIndex = fitFunction(blocks, requests[i], NUM_BLOCKS);
        if (blockIndex != -1) {
            blocks[blockIndex].allocated = 1;
            printf("Request %d of size %d is allocated to block %d\n", i + 1, requests[i].size, blockIndex + 1);
        }
    }
}

int firstFit(struct Block blocks[], struct Request request, int numBlocks) {
    for (int j = 0; j < numBlocks; ++j) {
        if (blocks[j].allocated == 0 && blocks[j].size >= request.size) {
            return j;
        }
    }
    return -1;
}

int bestFit(struct Block blocks[], struct Request request, int numBlocks) {
    int bestBlock = -1;
    for (int j = 0; j < numBlocks; ++j) {
        if (blocks[j].allocated == 0 && blocks[j].size >= request.size) {
            if (bestBlock == -1 || blocks[j].size < blocks[bestBlock].size) {
                bestBlock = j;
            }
        }
    }
    return bestBlock;
}

int worstFit(struct Block blocks[], struct Request request, int numBlocks) {
    int worstBlock = -1;
    for (int j = 0; j < numBlocks; ++j) {
        if (blocks[j].allocated == 0 && blocks[j].size >= request.size) {
            if (worstBlock == -1 || blocks[j].size > blocks[worstBlock].size) {
                worstBlock = j;
            }
        }
    }
    return worstBlock;
}

int main() {
    struct Block blocks[NUM_BLOCKS] = {
        {100, 0}, {200, 0}, {300, 0}, {400, 0}, {500, 0}
    };

    struct Request requests[NUM_REQUESTS] = {
        {50}, {200}, {75}, {300}, {100}, {250}, {150}, {100}, {200}, {50}
    };

    printf("First Fit:\n");
    allocateMemory(blocks, requests, firstFit);

    for (int i = 0; i < NUM_BLOCKS; ++i) {
        blocks[i].allocated = 0;
    }

    printf("\nBest Fit:\n");
    allocateMemory(blocks, requests, bestFit);

    for (int i = 0; i < NUM_BLOCKS; ++i) {
        blocks[i].allocated = 0;
    }

    printf("\nWorst Fit:\n");
    allocateMemory(blocks, requests, worstFit);

    return 0;
}

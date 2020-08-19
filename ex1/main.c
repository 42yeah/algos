//
//  main.c
//  ex1
//
//  Created by Hao Zhou on 19/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

// Question: Design an algorithm, which generates an array of 20 random elements less than 100. Put numbers below 50 in the first half, and numbers above 50 the second half. You need to write a header file too.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int main(int argc, const char * argv[]) {
    struct Array array;
    array.head = 0;
    array.tail = NUM_ELEMENTS - 1;
    
    srand((unsigned int) time(NULL));
    
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int gen = rand() % MAX;
        int pos = gen < MAX / 2 ? array.head++ : array.tail--;
        array.elements[pos] = gen;
    }
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d ", array.elements[i]);
    }
    printf("\n");
    return 0;
}

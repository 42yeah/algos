//
//  main.c
//  ex3
//
//  Created by Hao Zhou on 19/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

// Question: delete extranous elements inside a unidirectional linked list.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 100
#define LEN 200


struct Node {
    int value;
    struct Node *next;
};


void node_remove_duplicate(struct Node *head) {
    struct Node *node = head;
    while (node) {
        struct Node *prev = node;
        struct Node *cmp = node->next;
        while (cmp) {
            if (cmp->value == node->value) {
                prev->next = cmp->next;
                free(cmp);
                cmp = prev;
            }
            if (cmp != prev) {
                prev = prev->next;
            }
            cmp = cmp->next;
        }
        node = node->next;
    }
}

int main(int argc, const char * argv[]) {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *node = head;
    srand((unsigned int) time(NULL));
    
    for (int i = 0; i < LEN; i++) {
        node->value = rand() % RANGE;
        if (i == LEN - 1) {
            node->next = NULL; break;
        }
        node->next = malloc(sizeof(struct Node));
        node = node->next;
    }
    
    printf("Before: ");
    node = head;
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
    
    node_remove_duplicate(head);
    printf("After: ");
    node = head;
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
    return 0;
}

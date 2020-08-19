//
//  main.c
//  ex2
//
//  Created by Hao Zhou on 19/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

// Question: Detect palindrome using linear stack, and return 1 if it is, 0 if it isn't.

#define MAXLEN 1024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


struct Node *new_stack_from_str(char *str, int len) {
    struct Node *node = NULL;
    struct Node *head = NULL;
    
    for (int i = 0; i < len; i++) {
        if (!node) {
            node = malloc(sizeof(struct Node));
            node->checked = 0;
            node->prev = NULL;
            head = node;
        } else {
            node->next = malloc(sizeof(struct Node));
            node->checked = 0;
            node->next->prev = node;
            node = node->next;
        }
        node->value = str[i];
        node->next = NULL;
    }
    return head;
}

void free_stack(struct Node *node) {
    while (node) {
        struct Node *next = node->next;
        free(node);
        node = next;
    }
}

int is_palindrome(char *str, int len) {
    struct Node *head = new_stack_from_str(str, len);
    struct Node *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (head && tail && head != tail && !head->checked && !tail->checked) {
        if (head->value != tail->value) {
            return 0;
        }
        head->checked = 1;
        tail->checked = 1;
        head = head->next;
        tail = tail->prev;
    }
    free_stack(head);
    return 1;
}

int main(int argc, const char * argv[]) {
    size_t line_cap = MAXLEN;
    char *input = NULL;
    printf("Input sentence: ");
    getline(&input, &line_cap, stdin);
    
    int res = is_palindrome(input, (int) strlen(input) - 1);
    if (input) { free(input); }
    return res;
}

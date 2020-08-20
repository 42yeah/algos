//
//  main.c
//  ex4
//
//  Created by Hao Zhou on 20/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "question.h"

void enQueue(LiQueue *q, ElemType e) {
    QNode *node = malloc(sizeof(QNode));
    node->data = e;
    node->next = NULL;
    if (!q->front) {
        q->front = q->rear = node;
    }
    q->rear->next = node;
    q->rear = q->rear->next;
}

int deQueue(LiQueue *q, ElemType *e) {
    if (!q->front) {
        return 0;
    }
    
    ElemType value = q->front->data;
    QNode *next = q->front->next;
    *e = value;
    if (q->front == q->rear) {
        free(q->rear);
        q->front = NULL;
        q->rear = NULL;
    } else {
        free(q->front);
    }
    
    q->front = next;
    return 1;
}

int main(int argc, const char * argv[]) {
    LiQueue queue;
    enQueue(&queue, 3);
    enQueue(&queue, 56);
    enQueue(&queue, 123);
    
    ElemType val;
    deQueue(&queue, &val);
    printf("%d\n", val);
    return 0;
}

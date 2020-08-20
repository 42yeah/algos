//
//  question.h
//  algos
//
//  Created by Hao Zhou on 20/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

#ifndef question_h
#define question_h

// Question: implement the functions.
// The original question seems to be syntactically wrong; I am fixing it.
// It's not like I don't want to keep my code consistent. This is the original code presented in the challenge, and I am not going to change a lot of it.

typedef int ElemType;

typedef struct qnode {
    ElemType data;
    struct qnode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LiQueue;

// Implement those

void enQueue(LiQueue *q, ElemType e);

int deQueue(LiQueue *q, ElemType *e);

#endif /* question_h */

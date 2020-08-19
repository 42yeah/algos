//
//  stack.h
//  algos
//
//  Created by Hao Zhou on 19/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

#ifndef stack_h
#define stack_h


struct Node {
    char value;
    struct Node *next;
    struct Node *prev;
    int checked;
};

#endif /* stack_h */

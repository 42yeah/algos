//
//  binary.h
//  algos
//
//  Created by Hao Zhou on 20/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

#ifndef binary_h
#define binary_h

typedef int ElemType;

struct BinTreeNode {
    ElemType data;
    struct BinTreeNode *leftChild, *rightChild;
};

void sort_bin_tree(struct BinTreeNode *root);

#endif /* binary_h */

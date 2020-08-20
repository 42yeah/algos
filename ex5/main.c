//
//  main.c
//  ex5
//
//  Created by Hao Zhou on 20/08/2020.
//  Copyright © 2020 42yeah. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

// Question: implement an algorithm that sorts the binary tree. When the left child is greater than right child, swap'em.

void sort_bin_tree(struct BinTreeNode *root) {
    if (root->leftChild && root->rightChild && root->leftChild->data > root->rightChild->data) {
        struct BinTreeNode *temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;
    }
    if (root->leftChild) {
        sort_bin_tree(root->leftChild);
    }
    if (root->rightChild) {
        sort_bin_tree(root->leftChild);
    }
}

struct BinTreeNode *gen_node(ElemType val) {
    struct BinTreeNode *node = malloc(sizeof(struct BinTreeNode));
    node->data = val;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

int main(int argc, const char * argv[]) {
    struct BinTreeNode *root = gen_node(1);
    root->rightChild = gen_node(2);
    root->leftChild = gen_node(3);
    sort_bin_tree(root);
    return 0;
}

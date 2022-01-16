/*
 * Created by gt on 12/13/21 - 10:48 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree_node {
    int data;
    struct tree_node *left_ptr;
    struct tree_node *right_ptr;
};

typedef struct tree_node TreeNode;
typedef TreeNode *TreeNodePtr;

void insert_node(TreeNodePtr *tree_ptr, int value) {
    if (!(*tree_ptr)) {
        *tree_ptr = malloc(sizeof **tree_ptr);
        if (*tree_ptr) {
            (*tree_ptr)->data = value;
            (*tree_ptr)->left_ptr = NULL;
            (*tree_ptr)->right_ptr = NULL;
        } else {
            fprintf(stderr, "%i is not inserted. Memory is not available.\n", value);
        }
    } else {
        if (value < (*tree_ptr)->data) {
            insert_node(&((*tree_ptr)->left_ptr), value);
        } else if (value > (*tree_ptr)->data) {
            insert_node(&((*tree_ptr)->right_ptr), value);
        } else {
            printf("dup");
        }
    }
}

void in_order(TreeNodePtr tree_ptr) {
    if (tree_ptr) {
        in_order(tree_ptr->left_ptr);
        printf("%3i", tree_ptr->data);
        in_order(tree_ptr->right_ptr);
    }
}

void pre_order(TreeNodePtr tree_ptr) {
    if (tree_ptr) {
        printf("%3i", tree_ptr->data);
        pre_order(tree_ptr->left_ptr);
        pre_order(tree_ptr->right_ptr);
    }
}

void post_order(TreeNodePtr tree_ptr) {
    if (tree_ptr) {
        post_order(tree_ptr->left_ptr);
        post_order(tree_ptr->right_ptr);
        printf("%3i", tree_ptr->data);
    }
}

int main() {
    TreeNodePtr root_ptr = NULL;
    srandom(time(NULL));
    puts("The numbers being placed in the tree are:");
    for (int i = 0; i <= 10; ++i) {
        long item = random() % 15;
        printf("%3li", item);
        insert_node(&root_ptr, (int) item);
    }
    puts("\n\npre-order traversal:");
    pre_order(root_ptr);
    puts("\n\nin-order traversal:");
    in_order(root_ptr);
    puts("\n\npost-order traversal:");
    post_order(root_ptr);
    return 0;
}
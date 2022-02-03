/*
 * Created by gt on 2/3/22 - 3:14 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * [7, 5, 1, 8, 3, 6, 0, 9, 4, 2] dizisinin Binary-Search-Tree aşamalarını yazınız.
 *
 * Örnek: root x'dir. root'un sağından y bulunur. Solunda z bulunur vb.
 *
 *
 *                 _______________7______________
 *                /                              \
 *         _______5______                         8______
 *        /              \                               \
 *     ___1__             6                               9
 *    /      \
 *    0      _3
 *          /  \
 *          2   4
 *
 */

#include <iostream>
#include <malloc.h>
#include <deque>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

struct tree_node {
    int data;
    struct tree_node *left_ptr;
    struct tree_node *right_ptr;
};

typedef struct tree_node TreeNode;
typedef TreeNode *TreeNodePtr;

void insert_node(TreeNodePtr *tree_ptr, int value) {
    if (!(*tree_ptr)) {
        *tree_ptr = static_cast<TreeNodePtr>(malloc(sizeof **tree_ptr));
        if (*tree_ptr) {
            (*tree_ptr)->data = value;
            (*tree_ptr)->left_ptr = nullptr;
            (*tree_ptr)->right_ptr = nullptr;
            // echo root
        } else {
            cerr << value << " i is not inserted. Memory is not available." << endl;
        }
    } else {
        if (value < (*tree_ptr)->data) {
            insert_node(&((*tree_ptr)->left_ptr), value);
        } else if (value > (*tree_ptr)->data) {
            insert_node(&((*tree_ptr)->right_ptr), value);
        } else {
            cerr << "Entries must be unique." << endl;
        }
    }
}

void create_tree(TreeNodePtr *root, int A[], int size) {
    for (int i = 0; i < size; ++i) {
        insert_node(root, A[i]);
    }
}

int maxHeight(TreeNodePtr p) {
    if (!p) return 0;
    int leftHeight = maxHeight(p->left_ptr);
    int rightHeight = maxHeight(p->right_ptr);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

string intToString(int val) {
    ostringstream ss;
    ss << val;
    return ss.str();
}

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel,
                   const deque<TreeNodePtr> &nodesQueue) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        cout << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << "" << ((*iter++) ? "/" : " ");
        cout << setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
    }
    cout << endl;
}

void
printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNodePtr> &nodesQueue) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        cout << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << ""
             << ((*iter && (*iter)->left_ptr) ? setfill('_') : setfill(' '));
        cout << setw(branchLen + 2) << ((*iter) ? intToString((*iter)->data) : "");
        cout << ((*iter && (*iter)->right_ptr) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    cout << endl;
}

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNodePtr> &nodesQueue) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        cout << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2)) << ((*iter) ? intToString((*iter)->data) : "");
    }
    cout << endl;
}

void printPretty(TreeNodePtr root, int level, int indentSpace) {
    int h = maxHeight(root);
    int nodesInThisLevel = 1;

    int branchLen = 2 * ((int) pow(2.0, h) - 1) - (3 - level) * (int) pow(2.0, h - 1);
    int nodeSpaceLen = 2 + (level + 1) * (int) pow(2.0, h);
    int startLen = branchLen + (3 - level) + indentSpace;

    deque<TreeNodePtr> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
        branchLen = branchLen / 2 - 1;
        nodeSpaceLen = nodeSpaceLen / 2 + 1;
        startLen = branchLen + (3 - level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);

        for (int i = 0; i < nodesInThisLevel; i++) {
            tree_node *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left_ptr);
                nodesQueue.push_back(currNode->right_ptr);
            } else {
                nodesQueue.push_back(nullptr);
                nodesQueue.push_back(nullptr);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue);
}

int main() {
    int A[] = {7, 5, 1, 8, 3, 6, 0, 9, 4, 2};
    int size = sizeof A / sizeof A[0];
    TreeNodePtr root_ptr = nullptr;
    create_tree(&root_ptr, A, size);
    printPretty(root_ptr, 1, 0);
    return 0;
}

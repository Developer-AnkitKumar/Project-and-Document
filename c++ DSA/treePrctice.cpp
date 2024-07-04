#include<iostream>
using namespace std;

struct node
{
    long long value;
    node *left;
    node *right;
};

bool isLeaf(node* root) {
    return (root != nullptr) && (root->left == nullptr) && (root->right == nullptr);
}

bool checkSumTree(node* n)
{
    if (n == nullptr || isLeaf(n)) {
        return true;
    }

    long long leftSum = checkSumTree(n->left) ? n->left->value : 0;
    long long rightSum = checkSumTree(n->right) ? n->right->value : 0;

    return (n->value == leftSum + rightSum) && checkSumTree(n->left) && checkSumTree(n->right);
}

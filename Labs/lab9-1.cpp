#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int val) {  // val is data value
    struct node* temp = (struct node*)malloc(sizeof(struct node));  // malloc is allocated memory
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }
}
struct node* insertNode(struct node* node, int val) {
    if (node == NULL) return createNode(val);
    if (val < node->data)
        node->left = insertNode(node->left, val);
    else if (val > node->data)
        node->right = insertNode(node->right, val);
    return node;
}
int main() {
    vector<int> v;
    int n, k;
    while (cin >> n) {
        v.push_back(n);
    }

    struct node* root = NULL;

    root = insertNode(root, v[0]);
    for (int i = 1; i < v.size(); i++) {
        insertNode(root, v[i]);
    }

    postorder(root);
    return 0;
}
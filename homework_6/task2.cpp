#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    int leftChildren = 0;
    int rightChildren = 0;
    Node* left;
    Node* right;
}nodes[10000000];

int countChildren(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftChildren = countChildren(node->left);
    int rightChildren = countChildren(node->right);

    node->leftChildren = leftChildren;
    node->rightChildren = rightChildren;

    return 1 + leftChildren + rightChildren;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long  n, left, right;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        nodes[i].value = i;
        if (left != -1) {
            nodes[i].left = &nodes[left];
        }
        else {
            nodes[i].left = nullptr;
        }
        if (right != -1) {
            nodes[i].right = &nodes[right];
        }
        else {
            nodes[i].right = nullptr;
        }
    }

    countChildren(&nodes[0]);
    long long maxRes = -10000000;

    for (int i = 0; i < n; i++) {
        long long  m = 1;
        if (nodes[i].leftChildren != 0) {
            m *= nodes[i].leftChildren;
        }
        if (nodes[i].rightChildren != 0) {
            m *= nodes[i].rightChildren;
        }

        long long diff = n - nodes[i].leftChildren - nodes[i].rightChildren - 1;

        if (diff <= 0) {
            maxRes = max(maxRes, m);
        }
        m *= diff;
        maxRes = max(maxRes, m);
    }

    cout << maxRes;
    return 0;
}
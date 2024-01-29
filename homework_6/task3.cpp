#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
}nodes[10000000];

int maxPath(Node* node, int& res) {
    if (node == nullptr) {
        return 0;
    }
    int maxLeft = max(0, maxPath(node->left, res));
    int maxRight = max(0, maxPath(node->right, res));
    res = max(res, maxLeft + maxRight + node->value);
    return node->value + max(maxLeft, maxRight);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  n, value, left, right;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value >> left >> right;
        nodes[i].value = value;
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
    int res = -100000;
    maxPath(&nodes[0], res);
    cout << res;
    return 0;
}

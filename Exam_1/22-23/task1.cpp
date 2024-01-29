#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left, * right;
    int value;
    Node(int value) :value(value) {
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (node->value < value) {
        node->right = insert(node->right, value);
    }
    else if (node->value > value) {
        node->left = insert(node->left, value);
    }
    return node;
}
void print(Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node->left && node->right) {
        cout << node->value << ' ';
    }
    print(node->left);
    print(node->right);
}

void solve(vector<long long>& arr, Node* node, long long x) {
    if (node == nullptr) {
        return;
    }
    solve(arr, node->left, x - 1);
    solve(arr, node->right, x + 1);
    arr[x + 100000] += node->value;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        Node* root = nullptr;
        vector<long long> arr(1000000, 0);
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            root = insert(root, num);
        }
        solve(arr, root, root->value);
        for (int j = 0; j < 1000000; j++) {
            if (arr[j] != 0) {
                cout << arr[j] << ' ';
            }
        }
        cout << "\n";
    }
    return 0;
}
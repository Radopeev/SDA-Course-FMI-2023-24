#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long value;
    Node* left;
    Node* right;
}nodes[1000000];

void solve(vector<long long>& arr, Node* node, long long x) {
    if (node == nullptr) {
        return;
    }
    solve(arr, node->left, x - 1);
    solve(arr, node->right, x + 1);
    arr[x + 100000] += node->value;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  n, value, left, right;
    vector<long long> arr(1000000, 0);
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
    solve(arr, &nodes[0], 0);
    for (int i = 0; i < 1000000; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << ' ';
        }
    }
    return 0;
}
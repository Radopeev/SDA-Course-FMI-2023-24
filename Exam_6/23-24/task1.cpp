#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int find(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v], parent);
}

void connect(int u, int v, vector<int>& parent) {
    parent[u] = parent[v];
}

int main() {
    int n;
    cin >> n;
    int x, y;
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    unordered_map<int, vector<int>> graph;
    int component = n;
    while (cin >> x >> y) {
        int u = find(x, parent);
        int v = find(y, parent);
        if (u != v) {
            cout << --component << "\n";
            connect(u, v, parent);
        }
        else {

            cout << component << " CYCLE FORMED!\n";
        }
    }
    return 0;
}






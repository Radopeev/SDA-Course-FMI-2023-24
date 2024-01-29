#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int bfs(vector<vector<int>>& graph, int start, int target,unordered_set<int>& set) {
    queue<pair<int, int>> q;
    q.push({ start,0 });
    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (node == target) {
            return dist;
        }
        for (auto& el : graph[node]) {
            if (set.find(el) == set.end()) {
                q.push({ el,dist + 1 });
            }
        }
    }
    return -1;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(1000000);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    int p;
    cin >> p;
    unordered_set<int> set;
    vector<int> path(p);
    for (int i = 0; i < p; i++) {
        cin >> path[i];
        set.insert(path[i]);
    }
    queue<int> q;
    int totalDist = 0;
    for (int i = 0; i < p - 1; i++) {
        int from = path[i];
        int to = path[i + 1];
        set.erase(from);
        set.erase(to);
        int tempDist = bfs(graph, from, to,set);
        if (tempDist == -1) {
            cout << -1;
            return 0;
        }
        else {
            totalDist += tempDist;
        }
    }
    cout << totalDist;
    return 0;
}

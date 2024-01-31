#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void min_path_and_ways(int n, vector<vector<pii>>& graph) {
    vector<ll> distance(n + 1, LLONG_MAX);
    vector<ll> ways(n + 1, 0);

    distance[1] = 0;
    ways[1] = 1;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        ll  node = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();

        if (dist > distance[node]) continue;

        for (auto& neighbor : graph[node]) {
            ll v = neighbor.first;
            ll w = neighbor.second;

            if (distance[v] > dist + w) {
                distance[v] = dist + w;
                ways[v] = ways[node];
                pq.push({ distance[v], v });
            }
            else if (distance[v] == dist + w) {
                ways[v] = (ways[v] + ways[node]) % MOD;
            }
        }
    }
    if (distance[n] != LLONG_MAX) {
        cout << distance[n] << " " << ways[n] % MOD << endl;
    }
    else {
        cout << -1 << " " << 0;
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({ v, c });
    }

    min_path_and_ways(n, graph);

    return 0;
}





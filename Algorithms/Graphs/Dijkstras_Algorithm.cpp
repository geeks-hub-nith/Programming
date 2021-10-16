/*
    Author: master._.mind
    Link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<int> dijkstra(int source, vector<vector<pair<int, int>>> adj) {
    int n = adj.size();
    vector<int> dist(n + 1);
    for (int i = 1; i <= n; ++i) dist[i] = INF;  // initialise all distances to infinity
    dist[source] = 0;                            // initialize source distance to 0
    set<pair<int, int>> s;                       //{dist from source, node}
    s.insert({0, source});
    while (!s.empty()) {
        int dis = s.begin()->first;
        int vertex = s.begin()->second;
        s.erase(s.begin());
        for (pair<int, int> x : adj[vertex]) {
            int newDis = dis + x.second;
            int newVer = x.first;
            if (newDis < dist[newVer]) {
                s.erase({dist[newVer], newVer});
                dist[newVer] = newDis;  // update the distance to smaller one
                s.insert({dist[newVer], newVer});
            }
        }
    }
}

int main() {
    int n, m;  // vertices, edges
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);  // adjacency list
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;  // w - weight
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    // Run dijkstras algorithm with source as node number 1
    vector<int> d = dijkstra(1, adj);

    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
    return 0;
}
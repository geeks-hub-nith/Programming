// Author: prashant_th18
// Link: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> v;
vector<bool> vis;
void dfs(int node) { // Prints nodes of the graph in dfs order
	vis[node] = true;
	cout << node << ' ';
	for(const auto& val : v[node]) {
		if(!vis[val]) {
			dfs(val);
		}
	}
}
int main() {
	int nodes, edges; cin >> nodes >> edges;
	v.assign(nodes + 1, vector<int>());
	vis.assign(nodes + 1, false);
	for(int i = 0; i < edges; ++i) {
		int a, b; cin >> a >> b; // An edge exists between a and b
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1); // Starting from node "1"
	return 0;
}

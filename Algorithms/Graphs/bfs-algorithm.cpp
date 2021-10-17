#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; //n corresponds to number of vertices and m corresponds to number of edges
    cin >> n >> m;
    vector<int> adj[n + 1]; //a adjacency list to store which node is connected to which node
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int source;

    /*To detect the source here i have traversed to a point where the size of the adjacency list there will not be 0*/

    for (int i = 0; i < n + 1; i++)
    {
        if (adj[i].size() != 0)
        {
            source = i;
            break;
        }
    }
    // a marked array is created to get to know which nodes are visited ,else we'll get stuck in a infinite loop
    bool marked[n] = {false};

    /* queue is used for bfs traversal as we have to traverse more horizotally so we have to look for max number of nodes which are closest to source*/
    queue<int> q;
    q.push(source);
    marked[source] = true;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        cout << k << " ";
        for (int i = 0; i < adj[k].size(); i++)
        {
            if (marked[adj[k][i]] == false)
            {
                q.push(adj[k][i]);
                marked[adj[k][i]] = true;
            }
        }
    }
}

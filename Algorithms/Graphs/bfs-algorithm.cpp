//Priyanshu Agarwal
// problem - to traverse the graph using BFS - here in question the starting point is mentioned to be 0 but for general purpose you can start from where the graph is starting
 /*
    Edit by - Sahil Verma (sahil19-19)

    Links
         BFS - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
             - https://youtu.be/M8jdDR5kV3k
         multi souce BFS - https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/
         0-1 BFS - https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/

    Multi source BFS
        In this type of BFS there are multiple sources hence it is called multi source BFS
        This algo gives the shortest path to a node from all te starting nodes.

    0-1 BFS
        BFS can only be applied if the graph is non weighted OR if the weights of all the edges are the same,
        but there is a special condition when BFS can be applied to a weighted graph of different weights. 
        This is when we are given that the weight of any given edges is either 0 or 1.
*/ 
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; //n corresponds to number of vertices and m corresponds to number of edges
    cin >> n >> m;
    vector<int> adj[n + 1]; // an adjacency list to store which node is connected to which node
    // for 0-1 BFS we also need to store the weight of the edge between the 2 nodes so, we use vector<int,pair<int,int>> adj[n+1];
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

    queue<int> q; // for 0-1 BFS we use a dequeue

    /*
        For multisource BFS we push all the souce nodes into the queue at this point.By doing so we ensure that any node is reached from the
        source node that is at the shortest distance from that node before any other source node is marked 'visited' / 'true'. 
    */

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
                /*
                    For 0-1 BFS we check the weight of the edge
                    if weight == 0 we push node to the front of the dequeue - makes the level of both the nodes equal
                    if weight == 1 we push node to the end of the dequeue

                    this justifies the use of a dequeue in 0-1 BFS as we push elements on both the head and the tail
                */
                marked[adj[k][i]] = true;
            }
        }
    }
}

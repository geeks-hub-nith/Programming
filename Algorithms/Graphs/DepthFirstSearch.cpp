
#include<iostream>
#include<vector>
using namespace std;



void dfs_with_adjacency_list(vector<int> graph[] , int n , bool visited[] , int sv){
    visited[sv] = true;
    cout<<sv<<" ";
    for(int j=0 ; j<graph[sv].size() ; j++){
        int adj_node = graph[sv][j];
        if(!visited[adj_node]){
            dfs_with_adjacency_list(graph , n , visited , adj_node);
        }
    } 
}





int main(){
    // n = num of nodes
    // m = num of edges
    
    // adjacency list
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    
    for(int i=0 ; i<m ; i++){
        int src , dst;
        cin>>src>>dst;
        graph[src-1].push_back(dst-1);
        graph[dst-1].push_back(src-1);
    }

    bool* visited = new bool[n]{0};

    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            dfs_with_adjacency_list(graph , n , visited , i);
            cout<<endl;
        }
    }




}


// 9 9
// 1 4
// 1 2
// 1 3
// 1 6
// 2 4
// 2 5
// 3 5
// 4 6
// 7 8




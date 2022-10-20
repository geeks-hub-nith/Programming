#include <bits/stdc++.h>
using namespace std;
const int maxN=1e5+8;
vector<int> adj[maxN];
bool visited[maxN];int teams[maxN];
int main(){
memset(teams,-1,sizeof teams);
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  int n,m;scanf("%d %d",&n,&m);
  while(m--){
    int a,b;scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  queue<int> q;
  for(int i=1;i<=n;i++){    
    if(teams[i]==-1){
      teams[i]=1;
      q.push(i);
    }
    while(!q.empty()){
      int node=q.front();q.pop();
      if(teams[node]==-1){
        teams[node]=1;
      }
    for(auto j:adj[node]){
      
      if(teams[node]==teams[j]) 
      {
        //cout<<i<<"  "<<j<<endl;
        printf("IMPOSSIBLE\n");return 0;}
      else
      {auto color=teams[node]==1?2:1;
        if(teams[j]==-1) {teams[j]=color;
        q.push(j);}
      }
     
          }
  }
  }
   for(int i=1;i<=n;i++){
      printf("%d ",teams[i]);
  }
  return 0;
}

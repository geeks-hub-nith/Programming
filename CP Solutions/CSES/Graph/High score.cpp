#include <bits/stdc++.h>
using namespace std;
#define int long long

//#define LOCAL true
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
const int maxN=2507,NINF=-1e18;
int N,M;
vector<vector<int>> adj[maxN];
vector<int> dist,G[maxN],G2[maxN];
bool check=false,MARK[maxN],VIS[maxN],VIS2[maxN];
bool bellmanF(){
 
  for(int i=0;i<N;i++){
if(i==N-1) check=true;
    for(int j=1;j<=N;j++){
      for(auto k:adj[j]){
 
        int a=j,b=k[0],c=k[1];
        
        if(check){
          if(dist[b]<dist[a]+c) {MARK[b]=true; }  }
        dist[b]=max(dist[b],dist[a]+c) ;
        
      }
    }
  }
  
  return true;
}
void rev(){
  for(int i=1;i<=N;i++){
    reverse(adj[i].begin(),adj[i].end());
  }
}
bool found1=false,one_found=true;
bool dfs(int start){
  //cout<<start<<" ";
  VIS[start]=true;
  for(auto i:G[start]) {
    if(i==1) one_found=true;
    if(one_found and found1) return true; 
    if(MARK[i]) found1=true;
    if(!VIS[i]) if(dfs(i)) return true;
  }
  found1=false;
  return false;
}

bool foundN=false,N_found=false;
bool dfs2(int start){
  //cout<<start<<" ";
  VIS2[start]=true;
  for(auto i:G2[start]) {
    if(i==N) N_found=true;
    if(N_found and foundN) return true; 
    if(MARK[i]) foundN=true;
    if(!VIS2[i]) if(dfs2(i)) return true;
  }
  found1=false;
  return false;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifdef LOCAL
  clock_t tStart = clock();
freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
   #endif
 
   cin>>N>>M;
   dist.assign(maxN,NINF);
   dist[1]=0;
   for(int i=0;i<M;i++){
    int a,b,c;see(a,b,c);
    adj[a].push_back({b,c});
    G[b].push_back(a);
    G2[a].push_back(b);
   }
bellmanF();
   rev();
auto ans=dfs(N);
 auto ans2=dfs2(1);
 for(int i=1;i<=N;i++){
  if(VIS[i] and VIS2[i] and MARK[i]) {cout<<"-1\n"; return 0;}
 }
  cout<<dist[N];
 #ifdef LOCAL
 
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}

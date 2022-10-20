#include <iostream>
using std::cin;
using namespace std;
char c;
int m,n;
int v[]={0,0,1,-1},h[]={1,-1,0,0};
 
bool vis[1000][1000];
 
void dfs(int x,int y){
  vis[x][y]=true;
  for(int i=0;i<4;i++){
    int dx=x+v[i],dy=y+h[i];
    if(dx<m && dx>=0 && dy<n && dy>=0 && !vis[dx][dy]){
      dfs(dx,dy);
    }
  }
}
 
int solve(){
cin>>m>>n;
int cnt=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>c;
      vis[i][j]=(c=='#');
    }
  }
 for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
if(!vis[i][j]){
  dfs(i,j);
  cnt++;
}
    }
    }
    return cnt;
}
int main(){
cout<<solve();
}

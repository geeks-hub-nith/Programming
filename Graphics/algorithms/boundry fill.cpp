#include <bits/stdc++.h>
using namespace std;
const int maxN=1e3;
int graph[maxN][maxN];
int boundry,color;

vector<int> v={1,-1,0,0},h={0,0,-1,1};
bool check(int x,int y){
if(x>=0 and x<maxN) if(y>=0 and y<maxN) return true;
return false;
}
void fill_boundry(){
  vector<int> a={0,10,100};
  for(auto i:a){
for(int j=0;j<100;j++){
  graph[j][i]=graph[i][j]=boundry;
 
}
  }
}
void floodfill(int x,int y){
  if(!check(x,y))return ;
  if( graph[x][y]!=boundry and graph[x][y]!=color){
graph[x][y]=color;
 for(int k=0;k<v.size();k++){
    floodfill(x+v[k],y+h[k]);
  }

  }
}
void display(){
  for(int i=0;i<maxN;i++){
    for(int j=0;j<maxN;j++){
      cout<<graph[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){

 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

  memset(graph,0,sizeof graph);
 
  boundry=3;color=1;
   fill_boundry();
  //display();
  floodfill(1,11);
  display();

return 0;
}

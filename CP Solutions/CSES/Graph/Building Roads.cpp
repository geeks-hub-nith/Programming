// name: lekhit borole email: blekhit@gmail.com

#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e5+7;
 int id[MaxN],N,M,sz[MaxN];

 void QuickUnion(int N)
 {

 for (int i = 0; i < N; i++) id[i] = i;
 }
int root(int i)
 {
 while (i != id[i]) {id[i] = id[id[i]];i=id[i];}
 return i;
 }
 bool find(int p, int q)
 {
 return root(p) == root(q);
 }
 void unite(int p, int q)
 {
 int i = root(p), j = root(q);
  if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
 else { id[j] = i; sz[i] += sz[j]; } 

 }

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test_input_1.txt", "r", stdin);
    // freopen("test_output_1.txt", "w", stdout);
cin>>N>>M;
for(int i=0;i<N;i++){
  id[i]=i;
}
for(int i=0;i<M;i++){
  int a,b;cin>>a>>b;
  unite(a-1,b-1);
}
unordered_set<int> uns;
int p;
for(int i=0;i<N;i++){
  p= root(i);
  if(!uns.count(p)){
    uns.insert(p);
  }
}
if(uns.size()>1)
{
  cout<<(uns.size()-1)<<endl;
  for(auto i:uns){
    if(i!=p ) cout<<(p+1)<<" "<<(i+1)<<endl;
  }
}
else{
  cout<<0<<endl;
}
}

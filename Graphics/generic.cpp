#include <bits/stdc++.h>
using namespace std;
double PI;
#define LOCAL
vector<vector<double>> matrix_multipication(vector<vector<double>> a,vector<vector<double>> b){
int ar=a.size(),ac=a[0].size(),br=b.size(),bc=b[0].size();
if(ac!=br) return a;
vector<vector<double>> ans(ar,vector<double>(bc,0));
for(int i=0;i<ar;i++){
  for(int j=0;j<bc;j++){
int c=0;
for(int i1=0,j1=0;i1<ac;j1++,i1++){
  c+=a[i][i1]*b[j1][j];
}
ans[i][j]=c;
  }
}
return ans;
}
vector<vector<double>> chain_multipication(vector<vector<vector<double>>> a){
  auto i=a[0];
  for(auto j:a){
    if(j!=i){
      i=matrix_multipication(i,j);
    }
  }
  return i;
}

void print(vector<vector<double>>  i){
  for(auto j:i){
  for(auto k:j){
    cout<<k<<"  ";
  }
  cout<<endl;
}
}
vector<vector<double>> rotate(vector<vector<double>>  points,double angle){
  vector<vector<double>> a={{},{},{}};
for(auto i:points){
a[0].push_back(i[0]);
a[1].push_back(i[1]);
a[2].push_back(1);
}
  auto i=matrix_multipication({{cos(angle),sin(angle),0},{sin(angle),-cos(angle),0},{0,0,1}},a);
//print(i);
return i;
}


vector<double>  rotate_about(double x,double y,double ax,double ay,double angle){
auto i=rotate({{x-ax*1.0,y*1.0-ay}},angle);
for(auto &j:i[0]) j+=ax;
for(auto &j:i[1])j+=ay;

return i[0];
}
vector<vector<double>> rotate_matrix_about(vector<vector<double>>  points,vector<double> about,double angle){
double ax=about[0],ay=about[1];
vector<vector<double>> ans;

for(auto point:points){
  ans.push_back(rotate_about(point[0],point[1],ax,ay,angle));
}
return ans;
}
vector<vector<double>> scaling_matrix_maker(double sx,double sy){
 return {{sx,0,0},{0,sy,0},{0,0,1}};
}
vector<vector<double>>  scaling(vector<vector<double>>  points,double sx,double sy){
vector<vector<double>> a={{},{},{}};
for(auto i:points){
a[0].push_back(i[0]);
a[1].push_back(i[1]);
a[2].push_back(1);
}

auto ans=matrix_multipication(scaling_matrix_maker(sx,sy),a);
return ans;
}
vector<vector<double>> traslation(vector<vector<double>>  points,double tx,double ty){
  vector<vector<double>> a={{},{},{}},tr_matrix={{1,0,tx},{0,1,ty},{0,0,1}};
for(auto i:points){
a[0].push_back(i[0]);
a[1].push_back(i[1]);
a[2].push_back(1);
}
return matrix_multipication(tr_matrix,a);
}
vector<vector<double>> points_to_matrix(vector<vector<double>> points){
  vector<vector<double>> a={{},{},{}};
for(auto i:points){
a[0].push_back(i[0]);
a[1].push_back(i[1]);
a[2].push_back(1);
}
return a;
}

vector<vector<double>> to_points(vector<vector<double>> a){
vector<vector<double>> ans(a[0].size());
  for(int i=0;i<a[0].size();i++){
    ans[i].push_back(a[0][i]);
    ans[i].push_back(a[1][i]);
  }
  return ans;
}
//auto i=reflection({{10,22},{1,33},{11,22}},{{1,0,0},{0,-1,0},{0,0,1}});
vector<vector<double>> reflection(vector<vector<double>> points,vector<vector<double>> directions){
return matrix_multipication(directions,  points_to_matrix(points));
}

vector<vector<double>> sheer(vector<vector<double>> points,vector<vector<double>> sheer){
return matrix_multipication(sheer,  points_to_matrix(points));
}
vector<vector<double>> sheer_x_y(vector<vector<double>> points,double sx=0,double sy=0,double xref=0,double yref=0){
vector<vector<double>> a={{1,sx,-1*sx*xref},{sy,1,-1*sy*yref},{0,0,1}};
return sheer(a,points);
}
vector<vector<double>> get_points(){
  //cout<<"enter number of points in input\n";
 int n; cin>>n;
 //cout<<"enter points\n";
vector<vector<double>> v;
 string p;cin>>p;
    
for(int i=1;i<=n;i++){
   // cout<<i<<" th point x y : ";
    double a,b;
    cin>>a>>b;
if(p!="Y") 
    cout<<a<<" "<<b<<"\n";
v.push_back({a,b});
  }
  if(p!="Y") exit(0);
   //cout<<"do you wish to process output?Y\n";
   
  return v;
}

int main(){
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifdef LOCAL
freopen("python/input.txt", "r", stdin);
  
   #endif
   freopen("python/output.txt", "w", stdout);
PI=acos(0.0);
vector<vector<double>> points=get_points();
// {{10,22},{1,33},{11,22}}
auto i=scaling(points,2,3);
i=to_points(i);
print(i);
}
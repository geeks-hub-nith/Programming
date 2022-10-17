#include <bits/stdc++.h>
using namespace std;
double xmin=10,ymin=10,xmax=100,ymax=100,u1=0.0,u2=1.0;
bool clip_test(double p,double q){//,double &u1,double &u2){
  if(p==0) return q<0?false:true; // line is out of window
  double r=q/p;
  if(p<0.0){// line outside->inside
    if(r>u2) return false;
    if(r>u1) u1=r;
  }
  if(p>0.0)//overkill
  {
    if(r<u1) return false;
    if(r<u2) u2=r;
  }
  return true;
}
vector<vector<double>> clip(vector<vector<double>> p={{1,2},{2,11}}){
  double x1=p[0][0],y1=p[0][1];
double dx=p[1][0]-x1,dy=p[1][1]-y1;//x2-x1 y2-y1
if(clip_test(-dx,x1-xmin))
  if(clip_test(dx,xmax))
    if(clip_test(-dy,y1-ymin))
      if(clip_test(dy,ymax-y1)){
        return {{x1+u1*dx, y1+u1*dy},{x1+u2*dx, y1+u2*dy}};
      }
  return p;

}
void print(vector<vector<double>>  i){
  for(auto j:i){
  for(auto k:j){
    cout<<k<<"  ";
  }
  cout<<endl;
}
}

int main(){
  double u1=1,u2=2;
auto i=clip({{1,11},{99,121}});
print(i);
}
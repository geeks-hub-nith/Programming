#include<bits/stdc++.h>
using namespace std;
#define F first
bool mycomp(float a,float b){
  return abs(a)<abs(b);
}
void dda(vector<int> p1,vector<int> p2){
  vector<float> d;

  for(int i=0;i<=1;i++){
    d.push_back(p1[i]-p2[i]);
  }
  int steps=*max_element(d.begin(),d.end());
  for(auto &i:d){
    i/=steps;
  }
float x=p1[0],y=p1[1];
vector<pair<float,float>> co={{p1[0],p1[1]}};
while (steps--){
  auto i=co.back(); 
  
  co.push_back({floor(x),floor(y)});
}
}



int main(){
pair<int,int> a={1,2};
cout<<a.F;

}
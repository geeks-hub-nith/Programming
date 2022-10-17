#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int cc=0;
class process{public:
    vector<int> allocated;
    vector<int> max_need;
    vector<int> demand;
    int id;
    process( vector<int> a,
    vector<int> m,
    vector<int> d){
        allocated=a;
        max_need=m;
        demand=d;
        id=cc++;
    }
    
};
class Deadlock{
    public:
      vector<int> current;
      vector<int> total;
      vector<process> prs;
      Deadlock(
      vector<int> tota){
          total=tota;
      }
      void insert_process(process p){

          prs.push_back(p);
      }
      bool safty(process p){
          auto a=p.demand,mn=p.max_need;
          for(int i=0;i<a.size();i++){
              if(a[i]>mn[i]) {  return false; }
          }
          cout<<"\nProcess "<<p.id<<" : safty check passed\n";
          return true;
      }
      bool resource_allocation(process p){
          auto a=p.demand;
          for(int i=0;i<a.size();i++){
              if(a[i]>current[i]) return false;
          }
          return true;
      }
      void set_current(){
          vector<int> s;

          for(auto I:total) s.push_back(0);
          //cout<<"total size"<<total.size();
          for (auto p:prs){
              //cout<<p.id<<"set current";
              auto a=p.allocated;
              for (int i=0;i<total.size();i++) s[i]+=a[i];
          }
          //return ;
          for(int i=0;i<total.size();i++) 
          if(s[i]>total[i]) {cout<<"error total resources are less than allocated";// exit(0);
              
          }
          else{
              //cout<<"\nss: "<<s[i]<<"\n";
          s[i]=total[i]-s[i];}
          current=s;
          
          
      }

      void bankers(){
          set_current();
          //checking safty
          
          for(auto it:prs){
              if(!safty(it))  {cout<<"safty voilated";exit(0);}
          }
          //return;
          vector<pair<process,bool>> lt;
          for (auto i:prs) lt.push_back(make_pair(i,true));
int c1=0;

    do{
        for (auto &i:lt)
    if(!resource_allocation(i.first) or !i.second) {continue;}
    else {
        auto p=i.first;
        cout<<"\ntaken process : P"<<p.id<<" Current available resource : ";
              for(auto &c:current) cout<<c<<',';
              cout<<" Requested resouces by process : ";
              for(auto pp:p.demand) cout<<pp<<','; 
              i.second=false;
              c1++;       
              for(int i=0;i<current.size();i++) current[i]+=p.allocated[i];

              }

}while(c1<lt.size());
      }
      
      
};


int main()
{//total resource
    Deadlock d({10,5,7});
    d.insert_process(process({0,1,0},{7,5,3},{7,4,3}));
    d.insert_process(process({2,0,0},{3,2,2},{1,2,2}));
    d.insert_process(process({3,0,2},{9,0,2},{6,0,0}));
    d.insert_process(process({2,1,1},{4,2,2},{2,1,1}));
    d.insert_process(process({0,0,2},{5,3,3},{5,3,1}));

    d.bankers();

    return 0;
}

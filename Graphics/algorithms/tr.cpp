#include <bits/stdc++.h>
using namespace std;
class PT{
public:
double x,y;
PT(int x1,int y1){x=x1,y=y1;}
PT(){}
 PT operator + (PT const &obj) {
         PT res;
         res.x = x + obj.x;
         res.y = y + obj.y;
         return res;
    }
    void print(){
printf(" %f , %f \n",x,y);
    }

};
void move(PT &x, PT &t){
x=x+t;
}
int main(){
  PT x(1,10),t(11,12);
move(x,t);
x.print();
}

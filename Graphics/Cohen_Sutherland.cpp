#include <bits/stdc++.h>
using namespace std;

const int INSIDE=0,TOP=1,BOTTOM=2,RIGHT=4,LEFT=8;//0001

const int xmin=10,ymin=10,xmax=100,ymax=100;

int compute_points(double x,double y){
  int code=INSIDE;
if(x<xmin) code|=LEFT;
if(x>xmax) code|=RIGHT;
if(y<ymin)code|=BOTTOM;
if(y>ymax)code|=TOP;
return code;
}

void clip(double x1,double y1,double x2,double y2){
vector<int> codes={compute_points(x1,y1),compute_points(x2,y2)};
bool accepted=false;
while (true){
  if(codes[0]==INSIDE and codes[1]==INSIDE) {accepted=true; break;}
  else if(codes[0]&codes[1]){
    break;
  }
  else{
    int code_out=codes[0];
    double x,y;
    if(codes[1]!=INSIDE){
        code_out=codes[1];
    }
    if(code_out & TOP){
      y=ymax;
      x=x1+(x2-x1)*(y-y1)/(y2-y1);
    } 
    else if(code_out & BOTTOM){
      y=ymin;
      x=x1+(x2-x1)*(y-y1)/(y2-y1);
    }
    else if(code_out & RIGHT){
      x=xmax;
      y=y1+(y2-y1)*(x-x1)/(x2-x1);
    }
    else if(code_out & LEFT){
      x=xmin;
      y=y1+(y2-y1)*(x-x1)/(x2-x1);
    }

    if(code_out ==codes[0]){
      x1=x,y1=y;
    }
    else{
      x2=x,y2=y;
    }
    codes={compute_points(x1,y1),compute_points(x2,y2)};
  }
}
if(accepted){
printf("{%f, %f} , {%f, %f}\n",x1,y1,x2,y2);
}
else{
  printf("outside\n");
}
}

int main(){
clip(9,11,99,111);

}
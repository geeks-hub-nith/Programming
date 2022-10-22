#include <bits/stdc++.h>
#include "graphics.cpp"

using namespace std;

void midptellipse(int rx, int ry,
                  int xc, int yc)
{
  graphics g;
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
 
    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
                     (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
 int mg=100;
    // For region 1
    while (dx < dy)
    {
 
        // Print points based on 4-way symmetry
        //cout << x + xc << " , " << y + yc << endl;
        g.put_points(mg+x+xc,mg+y+yc);
        g.put_points(mg-x+xc,mg+y+yc);
        g.put_points(mg+x+xc,mg-y+yc);
        g.put_points(mg-x+xc,mg-y+yc);
        // cout << -x + xc << " , " << y + yc << endl;
        // cout << x + xc << " , " << -y + yc << endl;
        // cout << -x + xc << " , " << -y + yc << endl;
 
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
 
    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
 
    // Plotting points of region 2
    while (y >= 0)
    {
 g.put_points(mg+x+xc,mg+y+yc);
        g.put_points(mg-x+xc,mg+y+yc);
        g.put_points(mg+x+xc,mg-y+yc);
        g.put_points(mg-x+xc,mg-y+yc);

        // Print points based on 4-way symmetry
        // cout << x + xc << " , " << y + yc << endl;
        // cout << -x + xc << " , " << y + yc << endl;
        // cout << x + xc << " , " << -y + yc << endl;
        // cout << -x + xc << " , " << -y + yc << endl;
 
        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int ellipse(){
  graphics g;
double x,y,a,b,d1,d2;
a=300,b=300;
x=0,y=b;
d1=b*b*(x+1)*(x+1)+a*a*(y-.5)*(y-.5)-a*a*b*b;


// while((pow(a,2)*pow(y-.5,2)<pow(b,2)*pow(x+1,2)))
while(a*pow(x+1,2)<b*pow(y-.5,2)){
  g.put_points(100+x,100+y);
if(d1<0){
  d1+=b*b*(2*x+3);}
else{
  d1+=b*b*(2*x+3)+a*a*(-2*y+2);
  y-=1;
}x++;
}
d1=b*b*(x+.5)*(x+.5)+a*a*(y-1)*(y-1)-a*a*b*b;
while(y>0){
  g.put_points(100+x,100+y);
  if(d2<0){
    d2+=b*b*(2*x+2)+a*a*(-2*y+3);
    x++;
  }
  else{
    d2+=a*a*(-2*y+3);
    y--;
  }
}
return 0;
}
int main(){
  midptellipse(225, 115, 250, 350);
  


  return 0;
}

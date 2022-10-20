#include <bits/stdc++.h>
#include <fstream>
#include "graphics.hpp"

using namespace std;
class graphics{
public:
FILE * pFile;
graphics(){
   //clear_screen();
}
int clear_screen(){
pFile = fopen ("python/output.txt","w");
  return 0;
}
  int put_points(int x,int y){
    pFile = fopen ("python/output.txt","a+");
  fprintf(pFile,"%d %d\n",x,y);
  fclose(pFile);
return 1;
}
int put_points(double x,double y){
  pFile = fopen ("python/output.txt","a+");
  fprintf(pFile,"%d %d\n",(int)x,(int)y);
  fclose(pFile);
  return 1;
}
};




  
 // namespace std


#include<stdio.h>
#include<math.h>

int cla(double,double,double,double,int);  

int main(){
  int n;
  double p1x=0.0,p1y=0.0,p2x=100.0,p2y=0.0;
  scanf("%d",&n);
  printf("%f %f\n",p1x,p1y);
  cla(p1x,p1y,p2x,p2y,n);
  return 0;
}
 
int cla(double p1x,double p1y,double p2x,double p2y,int n){
  double c=M_PI/3;
  double sx,sy,tx,ty,ux,uy;
 
  if(n==0){
    printf("%f %f\n",p2x,p2y);
    return 0;
  }
 
  else{
  sx=((p2x-p1x)/3)+p1x;
  sy=((p2y-p1y)/3)+p1y;
 
  tx=((p2x-p1x)*2/3)+p1x;
  ty=((p2y-p1y)*2/3)+p1y;
 
  ux=(cos(c)*(tx-sx)-sin(c)*(ty-sy))+sx;
  uy=(sin(c)*(tx-sx)+cos(c)*(ty-sy))+sy;
 
  cla(p1x, p1y, sx, sy, n-1);
  cla(sx, sy, ux, uy, n-1);
  cla(ux, uy, tx, ty, n-1);
  cla(tx, ty, p2x, p2y, n-1);
  }
  
}

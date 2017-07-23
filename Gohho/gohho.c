#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10000 
int main(){
  int i,j;
  double x,y,x1,y1,sx,sy,th,th2,tx,ty,r;
  double x2,y2,z,l;
  double x3,y3;
  double x4,y4;

  FILE *fp;
  fp = fopen("gohho.dat","w");
  srand(10);
  sx = sy = 1.0/3.0;
  x = y = 0.0;
  th2 = M_PI/3.0;

  for(i = 0;i < N;i++){
    r = (double)rand()/(RAND_MAX);

    if(r < 0.25){
      th = 0.0;
      tx = ty = 0;
    }else if(r < 0.5){
      th = 60.0 * M_PI/180;
      tx = 1.0/3.0;
      ty = 0.0;
    }else if(r < 0.75){
      th = -60.0 * M_PI/180;
      tx = 1.0/2.0;
      ty = sqrt(3.0)/6.0;
    }else{
      th = 0.0;
      tx = 2.0/3.0;
      ty = 0.0;
    }
    x1 = sx * cos(th) * x - sx * sin(th) * y + tx;
    y1 = sy * sin(th) * x + sy * cos(th) * y + ty;

    /* x = x1; */
    /* y = y1; */

    /*  テスト */
    x2 = x * cos(60) - y * sin(60) + 1.0/3.0 ;
    y2 = -x * sin(60) - y * cos(60);

    x3 = x * cos(-60) - y * sin(-60) + 1.0/2.0;
    y3 = x * sin(-60) + y * cos(-60) + sqrt(3.0)/6.0;

    x4 = x * cos(0) - y * sin(0) + 2.0/3.0;
    y4 = x * sin(0) + y * cos(0);

    x = x1;
    y = y1;

    fprintf(fp,"%f %f\n",x,y); /*  元々あった */
    fprintf(fp,"%f %f\n",x2,y2);
    fprintf(fp,"%f %f\n",x3,y3);
    fprintf(fp,"%f %f\n",x4,y4);

    /* ここまで */

  }

  fclose(fp);
  return 0;
}

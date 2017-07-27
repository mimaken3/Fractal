#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100000

int main(){
  int i,t;
  double x = 0,y = 0,x1,y1,sx,sy,th,tx,ty,r;
  double x2,y2;
  double x3,y3;
  double x4,y4;


  FILE *fp;
  fp = fopen("fractal2.dat","w");
  srand(10);

  sx = sy = 1.0/2.0;
  th = 0.0;

  for(i = 0;i < N;i++){
    r = rand()/(RAND_MAX + 1.0);

    if(r > 2.0/3.0){
      tx = ty = 0.0;
    }else if(r > 1.0/3.0){
      tx = 1.0/2.0;
      ty = 0.0;
    }else if(r < 0.75){
      tx = 1.0/4.0;
      ty = 1.0/2.0;
    }else{
      tx = 1.0/4.0;
      ty = 1.0/2.0;
    }
    x1 = sx * cos(th) * x - sx * sin(th) * y + tx + 1.0/3.0;
    y1 = sy * sin(th) * x + sy * cos(th) * y + ty + 1.0/3.0;

    /* x = x1; */
    /* y = y1; */

    x2 = sx * cos(90) * x - sx * sin(90) * y + tx;
    y2 = -sy * sin(-90) * x - sy * cos(-90) * y + ty;

    /* x2 = sx * cos(90) - sy * sin(90); */
    /* y2 = -sx * sin(90) - sy * cos(90) + 1.0/3.0; */


    x = x1;
    y = y1;

    /* fprintf(fp,"%f %f\n",x1/3.0,y1/3.0); */
    fprintf(fp,"%f %f\n",x/3.0,y/3.0);
    fprintf(fp,"%f %f\n",x2/3.0,y2/3.0);


  }
  fclose(fp);

  return 0;
}

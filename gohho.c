#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10000 
int main(){
  int i,j;
  double x,y,x1,y1,sx,sy,th,th2,tx,ty,r;
  double x2,y2,z,l;
  double x_tmp,y_tmp,z_tmp,l_tmp;
  double x_reverse_left,y_reverse_left;
  double x_reverse_right,y_reverse_right;


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

    x = x1;
    y = y1;

/*  テスト */
    x_reverse_left = x * cos(-150) - y * sin(-150);
    y_reverse_left= -x * sin(-150) - y * cos(-150);

    x_reverse_right = x * cos(-90) - y * sin(-90) + 1;
    y_reverse_right = x * sin(-90) + y * cos(-90);

/* ここまで */

    fprintf(fp,"%f %f\n",x,y);
    fprintf(fp,"%f %f\n",x_reverse_left,y_reverse_left);
    fprintf(fp,"%f %f\n",x_reverse_right,y_reverse_right);
    
    /* fprintf(fp,"%f %f\n",x_tmp,y_tmp); */
    /* fprintf(fp,"%f %f\n",z_tmp,l_tmp); */

  }
  fclose(fp);

  return 0;
}

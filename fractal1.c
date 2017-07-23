#include<stdio.h>
#include<stdlib.h>
#define N 100000

int main(){

  int i,j,t;
  double x=0,y=0,r;
  double a[3][2]=
  {
    {0.0,0.0}, {1.0,0.0}, {1.0,1.0}
  };
  FILE *fp;
  fp = fopen("data_frac1.dat","w");
      srand(10);

      for(i = 0;i < N;i++){
      r = rand()/(RAND_MAX + 1.0);
      t = (int)(r * 3.0);

      x = (x + a[t][0])/2.0;
      y = (y + a[t][1])/2.0;

      fprintf(fp, "%f%f\n",x,y);
      }

      fclose(fp);

      return 0;
      }

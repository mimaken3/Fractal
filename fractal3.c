#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* #include<eggx.h> */
/* #include<cs50.h> */

float LPX,LPY,ANGLE;
int w;
int N;

void koch(float,int);
void setlp(float,float);
void setangle(float);
void turn(float);
void set_hiki(float);

int main(){

  printf("intput degree N >");
  scanf("%d",&N);
  w = gopen(500,400);

  setlp(20.,100.);
  setangle(0.0);
  koch(350.,0);

  ggetch();
  exit(0);


  return 0;
}

void koch(float leng, int n){
  if(n >= N){
    set_hiki(leng);
  }else{
    koch(leng/3.,n + 1);
    turn(60.);
    koch(leng/3.,n + 1);
    turn(-120.);
    koch(leng/3.,n + 1);
    turn(60.);
    koch(leng/3.,n + 1);
  }
  return;
}










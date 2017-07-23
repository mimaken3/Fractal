/* koch : snow flake
位数０のKoch曲線から位数１の曲線を作るためには、Turtleは
その進行方向を元の直線の１/３の長さ(size)のところで反時計回りに
６０度変えて、またsize分だけ進んだところで今度は時計回りに
１２０度、さらにsize分だけ進んだところで反時計回りに６０度
変えればよい。Koch曲線のように、内部に自分自身を含むように
定義されている図形を"再帰的(recursive)な図形"と呼ぶ。*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void koch( double size, int order);

double x=0.0;
double y=0.0;
double theta=0.0;

FILE *fp;

int main(void)
{
	double size=243.0;
	int order=5;
	
	fp=fopen("koch.csv","w");
	
	printf("TitleText: Koch Order ");
	printf("%d\n", order);
	printf("Ticks: true\n");
	printf("BoundBox: on\n");
	printf("%f %f \n", 0.0, 0.0);

	koch(size, order);
	theta -= 2*M_PI/3.0;
	koch(size, order);
	theta -= 2*M_PI/3.0;
	koch(size, order);
	
	fclose(fp);
	
	rewind(stdin);
	getchar();
	return 0;	
}

void koch( double size, int order)
{
	if (order == 0){
		x += size * cos(theta);
		y += size * sin(theta);
 		printf("%f %f \n", x, y);
 		fprintf(fp,"%f,%f\n",x,y);
 	} else {
		koch(size/3.0, order-1);
		theta += M_PI/3.0;
		koch(size/3.0, order-1);
		theta -= 2.0*M_PI/3.0;
		koch(size/3.0, order-1);
		theta += M_PI/3.0;
		koch(size/3.0, order-1);
	}
}

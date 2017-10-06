// DDA algorithm is used to draw a line on computer screen. It works on the slope intercept form of a line i.e. y = mx+c

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	float x0, x1, y0, y1;
	cout<<"Enter the value of x0 and y0";
	cin>>x0;
	cin>>y0;

	cout<<"Enter the value of x1 and y1";
	cin>>x1;
	cin>>y1;

	float dx = x1-x0;
	float dy = y1-y0;
	float steps;

	if(dx>dy){
		steps = abs(dx);
	}else{
		steps = abs(dy);
	}

	float x_inc, y_inc;
	x_inc = dx/steps;
	y_inc = dy/steps;

	float x , y;
	x = x0;
	y = y0;

	for(int i = 0; i <steps ; i++){
		x = x + x_inc;
		y = y + y_inc;
		putpixel(x, y,WHITE);

	}

	getch();
	closegraph();
	return 0;
}

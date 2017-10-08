
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main(){
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	float X,Y,rx,ry;
	cout<<"Enter the Center (X, Y) : ";
	cin>>X>>Y;

	cout<<"Enter major Axis radius (rx) : ";
	cin>>rx;
	cout<<"Enter minor Axis radius (ry) : ";
	cin>>ry;

	float *quadCordPh1;// Holds y Coordinates
	quadCordPh1 = new float[rx];
	quadCordPh1[0] = ry;
	float *quadCordPh2; // Holds x cordinates
	quadCordPh2 = new float[rx];

	float p_1, p_2;
	p_1 = pow(ry,2)-(pow(rx,2)*ry) +((1/4)*pow(rx,2));
	float x, y;
	x = 0;
	y = ry;

	// Phase One of the ellipse //
	while((2*pow(ry,2)*x) <= (2*pow(rx, 2)*y)){

		x = x+1;

		if(p_1<0){
			quadCordPh1[x] = y;
			p_1 += (2*pow(ry,2)*x)+pow(ry,2);
		}else{
			y  = y-1;
			quadCordPh1[x] = y;
			p_1 += (2*pow(ry,2)*x)-(2*pow(rx,2)*y)+pow(ry,2);
		}
	}

	p_2 = (pow(ry,2)*pow((x+1/2), 2))+(pow(rx,2)*pow((y-1),2))-(pow(rx, 2)* pow(ry,2));
	int i = 0;
	int offSet=x;
	quadCordPh2[0] = x;
	while(y > 0){
		i +=1;
		y -=1;
		if(p_2>0){
			quadCordPh2[i] = x;
			p_2 += -2*pow(rx,2)*y+pow(rx,2);
		}else{
			x+=1;
			quadCordPh2[i] = x;
			p_2 += 2*pow(ry,2)*x-2*pow(rx,2)*y+pow(rx,2);
		}
	}

	//Generating Phase One.
	for(int j = 0; j<offSet;j++){
		putpixel(X+j, Y+quadCordPh1[j],WHITE);
		putpixel(X+j, Y-quadCordPh1[j],WHITE);
		putpixel(X-j, Y+quadCordPh1[j],WHITE);
		putpixel(X-j, Y-quadCordPh1[j],WHITE);
		y = quadCordPh1[j];
	}
	// Generating Phase Two.
	for(j = 0;j<=i;j++){
		putpixel(X+quadCordPh2[j],Y+(y-j),WHITE);
		putpixel(X+quadCordPh2[j], Y-(y-j),WHITE);
		putpixel(X-quadCordPh2[j], Y+(y-j),WHITE);
		putpixel(X-quadCordPh2[j], Y-(y-j),WHITE);
	}
	getch();
	closegraph();
	return 0;

}
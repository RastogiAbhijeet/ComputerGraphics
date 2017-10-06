// Bresenham's Line Drawing Algorithm

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    float x1, y1, x2, y2, deltaX, deltaY, gradient;
    float decisionParameter;
    cout<<"Enter Point(x1, y1)";
    cin>>x1;
    cin>>y1;
    cout<<"Enter Point(x2, y2)";
    cin>>x2;
    cin>>y2;

    putpixel(x1,y1, WHITE);
    deltaX = abs(x2-x1);
    deltaY = abs(y2-y1);
    gradient = deltaY/deltaX;
    cout<<gradient;

    if(gradient<1){
	decisionParameter = 2*deltaY-deltaX; //Initial Parameter.
	for(int x = x1+1 ; x<=x2 ; x++){
	    if(decisionParameter<0){
		putpixel(x, y1, WHITE);
		decisionParameter = decisionParameter + 2*deltaY;
	    }else{
		putpixel(x, y1+1, WHITE);
		y1 = y1+1;
		decisionParameter = decisionParameter + 2*deltaY-2*deltaX;
	    }
	}
    }else{
	decisionParameter = 2*deltaX-deltaY;
	for(int y = y1+1; y<=y2 ;y++){
		if(decisionParameter<0){
			putpixel(x1, y, WHITE);
			decisionParameter += 2*deltaX;
		}else{
			putpixel(x1+1, y, WHITE);
			x1 += 1;
			decisionParameter += 2*deltaX-2*deltaY;
		}
	}
    }
    getch();
    closegraph();
    return 0;

}

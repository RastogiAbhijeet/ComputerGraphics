#include<iostream.h>
#include<graphics.h>
#include<conio.h>

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    float X, Y, radius, y_cord;
    float decisionParameter;
    float x = 0;
    float *octCord ;
    octCord = new float(radius);
    octCord[0] = radius;

    cout<<"Enter Center : ";
    cin>>X;
    cin>>Y;
    cout<<"Enter radius : ";
    cin>>radius;

    decisionParameter = 5/4-radius;
    y_cord = radius;
    
    while(x!=y_cord && x<radius){
        if(decisionParameter < 0){
            octCord[x+1] = y_cord;
            decisionParameter += 2*(x)+1;
        }else{
            octCord[x+1] = y_cord-1;
            y_cord = y_cord-1;
            decisionParameter += (2*x+1)-2*y_cord;
        }
        x += 1;
    }
    octCord[x+1] = y_cord;
	putpixel(X,Y+radius, WHITE);
	putpixel(X,Y-radius, WHITE);
	putpixel(X-radius, Y, WHITE);
	putpixel(X+radius,Y,WHITE);
    // Time to render the pixel.
    for(int i = 0; i<=y_cord ; i++){
        putpixel(i+X,octCord[i]+Y, WHITE);
        putpixel(octCord[i]+Y, i+X, WHITE);
        putpixel(i+X,Y- octCord[i], WHITE);
        putpixel(Y-octCord[i],i+X, WHITE);
        putpixel(X-i, (octCord[i]+Y), WHITE);
        putpixel(octCord[i]+Y,(X-i), WHITE);
        putpixel(X-i,Y- octCord[i], WHITE);
        putpixel(Y-octCord[i] , X-i , WHITE);
    }
    getch();
    closegraph();
    return 0;

}
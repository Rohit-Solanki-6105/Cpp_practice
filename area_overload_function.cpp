#include <iostream>
#include <conio.h>
using namespace std;

enum shapes{
	square = 1,
	circle,
	rect,
	cube,
	rect_cube,
	cylinder
};

int main(){
	float area(float ); // square
	float area(float , float); //rect
	double area(double r, double pi = 3.14915); // circle
	float volume(float); // cube
	float volume(float, float, float); //rect cube
	float volume(float, float); //cylinder


	int op;
	
	do{
		cout<<"1. square"<<endl
			<<"2. circle"<<endl
			<<"3. rect"<<endl
			<<"4. cube"<<endl
			<<"5. rect cube"<<endl
			<<"6. cylinder"<<endl
			<<"0. Exit"<<endl
			<<">";
		cin>>op;
		
		switch(op){
			case square:
				float s;
				cout<<"Enter Side: ";
				cin>>s;
				cout<<"Area: "<<area(s);
				break;
				
			case circle:
				float rad;
				cout<<"Enter Rad: ";
				cin>>rad;
				cout<<"Area: "<<area(rad, 3.14915);
				break;
				
			case rect:
				float l, b;
				cout<<"Enter L: ";
				cin>>l;
				cout<<"Enter B: ";
				cin>>b;
				cout<<"Area: "<<area(l, b);
				break;
				
			case cube:
				float side;
				cout<<"Enter Side: ";
				cin>>side;
				cout<<"Volume: "<<volume(side);
				break;
				
			case rect_cube:
				float len, bridth, width;
				cout<<"Enter L: ";
				cin>>len;
				cout<<"Enter B: ";
				cin>>bridth;
				cout<<"Enter W: ";
				cin>>width;
				cout<<"Volume: "<<volume(len, bridth, width);
				break;
				
			case cylinder:
				float r, h;
				cout<<"Enter r: ";
				cin>>r;
				cout<<"Enter h: ";
				cin>>h;
				cout<<"Volume: "<<volume(r, h);
				break;
				
			case 0:
				break;
				
			default:
				cout<<"Invalid Option!.....";
				break;
				
		}
		cout<<"\n-----------------------------------------\n"<<endl;
	}while(op != 0);
	
	getch();
	return 0;
}

float area(float s){
	return(s*s);
}

double area(double r, double pi){
	return(pi * r * r);
}

float area(float l, float b){
	return(l*b);
}

float volume(float s){
	return(s*s*s);
}

float volume(float l, float b, float w){
	return(l*b*w);
}

float volume(float r, float h){
	return(3.14915 * r * r * h);
}
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;
class shape{
	protected:
		int r;
	public:
		virtual void area(){
			cout<<"Area = ";
		}
		void getData(int x){
			r = x;
		}
};

class square: public shape{
	public:
		square(){}
		void area(){
			shape::area();
			cout<<r*r<<"\n";
		}
};

class circle: public shape{
	public:
		circle(){}
		void area(){
			shape::area();
			cout<<3.14*r*r<<"\n";
		}
};

int main(){
	shape *s;
	int ch;
	cout<<"Enter choise (1: square, 2: circle)= ";
		cin>>ch;
		
	if(ch == 1){
		s = new square();
		cout<<"Enter side = ";
		int side;
		cin>>side;
		s->getData(side);
		s->area();
	} else{
		s = new circle();
		cout<<"Enter Radius = ";
		int radius;
		cin>>radius;
		s->getData(radius);
		s->area();
	}
	getch();
	return 0;
}

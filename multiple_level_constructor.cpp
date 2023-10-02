#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class c1{
	protected: int a;
	public:
		c1(){}
		c1(int x){
			a=x;
		}
		void display(){
			cout<<a;
		}
};

class c2{
	protected: int b;
	public:
		c2(){}
		c2(int x){
			b=x;
		}
		void display(){
			cout<<b;
		}
};

class D: public c1, public c2{
	protected: int c;
	public:
		D(){}
//		D(int x, int y, int z):c1(x), c2(y){ // multiple constructor at a time
//			c=z;
//		}

		D(int x, int y, int z){ //direct using variable using scope resolution operator
			c1::a = x;
			c2::b = y;
			c = z;
		}
		void display(){
			cout<<"D: "<<c<<"\n";
			
			cout<<"c1: "; c1::display(); cout<<"\n"; // using display function of different classes
			cout<<"c2: "; c2::display(); cout<<"\n";
			
			cout<<"c1: "<<c1::a<<"\n"; // direct using variable using scope resution operator
			cout<<"c2: "<<c2::b<<"\n";
		}
};

int main(){
	D d1(1,2,3);
	
	d1.display();
	getch();
	return 0;
}

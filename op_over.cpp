#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
class point{
	int x,y,z;
	public:
		void getData(int a, int b, int c){
			x = a;
			y = b;
			z = c;
		}
		void display(){
			cout<<"X: "<<x<<endl
				<<"Y: "<<y<<endl
				<<"Z: "<<z<<endl;
		}
		void operator -(){
			x = -x;
			y = -y;
			z = -z;
		}
};

int main(){
	point p1;
	p1.getData(1,2,3);
	p1.display();
	cout<<"\n--------------------------\n";
	-p1; // unary
	p1.display();
	getch();
	return 0;
}

#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
class point{
	int x,y,z;
	public:
		point(){}//default constructor
		point(int a, int b, int c){
			x = a;
			y = b;
			z = c;
		}
		void display(){
			cout<<"("<<x<<", "<< y<<", "<<z<<")";
		}                                    
		//point = self + p
		point operator +(point p){//binary 
			point p_r;
			p_r.x = x + p.x;
			p_r.y = y + p.y;
			p_r.z = z + p.z;
			return p_r;			
		}
};

int main(){
	point p1(1,2,3),p2(9,8,7),p3;
	
	p1.display();
	cout<<" + ";
	p2.display();
	
	cout<<" = ";
	p3 = p1+p2; //  method is called from p1 and arg is p2, p2 is called, p_r returned
	p3.display();
	getch();
	return 0;
}

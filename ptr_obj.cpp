#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class point{
	int x,y;
	public:
		point(){}
		point(int a, int b){
			x=a; y=b;
		}
		void set(int a, int b){
			x=a; y=b;
		}
		void display(){
			cout<<"( "<<x<<", "<<y<<")\n";
		}
};

int main(){
	point p(1,2);
	p.display();
	
	point *ptr;
	ptr = &p;
	ptr->display();
	
	point *ptr_test = new point;
	ptr_test->set(3,4);
	ptr_test->display();
	
	cout<<"-----------\n";

//	point *ptr_arr[4]; // array of pointers, to access it we have to use ptr_arr[i]

//	point *ptr_arr = new point[4]; // finite array
	point *ptr_arr = new point; // infinite array
	for(int i=0; i<4; i++){
		int a, b;
		cin>>a>>b;
		(ptr_arr+i)->set(a,b);
	}
	for(int i=0; i<4; i++){
		(ptr_arr+i)->display();
//		cout<<ptr_arr+i<<"\n"; // printing address
	}
	
	getch();
	return 0;
}
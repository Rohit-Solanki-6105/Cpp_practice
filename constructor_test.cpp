#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;

class car{
	string brand;
	int modelNum;
	
	public:
		void display(){
			cout<<modelNum<<setw(20)<<brand<<endl;
		}
		car(){
			modelNum = 0;
			brand = "null";
		}
		car(car &a){
			brand = a.brand;
			modelNum = a.modelNum;
		}
		car(string x){
			brand = x;
			modelNum = 0;
		}
		car(string x, int y){
			brand = x;
			modelNum = y;
		}
};

int main(){
	car c1("bmw", 10), c2("hi"), c3(), c4(c1), c5;
	c5 = c2;
	
	c1.display();
	c2.display();
//	c3.display();
	c4.display();
	c5.display();
	getch();
	return 0;
}

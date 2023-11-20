#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class person{
	int age;
	public:
		person(){}
		person(int a){
			age = a;
		}
		person greater(person &x){
			if(x.age >= age){ // no need to write *this
				return x;
			}
			else{
				return *this; // returning this pointer
			}
		}
		void display(){
			cout<<age<<"\n";
		}
};

int main(){
	person P, P1(10), P2(5), P3(20);
	P1.display();
	P2.display();
	P3.display();
	
	cout<<"\n-----------\n";
	P = P1.greater(P2);
	P.display();
	
	P = P1.greater(P3);
	P.display();

	getch();
	return 0;
}

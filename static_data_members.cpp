#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// static to auto increment

class employee{
	static int id; // common for every obj
	int age;
	
	public:
		void getdata(int a){
			age = a;
			id++; // auto incrementing
		}
		void displaydata(){
			cout<<id<<": "<<age<<endl;
		}
};

int employee::id; // static var should be defined out of class also

int main(){
	employee e1,e2,e3;
	
	e1.getdata(23);
	e1.displaydata(); // id++ , all 1
	
	e2.getdata(25);
	e2.displaydata(); // id++ , all 2
	
	e3.getdata(56);
	e3.displaydata(); // id++ , all 3
	
	e2.displaydata(); // just showing for common values of id
	
	cout<<"\n---------------------\n";
	
// //   id will be same
	e1.getdata(23);
	e2.getdata(25);
	e3.getdata(56);
	e1.displaydata();
	e2.displaydata();
	e3.displaydata();
	getch();
	return 0;
}

/*
1: 23
2: 25
3: 56
3: 25

---------------------
6: 23
6: 25
6: 56
*/

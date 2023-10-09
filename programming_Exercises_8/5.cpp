/*8.5) Consider a class network given in figure . The class master derives information from both account and admin classes 
Which in turn derive information from the class person .define all the four classes and write a program to 
create, update and display the information contained in master objects;
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class person{
	protected:
		string name;
		long int code;
	
	public:
		person(){}
		person(string n, long int c){
			name = n; code = c;
		}
};

class account:virtual public person{
	protected:
		float pay;
		
	public:
		account(){}
		account(string n, long int c, float p):person(n, c){
			pay = p;
		}
};

class admin:public virtual person{
	protected:
		float experience; //in years
	
	public:
		admin(){}
		admin(string n, long int c, float e):person(n, c){
			experience = e;
		}
};

class master:public account, public admin{
	public:
		master(){}
		master(string n, long int c, float p, float e){
			person::name = n;
			person::code = c;
			account::pay = p;
			admin::experience = e;
		}

		void display(){
			cout<<"Name: "<<person::name<<endl
				<<"Code: "<<person::code<<endl
				<<"Pay: "<<account::pay<<endl
				<<"Experience(in years): "<<admin::experience<<endl;
		}
};

int main(){
	master m1("Hi", 1234, 1000, 1.5);
	m1.display();
	getch();
	return 0;
}

/*
Name: Hi
Code: 1234
Pay: 1000
Experience(in years): 1.5

*/
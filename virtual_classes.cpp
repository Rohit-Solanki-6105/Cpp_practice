#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;
// virtual classes
class person{
	protected: 
		string name;
		long int phone;
		
	public:
		person(){}
		person(string n, long int p){
			name = n;
			phone = p;
		}
		void display(){
			cout<<"Name: "<<name<<"\n"
				<<"Phone: "<<phone<<"\n";
		}
};

class student: public virtual person{
	protected:
		int roll;
	
	public:
		student(){}
		student(int r, string n, long int p){
			person::name = n;
			person::phone = p;
			roll = r;
		}
		void display(){
			cout<<"Roll: "<<roll<<"\n";
		}
};

class teacher: virtual public person{
	protected:
		int id;
	public:
		teacher(){}
		teacher(int i, string n, long int p){
			person::name = n;
			person::phone = p;
			id = i;
		}
		void display(){
			cout<<"Id: "<<id<<"\n";
		}
};

class ts: public teacher, public student{ // only one data of person will be get
	int ts_id;
	
	public:
		ts(int t, int r, int i, string n, long int p){
			person::name = n;
			person::phone = p;
			student::roll = r;
			teacher::id = i;
			ts_id = t;
		}
		
		void display(){
			person::display();
			student::display();
			teacher::display();
			cout<<"TS id: "<<ts_id<<"\n";
		}
};


int main(){
	ts t1(1,1,1,"hi",1234576890);
	
	t1.display();
	getch();
	return 0;
}

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class person{
	long int ashar_num;
	string name;
	string city;
	int age;
	char gender;
	public:
		setdata(long int a, string n, string c, int age_, char g){
			adhar_num = a;
			name = n;
			city = c;
			age = age_;
			gender = g;
		}
		getdata(){
			cout<<"Adhar: "<<adhar_num<<"\n"
				<<"Name: "<<name<<"\n"
				<<"City: "<<city<<"\n"
				<<"Age: "<<age<<"\n"
				<<"Gender: "<<gender<<"\n";
		}
};

//single ex
class employee: public person{ // public derivation of class person, accenss public members not all
	int emp_id, salary;
	string designition;
	public:
		setempdata(int e, int sal, string d){
			emp_id = e;
			salary = salary;
			designition = d;
		}	
		
		getempdata(){
			cout<<"Eid: "<<emp_id<<"\n"
				<<"Salary: "<<salary<<"\n"
				<<"Designition: "<<designition<<"\n";
		}
};

// level 2
class hourly_emp: public employee{
	int num_hours;
	public:
		sethdata(int n){
			num_hours = n;
		}
		gethdata(){
			cout<<"Hours: "<<num_hours<<"\n";
		}
};

//level 2, heirarchial of employee
class regular_emp: public employee{
	int hra, 
};

int main(){

	getch();
	return 0;
}

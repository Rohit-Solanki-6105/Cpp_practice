#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// friend functions not a method in class
/* not in class but can access private member variables using friend functions , 
making a function a friend of class */
class employee;

class customer{
	int id;
	string name;
	int salary;
	public:
		void getdata()
		{
			cout<<"\nEnter id: ";
			cin>>id;
			cout<<"\nEnter name :";
			cin>>name;
			cout<<"\nEnter salary :";
			cin>>salary;
		}
		void dsiplaydata()
		{
			//cout<<"\n" <<name <<" "<<calculatetax(salary);
		 } 
		int getsalary()
		{
			return salary;
		}
		friend int calculatemax(employee,customer);
};


class employee{
	int id;
	string name;
	int pfnumber;
	int salary;
	int d1,d2,d3;
	public:
		void getsalary(int h,int d,int t,int d1,int d2, int d3)
		{
			salary=h+d+t-d1-d2-d3;
//			cout<<salary<<endl;
		}
		friend int calculatemax(employee , customer);
};

int calculatemax(employee e, customer c){
		int se = e.salary;
		int sc = c.salary;
		
		if(se > sc){
			return se;
		}
		else{
			return sc;
		}
}
int main(){
	customer c1;
	c1.getdata();
	c1.dsiplaydata();
	employee e1;
	e1.getsalary(1000,100,45,55,100, 100);
	cout<<endl<<"Max: "<<calculatemax(e1, c1)<<endl;
	getch();
	return 0;
}

// employee class : name, age, gender, salary
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class employee{
	static int id;
	char name[50];
	int salary;
	char city[50];
	int age;
	char gender;
	
	public:
		void id_init(){
			id=0;
		}
		void setData(){
			cout<<"Name: ";
				cin>>name;
				
			cout<<"Age: ";
				cin>>age;
				
			cout<<"City: ";
				cin>>city;
				
			cout<<"Salary: ";
				cin>>salary;
				
			cout<<"Gender[f/m]: ";
				cin>>gender;
				
			id++;
		}
		void displayData(){
			cout<<name<<" "<<city<<" "<<salary<<" "<<gender<<" "<<age<<endl;
		}
		char getGender(){
			return(gender);
		}
		int getSalary(){
			return(salary);
		}
		int getAge(){
			return(age);
		}
};

int main(){
	
	employee e[5],e1;
	
	for(int i = 0; i<5; i++){
		e[i].setData();
	}
	cout<<"\n------------------------------------------\n";
	for(int i=0; i<5; i++){
		e[i].displayData();
	}
	getch();
	return 0;
}

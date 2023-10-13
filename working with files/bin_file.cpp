#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class inventory{
	int id;
	string name;
	float cost;
	
	public:
		void readData(){
			cout<<"Enter ID: ";
				cin>>id;
			cout<<"Enter Inv Name: ";
				cin>>name;
			cout<<"Cost: ";
				cin>>cost;
		}
		void displayData(){
			cout<<setw(5)<<id<<setw(20)<<name<<setw(10)<<cost<<"\n";
		}
};

int main(){
	inventory product[3];
	fstream file;
	file.open("Stock", ios::in | ios::out); //opening for read , write both
	for(int i=0; i<3; i++){
		product[i].readData();
		file.write((char *)&product[i], sizeof(product[i]));
	}
	
	file.seekg(0); // goto starting point
	cout<<"\nIn file\n";
	
	
	for(int i=0; i<3; i++){
		cout.fill('-');
		file.read((char *)&product[i], sizeof(product[i]));
		product[i].displayData();
	}
	file.close();
	getch();
	return 0;
}

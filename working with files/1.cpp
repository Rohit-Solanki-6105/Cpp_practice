#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream> // file streaming
using namespace std;

// ifstream for only input from file
// ofstream for only output in file
// fstream for both

// using constructor
int main(){
	
	ofstream outf("ITEM"); // connecting to ITEM file for inserting output 
	
	cout<<"Enter Name of ITEM: ";
	char name[50];
		cin>>name;
		
	outf<< name <<"\n"; // inserting name value into file
	
	cout<<"Enter the cost: ";
	float cost;
		cin>>cost;
	
	outf<< cost <<"\n"; // inserting cost value into file
	
	outf.close(); //closing file
	
	ifstream inf("ITEM"); // connectint to ITEM file for getting the data in it
	
	inf>>name; // storing the values in variable
	inf>>cost;
	
	cout<<"\n"
		<<"Name of ITEM: "<<name<<"\n"
		<<"Cost: "<<cost<<"\n";
	
	getch();
	return 0;
}

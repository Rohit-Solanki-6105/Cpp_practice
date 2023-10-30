#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

int sq1(int n){
	return n*n;
}

void sq2(int *n){
	(*n)*=(*n);
}

void sq3(int &n){
	n*=n;
}

int main(){
	int a1=5, a2 = 2, a3 = 3;
	
	cout<<"A1: "<<a1<<"\n"
		<<"sq1: "<<sq1(a1)<<"\n"
		<<"A1: "<<a1<<"\n\n";
		
	
	cout<<"A2: "<<a2<<"\n";
	sq2(&a2);
	cout<<"sq2: "<<a2<<"\n";
	cout<<"A2: "<<a2<<"\n\n";
		
		
	cout<<"A3: "<<a3<<"\n";
	sq3(a3);
	cout<<"sq3: "<<a3<<"\n";
	cout<<"A3: "<<a3<<"\n\n";
	
	getch();
	return 0;
}

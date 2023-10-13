#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

int main(int argn, char *args[]){ //  int n of args, char * arguments
	
	cout<<"N: "<<argn<<"\n";
	cout<<"Arguments: \n\n";
	
	for(int i; i<argn; i++){
		cout<<i<<" = "<<args[i]<<"\n";
	}
	
	getch();
	return 0;
}

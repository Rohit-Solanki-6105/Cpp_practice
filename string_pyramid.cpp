#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	 
	char *str1 = "Programming";
	int n = strlen(str1);
	
	char *str2 = "C++";
	int m = strlen(str2);
	
	for(int i=1; i<=n; i++){
		  cout.write(str1, i);
		  cout<<"\n";
	}
//	cout.write("C++", 10);

    for(int i=n-1; i>0; i--){
    	  cout.write(str1, i);
		  cout<<"\n";
	}
	
	cout.write(str2, m+1).write(str1, n);
	
	getch();
	return 0;
}
/*
P
Pr
Pro
Prog
Progr
Progra
Program
Programm
Programmi
Programmin
Programming
Programmin
Programmi
Programm
Program
Progra
Progr
Prog
Pro
Pr
P
C++ Programming

*/
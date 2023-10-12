#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	int a,b;
	cout<<"A: ";
		cin>>a;
	cout<<"B: ";
		cin>>b;
		
	try{
		if(b!=0){
			cout<<"\n"<< (float)a/b;
		} else{
			throw(b);	// throw error value
		}
	} catch(int e){ // catch the error, can be made as many as we want
		cout<<"Exception: "<<e;
	}
	getch();
	return 0;
}
/*
multiple catches and throws can be made
throw can be anywhere
in catch we can also use string , char, float for get the exception
*/

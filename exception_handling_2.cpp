#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	try{
		for(int i=0; i<30; i++){
			if(i>20){
				throw(i);
			} else{
				cout<<i<<endl;
			}
		}
	} catch(int e){
		cout<<"Exception: "<<e;
		cout<<"\nGreater than 20\n";
	}
	getch();
	return 0;
}

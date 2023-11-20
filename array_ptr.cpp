#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <ctype.h>
using namespace std;

int main(){
	int i=0;
	
	char *ptr[10] = {
		"books",
		"television",
		"computer",
		"sports"
	};
	
	char str[25];
	
	cout<<"\n\n\nEnter Your Favourite leisure persuit: ";
	cin>>str;
	for(i=0; i<4; i++){
		if(!(strcmp(str, ptr[i]))){
			cout<<"\n\nYour Favourite persuit is available here\n";
			break;
		}
	}
	if(i==4){
		cout<<"\n\nYour Favourite Is not available here\n";
	}

	getch();
	return 0;
}

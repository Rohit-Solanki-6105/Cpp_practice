#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main(){
	cout.fill('~'); // fill this with width
	cout.precision(5); // total number of digits
//	cout.setf(ios::left, ios::adjustfield); // left aligned
//	cout.setf(ios::showpoint); // display all zeros
//	cout.setf(ios::showpos); // display positives with +
	cout.setf(ios::showbase);
	for(int i=1; i<=6; i++){
		cout.width(5);
		cout<<i;
		cout.width(10);
		cout<<sqrt(i)<<"\n";
	}
	getch();
	return 0;
}

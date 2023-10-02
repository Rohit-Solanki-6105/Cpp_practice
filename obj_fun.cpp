#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// objs as function args

class times{
	int hours;
	int minutes;
	
	public:
		void getTime(int h, int m){
			hours = h;
			minutes = m;
		}
		void putTime(){
			cout<<"Hours: "<<hours<<endl
				<<"Minutes: "<<minutes<<endl;
		}
		void sum(times t1, times t2){
			minutes = t1.minutes + t2.minutes;
			hours = minutes/60;
			minutes = minutes%60;
			hours = hours + t1.hours + t2.hours;
		}
};

int main(){
	times t1,t2,t3;
	
	t1.getTime(2, 45);
	t2.getTime(3, 30);
	
	t3.sum(t1, t2);
	
	cout<<"\nT1\n\n";t1.putTime();
	cout<<"\nT2\n\n";t2.putTime();
	cout<<"\nT3\n\n";t3.putTime();
	
	getch();
	return 0;
}

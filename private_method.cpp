#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class sample{
	int m;
	void read(int x){
		m=x;
	}
	public:
		void update(){
			int a;
			cout<<"Enter Num: ";
			cin>>a;
			read(a);
			m = a*10;
		}
		int display();
};

inline int sample::display(){
	return (m);
}

int main(){
	
	sample s1;
	s1.update();
	cout<<"Sample Num: "<<s1.display();
	
	getch();
	return 0;
}
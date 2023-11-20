#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void display(vector<int> &v){
	cout<<"[ ";
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<", ";
	cout<<"]\n";
}

int main(){
	vector<int> v1;
	cout<<"Vector size: "<<v1.size()<<"\n\n";
	cout<<"Enter 5 ints: \n";
	for(int i=0; i<5; i++){
		int a;
		cin>>a;
		v1.push_back(a);
	}
	display(v1);
	
	cout<<"Now Size: "<<v1.size()<<"\n";
	
	v1.push_back(6.8); //float value trucated to int
	display(v1);
	
	//insert elements
	vector<int>::iterator itr = v1.begin(); // iterator
	itr = itr + 3; // iterator to 4th element
	v1.insert(itr, 80); // inserting to the position
	
	display(v1);
	
	// removing 4th & last element
	v1.erase(v1.begin()+3,v1.begin()+5);
	display(v1);
	
	
	getch();
	return 0;
}

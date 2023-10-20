#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

template <typename T, int size>
class Array_class{
	T a[size];
	public:
		void insert(){
			cout<<"Enter values:\n";
				for(int i=0; i<size; i++)
					cin>>a[i];
		}
		
		void display(){
			cout<<"[ ";
				for(int i=0; i<size; i++)
					cout<<a[i]<<", ";
			cout<<"]";
		}
};

int main(){
	Array_class<int , 5> arr;
	arr.insert();
	cout<<"\n";
	arr.display();
	cout<<"\n------------------\n";
	
	Array_class<float, 3> arr_float;
	arr_float.insert();
	cout<<"\n";
	arr_float.display();
	
	cout<<"\n------------------\n";
	Array_class<char, 5> arr_char;
	arr_char.insert();
	cout<<"\n";
	arr_char.display();
	getch();
	return 0;
}

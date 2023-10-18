#include <iostream>
#include <conio.h>
using namespace std;

// template:
template <typename T> // making a template will get data type of any
// created a template named t will get any data type
// can use class also for any type of class

T maximum(T a, T b){ // don't need to use a return type, specified as template
	return (a>b?a:b); //condition in
	// using inline condition ?if(ontrue) , :else(on false) 
} // this function can return any data type
// maximum function becomes a template

int main(){
	cout<<maximum<int>(1,2)<<"\n"
		<<maximum<char>('x', 'X')<<"\n"
		<<maximum<float>(1.5, 1.4);
	getch();
	return 0;
}

// the maximum function is equal to return type char , int, float diff. functions combined
// all in one function
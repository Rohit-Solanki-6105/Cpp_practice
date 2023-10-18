#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

template <typename T>

void sort(T arr[], int n){
	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
			if(arr[i] > arr[j])
				swap(arr[j], arr[i]);
}


int main(){
	int a[5] = {1,4,6,3,8};
	char c[6] = "hicbs";
	cout<<"Unsorted\n";
	
	for(int i=0; i<5; i++)
		cout<<a[i]<<", ";
	cout<<"\n";
	for(int i=0; i<5; i++)
		cout<<c[i]<<", ";
		
	sort<int>(a, 5);
	sort<char>(c, 5);
	
	cout<<"\n\nSorted\n";
	for(int i=0; i<5; i++)
		cout<<a[i]<<", ";
	cout<<"\n";
	for(int i=0; i<5; i++)
		cout<<c[i]<<", ";
	
	getch();
	return 0;
}

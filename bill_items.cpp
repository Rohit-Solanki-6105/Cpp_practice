#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
const int m = 50;

class order{
	int itemcode[m];
	float itemprice[m];
	int count;
	
	public:
		void cnt(){count = 0;}
		void getitem();
		void displaySum();
		void remove();
		void displayitems();
};

void order::getitem(){
	cout<<"Enter item code: ";
	cin>>itemcode[count];
	
	cout<<"Enter item cost: ";
	cin>>itemprice[count];
	count++;
}

void order::displaySum(){
	float sum = 0;
	for(int i = 0; i<count; i++){
		sum+=itemprice[i];
	}
	cout<<"Total Value: "<<sum<<endl;
}
void order::remove(){
	int a;
	cout<<"Enter Item code: ";
	cin>>a;
	
	for(int i = 0; i<count; i++){
		if(itemcode[i] == a){
			itemprice[i] = 0;
		}
	}
}

void order::displayitems(){
	cout<<"\nCode Price \n";
	for(int i = 0; i<count; i++){
		cout<<setw(4)<<itemcode[i]<<" "<<setw(5)<<itemprice[i]<<endl;
	}
	cout<<endl;
}

int main(){
	order o1;
	o1.cnt();
	
	int x;
	
	do{
		cout<<"\n------------------------------\n";
		cout<<"1. Add item"<<endl
			<<"2. Display Total Value"<<endl
			<<"3. Delete item"<<endl
			<<"4. Display all items"<<endl
			<<"0. exit"<<endl
			<<">";
		cin>>x;
		
		switch(x){
			case 1: o1.getitem(); break;
			case 2: o1.displaySum(); break;
			case 3: o1.remove(); break;
			case 4: o1.displayitems(); break;
			case 0: break;
			default: cout<<"Invalid option!"<<endl;
		}
	}while(x != 0);
	
	
	getch();
	return 0;
}

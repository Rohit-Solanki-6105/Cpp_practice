#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

// bank account
class bank_account{
	string name_of_depos;
	long int acc_num;
	string type_of_acc;
	float balance;
	
	public:
		bank_account(){}
		bank_account(string name, long int num, string type, float bal){
			name_of_depos = name;
			acc_num = num;
			type_of_acc = type;
			balance = bal;
		}
		
		void display(){
			cout<<"\n----------------------------------------\n"
				<<"Name of Depositor: "<<name_of_depos<<endl
				<<"Acc Num: "<<acc_num<<endl
				<<"Type of Acc: "<<type_of_acc<<endl
				<<"Balance: "<<balance<<endl
				<<"\n----------------------------------------\n";
		}
		
		// de
		void operator -(float val){ //withdraw
			if(val > balance){
				cout<<"\nNot sifficient balance\n";
			}
			else{
				balance = balance - val;
			}
		}
		
		void operator +(float val){// deposit
			balance+=val;
		}
};

int main(){
	bank_account a1("hi", 123, "savings", 1000);
	a1.display();
	
	cout<<"Withdraw";
	a1-10;
	a1.display();
	
	cout<<"Deposit";
	a1+20;
	a1.display();
	getch();
	return 0;
}

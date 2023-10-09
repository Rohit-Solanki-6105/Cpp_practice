/*8.2) modify the excercise 8.1 include constructors for all three classes*/
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

class Account{
	protected:
		string customer_name;
		long int acc_num;
		float amount;
		
	public:
		Account(){}
		Account(string c, long int a, float amt){
			customer_name = c;
			acc_num = a;
			amount = amt;
		}
		void display(){
			cout<<"Name: "<<customer_name<<"\n"
				<<"Account Num: "<<acc_num<<"\n"
				<<"Amount: "<<amount<<"\n";
		}
		
		void deposite_amount(float amt){
			amount+=amt;
		}
		
		void withdrawl(float amt){
			if(amount-amt < 0){
				cout<<"Insufficient Balance!!\n";
			} 
			else{
				amount-=amt;
			}
		}
};

class sav_acc:public Account{
	protected:
		float interest;
	
	public:
		sav_acc(){}
		sav_acc(string n, long int a, float amt, float i):Account(n, a, amt){
			interest = i;
			while(interest > 100){
				cout<<"Enter a Valid Interest Percentage: ";
					cin>>interest;
			}
			
			while(interest < 0){
				cout<<"Enter a Valid Interest Percentage: ";
					cin>>interest;
			}
		}
		void display(){
			
			cout<<"\n--------------------------------------------\n";
			Account::display();
			cout<<"Interest(%): "<<interest<<"\n";
			cout<<"Total Balance: "<<(amount*interest/100) + amount<<"\n";
			cout<<"Checkbook: No\n";
			cout<<"\n--------------------------------------------\n";
		}
};

class cur_acc:public Account{
	protected:
		float min_amt = 1000;
		float panalty = 5; // in %
		
		void check_amt(){
			if(amount < min_amt){
				cout<<"----------------------------\n";
				cout<<"Min Amt: "<<min_amt<<"\n"
					<<"Your Balance: "<<amount<<"\n"
					<<"Panulty(%): "<<panalty<<"\n";
				
				cout<<"----------------------------\n";
				amount =  amount - (amount*panalty/100);
			}
		}
	public:
		cur_acc(){}
		cur_acc(string n, long int a, float amt):Account(n, a, amt){
			check_amt();
		}
		
		void withdrawl(float amt){
			Account::withdrawl(amt);
			check_amt();	
		}
		
		void deposite_amount(float amt){
			Account::deposite_amount(amt);
			check_amt();
		}
		
		void display(){
			cout<<"\n--------------------------------------------\n";
			Account::display();
			cout<<"CheckBook: Yes\n";
			cout<<"\n--------------------------------------------\n";
		}
};


int main(){
	//savings account
	sav_acc a1("Hi", 123456, 1000, 10);
//	a1.set_data("Hi", 123456, 1000, 10);
	a1.display();
	a1.deposite_amount(100);
	a1.display();
	a1.withdrawl(10000);
	a1.withdrawl(500);
	a1.display();
	
	//current account
	cur_acc c1("Hello", 12478, 10000), c2("Test", 34590, 700);

	c1.display();
	c1.deposite_amount(123);
	c1.display();
	c1.withdrawl(456);
	c1.display();
	
	c2.display();
	c2.withdrawl(100);
	c2.display();
	c2.deposite_amount(500);
	c2.display();
	getch();
	return 0;
}

/*

--------------------------------------------
Name: Hi
Account Num: 123456
Amount: 1000
Interest(%): 10
Total Balance: 1100
Checkbook: No

--------------------------------------------

--------------------------------------------
Name: Hi
Account Num: 123456
Amount: 1200
Interest(%): 10
Total Balance: 1320
Checkbook: No

--------------------------------------------
Insufficient Balance!!

--------------------------------------------
Name: Hi
Account Num: 123456
Amount: 820
Interest(%): 10
Total Balance: 902
Checkbook: No

--------------------------------------------
----------------------------
Min Amt: 1000
Your Balance: 700
Panulty(%): 5
----------------------------

--------------------------------------------
Name: Hello
Account Num: 12478
Amount: 10000
CheckBook: Yes

--------------------------------------------

--------------------------------------------
Name: Hello
Account Num: 12478
Amount: 10123
CheckBook: Yes

--------------------------------------------

--------------------------------------------
Name: Hello
Account Num: 12478
Amount: 9667
CheckBook: Yes

--------------------------------------------

--------------------------------------------
Name: Test
Account Num: 34590
Amount: 665
CheckBook: Yes

--------------------------------------------
----------------------------
Min Amt: 1000
Your Balance: 565
Panulty(%): 5
----------------------------

--------------------------------------------
Name: Test
Account Num: 34590
Amount: 536.75
CheckBook: Yes

--------------------------------------------

--------------------------------------------
Name: Test
Account Num: 34590
Amount: 1036.75
CheckBook: Yes

--------------------------------------------
*/
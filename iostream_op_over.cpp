#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;
class test{
	char str[999];
	public:
		test(){}
		test(char s[999]){
			strcpy(str, s);
		}
		test(test &t){
			strcpy(str, t.str);
		}
		~test(){
			delete this;
			cout<<"\nDestroyed\n";
		}
		friend ostream &operator <<(ostream &, test &);
		friend istream &operator >>(istream &, test &);
};
istream & operator >>(istream &din, test &t){
	for(int i=0; i<999; i++){
		din>>t.str[i];
	}
	return(din);
}
ostream & operator <<(ostream &dout, test &t){
	for(int i=0;i<strlen(t.str);i++){
		dout<<t.str[i];
	}
	return(dout);
}
int main(){
	test t1,t2("hi"), t3;
	cout<<t2;
	cout<<"\n t1 >";
	cin>>t1;
	cout<<t1;
	
	t3 = t2;
	cout<<"\n"<<t3;
	getch();
	return 0;
}

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;
class gama{
	protected:
		int z;
	public:
		gama(){}
		gama(int a)
		{
			z=a;
		}
		int display(){
			return z;	
		}
};
class beta{
	int x;
	gama g;
	public:
		beta(){}
		beta(int a, int b):g(a)
		{
			x=b;
//			gama::z=a;	
		}
		void display(){
			cout<<"A: "<<g.display()<<"\n"
				<<"B: "<<x<<"\n";
		}
};

int main(){
	beta b(1,2);
	b.display();
	getch();
	return 0;
}

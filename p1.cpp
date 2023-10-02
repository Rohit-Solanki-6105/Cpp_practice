#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
/*write a program which does following:
1. compare 2 int for equality
2. compare 2 points for equality
3. compare 2 circles and display the larger circle
4. compare radius of a circle with length of a rectangle and display if = or !=
*/


class point{
	int x, y;
	
	public:
		point(){} // default constructor
		point(int a,int b){
			x = a;
			y = b;
		}
		
		// 2
		void operator ==(point p){
			if((p.x == x) && (p.y == y)){
				cout<<"Both points are equal"<<endl;
			}
			else{
				cout<<"Both points are not equal"<<endl;
			}
		}
};

// 4
void compare_length(circle c, float l){
	if(c.radius == l){
		cout<<"Circle radius and rectangle length are equal\n";
	}
	else{
		cout<<"Circle radius and rectangle length are not equal\n";
	}
}

class circle{
	float radius;
	public:
		circle(){}
		circle(float r){
			radius = r;
		}
		// 3
		int operator >(circle c){
			if(c.radius > radius){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		friend void compare_length(circle , float);
};

// 1
void compare_int(int a, int b){
	if(a==b){
		cout<<"Both are equal\n";
	}
	else{
		cout<<"Both are not equal\n";
	}
}
int main(){
	point p1(1,1), p2(1,1);
	p1==p2; // 2
	
	circle c1(1), c2(2);
	if((c1>c2) == 1){
		cout<<"C1 is larger\n";
	} 
	else if((c2>c1) == 1){
		cout<<"C2 is larger\n";
	}
	else{
		cout<<"C1 and C2 are equal";
	}
	
	compare_int(1,2);
	
	
	getch();
	return 0;
}

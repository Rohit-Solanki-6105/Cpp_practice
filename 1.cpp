#include <iostream>
using namespace std;

class square{
    int side;

    public:
        void set_side(int s){
          side = s;  
        }
        int calc_area(){
            return (side*side);
        }
        int calc_perimeter(){
            return (4*side);
        }
        int calc_volume(){
            return (side*side*side);
        }
};

int main(){
    square s1;
    int n;
    cout<<"Enter side: ";
        cin>>n;
        s1.set_side(n);
    cout<<"Area: "<<s1.calc_area()<<endl;
    cout<<"Perimeter: "<<s1.calc_perimeter()<<endl;
    cout<<"Volume: "<<s1.calc_volume()<<endl;
    return 0;
}
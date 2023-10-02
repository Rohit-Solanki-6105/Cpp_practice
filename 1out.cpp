#include <iostream>
using namespace std;

class square{
    float side;

    public:
        void set_side(float s);
        float calc_area();
        float calc_perimeter();
        float calc_volume();
};
void square::set_side(float s){
    side = s;  
}
float square::calc_area(){
    return (side*side);
}
float square::calc_perimeter(){
    return (4*side);
}
float square::calc_volume(){
    return (side*side*side);
}

int main(){
    square s1;
    float n;
    cout<<"Enter side: ";
        cin>>n;
        s1.set_side(n);
    cout<<"Area: "<<s1.calc_area()<<endl;
    cout<<"Perimeter: "<<s1.calc_perimeter()<<endl;
    cout<<"Volume: "<<s1.calc_volume()<<endl;
    return 0;
}
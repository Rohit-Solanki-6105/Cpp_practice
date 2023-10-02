#include <iostream>
using namespace std;

enum shapes{// category
    circle, // can define specific number using = , ex circle = 5
    square,
    rectangle,
    triangle
};

int main(){
    // int code;
    enum shapes s;
    cout<<"Enter shape: ";
    cin>>s; // we can enter name of shape or number of index

    switch (s){

    case circle:
        cout<<"Entered Circle";
        break;
    
    case square:
        cout<<"Entered square";
        break;

    case rectangle:
        cout<<"Entered Rect";
        break;
    
    case triangle:
        cout<<"Entered Triangle";
        break;

    default:
        cout<<"Invalid";
        break;
    }
    cout<<"\n-------------------------------------\n";
    for(int i=0; i<3; i++){ //declaring var inside loop
        cout<<i<<endl;
    }
    return 0;
}
/*
Enter shape: circle
Entered Circle
-------------------------------------
0
1
2
_________________________________________________
Enter shape: 1
Entered square
-------------------------------------
0
1
2
*/
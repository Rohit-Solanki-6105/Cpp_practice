#include <iostream>
using namespace std;

class student{
    int marks;
    char name[20];

    public:
        void getdata(void);
        void displaydata(void);
        char findname(void);
};

void student::getdata(void){
    cout<<"name: "<<endl;
    cin>>name;
    cout<<"marks"<<endl;
    cin>>marks;
}

void student::displaydata(void){
    cout<<"Name: "<<name<<endl;
    cout<<"Marks: "<<marks<<endl;
}
char student::findname(void){
    
}

int main(){
    student s1;
    s1.getdata();
    s1.displaydata();
    return 0;
}
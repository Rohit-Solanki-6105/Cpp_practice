#include <iostream>
#include <conio.h>
//#include <stdio.h>
using namespace std;

class emp{
    float salary,gross_sal,net_sal,reductions;
    float hra,pf,da;
    float pt1,pt2,it;

    public:
        void set_data(){
            cout<<"Salary: ";
            cin>>salary;
            cout<<"da: ";
            cin>>da;
            cout<<"hra: ";
            cin>>hra;
            cout<<"pf: ";
            cin>>pf;
            cout<<"pt1: ";
            cin>>pt1;
            cout<<"pt2: ";
            cin>>pt2;
            cout<<"it: ";
            cin>>it;
            calc_gross();
            calc_net();
        }
        void calc_gross(){
            gross_sal = salary+hra+pf+da;
        }
        void calc_net(){
            reductions = pt1+pt2+it;
            net_sal = gross_sal - reductions;
        }
        float get_sal(char op){
            if(op == 'g'){
                return gross_sal;
            }
            else if(op == 'r'){
                return reductions;
            }
            else if(op == 'n'){
                return net_sal;
            }
        }
};

int main(){
    // int a,b,c;
    // cin>>a>>b;
    // cout<<a+b;
    emp e;
//    system("color f0");
    e.set_data();
    cout<<"Gross sal: "<<e.get_sal('g')<<endl;
    cout<<"Reductions: "<<e.get_sal('r')<<endl;
    cout<<"Net sal: "<<e.get_sal('n')<<endl;
    
    getch();
    return 0;
}
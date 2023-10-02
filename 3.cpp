#include <iostream>
using namespace std;

int main(){

    void *vp; // can't be derefference
    int *ip, a, *ptr;
    a = 10;
    ip = &a;
    cout<<"a: "<<a << " Ip: "<< *ip<< endl;
    vp = ip;
    // printf("vp : %d", *vp);
    cout<<"vp: "<<vp<<endl;
    cout<<"*((int *)vp): "<<*((int *)vp)<<endl;
    ptr = (int *)vp;
    cout<<"Ptr = *(int *)Vp : "<<*ptr<<endl;
    cout<< "Sizeof(char): "<<sizeof(char)<<endl<<"Sizeof(wchar_t): "<<sizeof(wchar_t)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

class A {
    public:
    int x;
    
    A()
    {cout<<"a ctor"<<endl;}

    A(const A& in){
        this->x=in.x;
        cout<<"a copy ctor"<<endl;
    }
    
    operator int() { 
        return x; 
    }
};

class B {
    public:
    A y;
    operator A() { 
        return y; 
    }
    operator A&() {
        cout<<"ref called"<<endl;
        return y;
    }
};

int main () {
    B b_obj;
    cout<<"b inited"<<endl;
    b_obj.y.x=2;
    //  int i = b_obj;
    A&& a = A(b_obj);
    a.x=3;
    cout
        << a.x
        << endl;

}

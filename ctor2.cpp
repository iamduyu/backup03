#include <iostream>
#include <vector>
using namespace std;

struct Two;

struct One {
 char o='z';
 
 One(){
    cout << "One()" << endl;
 }
 
 //init by two
 /*
 One(Two&){
     o='o';
    cout
        << "One::One(Two&)"
        << endl;
 }
 */

 //copy init
 One(const One& o){
     if( o.o == 'o') {
        this->o = 'p';
     }else
         this->o ='o';
    cout
        << "One::One(One&)"
        << endl;
 }

};

struct Two {
    // default ctor
    Two(){
        cout << "Two()" << endl;
    }

    // convertor, fron Two to One;
    
    operator One() {
        cout << "Two::One()" << endl;
    }
    
};

int main(void) {
    
    Two t;
    cout << "-------------pre convention -------------" << endl;

    // 1) call Two::One() convertor
    // 2) call One::Two() convertor;
    One o = t;
 
    // if 1) then NO CTOR of one will be called
    // the new One object is "naked" (only GCC, msvc will force you to return a value from Two::One())
    cout << o.o << endl;

    //One o(t);
    // only ctor be called
    //One o = t;

    //cout
    //    << o.o
    //    << endl;


    // vector test

    //vector<One> v(10,One());

    //cout << v.at(0).o << endl;

    //v.push_back(o);

    //vector<two> v;
    
}

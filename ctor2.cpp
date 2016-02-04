#include <iostream>
#include <vector>
using namespace std;

struct Two;

struct One {
 char o;
 One(){
    cout << "One()" << endl;
 }
 One(Two&){
     o='o';
    cout
        << "One(Two&)"
        << endl;
 }
 One(const One& o){
     if( o.o == 'o') {
        this->o= 'p';
     }else
         this->o='o';
    cout
        << "One(One&)"
        << endl;
 }
};

struct Two {

};

int main(void) {
    
    One o;
    Two t;
    //One o(t);
    // only ctor be called
    //One o = t;

    //cout
    //    << o.o
    //    << endl;


    // vector test

    vector<One> v {o};
    cout << v.at(0).o << endl;

    //v.push_back(o);
}

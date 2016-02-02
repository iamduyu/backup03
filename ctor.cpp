#include <iostream>
#include <typeinfo>
using namespace std;


class Ctor {
    public:
        int m;
    public:
        Ctor() {
           cout
               << "ctor default"
               << endl;
        }

        // ctor int, also can be used "convert from"
        Ctor(int in) {
            cout 
                << "ctor int"
                << endl;
        }

        Ctor(Ctor& in) {
            cout
                << "ctor copy"
                << endl;
        }

        Ctor(const Ctor& in) {
            cout
                << "ctor, dup copy"
                << endl;
        }

        // assigment, int
        Ctor& operator= (int) {
            cout
                << "assignment from int"
                << endl;
        }

        // assigment, same ref
        Ctor& operator= (const Ctor& in) {
            cout 
                << "assigment ="
                << endl;

            //implicit return *this
            return *this;
        }

        // functor, int
        Ctor& operator()(int in) {
            cout
                << "functor(int) called"
                << endl;
            return *this;
        }
    
        // convertor, to int
        operator int() {
            cout
                << "convetor to int called"
                << endl;
             return 0;          
        }
};


Ctor ret() {
    // don't know
    return {};
}


int main() {
    
    //const Ctor& one = Ctor();
    
    // 
    // Ctor two = one ; //error, you have to EXPLICITY call constructor
    //Ctor two(one);
    //two.m=998;
    
    // this will call real assignment operator
    //Ctor tree(two = one);
    //cout
    //    << two.m
    //    << endl;

    //ret();
    
    //Ctor a=3;
    //a=4;

    //Ctor b{5};
    //Ctor c = {6};


    Ctor e;
    e(3);
    int i = (int)e;
    int j = static_cast<int>(e);
    //int* k = reinterpret_cast<int>(e);

    return 0;
}

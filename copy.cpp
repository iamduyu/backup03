#include <iostream>
using namespace std;

// translation unit private namespace
namespace{
    int count = 0;
}


class One {
    public:
        // default constructor
        One(){
        }
        
        // copy constructor
        One(const One&){

            count++;

            cout
                << " I'm copied"
                << endl;
        }

        void foo() {
            cout
                << "foo"
                << endl;
        }
};

// test return value

One creator() {
    return One();
}


One creator2() {
    One* tmp=new One();
    return *tmp;
}


// test pass by val v.s. ref

void byValue(One val) {
}

void byRef(One& ref) {
    
}


// test return ref, just says: we could be bind to a reference, only if you are reference too :)

One& retRef(One& ref) {
    //return ref;
}

One& retRef2() {
}

int main(int argc, char** argv) {
    
    // 
    // One obj=creator();
    
    // becuase the function returns by value, 
    // so compiler will generator a rvalue (temprary object)
    // it's not the same with *tmp, is purely rvalue
    // why we have to be const refenrece to ref an rvalue ?
    //const One& obj2=creator2();
    // cout
    //    << count
    //   << endl;
    

    // pass by value
    One tmp;
    //byValue(tmp);
    //byRef(tmp);

    //One& tmp2=retRef(tmp);
    auto tmp3=retRef2();
    //tmp3.foo();

    // rvalue ref syntax
    //int&& rv = 100;

    //cout
    //    << rv
    //    << endl;

    return 0;
}

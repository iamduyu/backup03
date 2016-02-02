#include <iostream>
#include <functional>
#include <type_traits>
using namespace std;

class Functor {
    public:
        // the (*) indicate a funcion pointer, 
        // prefix is the return, postfix is the arguments
        typedef void(*fp)(int);

        // this is actually a convertor
        operator fp() const {
            cout
                << "fp get called"
                << endl;
        }

        // maybe, this function will be called
        void operator()(int) {
            cout
                << "real inner func get called"
                << endl;
        }

};


void caller(Functor::fp f) {
    f(1);
}


int main(int argc, char** argv) {
    
    Functor f;
    caller(f);


    /*
    Functor::fp pFunc = nullptr;
    Functor f;
    pFunc=f;
    //f(1);
    
    cout
        << pFunc
        << endl

        << boolalpha
        << typeid(pFunc).name()
        << endl
        << is_pointer<decltype(pFunc)>::value
        << endl
        << is_function<decltype(f)>::value
        << endl
        << is_function<decltype(boolalpha)>::value
        << endl;

    //pFunc(1);
    */
}

#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>
#include <typeinfo>

using namespace std;

class Poco {
    public:
        int a;

        // legal ?
        void func(decltype(a) i){
            cout
                << "i'm ok"
                << endl;
        }
        
        Poco():a(1) {
            cout
                << "default ctor is called"
                << endl;
        }

       // Poco(Poco&& in){
       //     cout
       //         << "move ctor is called"
       //         << endl;
       //}


        Poco(const Poco&) {
            cout
                << "copy ctor is called"
                << endl;
        }

        Poco& getRef() {
            return *this;
        }

        int& getA() {
            return a;
        }
};



int main(int argc, char** argv) {
    
    // return reference means return the exact the refrenced object
    // not a copy, not a pointer
    //Poco one;
    //const int& b = one.getA();
    //cout
    //    << one.a
    //    << endl;
    
    //Poco one{};
    //Poco two{};
    //auto three(two);
    //auto four(Poco{});
    //two.a=3;

    //cout
    //    << one.a << endl
    //    << two.a << endl;


    //auto tmp 
    //    = make_unique<Poco>();
    //tmp->a=3;
    //tmp->func(3);
    //cout
        //<< tmp->a
        //<< endl;


    vector<int> v{2,3,1};
    array<int,3> arr{1,2,3};

    // itor is also a kind of object who minic pointer too!
    auto z=find(
        begin(v),
        end(v),
        3
    );

    //cout
        //<< *z << endl
        //<< arr[0] << endl
        //<< v[0]
        //<< endl;

    // lambda isn't a function, they just functor
    auto lm = []{
        cout
            << " i'm lambda! "
            << endl;
    };

    decltype(lm)& lm2 = lm;

    //lm();
    //lm2();

    //assert(0);
  
    // lambda as function pointer.
    typedef int(*ft)(int);

    ft f = nullptr;

    auto lm3 =[](int a) {
        cout
            << "lambda as real function pointer"
            << endl;
        return 1;
    };
    //f = lm3;
    //f(1);
    
    // type info
    cout
        << typeid(lm3).name()
        << endl;

    R"("test")";
}

void test() throw() {
    ;
}

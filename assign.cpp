#include <iostream>
#include <typeinfo>
using namespace std;

class Foo;
class Third;

class Bar {
    public:
        int b=102;
        
        // default ctor
        Bar() {
            this->b =5;
            cout
                << "default bar ctor"
                << endl;
        }

        // copy ctor
        Bar(const Bar& b) {
        
            cout
                << "bar copy ctor" << endl
                << "this->b\n"
                << this->b
                << endl;

            cout
                << "Bar::b\n"
                << b.b
                << endl;
        }

        // copy assign
        const Bar& operator= (const Bar& b) {
                this->b = b.b;
            cout
                << " copy assign? " << endl
                << "this->b\n"
                << this->b << endl
                << "b.b=\n"
                << b.b
                << endl;
        }

        const Bar& operator= (const Third& f);
    
        
};

class Foo {
    private:
        int p;
    public:
        int m;

        // ctor default
        Foo() {
            this->p=2;
            this->m=3;
            cout
                << "default ctor"
                << endl;
        }

        // ctor copy
        Foo(Foo&) {
            cout
                << "copy ctor"
                << endl;
        }

        // converor for Bar
       
        /*
        operator Bar&() {
            cout
                << "cvt to Bar&"
                << endl;
        }
        */
        

        operator Bar() {
            cout
                << "cvt to Bar without &"
                << endl;
        }

        // op assign
        void operator= (const Foo& ori) {
            cout
                << "assign from Foo&"
                << endl;
        }

        void setp(int p) {
            this->p=p;
        }
        int getp() {
            return this->p;
        }

};

class Third {
    
};

// this is first chose by the compiler
const Bar& Bar::operator= (const Third& f) {
    b=3;
    cout
        << "first chose, direct foo to bar"
        << endl;
}


int main(int argc, char** argv) {
    
    // only call default ctor, operator assign will called

    //Foo a, b;
    //a.m = 1, b.m = 2;

    // set p
    //a.setp(20), b.setp(30);
    
    //cout
    //    << a.getp() << endl 
    //    << b.getp() << endl;
    
    // assign a to b
    //a = b;

    //cout
    //    << a.getp() << endl 
    //    << b.getp() << endl;

    // trigger copy ctor
    //auto c = a;

    //Bar test;

    Foo foo;
    Bar bar;
    cout << endl << endl << endl;
    bar.b=999;
    //bar = (Bar)c;
    //bar = c;
    
    // call Foo::operator Bar(), then call Bar::operator= (Bar&)
    // but this path is undifined, don't do it, just define the real assign op, from Foo to Bar.
    // then just one function call.
    bar = foo;


    //Third tr;
    //bar = tr;

    cout
        << "bar.b=\n"
        << bar.b
        << endl;

    //cout
        //<< typeid(bar).name()
        //<< endl;

}

#include <iostream>
using namespace std;
template<class T> void ignore( const T& ) { }

struct A
{
    A(int) {
        cout << "A(int)" << endl;
    }      // converting constructor
    A(int, int) { 
        cout << "A(int,int)" << endl;
    } // converting constructor (since C++11)
};
 
struct B
{
    explicit B(int) { }
    explicit B(int, int) { }
};
 
int main()
{
    A a1 = 1;      // OK: copy-initialization selects A::A(int)
    cout << "------" << endl;
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3{4, 5};    // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast, direct-initialization
 
//  B b1 = 1;      // error: copy-initialization does not consider B::B(int)
    B b2(2);       // OK: direct-initialization selects B::B(int)
    B b3{4, 5};    // OK: direct-list-initialization selects B::B(int, int)
//  B b4 = {4, 5}; // error: copy-list-initialization does not consider B::B(int, int)
    B b5 = (B)1;   // OK: explicit cast performs static_cast, direct-initialization
    
    ignore(a1);
    ignore(a2);
    ignore(a3);
    ignore(a4);
    ignore(a5);
    ignore(b2);
    ignore(b5);
    
}


#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

// tempate st
template <int n>
struct st {
    int a=n;
};

// partcial st
template <>
struct st<0> {
    int a=3;
    void func() {
        a=4;
    }
};

int main(void) {

    // template is the same, then the type? 
    st<0> obj;
    obj.func();
    st<12> obj2;
    cout
        << obj.a << endl
        << obj2.a << endl;
    cout
        << typeid(obj).name() << endl
        << typeid(obj2).name() << endl;
    
    cout
        << boolalpha
        << is_same<decltype(obj),decltype(obj2)>::value << endl
        << is_convertible<decltype(obj),decltype(obj2)>::value
        << endl;
}

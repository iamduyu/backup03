#include <iostream>
#include <typeinfo>

using namespace std;


int main(int argc, char** argv) {
    int i = 1;
    int& j = i;

    cout
        << typeid(decltype(i)).name()
        << endl;

    cout
        << typeid(decltype(j)).name()
        << endl;
}

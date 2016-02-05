#include <iostream>
using namespace std;

struct One {
};

struct Two {
    Two(){
        cout << "Two::Two()" << endl;
    }
    Two(One& o) {
        cout << "Two::Two(One&)" << endl;
    }
};

int main(void) {
    One o;
    Two t = o;
}

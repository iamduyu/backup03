#include <iostream>
using namespace std;

struct Two;
struct Three;

struct One {
    operator Two();
};

struct Two {
    Two()=default;
    Two(One&){
    }
};

struct Three {
    Three(){
        cout << "three default" << endl;
    }
    Three(Two&){
        cout << "from two" << endl;
    }
    Three(Three& t){
        cout << "Three&" << endl;
    }
    Three(Three&& t){
        cout << "Three&&" << endl;
    }

    operator Three&&(){
        cout << "op th && " << endl;
    }

    Three& operator= (Three&) {
        cout << "three op" << endl;
    }
    
    Three& operator= (Three&&) {
        cout << "three op" << endl;
    }
};

One::operator Two(){
};

int main(void) {
    One o;
    Two t;
    Three r = t;
    Three r2;
    Three&& r3 = (Three&&)r;
    return 0;
}

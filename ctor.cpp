#include <iostream>
using namespace std;

struct One;

struct Two{
    int id;
    Two();
    explicit Two(One& o);
    Two(Two& t);
    operator One();
};

struct One {
    Two t;
	One(){
		//cout << "One::One()" << endl;
	}
	One(Two& t);
	One(One& o){
		cout << "One::One(One&)" << endl;
	}

    // it's also a normal function, Two&() diff from Two()
    operator Two&();
};


Two::Two(){
    cout << "Two::Two()" << endl;
}

Two::Two(Two&){
    cout << "Two::Two(Two&)" << endl;
}

Two::Two(One& o) {
    cout << "Two::Two(One&)" << endl;
}

Two::operator One() {
    cout << "Two::operator One()" << endl;
}


One::One(Two& t)
{
	cout << "One::One(Two&)" << endl;
}

One::operator Two&() {
    cout << "One::operator Two&()" << endl;
    return t;
}


int main(void) {
    One o;
    o.t.id=3;
    cout << "------start test----------" << endl;

    Two t = o;
    cout << t.id << endl;
    t.id=4;
    cout << o.t.id << endl;
}

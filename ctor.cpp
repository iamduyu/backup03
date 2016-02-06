#include <iostream>
using namespace std;

struct One;

struct Two{
    int id;
    Two();
    //explicit 
		Two(One& o);
    Two(Two& t);
	Two(Two&& t){
		cout << "Two::Two(Two&&)" << endl;
	}
    operator One();
	operator Two&(){
		cout << "Two::operator Two&()" << endl;
	}
	operator Two&&(){
		cout << "Two::operator Two&&()" << endl;
	}
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
    explicit operator Two&();
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
	// msvc force a return value, while gcc needn't.
	return *(new One);
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



    // this means you need a new object
    //Two t = o;

    // this means you need a exist object
    // also, the One::operator Two&() show return a ref
    // or you get a rvalue of One;
    // Two& t = static_cast<Two&>(o);
	// Two& t = (Two&)o;
	// Two& t = Two(o);
	Two& t = (Two&)(o);
	// Two& t = (Two)o;
	// Two t(o);

	Two r2 = move(t);



	// string str = "ok";
	// string str2 = static_cast<string&&>(str);

    cout << t.id << endl;
    t.id=4;
    cout << o.t.id << endl;
}

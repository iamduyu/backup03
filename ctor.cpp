#include <iostream>
using namespace std;

struct Two;

struct One {
	One(){
		//cout << "One::One()" << endl;
	}
	One(Two& t);
	One(One& o){
		cout << "One::One(One&)" << endl;
	}
};



struct Two {
    Two(){
        cout << "Two::Two()" << endl;
    }
    Two(One& o) {
        cout << "Two::Two(One&)" << endl;
    }
};


One::One(Two& t)
{
	cout << "One::One(Two&)" << endl;
}

int main(void) {
    One o;
    Two t = (Two)o;
}

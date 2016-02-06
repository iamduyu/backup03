#include <iostream>
using namespace std;

struct To;

void func(struct To&);

struct To {

	friend void func(struct To&);

    To(){
        cout << "To" << endl;
		func(*this);
    }
    To(const struct From const &) {
        cout << "To::To(From&)" << endl;
    } // converting constructor

    To(const To&){
        cout << "copy ctor" << endl;
    }
};
 
struct From {
    
    //less const will win! in overload selection

    operator To() {
        cout << "From operator To" << endl;
        return To();
    } // conversion function
};

void func(struct To&){
	cout << "func" << endl;
}
 
int main()
{
    From f;
    //To t1(f); // direct-initialization: calls the constructor
    // (note, if converting constructor is not available, implicit copy constructor
    //  will be selected, and conversion function will be called to prepare its argument)
    To t2 = move(f); // copy-initialization: ambiguous
    // (note, if conversion function is from a non-const type, e.g.
    //  From::operator To();, it will be selected instead of the ctor in this case)
    //  ����msvcȴѡ��ctor������gcc��ѡ��ͬ�ķ���������������һ��
    //  ����������֮���ת����Ҫ���ö���ת��·�������������Ҳ���в�ͬ��ѡ��
    //To t3 = static_cast<To>(f); // direct-initialization: calls the constructor
    //const To& r = f; // reference-initialization: ambiguous
    //
    
    short s = 0;
    const int& i = s;
}

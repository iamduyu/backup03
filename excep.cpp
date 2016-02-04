#include <iostream>
#include <exception>
#include <functional>
#include <string>
using namespace std;

class e2 : public exception {
    public:
        // stor lambda
        function<void()> f;
        
        // this exception's `what`
        string say;
        
        e2(const function<void()>& f) {
            this->f = f;
            say=R"("hi, brother, I shoud say, this is not a good way to do it")";
        }

        const char* what() {
           this->f();
           return  say.c_str();
        }
};

void func() /*noexcept*/ {
    throw e2(
        function<void()>(
            []{
                cout
                    << "lambda throw"
                    << endl;
            }
        )
    );
}


int main(void) {
    try {
        func();
    } catch(e2& e) {
        cout
            << e.what() 
            << endl
            << "catched"
            << endl;
    }
    return 0;
}

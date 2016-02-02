// example for iostream
// cout :
//    osteam cout(stdout)
// where stdout:
//    FILE* stdout

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// example for file steam
// there are no pre defined object like iostream
#include <fstream>
using std::ofstream;
using std::ios;

// rtti example
#include <typeinfo>


// string
#include <string>
using std::string;

int main() {
    
    // iostream
    //cout
    //    <<"ok"
    //    <<endl;

    //char c;
    //cin.get(c);
    //cout
    //    <<c
    //    <<endl;
    
    // file stream
    ofstream fs("test.txt",ios::out);
    fs<<"ok"<<endl;
    fs.close();

    // rtti test
    //cout
    //    << typeid(decltype(endl)).name();
    cout
        <<typeid(char).name()
        <<endl;

}

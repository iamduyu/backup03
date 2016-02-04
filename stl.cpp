#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    
    // vector

    vector<string> thing {
        "thing1",
        "thing2"
    };

    cout << thing[0] << endl;

    
    // std::move
    
    string str1 = "str1";
    string str2 = move(str1);

    cout
        << str1
        << str2
        << endl;


}

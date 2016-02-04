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
    
    string str1 = "who_owns_me?";
    string str2 = move(str1);

    cout
        << boolalpha
        << str1 << endl
        << str2 << endl
        << str1.empty() << endl
        << str2.max_size() << endl
        << str2[1] << endl
        << endl;
}

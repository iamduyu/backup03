#include <iostream>
#include <strstream>

using namespace std;


int main() {

    ostrstream ss;
    ss
        << "ok"
        << endl;
    cout
        << ss.str()
        << endl;

    return 0;
}

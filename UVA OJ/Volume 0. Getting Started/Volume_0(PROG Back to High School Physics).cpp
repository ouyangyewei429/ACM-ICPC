/*
PROG:   Back to High School Physics
ID  :   ouyangyewei
LANG:   C++
*/
#include <iostream>
using namespace std;

namespace {

int v, t;

}// namespace

int main() {
    // v0 = 0, vt = v0 + a * t
    // S = v0*t + 1/2 * a * t^2
    while (cin >> v >> t) {
        cout << 2 * v * t << endl;
    }
    
    return 0;
}

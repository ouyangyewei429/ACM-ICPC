/*
PROG:   10055 - Hashmat the Brave Warrior
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

namespace {

long long hashmat, enemy;

}// namespace

int main() {
    while (cin >> hashmat >> enemy) {
        if (hashmat-enemy >0) {
            cout << hashmat-enemy << endl;
            
        } else {
            cout << enemy-hashmat << endl;
        }
    }// End of while
    
    return 0;
}

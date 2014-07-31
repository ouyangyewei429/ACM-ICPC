/*
PROG:   The Decoder
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

namespace {

char c;

}// namespace

int main() {
#if DEBUG
    freopen("E:\\decoder.in", "r", stdin);
    freopen("E:\\decoder.out", "w", stdout);
#endif

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            printf("%c", c-7);
            
        } else {
            printf("%c", c);
        }
    }// End of while
    
    return 0;
}

/*
PROG:   Faulty Odometer
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const char numtri[10] = {0, 1, 2, 0, 3, 4, 5, 6, 0, 7};

void Trans(char speed[], long &ans) {
    int slen = strlen(speed);
    
    ans = 0;
    for (int i = 0; i < slen; ++i) {
        ans  = (ans << 3) + numtri[speed[i] - '0'];
    }
}

int main() {
    char speed[20];
    long ans;
    
    while (~scanf("%s", &speed) && speed[0] != '0') {
        Trans(speed, ans);
        printf("%s: %ld\n", speed, ans);
    }// End of while
    
    return 0;
}

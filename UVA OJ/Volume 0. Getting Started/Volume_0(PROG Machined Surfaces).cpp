/*
PROG:   Machined Surfaces
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int countX(string ss, int &maxValue) {
    int ret = 0;
    int len = ss.length();
    
    for (int i = 0; i < len; ++i) {
        if (ss[i] == 'X') {
            ++ret;
        }
    }
    if (maxValue < ret) {
        maxValue = ret;
    }
    
    return ret;
}// countX

int main() {
    string lines;
    int images, sum, maxValue;
    
    while (cin >> images && images!=0) {
        getchar();
        
        sum = 0;
        maxValue = -1;
        for (int i = 0; i < images; ++i) {
            getline(cin, lines);
            sum += countX(lines, maxValue);
        }
        
        printf("%d\n", maxValue * images - sum);
    }// End of while

    return 0;
}

/*
PROG:   Rotating Sentences
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

namespace {

const int maxn = 102;

int row, col, slen;
char matrix[maxn][maxn];

inline void ReadData() {
    for (row = 0, col = -1; gets(matrix[row]); ++row) { // row
        slen = strlen(matrix[row]);
        if (col < slen) {
            col = slen;
        }
    }
}// ReadData

void Solve() {
    for (int i = 0; i < col; ++i) {  // row
        for (int j = row - 1; j >= 0; --j) {  // col
            if (i >= strlen(matrix[j])) {
                printf(" ");
            } else {
                printf("%c", matrix[j][i]);
            }
        }
        
        printf("\n");
    }
}// Solve

}// namespace

int main() {
#if DEBUG
    freopen("E:\\490.in", "r", stdin);
    freopen("E:\\490.out", "w", stdout);
#endif

    ReadData();
    Solve();

    return 0;
}

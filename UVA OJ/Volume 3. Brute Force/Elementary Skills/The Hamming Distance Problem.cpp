/*
PROG:   The Hamming Distance Problem
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 18;

int testCases, N, H, hamNums;
int C[MAXN][MAXN] = {0};

void debug() {
    for (int N = 1; N < MAXN; ++N) {
        for (int M = 0; M < MAXN; ++M) {
            printf("%6d", C[N][M]);
        }
        printf("\n");
    }
}

void combine() {
    for (int N = 1; N < MAXN; ++N) {
        for (int M = 0; M < MAXN; ++M) {
            if ( M > N ) {
                C[N][M] = 0;
            } else if ( M == 0 || M == N ) {
                C[N][M] = 1;
            } else {
                C[N][M] = C[N - 1][M] + C[N - 1][M - 1];
            }
        }
    }
    // debug();
}

bool isHamming(int x) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if ( (x & (1 << i)) ) {
            ++cnt;
        }
    }
    return cnt == H;
}

void display(int x) {
    char str[MAXN];
    int bits = 0;
    
    while ( x ) {
        str[ bits++ ] = (x % 2) + '0';
        x >>= 1;
    }
    for (int i = 0; i < N - bits; ++i) {
        printf("0");
    }
    for (int i = bits - 1; i >= 0; --i) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void solve() {
    int low = (1 << H) - 1;
    int high = (1 << N) - 1;
    
    hamNums = 0;
    for (int i = low; hamNums < C[N][H]; ++i) {
        if ( isHamming( i ) ) {
            ++hamNums;
            display( i );
        }
    } 
}

int main() {
    combine();
    
    scanf("%d", &testCases);
    while ( testCases-- ) {
        scanf("%d %d", &N, &H);
        solve();
        if ( testCases > 0 ) {
            printf("\n");
        }
    }// End of while
    
    //system("pause");
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10596494 	729 	The Hamming Distance Problem 	Accepted 	C++ 	0.152 	2012-09-13 05:19:50
*/

/*
PROG:   humble(Accept)
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <memory.h>

using namespace std;

#define INF 0x7FFFFFFF

namespace {

const int MAXN = 102;
const int MAXK = 100002;

long MinValue, hum[MAXK];
int N, K, nhums, minp, S[MAXN], pindex[MAXK];

}// namespace

void ReadData() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
}// ReadData

// Pseudocode:
//      for each prime p
//          find the minimum humble number h
//              such that h * p is bigger than the last humble number
//
//      take the smallest h * p found: that's the next humble number        
void Solve() {
    hum[nhums++] = 1;
    for (int i = 1; i < N; ++i) {
        pindex[i] = 0;
    }
    
    while (nhums < K+1) {
        minp = -1;
        MinValue = INF;
        for (int j = 0; j < N; ++j) {
            while ((double)S[j] * hum[pindex[j]] <= hum[nhums-1]) {
                ++pindex[j];  // record what h is
            }
            
            if ((double)S[j] * hum[pindex[j]] < MinValue) {
                minp = j;
                MinValue = S[j] * hum[pindex[j]];
            }
        }
        
        hum[nhums++] = MinValue;
        ++pindex[minp];
    }
    
    cout << hum[K] << endl;
    return ;
}// Solve

int main() {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    
    ReadData();
    Solve();
    
    return 0;
}
/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 3992 KB]
   Test 2: TEST OK [0.000 secs, 3992 KB]
   Test 3: TEST OK [0.000 secs, 3992 KB]
   Test 4: TEST OK [0.011 secs, 3992 KB]
   Test 5: TEST OK [0.011 secs, 3992 KB]
   Test 6: TEST OK [0.043 secs, 3992 KB]
   Test 7: TEST OK [0.000 secs, 3992 KB]
   Test 8: TEST OK [0.000 secs, 3992 KB]
   Test 9: TEST OK [0.000 secs, 3992 KB]
   Test 10: TEST OK [0.000 secs, 3992 KB]
   Test 11: TEST OK [0.011 secs, 3992 KB]
   Test 12: TEST OK [0.119 secs, 3992 KB]

All tests OK.
Your program ('humble') produced all correct answers!  This is your
submission #17 for this problem.  Congratulations!
*/

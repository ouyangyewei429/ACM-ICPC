/*
PROG:   The Collatz Sequence
ID  :   ouyangyewei
LANG:   C++
*/
#include <memory.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define DEBUG 0

namespace {
    
bool NotHaveSame;
int A, L, cnt, caseNums = 1;

}// namespace

int main() {
#if DEBUG
    freopen("E:\\694.in", "r", stdin);
    freopen("E:\\694.out", "w", stdout);
#endif

    while (~scanf("%d %d", &A, &L), A+L!=-2) {
        printf("Case %d: A = %d, limit = %d, number of terms = ",
                caseNums++, A, L);
                
        vector<int> data;
        data.push_back(A);
        cnt = 1, NotHaveSame = true;
        while (NotHaveSame) {
            if ((A & 1) == 1) {  // A is an odd
                A = A * 3 + 1;
                if (A > L || A < 1) {  // 越界或溢出 
                    break;
                } else {
                    ++cnt;
                }
            } else {  // A is an even 
                A >>= 1;
                if (A == 1) {  // A == 1
                    ++cnt;
                    break;
                } else {
                    ++cnt;
                }
            }
            
            int vSize = data.size();
            for (int i = 0; i < vSize; ++i) {
                if (data[i] == A) {  // if A is exist in vector 'data'
                    NotHaveSame = false;
                    break;
                }
            }
            
            data.push_back(A);
        }// simulation
        
        printf("%d\n", cnt);
    }// End of while

    return 0;
}

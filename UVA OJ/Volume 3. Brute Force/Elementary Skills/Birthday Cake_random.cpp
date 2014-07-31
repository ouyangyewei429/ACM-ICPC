/*
PROG:   Birthday Cake
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

typedef pair<int, int> PII;
typedef vector<PII> VPII;

int main() 
{
#if DEBUG
    freopen("E:\\10167.in", "r" ,stdin);
    freopen("E:\\10167.out", "w", stdout);
#endif

    VPII p;
    int nNums, x, y;
    
    while (~scanf("%d", &nNums) && nNums) {
        p.clear();
        for (int i = 0; i < nNums * 2; ++i) {
            scanf("%d %d", &x, &y);
            p.push_back( make_pair(x, y) );
        }
        
        bool isSolved = false;
        for (int A = -500; A <= 500; ++A) {
            for (int B = -500; B <= 500; ++B) {
                int pAbove = 0, pBelow = 0;
                for (int k = 0; k < nNums * 2; ++k) {
                    int val = A * p[k].first + B * p[k].second;
                    if ( val > 0 ) {
                        ++pAbove;
                    }
                    else if ( val < 0 ) {
                        ++pBelow;
                    }
                }// loop 3
                if ( pAbove == nNums && pBelow == nNums ) {
                    isSolved = true;
                    printf("%d %d\n", A, B);
                    break;
                }
            }// loop 2
            if ( isSolved ) {
                break;
            }
        }// loop 1
    }// End of while

    return 0;
}
/*
2
-20 20
-30 20
-10 -50
10 -5

# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10596887 	10167 	Birthday Cake 	Accepted 	C++ 	0.140 	2012-09-13 08:07:18
*/

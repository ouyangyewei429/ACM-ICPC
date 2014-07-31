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

int main() {
#if DEBUG
    freopen("E:\\", "r" ,stdin);
    freopen("E:\\", "w", stdout);
#endif

    VPII point;
    int nNums, x, y;
    
    while (~scanf("%d", &nNums) && nNums) {
        for (int i = 0; i < nNums * 2; ++i) {
            scanf("%d %d", &x, &y);
            point.push_back( make_pair(x, y) );
        }
        
        bool isSolved = false;
        for (int A = -500; A <= 500; ++A) {
            for (int B = -500; B <= 500; ++B) {
                int pAbove = 0, pBelow = 0;
                for (int k = 0; k < nNums * 2; ++k) {
                    int x1 = point[k].first;
                    int y1 = point[k].second;
                    int val = A * x1 + B * y1;
                    if (val > 0) {
                        ++pAbove;
                    } else if (val < 0) {
                        ++pBelow;
                    }
                }
                if (pAbove == nNums || pBelow == nNums) {
                    isSolved = true;
                    printf("%d %d\n", A, B);
                    break;
                }
            }
            if (isSolved)
                break;
        }
    }// End of while

    return 0;
}
/*
2
-20 20
-30 20
-10 -50
10 -5
*/

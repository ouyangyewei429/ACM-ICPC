/*
PROG:   Train Swapping
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int main() {
    VI myVector;
    int T, N, di, i, j;
    
    scanf("%d", &T);
    while ( T-- ) {
        myVector.clear();
        scanf("%d", &N);
        for (i = 0; i < N; ++i) {
            scanf("%d", &di);
            myVector.push_back( di );
        }
        
        int swapTimes = 0;
        for (i = 0; i < N - 1; ++i) {
            for (j = i + 1; j < N; ++j) {
                if ( myVector[i] > myVector[j] ) {
                    ++swapTimes;
                    swap( myVector[i], myVector[j] );
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swapTimes);
    }// End of while
    
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10588518 	299 	Train Swapping 	Accepted 	C++ 	0.016 	2012-09-11 02:45:41
*/

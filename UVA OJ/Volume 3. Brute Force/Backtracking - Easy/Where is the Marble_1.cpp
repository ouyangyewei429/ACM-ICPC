/*
PROG:   Where is the Marble?
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

const int MAXN = 10010;
/*
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
*/
int binSearch(int s[], int &N, int &tar) {
    int mid, left = 0, right = N - 1;
    
    while ( left <= right ) {
        mid = (left + right) / 2;
        if ( s[mid] == tar ) {
            return mid + 1;
        } else if ( s[mid] > tar ) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
#if DEBUG
    freopen("E:\\10474.in", "r" ,stdin);
    freopen("E:\\10474.out", "w", stdout);
#endif

    int s[MAXN];
    int i, j, N, Q, val, cas = 1;
    
    while (~scanf("%d %d", &N, &Q) && N + Q) {
        for (i = 0; i < N; ++i) {
            scanf("%d", &s[i]);
        }
        sort( s, s + N );
        
        printf("CASE# %d:\n", cas++);
        for (i = 0; i < Q; ++i) {
            scanf("%d", &val);
            int idx = binSearch( s, N, val );
            if ( idx != -1 ) {
                printf("%d found at %d\n", val, idx);
            } else {
                printf("%d not found\n", val);
            }
        }
    }// End of while

    return 0;
}


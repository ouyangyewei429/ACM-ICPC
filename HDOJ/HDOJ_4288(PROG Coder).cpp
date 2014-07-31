/*
PROG:   Coder
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <cmath>
#include <string>
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

typedef __int64 I64;
typedef vector<I64> VL;
typedef vector<I64>::iterator VIT;

int main() 
{
#if DEBUG
    freopen("E:\\", "r" ,stdin);
    freopen("E:\\", "w", stdout);
#endif

    VL v;
    VIT iter;
    __int64 x, sum;
    int nTests;
    char cmd[10];
    
    while (~scanf("%d", &nTests)) {
        v.clear();
        for (int i = 0; i < nTests; ++i) {
            scanf("%s", cmd);
            if ( cmd[0] == 'a' ) {
                scanf("%I64d", &x);
                iter = lower_bound( v.begin(), v.end(), x );
                if ( !v.size() )
                    iter = v.begin();
                v.insert( iter, x );
            } else if ( cmd[0] == 'd' ) {
                scanf("%I64d", &x);
                iter = lower_bound( v.begin(), v.end(), x );
                if ( !v.size() )
                    iter = v.begin();
                v.erase( iter );
            } else if ( cmd[0] == 's' ) {
                sum = 0;
                for (iter = v.begin() + 2; iter < v.end(); iter += 5)
                    sum += *iter;
                printf("%I64d\n", sum);
            }
        }
    }// End of while

    return 0;
}
/*
14
add 1
add 7
add 2
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum

5
11
13
*/

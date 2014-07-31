/*
PROG:   Coder
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::vector;

//typedef long long LL;
typedef vector<int> VI;
typedef vector<int>::iterator VIT;

int main()
{
    VI v;
    VIT iter;
    int nNums, x;
    char cmd[10];
    
    while (~scanf("%d", &nNums)) {
        v.clear();
        for (int i = 0; i < nNums; ++i) {
            scanf("%s", cmd);
            if ( cmd[0] == 'a' ) {
                scanf("%d", &x);
                iter = lower_bound( v.begin(), v.end(), x );
                v.insert( iter, x );
            } else if ( cmd[0] == 'd' ) {
                scanf("%d", &x);
                iter = lower_bound( v.begin(), v.end(), x );
                v.erase( iter );
            } else if ( cmd[0] == 's' ) {
                __int64 sum = 0;
                for (VI::size_type ix = 2; ix < v.size(); ix += 5)
                    sum += v[ix];
                printf("%I64d\n", sum);
            }
        }
    }// End of while
    return 0;
}

/*
PROG:   Buildings
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

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

const int MAXN = 100005;

struct Floor {
    int w, s;
}v[MAXN];

int cmp( Floor c, Floor d ) {
    return c.w + c.s < d.w + d.s;
}

int main() {
    int nFloors, wi, si;
    while (~scanf("%d", &nFloors)) {
        for (int i = 0; i < nFloors; ++i) {
            scanf("%d %d", &v[i].w, &v[i].s);
        }
        sort( v, v + nFloors, cmp );
        
        __int64 wj = 0, pdv = 0;
        for (int j = 0; j < nFloors; ++j) {
            if ( wj > v[j].s )
                pdv += wj - v[j].s;
            wj += v[j].w;
        }
        printf("%I64d\n", pdv);
    }// End of while

    return 0;
}


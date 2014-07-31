/*
PROG:   Same binary weight
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <stack>
#include <queue>
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

typedef long long LL;

int bitCount(LL num) {
    LL bits = 0;
    
    while ( num ) {
        bits += (num % 2);
        num >>= 1;
    }
    return bits;
}

int main() 
{
    LL num;
    int sw, dw;
    
    while (~scanf("%lld", &num)) {
        sw = bitCount( num );
        for (dw = 0, ++num; dw != sw; ++num) {
            dw = bitCount( num );
        }
        printf("%lld\n", num - 1);
    }// End of while
    return 0;
}


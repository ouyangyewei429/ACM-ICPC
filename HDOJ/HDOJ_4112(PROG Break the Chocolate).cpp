/*
PROG:   Break the Chocolate
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

int main() {
    __int64 T, N, M, K, hand, knife;
    
    scanf("%I64d", &T);
    for (__int64 cas = 1; cas <= T; ++cas) {
        scanf("%I64d %I64d %I64d", &N, &M, &K);
        hand = K * N * M - 1;
        knife = (__int64)( ceil( log(1.0 * K) / log(2.0) )
        + ceil( log(1.0 * N) / log(2.0) + ceil( log(1.0 * M) / log(2.0) ) ) );
        printf("Case #%I64d: %I64d %I64d\n", cas, hand, knife);
    }// End of for

    return 0;
}
/*
Run ID	Submit Time	Judge Status	Pro.ID	Exe.Time	Exe.Memory	Code Len.	Language	Author
6769182	2012-09-15 11:03:31	Accepted	4112	15MS	264K	818 B	C++	Maxwell
*/

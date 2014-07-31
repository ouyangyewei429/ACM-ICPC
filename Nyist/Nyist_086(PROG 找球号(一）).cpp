/*
PROG:   ’“«Ú∫≈(“ª£©
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
typedef map<LL, bool> MLLB;

int main() 
{
    MLLB mp;
    LL ballNums;
    int N, M;
    
    scanf("%d %d", &N, &M);
    //while (~scanf("%d %d", &N, &M)) {
        mp.clear();
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &ballNums);
            mp.insert( make_pair(ballNums, true) );
        }
        for (int j = 0; j < M; ++j) {
            scanf("%lld", &ballNums);
            if (mp[ballNums])
                printf("YES\n");
            else
                printf("NO\n");
        }
    //}// End of while
    return 0;
}


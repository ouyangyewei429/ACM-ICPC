/*
PROG:   找球号(一）
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

const int MAXN = 2000073;

typedef long long LL;

LL hash[MAXN];

void hashTable(LL &ball) {
    for (LL px = ball % MAXN; px < MAXN; px = (px + 1) % MAXN) {
        if ( !hash[px] ) {
            hash[px] = ball;
            break;
        }
    }// End of for
    return ;
}

bool isExist(LL &ball) {
    for (LL px = ball % MAXN; px < MAXN; px = (px + 1) % MAXN) {
        if ( hash[px] == ball )
            return true;
        else if ( !hash[px] )
            return false;
    }
}

int main() 
{
    LL ball;
    int N, M;
    
    scanf("%d %d", &N, &M);
    //while (~scanf("%d %d", &N, &M)) {
    //    memset(hash, 0, sizeof(hash));
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &ball);
            if ( !isExist(ball) )
                hashTable( ball );
        }
        for (int j = 0; j < M; ++j) {
            scanf("%lld", &ball);
            if ( isExist(ball) )
                printf("YES\n");
            else
                printf("NO\n");
        }
    //}// End of while
//    system("pause");
    return 0;
}
/*
6 4
23 34 46 768 343 343
2 4 23 343

NO
NO
YES
YES

运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247310 	FLex	找球号(一）	Accepted 	360 	15852 	C/C++	09-20 19:00:37
247309 	FLex	找球号(一）	Accepted 	328 	23664 	C/C++	09-20 19:00:18
*/

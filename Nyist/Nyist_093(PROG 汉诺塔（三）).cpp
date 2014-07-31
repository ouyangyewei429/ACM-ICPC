/*
PROG:   汉诺塔（三）
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (diaable : 4530)
//#pragma warnning (disable : 4786)
#include <set>
#include <map>
#include <list>
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
#include <fstream>
#include <algorithm>

using namespace std;

stack<int> pillar[3];

void clearPillar(int &P) {
    for (int ix = 0; ix < 3; ++ix) {
        while ( !pillar[ix].empty() )
            pillar[ix].pop();
    }// End of for
    for (int jx = P; jx >= 1; --jx) {
        pillar[0].push( jx );
    }
}

int main() 
{
    bool isLegal;
    int testCases, P, Q, xx, yy;
    
    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d %d", &P, &Q);
        
        isLegal = true;
        clearPillar( P );
        for (int ix = 0; ix < Q; ++ix) {
            scanf("%d %d", &xx, &yy);
            if ( pillar[xx - 1].empty() ) {
                isLegal = false;
            } else if ( !pillar[yy - 1].empty()
                        && pillar[xx - 1].top() > pillar[yy - 1].top() ) {
                isLegal = false;
            } else {
                pillar[yy - 1].push( pillar[xx - 1].top() );
                pillar[xx - 1].pop();
            }
        }
        if ( isLegal )
            printf("legal\n");
        else
            printf("illegal\n");
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247654 	FLex	汉诺塔（三）	Accepted 	0 	308 	C/C++	09-21 15:21:40
*/

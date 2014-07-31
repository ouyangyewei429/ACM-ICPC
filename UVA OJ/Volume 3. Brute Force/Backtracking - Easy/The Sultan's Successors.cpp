/*
PROG:   The Sultan's Successors
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

const int MAXN = 8;

bool vis[3][MAXN << 1];
int k, score, chess[MAXN][MAXN];

void readChess() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf("%d", &chess[i][j]);
        }
    }
}

void dfs(int row, int s) {
    if (row == 8) {
        if (s > score)
            score = s;
        return ;
    }// destination
    
    for (int col = 0; col < 8; ++col) {
        if (!vis[0][col] && !vis[1][row + col] && !vis[2][8 + row - col]) {
            vis[0][col] = true;
            vis[1][row + col] = vis[2][8 + row - col] = true;
            dfs(row + 1, s + chess[row][col]);
            vis[0][col] = false;
            vis[1][row + col] = vis[2][8 + row - col] = false;
        }
    }
}

int main() {
#if DEBUG
    freopen("E:\\167.in", "r" ,stdin);
    freopen("E:\\167.out", "w", stdout);
#endif

    scanf("%d", &k);
    while ( k-- ) {
        readChess();
        
        score = 0;
        memset(vis, false, sizeof(vis));
        dfs( 0, 0 );
        printf("%5d\n", score);
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10605723 	167 	The Sultan's Successors 	Accepted 	C++ 	0.012 	2012-09-15 08:25:32
*/

/*
PROG:   The Settlers of Catan
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

const int MAXN = 29;

bool hash[MAXN][MAXN];
int N, M, longest, graph[MAXN][MAXN];
/*
void initialize() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            hash[i][j] = false;
            graph[i][j] = 0;
        }
    }
}
*/
void dfs(int st, int dist) {
    if (dist > longest) {
        longest = dist;
    }
    
    for (int i = 0; i < N; ++i) {
        if (graph[st][i] && !hash[st][i]) {
            hash[st][i] = hash[i][st] = true;
            dfs(i, dist + 1);
            hash[st][i] = hash[i][st] = false;
        }
    }// End of for
}

int main() {
#if DEBUG
    freopen("E:\\539.in", "r" ,stdin);
    freopen("E:\\539.out", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M) && N + M != 0) {
        //initialize();
        memset(graph, 0, sizeof(graph));
        
        int a, b;
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &a, &b);
            graph[a][b] = graph[b][a] = 1;
        }
        
        longest = -1;
        for (int st = 0; st < N; ++st) {
            memset(hash, false, sizeof(hash));
            dfs(st, 0);
        }
        printf("%d\n", longest);
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10597066 	539 	The Settlers of Catan 	Accepted 	C++ 	0.020 	2012-09-13 09:24:18
*/

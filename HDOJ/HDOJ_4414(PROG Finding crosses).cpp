/*
PROG:   Finding crosses
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

#define DEBUG 0

const int MAXN = 52;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N;
char graph[MAXN][MAXN];

void readGraph() {
    for (int ix = 0; ix < N; ++ix)
        scanf("%s", graph[ix]);
}

bool isNotOkey(int x, int y) {
    return (x < 0 || y < 0 || x >= N || y >= N || graph[x][y] != '#');
}

int countGrids(int x, int y, int dir) {
    int ax, ay, ret = 0;
    
    while (!isNotOkey(x, y)) {
        ax = x + dx[(dir + 1) % 4];
        ay = y + dy[(dir + 1) % 4];
        if (!isNotOkey(ax, ay)) return 0;

        ax = x + dx[(dir + 3) % 4];
        ay = y + dy[(dir + 3) % 4];
        if (!isNotOkey(ax, ay)) return 0;
        
        ++ret, x += dx[dir], y += dy[dir];
    }// End of while
    return ret;
}

void Solve() {
    int cross = 0, grids[4] = {0};
    
    for (int ix = 0; ix < N; ++ix) {
        for (int jx = 0; jx < N; ++jx) {
            if (graph[ix][jx] == '#') {
                memset(grids, 0, sizeof(grids));  // record the grids
                for (int kx = 0; kx < 4; ++kx) {
                    int nx = ix + dx[kx];
                    int ny = jx + dy[kx];
                    grids[kx] = countGrids(nx, ny, kx);
                }
                if (!grids[0] || !grids[1] || !grids[2] || !grids[3]) {
                    continue;
                } else if (grids[0] + grids[2] == grids[1] + grids[3]) {
                    ++cross;
                }
            }// End of if
        }
    }// End of for
    printf("%d\n", cross);
}

int main() {
#if DEBUG
    freopen("E:\\hdoj_4414.in", "r", stdin);
    freopen("E:\\hdoj_4414.out", "w", stdout);
#endif

    while (~scanf("%d", &N), N != 0) {
        readGraph();
        Solve();
    }// End of while
    return 0;
}

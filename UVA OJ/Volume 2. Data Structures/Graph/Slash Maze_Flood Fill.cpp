/*
PROG:   Slash Maze
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

const int MAXN = 229;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int w, h, cycles, grids, maxGrids, cas = 1;
int graph[MAXN][MAXN];
bool vis[MAXN][MAXN], hash[MAXN][MAXN];

void debug() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (graph[i][j] == 1) {
                printf("*");
            } else if (graph[i][j] == 2) {
                printf("#");
            } else if (graph[i][j] == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void readGraph() {
    char ch;
    
    h *= 3, w *= 3;
    for (int i = 1; i < h; i += 3) {
        getchar();
        for (int j = 1; j < w; j += 3) {
            scanf("%c", &ch);
            if (ch == '\\') {
                graph[i][j] = 1;
                graph[i - 1][j - 1] = graph[i + 1][j + 1] = 1;
                graph[i - 1][j] = graph[i + 1][j] = 0;
                graph[i][j - 1] = graph[i][j + 1] = 0;
                graph[i - 1][j + 1] = graph[i + 1][j - 1] = 0;
            } else if (ch == '/') {
                graph[i][j] = 1;
                graph[i - 1][j + 1] = graph[i + 1][j - 1] = 1;
                graph[i - 1][j] = graph[i + 1][j] = 0;
                graph[i][j - 1] = graph[i][j + 1] = 0;
                graph[i - 1][j - 1] = graph[i + 1][j + 1] = 0;
            }
        }
    }
    // debug();
}

bool isBoundary(int &x, int &y) {
    return (x == 0 || y == 0 || x == h - 1 || y == w - 1);
}

bool isOut(int &x, int &y) {
    return (x < 0 || y < 0 || x >= h || y >= w);
}

void flood_fill(int x, int y, int color) {
    vis[x][y] = true;
    graph[x][y] = color;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isOut(nx, ny) && !vis[nx][ny] && !graph[nx][ny]) {
            flood_fill(nx, ny, color);
        }
    }
}

void colorBoundary() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (isBoundary(i, j) && !vis[i][j] && !graph[i][j]) {
                flood_fill(i, j, 2);
            }
        }
    }
    // debug();
}

void dfs(int x, int y) {
    ++grids;
    hash[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isOut(nx, ny) && !graph[nx][ny] && !hash[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

void solve() {
    cycles = 0, maxGrids = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!graph[i][j] && !hash[i][j]) {
                ++cycles;
                grids = 0;
                dfs(i, j);
                if (grids > maxGrids) {
                    maxGrids = grids;
                }
            }
        }
    }
}

void solve();

int main() {
#if DEBUG
    freopen("E:\\705.in", "r" ,stdin);
    freopen("E:\\705.out", "w", stdout);
#endif

    while (~scanf("%d %d", &w, &h) && w + h != 0) {
        memset(vis, false, sizeof(vis));
        memset(hash, false, sizeof(hash));
        memset(graph, -1, sizeof(graph));
        
        readGraph();
        colorBoundary();
        solve();
        
        printf("Maze #%d:\n", cas++);
        if (cycles) {
            printf("%d Cycles; the longest has length %d.\n", cycles, maxGrids / 3);
        } else {
            printf("There are no cycles.\n");
        }
        printf("\n");
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10592483 	705 	Slash Maze 	Accepted 	C++ 	0.036 	2012-09-12 03:01:16
*/


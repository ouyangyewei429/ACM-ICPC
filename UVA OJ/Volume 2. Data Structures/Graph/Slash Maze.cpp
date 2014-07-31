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

#define DEBUG 1

const int MAXN = 229;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int ex[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int ey[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool hash[MAXN][MAXN];
int graph[MAXN][MAXN];
int w, h, grids, cycles, maxGrids, last_x, last_y, testCases = 1;

void readGraph() {
    char ch;
    
    w *= 3, h *= 3;
    for (int x = 1; x < h; x += 3) {
        getchar();
        for (int y = 1; y < w; y += 3) {
            scanf("%c", &ch);
            //cin >> ch;
			if ( ch == '\\' ) {
                graph[x][y] = 1;
                graph[x - 1][y - 1] = graph[x + 1][y + 1] = 1;
            } else if ( ch == '/' ) {
                graph[x][y] = 1;
                graph[x - 1][y + 1] = graph[x + 1][y - 1] = 1;
            }
        }
    }
/*
    // debug .................................
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if ( graph[i][j] ) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
*/
}

bool isOut( int x, int y ) {
    return ( x < 0 || y < 0 || x >= h || y >= w );
}

void dfs( int x, int y ) {
    ++grids;
    hash[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( !isOut(nx, ny) && !hash[nx][ny]
            && !graph[nx][ny] ) {
            last_x = nx, last_y = ny;
            dfs( nx, ny );
        }
    }
}

bool isCricular( int &cx, int &cy ) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int tx = cx + ex[i];
            int ty = cy + ey[i];
            if ( tx == last_x && ty == last_y ) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cycles = 0, maxGrids = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if ( !hash[i][j] && !graph[i][j] ) {
                grids = 0;
                dfs( i, j );
                if ( grids >= 12 && isCricular( i, j ) ) {
                    ++cycles;
                    if ( maxGrids < grids ) {
                        maxGrids = grids;
                    }
                }
            }
        }
    }
}

int main() {
#if DEBUG
    freopen("E:\\705.in", "r" ,stdin);
    freopen("E:\\705.out", "w", stdout);
#endif

    while ( ~scanf("%d %d", &w, &h) && w + h != 0 ) {
        memset( hash, false, sizeof(hash) );
        memset( graph, 0, sizeof(graph) );
        
        readGraph();
        solve();
        
        printf("Maze #%d:\n", testCases++);
        if ( cycles ) {
            printf("%d Cycles; the longest has length %d.\n", cycles, maxGrids);
        } else {
            printf("There are no cycles.\n");
        }
        printf("\n");
        
    }// End of while

    return 0;
}

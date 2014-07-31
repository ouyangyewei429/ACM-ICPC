/*
PROG:   Dungeon Master
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

const int MAXN = 32;
const int dz[] = {1, -1, 0, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 0, -1, 1};

char maze[MAXN][MAXN][MAXN];
bool hash[MAXN][MAXN][MAXN];
int L, R, C, sx, sy, sz, tx, ty, tz;

struct Node {
    int xx, yy, zz, steps;
};

void debug() {
    for (int z = 0; z < L; ++z) {
        for (int x = 0; x < R; ++x) {
            for (int y = 0; y < C; ++y) {
                printf("%c", maze[z][x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void readGraph() {
    for (int z = 0; z < L; ++z) {
        for (int x = 0; x < R; ++x) {
            //getchar();
            for (int y = 0; y < C; ++y) {
                //scanf("%c", &maze[z][x][y]);
                cin >> maze[z][x][y];
                if ( maze[z][x][y] == 'S' ) {
                    sz = z, sx = x, sy = y;
                    maze[z][x][y] = '.';
                } else if ( maze[z][x][y] == 'E' ) {
                    tz = z, tx = x, ty = y;
                    maze[z][x][y] = '.';
                }
            }
        }
    }
    // debug();
}

bool isOut(int z, int x, int y) {
    return (z < 0 || x < 0 || y < 0 || z >= L || x >= R || y >= C);
}

int bfs() {
    Node c, n;
    queue<Node> q;
    
    c.steps = 0;
    c.xx = sx, c.yy = sy, c.zz = sz;
    hash[sz][sx][sy] = true;
    q.push(c);
    while (!q.empty()) {
        c = q.front();
        q.pop();
        
        if (c.zz == tz && c.xx == tx && c.yy == ty) {
            return c.steps;
        } else {
            for (int dir = 0; dir < 6; ++dir) {
                n.zz = c.zz + dz[dir];
                n.xx = c.xx + dx[dir];
                n.yy = c.yy + dy[dir];
                if (!isOut(n.zz, n.xx, n.yy)
                    && !hash[n.zz][n.xx][n.yy] && maze[n.zz][n.xx][n.yy] == '.') {
                    n.steps = c.steps + 1;
                    hash[n.zz][n.xx][n.yy] = true;
                    q.push(n);
                }
            }// End of for
        }// End of else
    }// End of while
    return 0;
}

int main() {
#if DEBUG
    freopen("E:\\532.in", "r", stdin);
    freopen("E:\\532.out", "w", stdout);
#endif

    while (~scanf("%d %d %d", &L, &R, &C) && L + R + C != 0) {
        memset(hash, false, sizeof(hash));
        memset(maze, 0, sizeof(maze));
        
        readGraph();
        int costTi = bfs();
        if (costTi) {
            printf("Escaped in %d minute(s).\n", costTi);
        } else {
            printf("Trapped!\n");
        }
    }// End of while

    return 0;
}
/*
#		Problem	Verdict	Language	Run Time	Submission Date
10593550	532	Dungeon Master	Accepted	C++	0.016	2012-09-12 11:37:12
*/

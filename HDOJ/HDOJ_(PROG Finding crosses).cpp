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

int N;
//bool vis[MAXN][MAXN];
char graph[MAXN][MAXN];

void readGraph() {
    for (int ix = 0; ix < N; ++ix) {
        getchar();
        for (int jx = 0; jx < N; ++jx)
            scanf("%c", &graph[ix][jx]);
    }// End of for
}

bool isOut(int x, int y) {
    return (x < 0 || y < 0 || x >= N || y >= N);
}

int upGrids(int cx, int cy) {
    int grids = 0;
    
    while (!isOut(cx, cy) && graph[cx][cy] == '#') {
        if ( (cy - 1 >= 0 && graph[cx][cy - 1] == '#')
          || (cy + 1 < N && graph[cx][cy + 1] == '#')) {
            grids = 0;
            break;
        } else {
            --cx, ++grids;
        }
    }// End of while
    return grids;
}

int downGrids(int cx, int cy) {
    int grids = 0;
    
    while (!isOut(cx, cy) && graph[cx][cy] == '#') {
        if ( (cy - 1 >= 0 && graph[cx][cy - 1] == '#')
          || (cy + 1 < N && graph[cx][cy + 1] == '#')) {
            grids = 0;
            break;
        } else {
            ++cx, ++grids;
        }
    }// End of while
    return grids;
}

int leftGrids(int cx, int cy) {
    int grids = 0;
    
    while (!isOut(cx, cy) && graph[cx][cy] == '#') {
        if ( (cx - 1 >= 0 && graph[cx - 1][cy] == '#')
          || (cx + 1 < N && graph[cx + 1][cy] == '#')) {
            grids = 0;
            break;
        } else {
            --cy, ++grids;
        }
    }// End of while
    return grids;
}

int rightGrids(int cx, int cy) {
    int grids = 0;
    
    while (!isOut(cx, cy) && graph[cx][cy] == '#') {
        if ( (cx - 1 >= 0 && graph[cx - 1][cy] == '#')
          || (cx + 1 < N && graph[cx + 1][cy] == '#')) {
            grids = 0;
            break;
        } else {
            ++cy, ++grids;
        }
    }// End of while
    return grids;
}

void process() {
    int crosses = 0;
    int up, down, left, right;
    
    for (int ix = 0; ix < N; ++ix) {
        for (int jx = 0; jx < N; ++jx) {
            if (graph[ix][jx] == '#') {
                up = down = 0;
                left = right = 0;
                up = upGrids(ix - 1, jx);
                down = downGrids(ix + 1, jx);
                left = leftGrids(ix, jx - 1);
                right = rightGrids(ix, jx + 1);
                
                if (!up || !down || !left || !right) {
                    continue;
                } else if (up + down == left + right) {
                    ++crosses;
                }
            }// End of if
        }
    }// End of for
    printf("%d\n", crosses);
    return ;
}

int main() 
{
#if DEBUG
    freopen("E:\\1005.in", "r" ,stdin);
    freopen("E:\\1005.out", "w", stdout);
#endif
    
    while (~scanf("%d", &N), N != 0) {
        readGraph();
        process();
    }// End of while
    return 0;
}

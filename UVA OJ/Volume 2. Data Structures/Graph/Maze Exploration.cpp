/*
PROG:   Maze Exploration
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

//#include <assert.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

const int MAXROW = 30;
const int MAXCOL = 80;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

void readGraph( char graph[][MAXCOL], int &row, int &sx, int &sy ) {
    char lines[MAXCOL] = {0};
    
    row = 0;
    while ( gets(lines) ) {
        strncpy( graph[row++], lines, MAXCOL );
        if ( lines[0] == '_' ) {
            break;
        }
    }
    
    bool isFound = false;
    for (int i = 0; i < MAXROW; ++i) {
        for (int j = 0; j < MAXCOL; ++j) {
            if ( graph[i][j] == 0 ) {
                break;
            } else if ( graph[i][j] == '*' ) {
                isFound = true;
                sx = i, sy = j;
                break;
            }
        }
        if ( isFound ) {
            break;
        }
    }// End of for
}

bool isOut( int x, int y, int &row ) {
    return ( x < 0 || y < 0 || x >= row || y >= MAXCOL );
}

void bfs( char graph[][MAXCOL], bool hash[][MAXCOL], int &row, int &sx, int &sy ) {
    Node c, n;
    queue <Node> q;
    
    c.x = sx, c.y = sy;
    graph[sx][sy] = '#';
    hash[sx][sy] = true;
    q.push( c );
    while ( !q.empty() ) {
        c = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            if ( !isOut(n.x, n.y, row) && !hash[n.x][n.y]
                && graph[n.x][n.y] == ' ' ) {
                 hash[n.x][n.y] = true;
                 graph[n.x][n.y] = '#';
                 q.push( n );
            }
        }// End of for
    }// End of while
}

void display( char graph[][MAXCOL], int &row ) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < MAXCOL; ++j) {
            if ( graph[i][j] == 0 ) {
                break;
            } else {
                printf("%c", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
#if DEBUG
    freopen("E:\\784.in", "r", stdin);
    freopen("E:\\784.out", "w", stdout);
#endif

    int testCases, sx, sy, row;
    char graph[MAXROW][MAXCOL];
    bool hash[MAXROW][MAXCOL];
    
    scanf("%d", &testCases);
    getchar();
    while ( testCases-- ) {
        memset( hash, false, sizeof(hash) );
        memset( graph, 0, sizeof(graph) );
        readGraph( graph, row, sx, sy );
        bfs( graph, hash, row, sx, sy );
        display( graph, row );
    }// End of while

    //system("pause");
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10589510 	784 	Maze Exploration 	Accepted 	C++ 	0.036 	2012-09-11 09:27:52
*/

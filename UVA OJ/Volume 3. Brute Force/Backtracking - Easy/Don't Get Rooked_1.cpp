/*
PROG:   Don't Get Rooked
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

const int MAXN = 5;

bool IsOk(char graph[][MAXN], int &row, int &col) {
    // checking col
    for (int i = col - 1; (i >= 0 && graph[row][i] != 'X'); --i) {
        if (graph[row][i] == '@') {
            return false;
        }
    }
    // checking row
    for (int j = row - 1; (j >= 0 && graph[j][col] != 'X'); --j) {
        if (graph[j][col] == '@') {
            return false;
        }
    }
    return true;
}

void Dfs(char graph[][MAXN], int &nSizes, int rooks,
        int grids, int &maxValue) {
    if (grids == nSizes * nSizes) {
        if (rooks > maxValue) {
            maxValue = rooks;
        }
        return ;
    }
    
    int nx = grids / nSizes;
    int ny = grids % nSizes;
    if (graph[nx][ny] == '.' && IsOk(graph, nx, ny)) {
        graph[nx][ny] = '@';
        Dfs(graph, nSizes, rooks + 1, grids + 1, maxValue);
        graph[nx][ny] = '.';
    }
    
    Dfs(graph, nSizes, rooks, grids + 1, maxValue);
}

int main() {
#if DEBUG
    freopen("E:\\639.in", "r", stdin);
    freopen("E:\\639.out", "w", stdout);
#endif

    int nSizes, maxValue;
    char graph[MAXN][MAXN];
    
    while (cin >> nSizes && nSizes) {
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < nSizes; ++i) {
            cin >> graph[i];
        }
        
        maxValue = -1;
        Dfs(graph, nSizes, 0, 0, maxValue);
        cout << maxValue << endl;
    }// End of while

    return 0;
}

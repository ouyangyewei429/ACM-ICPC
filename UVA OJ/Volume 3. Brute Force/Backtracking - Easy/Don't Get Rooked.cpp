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

#define DEBUG 1

const int MAXN = 10;

void ReadData(int &nSizes, char graph[][MAXN]) {
    for (int i = 0; i < nSizes; ++i) {
        cin >> graph[i];
    }
}

bool IsOk(char graph[][MAXN], bool hash[][MAXN], int &row, int &col) {
    // checking col
    for (int i = col - 1; (i >= 0 && graph[row][i] != 'X'); --i) {
        if (hash[row][i]) {
            return false;
        }
    }
    // checking row
    for (int i = row - 1; (i >= 0 && graph[i][col] != 'X'); --i) {
        if (hash[i][col]) {
            return false;
        }
    }
    return true;
}

void Dfs(char graph[][MAXN], int &limit, bool hash[][MAXN],
        int row, int rooks, int &maxValue) {
    if (row == limit) {
        if (rooks > maxValue) {
            maxValue = rooks;
        }
        return ;
    }
    
    for (int col = 0; col < limit; ++col) {
        if (graph[row][col] == '.' && !hash[row][col]
            && IsOk(graph, hash, row, col)) {
            hash[row][col] = true;
            Dfs(graph, limit, hash, row + 1, rooks + 1, maxValue);
            hash[row][col] = false;
        }
    }
}

int main() {
#if DEBUG
    freopen("E:\\639.in", "r", stdin);
    freopen("E:\\639.out", "w", stdout);
#endif

    int nSizes, maxValue;
    char graph[MAXN][MAXN];
    bool hash[MAXN][MAXN];
    
    while (cin >> nSizes && nSizes) {
        ReadData(nSizes, graph);
        
        maxValue = -1;
        memset(hash, false, sizeof(hash));
        Dfs(graph, nSizes, hash, 0, 0, maxValue);
        
        cout << maxValue << endl;
    }// End of while

    return 0;
}

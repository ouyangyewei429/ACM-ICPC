/*
PROG:   Oil Deposits
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <iostream>
using namespace std;

#define DEBUG 0

const int maxn = 104;

int  N, M, result;
bool hash[maxn][maxn];
char graph[maxn][maxn];
int  dx[] = {-1,-1,-1,0,1,1,1,0};
int  dy[] = {-1,0,1,1,1,0,-1,-1};

void dfs(int x, int y)
{
    if (hash[x][y])
        return ;
    
    hash[x][y] = true;
    for (int i=0; i<8; ++i)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if (nx<0 || ny<0 || nx>=N || ny>=M
            || graph[nx][ny]=='*')
            continue;
        
        dfs(nx, ny);
    }// end of for
}// dfs

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1241.txt", "r", stdin);
    freopen("E:\\hdoj_1241_ans.txt", "w", stdout);
#endif

    int i, j;
    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        memset(hash, false, sizeof(hash));
        //memset(graph, 0, sizeof(graph));
        
        for (i=0; i<N; ++i)
        {
            cin >> graph[i];
            /*
            //getchar();
            for (j=0; j<M; ++j)
            {
                hash[i][j] = false;
                //scanf("%c", &graph[i][j]);
            }
            */
        }// Input
        
        result = 0;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<M; ++j)
            {
                if (!hash[i][j] && graph[i][j]=='@')
                {
                    ++result;
                    dfs(i, j);
                }    
            }
        }// loop for dfs
        
        printf("%d\n", result);
    }// end of while
    
    return 0;
}

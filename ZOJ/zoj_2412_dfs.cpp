/*
PROG:   Farm Irrigation
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <iostream>
using namespace std;

const int maxn = 60;

int  N, M, ans;
char maze[maxn][maxn];
bool hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  graph[11][4] = {{1,0,3,0}, {1,0,0,4}, {0,2,3,0}, {0,2,0,4},
                     {1,2,0,0}, {0,0,3,4}, {1,0,3,4}, {1,2,3,0}, 
                     {0,2,3,4}, {1,2,0,4}, {1,2,3,4}};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */
                 
void dfs(int cx, int cy, char ct)
{
    if (hash[cx][cy])
        return ;
    
    hash[cx][cy] = true;
    for (int i=0; i<4; ++i)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (IsOut(nx, ny))
            continue;
            
        char nt = maze[nx][ny];
        if (i==0 && graph[ct-'A'][0]==1 && graph[nt-'A'][1]==2)
            dfs(nx, ny, nt);
        else if (i==1 && graph[ct-'A'][1]==2 && graph[nt-'A'][0]==1)
            dfs(nx, ny, nt);
        else if (i==2 && graph[ct-'A'][2]==3 && graph[nt-'A'][3]==4)
            dfs(nx, ny, nt);
        else if (i==3 && graph[ct-'A'][3]==4 && graph[nt-'A'][2]==3)
            dfs(nx, ny, nt);
    }/* Search In 4 direction */
}/* dfs */

int main()
{
    while (~scanf("%d %d", &N, &M), N+M!=-2)
    {
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &maze[i][j]);
            }
        }/* prepare */
        
        ans = 0;
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<M; ++j)
            {
                if (!hash[i][j])
                {
                    ++ans;
                    dfs(i, j, maze[i][j]);
                }    
            }
        }/* graph for dfs */

        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}

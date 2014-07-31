/*
PROG:   Tempter of the Bone
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <iostream>
using namespace std;

//#define onlinejudge

const int maxn = 12;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn];
int  N, M, T, walls, sx, sy, tx, ty;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt)
{
    if (x==tx && y==ty && cnt==T)
    {
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int dis = T-cnt-abs(x-tx)-abs(y-ty);
        
        if (nx<0 || ny<0 || nx>=N || ny>=M)
            continue;
        if (hash[nx][ny] || maze[nx][ny]=='X')
            continue;
        if (dis<0 || dis&1)
            continue;
        
        hash[nx][ny] = true;
        dfs (nx, ny, cnt+1);
        if (IsSolved)
            return ;
            
        hash[nx][ny] = false;
    }/* End of For */
    
    return ;
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1010.txt", "r", stdin);
    freopen("E:\\hdoj_1010_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &N, &M, &T), N+M+T!=0)
    {
        walls = 0;
        memset(maze, 0, sizeof(maze));
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                //cin >> maze[i][j];
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'X')
                    ++walls;
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                if (maze[i][j] == 'D')
                    tx = i, ty = j;
            }
        }/* prepare */
        
        if (N*M-walls <= T)
        {
            printf("NO\n");
            continue;
        }
        
        IsSolved = false;
        hash[sx][sy] = true;
        dfs(sx, sy, 0);
        if (IsSolved)
            printf("YES\n");
        else
            printf("NO\n");
    }/* End of While */
    
    return 0;
}


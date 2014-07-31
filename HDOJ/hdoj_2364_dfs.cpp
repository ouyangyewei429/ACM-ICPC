/*
PROG:   Escape
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 100;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn];
int  T, N, M, sx, sy, tx, ty;
int  fx[] = {-1, 1, 0, 0};
int  fy[] = {0, 0, -1, 1};
int  dx[4][3] = {{0,0,-1}, {0,0,1}, {1,-1,0}, {-1,1,0}};
int  dy[4][3] = {{-1,1,0}, {1,-1,0}, {0,0,-1}, {0,0,1}};
int  pos[4][3] = {{2,3,0}, {3,2,1}, {1,0,2,}, {0,1,3}};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void dfs(int x, int y, int t, int cur_dir)
{
    if (x==tx && y==ty)
    {
        IsSolved = true;
        printf("%d\n", t);
        return ;
    }/* Reach to the destination */
    
    for (int i=0, cango=1; i<3; ++i)
    {
        int nx = x + dx[cur_dir][i];
        int ny = y + dy[cur_dir][i];
        
        if (IsOut(nx, ny) || maze[nx][ny]=='#' || hash[nx][ny])
            continue;
        
        if (i==0 || i==1 || (i==2&&cango))
        {
            cango = 0;
            hash[nx][ny] = true;
            dfs(nx, ny, t+1, pos[cur_dir][i]);
            if (IsSolved)   return ;
            hash[nx][ny] = true;
        }/* not the straight direction */
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2364.txt", "r", stdin);
    freopen("E:\\hdoj_2364_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        memset(hash, false, sizeof(hash));
        
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i)
        {
            //getchar();
            for (int j=0; j<M; ++j)
            {
                cin >> maze[i][j];
                //scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx=i, sy=j, maze[i][j]='.';
                if (((i==0||i==N-1)&&maze[i][j]=='.')
                    || ((j==0||j==M-1)&&maze[i][j]=='.'))
                    tx=i, ty=j;
            }
        }/* End of For */
        
        IsSolved = false;
        hash[sx][sy] = true;
        for (int k=0; k<4; ++k)
        {
            int nx = sx + fx[k];
            int ny = sy + fy[k];
            
            if (IsOut(nx, ny) || maze[nx][ny]=='#')
                continue;
            
            hash[nx][ny] = true;
            dfs(nx, ny, 1, k);  /* x, y, t, dir */
            if (IsSolved)   break;
            //hash[nx][ny] = false;
        }/* The First Node */
        if (!IsSolved)
            printf("-1\n");
    }/* End of While */
    
    return 0;
}

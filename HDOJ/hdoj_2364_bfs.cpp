/*
PROG:   Ê¤Àû´óÌÓÍö(Ðø)
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

#define onlinejudge

const int maxn = 100;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn];
int  T, N, M, sx, sy, tx, ty;
int  fx[] = {-1, 1, 0, 0};
int  fy[] = {0, 0, -1, 1};
int  dx[4][3] = {{0,0,-1}, {0,0,1}, {1,-1,0}, {-1,1,0}};
int  dy[4][3] = {{-1,1,0}, {1,-1,0}, {0,0,-1}, {0,0,1}};
int  pos[4][3] = {{2,3,0}, {3,2,1}, {1,0,2,}, {0,1,3}};
typedef struct node
{
    int x, y, t, dir;
}NODE;

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    hash[sx][sy] = true;
    for (int i=0; i<4; ++i)
    {
        n.x = sx + fx[i];
        n.y = sy + fy[i];
        
        if (IsOut(n.x, n.y) || maze[n.x][n.y]=='#')
            continue;
        
        n.dir = i, n.t = 1;
        hash[n.x][n.y] = true;
        q.push(n);
    }/* The First Node */
    
    IsSolved = false;
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        //------------------------------------------------------
        //printf("%d %d %c | %d\n", c.x, c.y, maze[c.x][c.y], c.dir);
        //------------------------------------------------------
        
        if (c.x==tx && c.y==ty)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            return ;
        }/* End of IF */
        
        for (int i=0, cango=1; i<3; ++i)
        {
            n.x = c.x + dx[c.dir][i];
            n.y = c.y + dy[c.dir][i];
            
            if (IsOut(n.x, n.y) || maze[n.x][n.y]=='#' || hash[n.x][n.y])
                continue;
            
            if (i==0 || i==1)
            {
                cango = 0;
                n.t = c.t + 1;
                n.dir = pos[c.dir][i];
                hash[n.x][n.y] = true;
                q.push(n);
            }
            else if (cango)
            {
                n.t = c.t + 1;
                n.dir = pos[c.dir][i];
                hash[n.x][n.y] = true;
                q.push(n);
            }    
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
    
    return ;
}/* bfs */

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
            getchar();
            for (int j=0; j<M; ++j)
            {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx=i, sy=j, maze[i][j]='.';
                if (((i==0||i==N-1)&&maze[i][j]=='.')
                    || ((j==0||j==M-1)&&maze[i][j]=='.'))
                    tx=i, ty=j;
            }
        }/* End of For */
        
        bfs();
    }/* End of While */
    
    return 0;
}


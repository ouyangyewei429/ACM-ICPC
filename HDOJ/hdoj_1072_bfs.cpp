/*
PROG:   Nightmare
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 12;

bool IsSolved, hash[maxn][maxn][maxn];
int  T, N, M, sx, sy, tx, ty, maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, t, boom;
}NODE;

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.x=sx, c.y=sy, c.t=0, c.boom=6;
    IsSolved=false, hash[sx][sy][6]=true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.boom>0)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M
                || maze[n.x][n.y]==0)
                continue;
            
            if (maze[n.x][n.y]==4 && c.boom>1)
            {
                n.boom = 6;
                if (hash[n.x][n.y][n.boom]) continue;
                
                maze[n.x][n.y] = 1;
                hash[n.x][n.y][n.boom] = true;
                q.push(n);
            }/* Boom-Time-Reset */
            else if (maze[n.x][n.y]==1 && c.boom>1)
            {
                n.boom = c.boom - 1;
                if (hash[n.x][n.y][n.boom]) continue;
                
                hash[n.x][n.y][n.boom] = true;
                q.push(n);
            }/* The Empty Place */
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1072.txt", "r", stdin);
    freopen("E:\\hdoj_1072_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        memset(hash, false, sizeof(hash));
        
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<M; ++j)
            {
                scanf("%d", &maze[i][j]);
                if (maze[i][j] == 2)
                    sx=i, sy=j, maze[i][j]=1;
                if (maze[i][j] == 3)
                    tx=i, ty=j, maze[i][j]=1;
            }
        }/* End of For */
        
        bfs();
    }/* End of While */
    
    return 0;
}

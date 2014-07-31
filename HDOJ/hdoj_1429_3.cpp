#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 24;

char maze[maxn][maxn];
bool hash[maxn][maxn][1429];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  key[] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int  N, M, T, sx, sy, tx, ty;
struct Graph
{
    int x, y, t, k;  
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=N || y>=M)
        return false;
    
    return true;
}/* IsInBound */

int bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx, c.y = sy;
    c.t = c.k = 0;
    hash[sx][sy][0] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.t<T)
            return c.t;
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (!IsInBound(n.x, n.y) || maze[n.x][n.y]=='*' || n.t>=T)
                continue;
            
            if (maze[n.x][n.y] == '.')
            {   /* Empty place */
                if (!hash[n.x][n.y][c.k])
                {
                    n.k = c.k;
                    hash[n.x][n.y][n.k] = true;
                    q.push(n);
                }
            }
            else
            {
                if (maze[n.x][n.y]>='a' && maze[n.x][n.y]<='j')
                {   /* key place */
                    if (!hash[n.x][n.y][c.k|key[maze[n.x][n.y]-'a'+1]])
                    {
                        n.k = c.k|key[maze[n.x][n.y]-'a'+1];
                        hash[n.x][n.y][n.k] = true;
                        q.push(n);
                    }
                }
                else
                {   /* door place */
                    if (!hash[n.x][n.y][c.k] && (c.k & key[maze[n.x][n.y]-'A'+1]))
                    {
                        n.k = c.k;
                        hash[n.x][n.y][n.k] = true;
                        q.push(n);
                    }
                }
            }
        }/* End of For */
    }/* End of While */
    
    return -1;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1429.txt", "r", stdin);
    freopen("E:\\hdoj_1429_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &N, &M, &T))
    {
        memset(hash, false, sizeof(hash));
        
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == '^')
                    tx=i, ty=j, maze[i][j]='.';
            }
        }/* End of For */
        
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}

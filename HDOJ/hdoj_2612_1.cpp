#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 204;

char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  N, M, sx, sy, tx, ty, ans, hash[maxn][maxn], s[maxn][maxn];
struct Graph
{
    int x, y, t;
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=N || y>=M)
        return false;
    
    return true;
}/* IsInBound */

int bfs(int sx, int sy)
{
    queue <Graph> q;
    struct Graph c, n;
    
    memset(hash, 0, sizeof(hash));
    
    c.x = sx, c.y = sy, c.t = 0;
    hash[sx][sy] = 1;
    
    q.push(c);
    while (!q.empty())
    {
        printf("3 # %d %d %d %c #\n", c.x, c.y, c.t, maze[c.x][c.y]);
        
        c = q.front();
        q.pop();
        
        if (maze[c.x][c.y] == '@')
            return c.t;
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (!IsInBound(n.x, n.y) || maze[n.x][n.y]=='#'
                || hash[n.x][n.y])
                continue;
            
            hash[n.x][n.y] = 1;
            q.push(n);
        }
    }/* End of While */
}/* bfs */

int bbfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx, c.y = sy, c.t = 0;
    hash[sx][sy] = 1;
    q.push(c);
    
    n.x = tx, n.y = ty, n.t = 0;
    hash[tx][ty] = 2;
    q.push(n);
    
    /*****
    printf("sx, sy, tx, ty || %d %d %d %d\n\n", sx, sy, tx, ty);
    ****/
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (!IsInBound(n.x, n.y) || maze[n.x][n.y]=='#')
                continue;
            
            if (!hash[n.x][n.y])
            {
                
                printf("1 c # %d %d %d %c #\n", c.x, c.y, c.t, maze[c.x][c.y]);
                printf("1 n # %d %d %d %c #\n", n.x, n.y, n.t, maze[n.x][n.y]);
                
                s[n.x][n.y] = s[c.x][c.y] + 1;
                hash[n.x][n.y] = hash[c.x][c.y];
                q.push(n);
            }
            else if (hash[n.x][n.y] != hash[c.x][c.y])
            {
                
                printf("2 c # %d %d %d %c #\n", c.x, c.y, c.t, maze[c.x][c.y]);
                printf("2 n # %d %d %d %c #\n", n.x, n.y, n.t, maze[n.x][n.y]);
                
                if (maze[n.x][n.y] == '@')
                    return s[n.x][n.y]+s[c.x][c.y]+1;
                else
                {
                    int sum = s[n.x][n.y]+s[c.x][c.y]+1+bfs(n.x, n.y);
                    if (sum < ans)
                        ans = sum;
                }
            }
        }/* End of For */
    }/* End of While */
    
    return ans;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2612.txt", "r", stdin);
    freopen("E:\\hdoj_2612_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M))
    {
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                s[i][j] = hash[i][j] = 0;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == 'M')
                    tx=i, ty=j, maze[i][j]='.';
            }
        }/* End of For */
        
        ans = 0x3F3F3F3F;
        printf("%d\n", 11*bbfs());
    }/* End of While */
    
    return 0;
}

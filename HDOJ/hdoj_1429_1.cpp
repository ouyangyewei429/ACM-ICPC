#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
using namespace std;

#define onlinejudge

const int maxn = 24;

char maze[maxn][maxn];
bool hash[maxn][maxn][1049];
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
    c.t = 0, c.k = 0;
    hash[sx][sy][0] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.t >= T)
            continue;
        if (abs(c.x-tx)+abs(c.y-ty) > T-c.t)
            continue;
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            n.k = c.k;
            
            if (!IsInBound(n.x, n.y)
                || maze[n.x][n.y]=='*' || hash[n.x][n.y][c.k])
                continue;
     
            if (maze[n.x][n.y]=='.')
            {
                if (n.x==tx && n.y==ty && n.t<T)
                    return  n.t;
                
                hash[n.x][n.y][n.k] = true;
                q.push(n);
            }
            else if (isalpha(maze[n.x][n.y]))
            {
                if (maze[n.x][n.y] >= 'a')
                {
                    if (!hash[n.x][n.y][c.k|key[maze[n.x][n.y]-'a']])
                    {   /* keys place */
                        n.k = c.k|key[maze[n.x][n.y]-'a'];  /* Pick up the new key */
                        hash[n.x][n.y][n.k] = true; /* change the state */
                        q.push(n);
                    }
                }    
                else
                {
                    if (!hash[n.x][n.y][c.k]
                        && (c.k & key[maze[n.x][n.y]-'A']))
                    {   /* doors place */
                        hash[n.x][n.y][n.k] = true; /* change the state */
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
                    sx = i, sy = j;
                if (maze[i][j] == '^')
                    tx = i, ty = j;
            }
        }/* End of For */
        /**
        for (int i=0; i<N; ++i)
            printf("%s\n", maze[i]);
        ***/
        maze[sx][sy] = maze[tx][ty] = '.';
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}

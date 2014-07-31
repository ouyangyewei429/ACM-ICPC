#include <queue>
#include <cstdio>
#include <memory.h>

const int maxn = 1004;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int hash[maxn][maxn], maze[maxn][maxn];
int N, M, Q, sx, sy, tx, ty;
struct Graph
{
    int x, y, dir, k;
};

void Init_Hash()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
            hash[i][j] = 0;
    }
}/* Init_Hash */

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void bbfs()
{
    bool IsSolved = false;
    queue <Graph> q;
    struct Graph c, n;
    
    c.x=sx-1, c.y=sy-1, c.dir=4, c.k=0;
    hash[sx-1][sy-1] = 1;
    q.push(c);
    
    n.x=tx-1, n.y=ty-1, n.dir=4, n.k=0;
    hash[tx-1][ty-1] = 2;
    q.push(n);
    
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.dir = i;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
                       
            if (c.dir!=4 && i!=c.dir)
                n.k = c.k + 1;
            else
                n.k = c.k;
            
            if (IsOut(n.x, n.y) || n.k>2)
                continue;
            if (maze[n.x][n.y]==0 || (n.x==tx-1&&n.y==ty-1)
                || (n.x==sx-1&&n.y==sy-1))
            {
                if (!hash[n.x][n.y])
                {
                    hash[n.x][n.y] = hash[c.x][c.y];
                }
                else if (hash[n.x][n.y] != hash[c.x][c.y])
                {
                    
                }
            }/* End of IF */
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bbfs */

int main()
{
    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<M; ++j)
                scanf("%d", &maze[i][j]);
        }/* End of For */
        
        scanf("%d", &Q);
        for (int i=0; i<Q; ++i)
        {
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
            if (maze[sx-1][sy-1]==0 || maze[tx-1][ty-1]==0
                || maze[sx-1][sy-1]!=maze[tx-1][ty-1]
                || (sx==tx && sy==ty))
            {
                printf("NO\n");
                continue;
            }/* End of IF */
            
            Init_Hash();
            bbfs();
        }/* End of For */
    }/* End of While */
    
    return 0;
}

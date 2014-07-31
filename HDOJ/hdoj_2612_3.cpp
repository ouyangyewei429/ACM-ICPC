#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 204;

char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  ha[maxn][maxn], hb[maxn][maxn];
int  N, M, sx, sy, tx, ty, ans;
struct Graph
{
    int x, y, t;
};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

int Min(int x, int y)
{
    return (x<y ? x:y);
}/* Min */

void bfs(int a[][maxn], int b[][maxn], queue<Graph> &qa, queue<Graph> &qb)
{
    struct Graph c, n;
    if (!qa.empty())
    {
        c = qa.front();
        qa.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (IsOut(n.x, n.y) || maze[n.x][n.y]=='#'
                || ha[n.x][n.y]!=-1)
                continue;
            
            if (maze[n.x][n.y]=='@' && b[n.x][n.y]!=-1)
            {
                int sum = n.t + b[n.x][n.y];
                ans = Min(ans, sum);
                
                //---------------------------------------------
                printf("%d %d %d %d %c#\n", ans, n.x, n.y, n.t, maze[n.x][n.y]);
            }
            
            //---------------------------------------------
            printf("%d %d %d %d %c#\n", ans, n.x, n.y, n.t, maze[n.x][n.y]);
            
            a[n.x][n.y] = c.t + 1;
            qa.push(n);
        }/* End of For */
    }/* End of If */
}/* bfs */

int bbfs()
{
    queue <Graph> qa, qb;
    struct Graph p;
    
    p.x = sx, p.y = sy;
    p.t = ha[sx][sy] = 0;
    qa.push(p);
    
    p.x = tx, p.y = ty;
    p.t = hb[tx][ty] = 0;
    qb.push(p);
    
    ans = 0x3F3F3F3F;
    while (!qa.empty() && !qb.empty())
    {
        bfs(ha, hb, qa, qb);
        bfs(hb, ha, qb, qa);
    }/* End of While */
    
    return ans;
}/* bbfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2612.txt", "r", stdin);
    freopen("E:\\hdoj_2612_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M))
    {
        memset(ha, -1, sizeof(ha));
        memset(hb, -1, sizeof(hb));
        
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                //ha[i][j] = hb[i][j] = -1;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    sx = i, sy = j;
                if (maze[i][j] == 'M')
                    tx = i, ty = j;
            }
        }/* End of For */
        
        printf("%d\n", 11*bbfs());
    }/* End of While */
    
    return 0;
}

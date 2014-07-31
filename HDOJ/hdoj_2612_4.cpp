#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

//#define onlinejudge
#define Q   queue <Graph>

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

bool isout(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* isout */

void bfs(Q &qa, Q &qb, int a[][maxn], int b[][maxn])
{
    struct Graph c, n;
    if (!qa.empty())
    {
        c = qa.front();
        qa.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.t = c.t + 1;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (isout(n.x, n.y) || maze[n.x][n.y]=='#'
                || a[n.x][n.y]!=-1)
                continue;
            
            if (maze[n.x][n.y]=='@' && b[n.x][n.y]!=-1)
            {
                if (b[n.x][n.y]+n.t < ans)
                    ans = b[n.x][n.y]+n.t;
            }
            
            a[n.x][n.y] = n.t;
            qa.push(n);
        }/* End of For */
    }/* End of IF */
}/* bfs */

int bbfs()
{
    queue <Graph> qa, qb;
    struct Graph c;
    
    c.x = sx, c.y = sy;
    c.t = ha[sx][sy] = 0;
    qa.push(c);
    
    c.x = tx, c.y = ty;
    c.t = hb[tx][ty] = 0;
    qb.push(c);
    
    ans = 0x3F3F3F3F;
    while (!qa.empty() && !qb.empty())
    {
        bfs(qa, qb, ha, hb);
        bfs(qb, qa, hb, ha);
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
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                ha[i][j] = hb[i][j] = -1;
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

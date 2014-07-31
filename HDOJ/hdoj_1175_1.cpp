#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 1004;

bool IsSolved;
int  N, M, Q, sx, sy, tx, ty;
int  graph[maxn][maxn], maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
struct Graph
{
    int x, y, dir, t;
};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void Init_Graph()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
            graph[i][j] = 0x3F3F3F3F;
    }/* End of For */
}/* Init_Graph */

void bfs(int a, int b)
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx-1, c.y = sy-1;
    c.dir = 4, c.t = 0;
    graph[sx-1][sy-1] = 0;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx-1 && c.y==ty-1 && c.t<=2)
        {
            IsSolved = true;
            printf("YES\n");
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.dir = i;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (c.dir!=4 && i!=c.dir)
                n.t = c.t + 1;
            else
                n.t = c.t;
            
            if (IsOut(n.x, n.y) || n.t>2)
                continue;

            if (n.t == 1)
            {
                if (n.dir==0 && n.x<a) continue;
                if (n.dir==1 && n.x>a) continue;
                if (n.dir==2 && n.y<b) continue;
                if (n.dir==3 && n.y>b) continue;
            }
            else if (n.t == 2)
            {
                if (n.dir==0 && b-n.y==0 && n.x<a)    continue;
                if (n.dir==1 && b-n.y==0 && n.x>a)    continue;
                if (n.dir==2 && a-n.x==0 && n.y<b)    continue;
                if (n.dir==3 && a-n.x==0 && n.y>b)    continue;
            }

            if ((maze[n.x][n.y]==0 || n.x==tx-1&&n.y==ty-1) && graph[n.x][n.y]>=n.t)
            {
                graph[n.x][n.y] = n.t;
                q.push(n);
            }
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1175.txt", "r", stdin);
    freopen("E:\\hdoj_1175_ans.txt", "w", stdout);
#endif

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
    
            if (!maze[sx-1][sy-1] || !maze[tx-1][ty-1]
                || maze[sx-1][sy-1]!=maze[tx-1][ty-1]
                || (sx==tx && sy==ty))
            {
                printf("NO\n");
                continue;
            }/* End of IF */
            
            Init_Graph();
            IsSolved = false;
            bfs(tx-1, ty-1);
        }/* End of For */
    }/* End of While */
    
    return 0;
}

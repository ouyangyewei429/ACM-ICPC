#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 104;

char maze[maxn][maxn];
int  T, N, M, K, sx, sy, tx, ty, graph[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
struct Graph
{
    int x, y, dir, t;
};

void Init_Graph()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
            graph[i][j] = 0x3F3F3F3F;
    }
}/* Init_Graph */

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void bfs()
{
    bool IsSolved = false;
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx-1, c.y = sy-1;
    c.t = c.dir = 0;
    graph[sx-1][sy-1] = 0;
    
    /* The first dir */
    for (int i=0; i<4; ++i)
    {
        n.dir = i;
        n.x = c.x + dx[i];
        n.y = c.y + dy[i];
        
        if (IsOut(n.x, n.y) || maze[n.x][n.y]=='*')
            continue;

        n.t = graph[n.x][n.y] = 0;
        q.push(n);
    }/* End of For */
    
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        //---------------------------------------
        //printf("%d # %d %d\n", c.t, c.x, c.y);
        
        if (c.x==tx-1 && c.y==ty-1 && c.t<=K)
        {
            IsSolved = true;
            printf("yes\n");
            break;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            
        }
    }/* End of While */
    if (!IsSolved)
        printf("no\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1728.txt", "r", stdin);
    freopen("E:\\hdoj_1728_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                Init_Graph();
                scanf("%c", &maze[i][j]);
            }
        }/* End of For */
        
        scanf("%d %d %d %d %d", &K, &sy, &sx, &ty, &tx);
        
        bfs();
    }/* End of While */
    
    return 0;
}

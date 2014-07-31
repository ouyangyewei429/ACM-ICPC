#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge
//#define Q   queue <Graph>

const int maxn = 149;

char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  N, M, K, casenum;
int  graph[maxn][maxn], hash[maxn][maxn];
struct Graph
{
    int x, y, t, k;
};

bool isout(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* isout */

void bfs(int sx, int sy, int tx, int ty)
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx, c.y = sy;
    c.t = c.k = 0;
    graph[sx][sy] = 0;
    hash[sx][sy] = 1;
    q.push(c);
    
    n.x = tx, n.y = ty;
    n.t = n.k = 0;
    graph[tx][ty] = 0;
    hash[tx][ty] = 2;
    q.push(n);
    
    bool flag=false, IsSolved=false;
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.k = i;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = (i!=c.k) ? c.t+1 : c.t;
            
            if (isout(n.x, n.y) || maze[n.x][n.y]=='*')
                continue;
            
            if (!hash[n.x][n.y])
            {
                hash[n.x][n.y] = hash[c.x][c.y];
                graph[n.x][n.y] = (i!=c.k) ? graph[c.x][c.y]+1 : graph[c.x][c.y];
                q.push(n);
            }
            else if (hash[n.x][n.y] != hash[c.x][c.y])
            {
                //int cmp = ()graph[c.x][c.y]+n.t;
                if (graph[c.x][c.y]+n.t <= K)
                {
                    flag = IsSolved = true;
                    printf("Meet # %d %d %d %d || %d %d\n", c.x, c.y, n.x, n.y, graph[c.x][c.y], n.t);
                    printf("yes %d\n", graph[c.x][c.y]+n.t);
                    break;
                }
            }
            if (flag)
                break;
        }
    }/* End of While */
    if (!IsSolved)
        printf("no %d\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1728.txt", "r", stdin);
    freopen("E:\\hdoj_1728_ans.txt", "w", stdout);
#endif
       
    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                graph[i][j]=hash[i][j]=0;
                scanf("%c", &maze[i][j]);
            }
        }/* End of For */
        
        int sx, sy, tx, ty;
        scanf("%d %d %d %d %d", &K, &sy, &sx, &ty, &tx);
        
        bfs(sx-1, sy-1, tx-1, ty-1);
    }/* End of While */
    
    return 0;
}

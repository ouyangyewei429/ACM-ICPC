#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge
//#define Q   queue <Graph>

const int maxn = 149;

char maze[maxn][maxn];
bool hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  N, M, K, casenum, sx, sy, tx, ty;
struct Graph
{
    int x, y, t, k;
};

bool isout(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* isout */

void bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx-1, c.y = sy-1;
    c.t = c.k = 0;
    hash[sx-1][sy-1] = true;
    q.push(c);
    
    bool IsSolved=false;
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        //--------------------
        //printf("%d %d | %d %d\n", c.x, c.y, c.k, c.t);
        
        if (c.x==tx-1 && c.y==ty-1 && c.t<=K)
        {
            IsSolved = true;
            printf("yes\n");
            break;
        }/* End of If */
        
        for (int i=0; i<4; ++i)
        {
            n.k = i;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (c.x==sx-1 && c.y==sy-1)            
                n.t = c.t;
            else
                n.t = (i!=c.k) ? c.t+1 : c.t;
            
            if (isout(n.x, n.y) || maze[n.x][n.y]=='*'
                || hash[n.x][n.y])
                continue;
            
            hash[n.x][n.y] = true;
            q.push(n);
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
       
    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &maze[i][j]);
            }
        }/* End of For */
        
        scanf("%d %d %d %d %d", &K, &sy, &sx, &ty, &tx);
        
        //printf("# %d %d %d %d #\n\n", sx, sy, tx, ty);
        
        bfs();
    }/* End of While */
    
    return 0;
}

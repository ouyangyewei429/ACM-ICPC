#include <queue>
#include <stdio.h>
using namespace std;

//#define onlinejudge

const int maxn = 1010;

char ch;
bool hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  casenum, n, m, sx, sy, tx, ty, graph[maxn][maxn];
struct Graph
{
    int x, y, digs;
    const bool operator < (const struct Graph &t) const
    {
        return (t.digs < digs);
    }
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

int bfs()
{
    priority_queue <Graph> q;
    struct Graph cur, next;
    
    cur.x = sx-1;
    cur.y = sy-1;
    cur.digs = 0;
    hash[sx-1][sy-1] = true;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        
        if (cur.x==tx-1 && cur.y==ty-1)
            return cur.digs;
        
        for (int i=0; i<4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
                
            if (!hash[next.x][next.y] && IsInBound(next.x, next.y))
            {
                hash[next.x][next.y] = true;
                next.digs = cur.digs;
                if (graph[next.x][next.y])
                    next.digs++;
                q.push(next);
            }
        }/* End of For */
    }/* End of While */
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2822.txt", "r", stdin);
    freopen("E:\\hdoj_2822_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &m), n+m!=0)
    {
        for (int i=0; i<n; ++i)
        {
            getchar();
            for (int j=0; j<m; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &ch);
                if (ch == '.')
                    graph[i][j] = 1;
                else
                    graph[i][j] = 0;
            }
        }/* End of For */
        
        scanf("%d %d %d %d\n", &sx, &sy, &tx, &ty);
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}

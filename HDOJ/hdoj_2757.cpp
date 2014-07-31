#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 1004;

char maze[maxn][maxn];
bool hash[maxn][maxn][maxn];
int  r, c, n, sx, sy, tx, ty;
int  dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int  dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct Graph
{
    int x, y, t;
    
    bool operator < (const Graph &a) const
    {
        return a.t < t;
    }
};

void Init_Hash()
{
    for (int i=0; i<r; ++i)
    {
        for (int j=0; j<c; ++j)
        {
            for (int k=0; k<r*c; ++k)
                hash[i][j][k] = false;
        }
    }
}// Init_Hash


bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=r || y>=c);
}/* IsOut */

int bfs()
{
    priority_queue <Graph> q;
    struct Graph c, n;
    
    c.x=sx-1, c.y=sy-1, c.t=0;
    hash[sx-1][sy-1][0] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.top();
        q.pop();
        
        //---------------------------------------
        //printf("%d # %d %d -> %c\n", c.t, c.x, c.y, maze[c.x][c.y]);
        
        if (c.x==tx-1 && c.y==ty-1)
            return c.t;
        
        for (int i=0; i<8; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (maze[c.x][c.y]-'0' != i)
                n.t = c.t + 1;
            else
                n.t = c.t;
            
            if (hash[n.x][n.y][n.t] || IsOut(n.x, n.y))
                continue;

            hash[n.x][n.y][n.t] = true;
            q.push(n);
        }
    }/* End of While */
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2757.txt", "r", stdin);
    freopen("E:\\hdoj_2757_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &r, &c))
    {
        for (int i=0; i<r; ++i)
            scanf("%s", maze[i]);
        
        scanf("%d", &n);
        for (int i=0; i<n; ++i)
        {
            Init_Hash();
            //memset(hash, false, sizeof(hash));
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
            printf("%d\n", bfs());
        }
    }/* End of While */
    
    return 0;
}

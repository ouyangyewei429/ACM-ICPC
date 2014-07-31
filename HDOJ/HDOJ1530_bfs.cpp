#include <queue>
#include <cstdio>
using namespace std;

#define onlinejudge

const int maxn = 31;

char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  rNum, cNum, vis[maxn][maxn], cnt, IsSolved;

typedef struct graph
{
    int x, y, step;
}Graph;

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=rNum || y>=cNum)
        return false;
    
    return true;
}/* IsInBound */

void bfs(int sx, int sy)
{
    Graph cur, next; 
    queue <Graph> q;
    bool IsSolved = false;
    
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    q.push(cur);
    
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==rNum-1 && cur.y==cNum-1)
        {
            IsSolved = true;
            printf("%d\n", cur.step);
            
            break;
        }
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                
                if (!vis[next.x][next.y] && IsInBound(next.x, next.y)
                && maze[next.x][next.y]=='0')
                {
                    vis[next.x][next.y] = 1;
                    next.step = cur.step + 1;
                    
                    q.push(next);
                }
            }
        }
    }/* End of While */
    if (!IsSolved)
        printf("Impossible!\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1530.txt", "r", stdin);
    freopen("E:\\hdoj1530(ans).txt", "w", stdout);
#endif
    
    while (~scanf("%d %d", &rNum, &cNum))
    {
        for (int i=0; i<rNum; ++i)
        {
            for (int j=0; j<cNum; ++j)
            {
                maze[i][j] = '0';
                vis[i][j] = 0;
            }
        }/* End of For */
        
        for (int i=0; i<rNum; ++i)
            scanf("%s", maze[i]);
       
        bfs(0, 0);
    }/* End of While */
    
    return 0;
}

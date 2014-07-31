#include <queue>
#include <stdio.h>
using namespace std;

//#define onlinejudge

const int maxn = 10;

int vis[maxn][maxn];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Node
{
    int x, y, step;
}chess[maxn][maxn];

int bfs(int sx, int sy, int tx, int ty)
{
    queue <Node> q;
    struct Node cur, nt;
    
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    vis[sx][sy] = 1;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==tx && cur.y==ty)
            return cur.step;
        
        for (int i=0; i<8; ++i)
        {
            nt.x = cur.x + dx[i];
            nt.y = cur.y + dy[i];
            
            if (!vis[nt.x][nt.y] && nt.x>=0 && nt.y>=0
                && nt.x<8 && nt.y<8)
            {
                vis[nt.x][nt.y] = 1;
                nt.step = cur.step + 1;
                q.push(nt);
            }
        }
    }/* End of While */
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj 1372.txt", "r", stdin);
    freopen("E:\\hdoj 1372_ans.txt", "w", stdout);
#endif

    char sy, ty;
    int  sx, tx;
    
    while (~scanf("%c%d %c%d", &sy, &sx, &ty, &tx))
    {
        memset(vis, 0, sizeof(vis));
        memset(chess, 0, sizeof(chess));
        
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
        sy, sx, ty, tx, bfs(sx-1, sy-'a', tx-1, ty-'a'));
        
        getchar();
    }/* End of While */
    
    return 0;
}

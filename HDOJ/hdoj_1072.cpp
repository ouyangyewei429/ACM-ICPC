#include <queue>
#include <stdio.h>
using namespace std;

#define onlinejudge

const int maxn = 10;

bool IsSolved, hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  casenum, n, m, sx, sy, tx, ty, maze[maxn][maxn];
struct Graph
{
    int x, y, sec, bsec;
};
//-------------------------------------------
struct prev
{
    int px, py, sec, bsec;
}pn[maxn][maxn];
//-------------------------------------------
bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

//-------------------------------------------
void dfs(int x, int y, int s, int b)
{
    if (x!=sx && y!=sy)
        dfs(pn[x][y].px, pn[x][y].py, pn[x][y].sec, pn[x][y].bsec);
    
    printf("%d %d %d %d\n", x, y, s, b);
    return ;
}
//-------------------------------------------

void bfs()
{
    queue <Graph> q;
    struct Graph cur, next;
    
    cur.x = sx;
    cur.y = sy;
    cur.sec = 0;
    cur.bsec = 6;
    IsSolved = hash[sx][sy] = false;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        //-------------------------------------------
        //printf("%d %d %2d %d\n", cur.x, cur.y, cur.sec, cur.bsec);
        //-------------------------------------------
        
        if (maze[cur.x][cur.y]==3 && cur.bsec>0)
        {
            IsSolved = true;
            //dfs(cur.x, cur.y, cur.sec, cur.bsec);
            printf("%d\n", cur.sec);
            break;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            
            if (!hash[next.x][next.y] && maze[next.x][next.y]!=0
                && IsInBound(next.x, next.y))
            {
                hash[next.x][next.y] = true;
                next.sec = cur.sec + 1;
                next.bsec = cur.bsec - 1;
                                
                if (maze[next.x][next.y]==4 && next.bsec>0)
                {
                    next.bsec = 6;  /* Boom-Reset-place */
                }    
                if (next.bsec > 0)
                {
                    /****
                    pn[next.x][next.y].px = cur.x;
                    pn[next.x][next.y].py = cur.y;
                    pn[next.x][next.y].sec = cur.sec;
                    pn[next.x][next.y].bsec = cur.bsec;
                    ****/
                    
                    q.push(next);   /* pushing the current post into queue */
                }    
            }
        }
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1072.txt", "r", stdin);
    freopen("E:\\hdoj_1072_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                hash[i][j] = false;
                scanf("%d", &maze[i][j]);
                if (maze[i][j] == 2)
                    sx = i, sy = j;
            }
        }/* End of For */
        
        bfs();
    }/* End of While */
    
    return 0;
}

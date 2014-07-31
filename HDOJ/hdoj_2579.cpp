#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 104;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn][15];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  T, N, M, K, sx, sy, tx, ty;
struct Graph
{
    int x, y, t;
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=N || y>=M)
        return false;
    
    return true;
}/* IsInBound */

void bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx;
    c.y = sy;
    c.t = 0;
    hash[sx][sy][0] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            break;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.t = c.t + 1;
            
            if (!IsInBound(n.x, n.y) || hash[n.x][n.y][n.t%K])
                continue;
            
            if (maze[n.x][n.y] == '.')
            {
                hash[n.x][n.y][n.t%K] = true;
                q.push(n);
            }
            else
            {
                if (n.t%K == 0)
                {
                    hash[n.x][n.y][n.t%K] = true;
                    q.push(n);
                }    
            }
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("Please give me another chance!\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2579.txt", "r", stdin);
    freopen("E:\\hdoj_2579_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        memset(hash, false, sizeof(hash));
        
        scanf("%d %d %d", &N, &M, &K);
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    sx = i, sy = j;
                if (maze[i][j] == 'G')
                    tx = i, ty = j;
            }
        }/* End of For */
        /***
        for (int i=0; i<N; ++i)
            printf("%s\n", maze[i]);
        ****/
        IsSolved = false;
        maze[sx][sy] = maze[tx][ty] = '.';
        bfs();
    }/* End of While */
    
    return 0;
}

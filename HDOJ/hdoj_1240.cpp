#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 12;

char cmd[10], maze[maxn][maxn][maxn];
bool IsSolved, hash[maxn][maxn][maxn];
int  N, sx, sy, sz, tx, ty, tz;
int  dx[] = {-1, 1, 0, 0, 0, 0};
int  dy[] = {0, 0, -1, 1, 0, 0};
int  dz[] = {0, 0, 0, 0, 1, -1};    /* Up_Down */
struct Graph
{
    int x, y, z, t;
};

bool IsInBound(int x, int y, int z)
{
    if (x<0 || y<0 || z<0)
        return false;
    if (x>=N || y>=N || z>=N)
        return false;
        
    return true;
}/* IsInBound */

void bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx, c.y = sy;
    c.z = sz, c.t = 0;
    hash[sz][sy][sx] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.z==tz)
        {
            IsSolved = true;
            printf("%d %d\n", N, c.t);
            break;
        }/* End of IF */
        
        for (int i=0; i<6; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.z = c.z + dz[i];
            n.t = c.t + 1;
            
            if (!hash[n.z][n.y][n.x] && IsInBound(n.x, n.y, n.z)
                && maze[n.z][n.y][n.x]=='O')
            {
                hash[n.z][n.y][n.x] = true;
                q.push(n);
            }
        }
    }/* End of While */
    if (!IsSolved)
        printf("NO ROUTE\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1240.txt", "r", stdin);
    freopen("E:\\hdoj_1240_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", cmd))
    {
        memset(hash, false, sizeof(hash));
        
        if (cmd[0] == 'S')
        {
            scanf("%d", &N);
            for (int z=0; z<N; ++z)
            {
                for (int x=0; x<N; ++x)
                    scanf("%s", maze[z][x]);
            }
            
            scanf("%d %d %d\n", &sy, &sx, &sz);
            scanf("%d %d %d\n", &ty, &tx, &tz);
            
            IsSolved = false;
            bfs();
            /****
            for (int z=0; z<N; ++z)
            {
                for (int x=0; x<N; ++x)
                {
                    for (int y=0; y<N; ++y)
                        printf("%c", maze[z][x][y]);
                    printf("\n");
                }
                printf("\n");
            }
            ****/
        }    
    }/* End of While */
    
    return 0;
}

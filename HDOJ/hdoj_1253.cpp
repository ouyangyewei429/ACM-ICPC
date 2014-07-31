#include <queue>
#include <stdio.h>
using namespace std;

//#define onlinejudge

const int maxn = 60;

int dx[] = {0, 0, 0, 0, -1, 1}; /* left_right */
int dy[] = {0, 0, 1, -1, 0, 0}; /* front_back */
int dz[] = {-1, 1, 0, 0, 0, 0}; /* up_down */
bool hash[maxn][maxn][maxn];
int  maze[maxn][maxn][maxn];
int  K, A, B, C, T;
struct Graph
{
    int x, y, z, t;
};

int IsInBound(int x, int y, int z)
{
    if (x<0 || y<0 || z<0)
        return false;
    if (x>=A || z>=B || y>=C)
        return false;
    
    return true;
}/* IsInBound */

int bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x = c.y = 0;
    c.z = c.t = 0;
    hash[0][0][0] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==A-1 && c.z==B-1 && c.y==C-1 && c.t<=T)
            return c.t;
        
        for (int i=0; i<6; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.z = c.z + dz[i];
            n.t = c.t + 1;
            
            if (!hash[n.x][n.z][n.y] && IsInBound(n.x, n.y, n.z)
                && maze[n.x][n.z][n.y]==0)
            {
                hash[n.x][n.z][n.y] = true;
                q.push(n);
            }
        }
    }/* End of While */
    
    return -1;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1253.txt", "r", stdin);
    freopen("E:\\hdoj_1253_ans.txt", "w", stdout);
#endif

    scanf("%d", &K);
    while (K--)
    {
        scanf("%d %d %d %d", &A, &B, &C, &T);
        for (int x=0; x<A; ++x)
        {
            for (int z=0; z<B; ++z)
            {
                for (int y=0; y<C; ++y)
                {
                    hash[x][z][y] = false;
                    scanf("%d", &maze[x][z][y]);
                }
            }
        }/* End of For */
        /***
        for (int x=0; x<A; ++x)
        {
            for (int z=0; z<B; ++z)
            {
                for (int y=0; y<C; ++y)
                    printf("%d ", maze[x][z][y]);
                printf("\n");
            }
            printf("\n");
        }
        ****/
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}

#include <queue>
#include <cmath>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 10;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn];
int  N, M, T, sx, sy, tx, ty;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
struct Graph
{
    int x, y, t;
};

void bfs()
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.x=sx, c.y=sy, c.t=0;
    hash[sx][sy] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.t==T)
        {
            IsSolved = true;
            printf("YES\n");
            break;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.t = c.t + 1;
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (maze[n.x][n.y]=='X' || hash[n.x][n.y] || n.t>T)
                continue;
            if (abs(n.x-tx)+abs(n.y-ty) != T-n.t)
                continue;
            
            if (maze[n.x][n.y])
            hash[n.x][n.y] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1010.txt", "r", stdin);
    freopen("E:\\hdoj_1010_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &N, &M, &T), N+M+T!=0)
    {
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'S')
                    sx=i, sy=j;
                if (maze[i][j] == 'D')
                    tx=i, ty=j;
            }
        }/* End of For */
        
        IsSolved = false;
        bfs();
    }/* End of While */
    
    return 0;
}

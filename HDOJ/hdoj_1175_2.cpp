#include <stdio.h>
#include <memory.h>

#define onlinejudge

const int maxn = 1004;

bool IsSolved, hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  graph[maxn][maxn], maze[maxn][maxn];
int  N, M, Q, sx, sy, tx, ty;

void Init_Graph()
{
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            hash[i][j] = false;
            graph[i][j] = 0x3F3F3F3F;
        }    
    }
}/* Init_Graph */

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void dfs(int x, int y, int dir, int t)
{
    if (x==tx-1 && y==ty-1 && t<=2)
    {
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=0; i<4; ++i)
    {
        int nt = t;
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (dir!=4 && i!=dir)
            nt = t+1;
        
        if (IsOut(nx, ny) || nt>2 || hash[nx][ny])
            continue;

        if (nt == 1)
        {            
            //if (dir==0 && tx-1-x>=0)    continue;
            //if (dir==1 && tx-1-x<=0)    continue;
            //if (dir==2 && ty-1-y>=0)    continue;
            //if (dir==3 && ty-1-y<=0)    continue;
        }

        if (maze[nx][ny]==0 || (nx==tx-1 && ny==ty-1))
        {
            if (graph[nx][ny] >= nt)
            {
                graph[nx][ny] = nt;
                
                hash[nx][ny] = true;
                dfs(nx, ny, i, t);
                hash[nx][ny] = false;
            }
        }
        else
            continue;
    }/* End of For */
    
    return ;
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1175.txt", "r", stdin);
    freopen("E:\\hdoj_1175_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<M; ++j)
                scanf("%d", &maze[i][j]);
        }/* End of For */
        
        scanf("%d", &Q);
        for (int i=0; i<Q; ++i)
        {
            Init_Graph();
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
            
            if (!maze[sx-1][sy-1] || !maze[tx-1][ty-1]
                || maze[sx-1][sy-1]!=maze[tx-1][ty-1]
                || (sx==tx && sy==ty))
            {
                printf("NO\n");
                continue;
            }/* End of IF */
            
            IsSolved = false;
            hash[sx-1][sy-1] = true;
            dfs(sx-1, sy-1, 4, 0); /* x, y, dir, t */
            if (IsSolved)
                printf("YES\n");
            else
                printf("NO\n");
        }/* End of For */
    }/* End of While */
    
    return 0;
}

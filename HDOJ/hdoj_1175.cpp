#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 1004;

bool IsSolved, hash[maxn][maxn];
int  N, M, Q, sx, sy, tx, ty, maze[maxn][maxn];
int  dx[] = {-1, 0, 1, 0};
int  dy[] = {0, 1, 0, -1};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void dfs(int x, int y, int k, int dir)
{
    //--------------------------------
    //printf("%d %d ---- %d %d\n", x, y, k-1, dir);
    
    if (x==tx-1 && y==ty-1 && k-1<=2)
    {
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (hash[nx][ny] || IsOut(nx, ny))
            continue;
        
        int nk = (i!=dir ? k+1 : k);
        hash[nx][ny] = true;
        dfs(nx, ny, nk, i);
        hash[nx][ny] = false;
    }
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
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                scanf("%d", &maze[i][j]);
            }
        }/* End of For */

        scanf("%d", &Q);
        for (int i=0; i<Q; ++i)
        {
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
    
            if (!maze[sx-1][sy-1] || !maze[tx-1][ty-1]
                || maze[sx-1][sy-1]!=maze[tx-1][ty-1])
                printf("NO\n");
            else
            {
                IsSolved = false;
                dfs(sx-1, sy-1, 0, -1);
                if (IsSolved)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }/* End of While */
    
    return 0;
}

#include <cstdlib>
#include <cstdio>

//#define onlinejudge

const int maxn = 10;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn];
int  N, M, T, sx, sy, tx, ty;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int t)
{
    if (x==tx && y==ty && t==T)
    {
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (hash[nx][ny] || maze[nx][ny]=='X' || t+1>T)
            continue;
        if (abs(nx-tx)+abs(ny-ty) > T-t-1)
            continue;
        
        hash[nx][ny] = true;
        dfs(nx, ny, t+1);
        hash[nx][ny] = false;
    }/* End of For */
}/* dfs */

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
        
        IsSolved = false, hash[sx][sy] = true;
        
        dfs(sx, sy, 0);
        if (!IsSolved)
            printf("NO\n");
        else
            printf("YES\n");
    }/* End of While */
    
    return 0;
}

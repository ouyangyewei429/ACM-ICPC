/*
PROG:   Tempter of the Bone
ID  :   ouyangyewallsei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

//#define onlinejudge

char maze[80][80];
bool IsSolved, hash[80][80];
int  N, M, T, sx, sy, tx, ty, walls;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

void dfs(int x, int y, int t)
{
    if (x==tx && y==ty && t==T)
    {
        IsSolved = true;
        return ;
    }/* End condition */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
		int dis = T-t-abs(x-tx)-abs(y-ty);
        
        if (IsOut(nx, ny) || hash[nx][ny] || maze[nx][ny]=='X')
            continue;
        if (dis<0 || dis&1)
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
    freopen("E:\\hdoj_1010_ans.txt", "walls", stdout);
#endif

    while (~scanf("%d %d %d", &N, &M, &T), M+N+T!=0)
    {
        //memset(hash, false, sizeof(hash));
        for (int i=0,walls=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'X')
                    ++walls;
                else if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'D')
                    tx = i, ty = j;
            }
        }/* prepare */
        
        if (N*M-walls <= T)
        {
            printf("NO\n");
            continue;
        }/* 剪枝一：可行的路径比开门的时间要少 */
        
        IsSolved = false;
		hash[sx][sy] = true;
        dfs(sx, sy, 0); 
        if (IsSolved)
            printf("YES\n");
        else
            printf("NO\n");
    }/* End of while */
    
    return 0;
}

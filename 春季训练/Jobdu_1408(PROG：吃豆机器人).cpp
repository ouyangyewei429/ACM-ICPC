/**
 * PROG: ³Ô¶¹»úÆ÷ÈË
 */
#include <cstdio>
#include <memory.h>

const int MAX_SIZE = 1024;
const int DIR_X[] = {0, 1};
const int DIR_Y[] = {1, 0};

int  g_nPath;
int  g_width, g_height;
bool g_visit[MAX_SIZE][MAX_SIZE] = {false};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=g_height || y>=g_width)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int x, int y)
{
    if (x==g_height-1 && y==g_width-1)
    {
        g_nPath = (g_nPath + 1) % 10009;
        return ;
    }

    for (int dir=0; dir<2; ++dir)
    {
        int next_x = x + DIR_X[dir];
        int next_y = y + DIR_Y[dir];
        if (IsInBound(next_x, next_y) && !g_visit[next_x][next_y])
        {   // out of bound
            g_visit[next_x][next_y] = true;
            dfs(next_x, next_y);
            g_visit[next_x][next_y] = false;
        }
    }
}

int main(void)
{
    while (~scanf("%d %d", &g_width, &g_height))
    {
        g_nPath = 0;
        memset(g_visit, false, sizeof(g_visit));
        g_visit[0][0] = true;
        dfs(0, 0);
        printf("%d\n", g_nPath);
    }

    return 0;
}

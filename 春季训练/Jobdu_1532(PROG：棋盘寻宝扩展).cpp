/**
 * PROG: ∆Â≈Ã—∞±¶¿©’π
 */
#include <cstdio>

const int CHESS_SIZE = 8;
const int FROM_X = 0;
const int FROM_Y = 0;
const int TO_X = CHESS_SIZE - 1;
const int TO_Y = CHESS_SIZE - 1;

const int DIR_COUNT = 2;
const int DIR_X[] = {1, 0};  // South, East
const int DIR_Y[] = {0, 1};  // South, East

int  g_maxValue;
int  g_maxLimit;
int  g_chess[CHESS_SIZE][CHESS_SIZE] = {0};
bool g_visit[CHESS_SIZE][CHESS_SIZE] = {false};

bool IsInBound(const int x, const int y)
{
    if (x<0 || y<0 || x>=CHESS_SIZE || y>=CHESS_SIZE)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int x, int y, int value)
{
    if (x==TO_X && y==TO_Y)
    {
        if (value > g_maxValue)
        {
            g_maxValue = value;
        }
        return ;
    }

    for (int dir=0; dir<DIR_COUNT; ++dir)
    {
        int next_x = x + DIR_X[dir];
        int next_y = y + DIR_Y[dir];
        if (IsInBound(next_x, next_y)
            && !g_visit[next_x][next_y]
            && value+g_chess[next_x][next_y]<=g_maxLimit)
        {
            g_visit[next_x][next_y] = true;
            dfs(next_x, next_y, value+g_chess[next_x][next_y]);
            g_visit[next_x][next_y] = false;
        }
    }
}

int main(void)
{
    while (~scanf("%d", &g_maxLimit))
    {
        for (int i=0; i<CHESS_SIZE; ++i)
        {
            for (int j=0; j<CHESS_SIZE; ++j)
            {
                g_visit[i][j] = false;
                scanf("%d", &g_chess[i][j]);
            }
        }

        g_maxValue = -1;
        g_visit[FROM_X][FROM_Y] = true;
        dfs(FROM_X, FROM_Y, g_chess[FROM_X][FROM_Y]);

        printf("%d\n", g_maxValue);
    }

    return 0;
}

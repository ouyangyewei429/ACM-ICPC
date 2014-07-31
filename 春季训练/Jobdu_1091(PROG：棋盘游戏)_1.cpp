/**
 * PROG: ∆Â≈Ã”Œœ∑
 */
#include <queue>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 6;
const int DIR_X[] = {-1, 1, 0, 0};
const int DIR_Y[] = {0, 0, -1, 1};

int  g_minCost;
int  g_chess[MAX_SIZE][MAX_SIZE] = {0};
bool g_visit[MAX_SIZE][MAX_SIZE] = {false};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=MAX_SIZE || y>=MAX_SIZE)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int x, int y, int to_x, int to_y, int cost, int state)
{
    if (x==to_x && y==to_y)
    {
        if (cost < g_minCost)
        {
            g_minCost = cost;
        }
        return ;
    }

    for (int dir=0; dir<4; ++dir)
    {
        int next_x = x + DIR_X[dir];
        int next_y = y + DIR_Y[dir];
        if (IsInBound(next_x, next_y) && !g_visit[next_x][next_y])
        {
            int next_cost = cost + state * g_chess[next_x][next_y];
            int next_state = (state * g_chess[next_x][next_y]) % 4 + 1;
            if (next_cost < g_minCost)
            {
                g_visit[next_x][next_y] = true;
                dfs(next_x, next_y, to_x, to_y, next_cost, next_state);
                g_visit[next_x][next_y] = false;
            }
        }
    }
}

int main(void)
{
    int nCases;
    int from_x, from_y, to_x, to_y;

    scanf("%d", &nCases);
    while (nCases--)
    {
        for (int i=0; i<MAX_SIZE; ++i)
        {
            for (int j=0; j<MAX_SIZE; ++j)
            {
                g_visit[i][j] = false;
                scanf("%d", &g_chess[i][j]);
            }
        }
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);

        if (from_x==to_x && from_y==to_y)
        {
            printf("%d\n", g_chess[to_x][to_y]);
        }
        else
        {
            g_minCost = 0x3fffffff;
            g_visit[from_x][from_y] = true;
            dfs(from_x, from_y, to_x, to_y, 0, 1);
            printf("%d\n", g_minCost);
        }
    }// End of While

    return 0;
}

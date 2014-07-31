/**
 * PROG: ∆Â≈Ã”Œœ∑
 */
#include <queue>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 6;
const int DIR_X[] = {-1, 1, 0, 0};
const int DIR_Y[] = {0, 0, -1, 1};

int  g_chess[MAX_SIZE][MAX_SIZE] = {0};
bool g_visit[MAX_SIZE][MAX_SIZE] = {false};

struct Step
{
    int m_x;
    int m_y;
    int m_cost;
    int m_state;

    Step(int x, int y, int cost, int state)
    {
        m_x = x;
        m_y = y;
        m_cost = cost;
        m_state = state;
    }
};

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

void bfs(const int from_x, const int from_y, const int to_x, const int to_y)
{
    int min_cost = 0x3fffffff;

    queue<Step> q;
    Step start(from_x, from_y, 0, 1);
    q.push(start);

    while (!q.empty())
    {
        Step current = q.front();
        q.pop();

        if (current.m_x==to_x && current.m_y==to_y)
        {
            printf("** %d %d %d **\n", current.m_x, current.m_y, current.m_cost);  // debug.........................

            if (current.m_cost < min_cost)
            {
                min_cost = current.m_cost;
            }
        }

        for (int dir=0; dir<4; ++dir)
        {
            int next_x = current.m_x + DIR_X[dir];
            int next_y = current.m_y + DIR_Y[dir];
            if (IsInBound(next_x, next_y) && !g_visit[next_x][next_y])
            {
                int next_cost = current.m_cost + current.m_state * g_chess[next_x][next_y];
                int next_state = (current.m_state * g_chess[next_x][next_y]) % 4 + 1;
                Step next(next_x, next_y, next_cost, next_state);
                q.push(next);

                g_visit[next_x][next_y] = true;
            }
        }
    }
    printf("%d\n", min_cost);
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

        bfs(from_x, from_y, to_x, to_y);
    }// End of While

    return 0;
}

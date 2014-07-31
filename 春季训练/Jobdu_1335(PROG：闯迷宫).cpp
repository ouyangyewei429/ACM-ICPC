/**
 * PROG: ¥≥√‘π¨
 */
#include <queue>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 128;
const int DIR_X[] = {-1, 1, 0, 0};
const int DIR_Y[] = {0, 0, -1, 1};

int  g_size;
int  g_maze[MAX_SIZE][MAX_SIZE] = {0};
bool g_visit[MAX_SIZE][MAX_SIZE] = {false};

struct Node
{
    int m_x;
    int m_y;
    int m_nSteps;

    Node(int x, int y, int steps)
    {
        m_x = x;
        m_y = y;
        m_nSteps = steps;
    }
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=g_size || y>=g_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int from_x, int from_y, int to_x, int to_y)
{
    bool isFindPath = false;

    Node start(from_x, from_y, 0);
    queue<Node> q;
    q.push(start);
    g_visit[from_x][from_y] = true;

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        if (current.m_x==to_x && current.m_y==to_y)
        {
            isFindPath = true;
            printf("%d\n", current.m_nSteps);
            break;
        }

        for (int dir=0; dir<4; ++dir)
        {
            int next_x = current.m_x + DIR_X[dir];
            int next_y = current.m_y + DIR_Y[dir];
            if (IsInBound(next_x, next_y)
                && 0==g_maze[next_x][next_y]
                && !g_visit[next_x][next_y])
            {
                int next_step = current.m_nSteps + 1;
                Node next(next_x, next_y, next_step);
                q.push(next);

                g_visit[next_x][next_y] = true;
            }
        }
    }
    if (!isFindPath)
    {
        printf("-1\n");
    }
}

int main(void)
{
    while (~scanf("%d", &g_size))
    {
        for (int i=0; i<g_size; ++i)
        {
            for (int j=0; j<g_size; ++j)
            {
                g_visit[i][j] = false;
                scanf("%d", &g_maze[i][j]);
            }
        }

        if (0!=g_maze[0][0] || 0!=g_maze[g_size-1][g_size-1])
        {
            printf("-1\n");
        }
        else
        {
            bfs(0, 0, g_size-1, g_size-1);
        }
    }// End of While

    return 0;
}

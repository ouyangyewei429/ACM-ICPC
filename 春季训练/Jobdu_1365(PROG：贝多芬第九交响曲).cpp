/**
 * PROG: ±´¶à·ÒµÚ¾Å½»ÏìÇú
 */
#include <queue>
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAX_SIZE = 128;
const int DIR_X[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int DIR_Y[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int  g_size;
//int  g_chess[MAX_SIZE][MAX_SIZE] = {0};
bool g_visit[MAX_SIZE][MAX_SIZE] = {false};

struct Node
{
    int m_x;
    int m_y;
    int m_step;

    Node(int x, int y, int step)
    {
        m_x = x;
        m_y = y;
        m_step = step;
    }
};

bool IsInBound(const int x, const int y)
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

void bfs(const int from_x, const int from_y, const int to_x, const int to_y)
{
    bool isFindPath = false;

    Node start(from_x, from_y, 0);
    queue<Node> q;
    q.push(start);

    memset(g_visit, false, sizeof(g_visit));
    g_visit[from_x][from_y] = true;

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        if (current.m_x==to_x && current.m_y==to_y)
        {
            isFindPath = true;
            printf("%d\n", current.m_step);
            break;
        }

        for (int dir=0; dir<8; ++dir)
        {
            int next_x = current.m_x + DIR_X[dir];
            int next_y = current.m_y + DIR_Y[dir];
            if (IsInBound(next_x, next_y) && !g_visit[next_x][next_y])
            {
                int next_step = current.m_step + 1;
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
    int from_x, from_y, to_x, to_y;
    while (~scanf("%d", &g_size))
    {
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        bfs(from_x-1, from_y-1, to_x-1, to_y-1);
    }

    return 0;
}

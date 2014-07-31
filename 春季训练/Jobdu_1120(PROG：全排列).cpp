/**
 * PROG: х╚ееап
 */
#include <cstring>
#include <cstdio>
#include <memory.h>

const int MAX_SIZE = 6;

int  g_length;
char g_bunch[MAX_SIZE] = {0};
bool g_visit[MAX_SIZE] = {false};

void dfs(char szOrder[], int count)
{
    if (count == g_length)
    {
        printf("%s\n", szOrder);
        return ;
    }

    for (int i=0; i<g_length; ++i)
    {
        if (!g_visit[i])
        {
            g_visit[i] = true;
            szOrder[count] = g_bunch[i];
            dfs(szOrder, count+1);
            g_visit[i] = false;
        }
    }
}

int main(void)
{
    while (EOF != scanf("%s", g_bunch))
    {
        g_length = strlen(g_bunch);
        for (int i=0; i<g_length; ++i)
        {
            memset(g_visit, false, sizeof(g_visit));

            g_visit[i] = true;
            char szOrder[MAX_SIZE] = {0};
            szOrder[0] = g_bunch[i];
            dfs(szOrder, 1);
        }
        printf("\n");
    }// End of While

    return 0;
}

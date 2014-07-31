/**
 * PROG: 寻找最长合法括号序列II
 */
#include <cstdio>
#include <cstring>

const int MAX_STACK_SIZE = 1000004;

char g_bunch[MAX_STACK_SIZE] = {0};
char g_stack[MAX_STACK_SIZE] = {0};

int main(void)
{
    while (EOF != scanf("%s", g_bunch))
    {
        int top = 0;
        int length = 0;
        int strLen = strlen(g_bunch);
        for (int i=0; i<strLen; ++i)
        {
            if ('(' == g_bunch[i])
            {
                g_stack[top++] = g_bunch[i];
            }
            else if (')' == g_bunch[i])
            {
                if ('(' == g_stack[top-1])
                {
                    length += 2;
                    g_stack[--top] = '\0';
                }
                else
                {
                    g_stack[top++] = g_bunch[i];
                }
            }
        }
        printf("%d\n", length);
    }
    return 0;
}

/**
 * PROG: a+b
 */
#include <cstdio>
#include <cstring>
#include <memory.h>

const int MAX_NUMBER_SIZE = 1024;

char g_a[MAX_NUMBER_SIZE] = {0};
char g_b[MAX_NUMBER_SIZE] = {0};
int g_sum[MAX_NUMBER_SIZE] = {0};

int main(void)
{
    //char number_a[MAX_NUMBER_SIZE] = {0};
    //char number_b[MAX_NUMBER_SIZE] = {0};
    while (EOF != scanf("%s %s", g_a, g_b))
    {
        //printf("%s %s\n", g_a, g_b);
        int len_a = strlen(g_a);
        int len_b = strlen(g_b);
        int loops = (len_a > len_b ? len_a : len_b);
        for (int i=loops-1; i>=0; --i)
        {
            g_sum
        }

        memset(g_a, 0, sizeof(g_a));
        memset(g_b, 0, sizeof(g_b));
    }// End of while
    return 0;
}

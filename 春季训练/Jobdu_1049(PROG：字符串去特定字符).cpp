/**
 * PROG: ×Ö·û´®È¥ÌØ¶¨×Ö·û
 */
#include <cstdio>
#include <cstring>

const int MAX_SIZE = 4096;

char g_szBunch[MAX_SIZE] = {0};

int main(void)
{
    int  strLen;
    char target[5] = {0};

    while (EOF != scanf("%s", g_szBunch))
    {
        scanf("%s", target);

        strLen = strlen(g_szBunch);
        for (int i=0; i<strLen; ++i)
        {
            if (target[0] != g_szBunch[i])
            {
                printf("%c", g_szBunch[i]);
            }
        }
        printf("\n");
    }

    return 0;
}

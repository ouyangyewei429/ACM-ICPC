/**
 * PROG: Êı×éÄæÖÃ
 */
#include <cstdio>
#include <cstring>

const int MAX_STRING_SIZE = 256;

char g_szBunch[MAX_STRING_SIZE] = {0};

int main(void)
{
    while (gets(g_szBunch))
    {
        int strLen = strlen(g_szBunch);
        for (int i=strLen-1; i>=0; --i)
        {
            printf("%c", g_szBunch[i]);
        }
        printf("\n");
    }
    return 0;
}

/**
 * PROG: ’“Œª÷√
 */
#include <cstdio>
#include <cstring>

const int MAX_STRING_SIZE = 128;

char g_szBunch[MAX_STRING_SIZE] = {0};

int main(void)
{
    while (EOF != scanf("%s", g_szBunch))
    {
        int strLen = strlen(g_szBunch);
        for (int i=0; i<strLen; ++i)
        {
            bool isFirstOutput = true;
            for (int j=i+1; j<strLen; ++j)
            {
                if ('#'!=g_szBunch[i] && g_szBunch[i]==g_szBunch[j])
                {
                    if (isFirstOutput)
                    {
                        isFirstOutput = false;
                        printf("%c:%d,%c:%d", g_szBunch[i], i, g_szBunch[i], j);
                    }
                    else
                    {
                        printf(",%c:%d", g_szBunch[j], j);
                    }
                    g_szBunch[j] = '#';
                }
            }
            if (!isFirstOutput)
            {
                printf("\n");
            }
        }
    }
    return 0;
}

/**
 * PROG: ×Ó´®ÄæÐò´òÓ¡
 */
#include <cstdio>
#include <cstring>

const int MAX_SIZE = 100004;

char g_szBunch[MAX_SIZE] = {0};

int main(void)
{
    int strLen = 0;
    while (~scanf("%d", &strLen))
    {
        if (0 == strLen)
        {
            break;
        }

        getchar();
        gets(g_szBunch);

        int isFirstPart = 1;
        char *pStr = strtok(g_szBunch, " ");
        while (NULL != pStr)
        {
            if (0 == isFirstPart)
            {
                printf(" ");
            }
            else
            {
                isFirstPart = 0;
            }
            int partLen = strlen(pStr);
            for (int i=partLen-1; i>=0; --i)
            {
                printf("%c", pStr[i]);
            }

            pStr = strtok(NULL, " ");
        }
        printf("\n");
    }// End of While

    return 0;
}

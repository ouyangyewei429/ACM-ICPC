/**
 * PROG: ×Ó´®ÄæÐò´òÓ¡
 */
#include <cstdio>
#include <cstring>

const int MAX_STRING_SIZE = 100004;

char g_string[MAX_STRING_SIZE] = {0};

int main(void)
{
    int strLen;
    while (~scanf("%d", &strLen))
    {
        if (0 == strLen)
        {
            break;
        }

        gets(g_string);
        gets(g_string);
        //printf("%s\n", g_string);
        if (' ' == g_string[0])
        {
            printf(" ");
        }
        bool isFirstOutput = true;
        char *pStr = strtok(g_string, " ");
        while (NULL != pStr)
        {
            if (!isFirstOutput)
            {
                printf(" ");
            }
            int partLen = strlen(pStr);
            for (int i=partLen-1; i>=0; --i)
            {
                printf("%c", pStr[i]);
            }
            //printf("* %s *\n", pStr);
            isFirstOutput = false;
            pStr = strtok(NULL, " ");
        }
        if (' ' == g_string[strLen-1])
        {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}

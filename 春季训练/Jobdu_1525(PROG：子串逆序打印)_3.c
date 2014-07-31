/**
 * PROG: ×Ó´®ÄæÐò´òÓ¡
 */
#include <stdio.h>

#define MAX_STRING_SIZE 100004

char g_string[MAX_STRING_SIZE] = {0};

int main(void)
{
    int i, j, start;
    int strLen;

    while (~scanf("%d", &strLen))
    {
        if (0 == strLen)
        {
            break;
        }

        gets(g_string);
        gets(g_string);

        start = 0;
        if (' ' == g_string[start])
        {
            printf(" ");
            while (' ' == g_string[start])
            {
                ++start;
            }
        }
        for (i=start; i<strLen; ++i)
        {
            if (' ' == g_string[i])
            {
                for (j=i-1; j>=start; --j)
                {
                    printf("%c", g_string[j]);
                }
                printf(" ");
                while (' ' == g_string[i])
                {
                    ++i;
                }
                start = i;
                --i;
            }
        }
        if (' ' != g_string[strLen-1])
        {
            for (j=strLen-1; j>=start; --j)
            {
                printf("%c", g_string[j]);
            }
        }
        printf("\n");
    }
    return 0;
}

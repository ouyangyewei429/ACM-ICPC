/**
 * PROG: ZOJ
 */
#include <cstdio>
#include <cstring>

const int MAX_SIZE = 128;

int main(void)
{
    char szBunch[MAX_SIZE] = {0};
    while (EOF != scanf("%s", szBunch))
    {
        if ('E' == szBunch[0])
        {
            break;
        }

        int nZOJ[3] = {0};
        int strLen = strlen(szBunch);
        for (int i=0; i<strLen; ++i)
        {
            if ('Z' == szBunch[i])
            {
                ++nZOJ[0];
            }
            else if ('O' == szBunch[i])
            {
                ++nZOJ[1];
            }
            else if ('J' == szBunch[i])
            {
                ++nZOJ[2];
            }
        }

        while (0 != nZOJ[0]+nZOJ[1]+nZOJ[2])
        {
            if (nZOJ[0] > 0)
            {
                printf("Z");
                --nZOJ[0];
            }
            if (nZOJ[1] > 0)
            {
                printf("O");
                --nZOJ[1];
            }
            if (nZOJ[2] > 0)
            {
                printf("J");
                --nZOJ[2];
            }
        }
        printf("\n");
    }// End of While

    return 0;
}

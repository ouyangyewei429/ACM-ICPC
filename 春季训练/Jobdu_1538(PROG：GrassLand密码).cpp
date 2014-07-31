/**
 * PROG: GrassLand√‹¬Î
 */
#include <cstdio>
#include <cstring>

const int MAX_CODE_SIZE = 10004;

char *g_decode[] = {
    "", "", "abc",
    "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

int GetCodeBy(char key)
{
    char **ptr = g_decode;
    for (int i=2; ; ++i)
    {
        int codeSize = strlen(*(ptr+i));
        for (int j=0; j<codeSize; ++j)
        {
            if (key == ptr[i][j])
            {
                return i;
            }
        }
    }
}

int main(void)
{
    char szCode[MAX_CODE_SIZE] = {0};
    while (EOF != scanf("%s", szCode))
    {
        int strLen = strlen(szCode);
        for (int i=0; i<strLen; ++i)
        {
            printf("%d", GetCodeBy(szCode[i]));
        }
        printf("\n");
    }
    return 0;
}

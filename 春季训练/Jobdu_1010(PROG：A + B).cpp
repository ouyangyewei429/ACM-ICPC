/**
 * PROG: A + B
 */
#include <cstdio>
#include <cstring>

const int MAX_SIZE = 64;

char g_szFormula[MAX_SIZE];

int GetIntValue(const char* pNumber)
{
    if ('+' == *pNumber)
    {
        return -1;
    }
    if ('=' == *pNumber)
    {
        return -2;
    }
    if (0 == strcmp("zero", pNumber))
    {
        return 0;
    }
    if (0 == strcmp("one", pNumber))
    {
        return 1;
    }
    if (0 == strcmp("two", pNumber))
    {
        return 2;
    }
    if (0 == strcmp("three", pNumber))
    {
        return 3;
    }
    if (0 == strcmp("four", pNumber))
    {
        return 4;
    }
    if (0 == strcmp("five", pNumber))
    {
        return 5;
    }
    if (0 == strcmp("six", pNumber))
    {
        return 6;
    }
    if (0 == strcmp("seven", pNumber))
    {
        return 7;
    }
    if (0 == strcmp("eight", pNumber))
    {
        return 8;
    }
    if (0 == strcmp("nine", pNumber))
    {
        return 9;
    }
}

int main(void)
{
    while (NULL != gets(g_szFormula))
    {
        if (0 == strcmp("zero + zero =", g_szFormula))
        {
            break;
        }

        int  val_a = 0;
        int  val_b = 0;
        bool isSecond = false;
        char *pNumber = strtok(g_szFormula, " ");
        while (NULL != pNumber)
        {   //printf("%s\n", pNumber);
            int ret = GetIntValue(pNumber);
            if (-2 == ret)
            {
                break;
            }
            if (-1 == ret)
            {
                isSecond = true;
            }
            else if (-1!=ret && !isSecond)
            {
                val_a = val_a*10 + ret;
            }
            else if (-1!=ret && isSecond)
            {
                val_b = val_b*10 + ret;
            }
            //printf("%d**%d**%d**\n", ret, val_a, val_b);
            pNumber = strtok(NULL, " ");
        }
        printf("%d\n", val_a+val_b);
    }

    return 0;
}

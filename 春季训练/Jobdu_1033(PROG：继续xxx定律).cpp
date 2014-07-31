/**
 * PROG: ¼ÌÐøxxx¶¨ÂÉ
 */
#include <cstdio>

const int MAX_NUMBER_SIZE = 512;

int g_size = 0;
int g_number[MAX_NUMBER_SIZE] = {0};

void CoverNumber(const int cover)
{
    for (int i=0; i<g_size; ++i)
    {
        if (cover == g_number[i])
        {
            g_number[i] = -1;
        }
    }
}

void GoXXX()
{
    int cover;
    for (int i=0; i<g_size; ++i)
    {
        if (-1 != g_number[i])
        {
            cover = g_number[i];
            while (1 != cover)
            {
                if (1 == (cover & 1))
                {
                    cover = (3 * cover + 1) / 2;
                }
                else
                {
                    cover /= 2;
                }

                CoverNumber(cover);
            }
        }
    }// end of for

    // output
    bool isFirstOutput = true;
    for (int j=g_size-1; j>=0; --j)
    {
        if (-1 != g_number[j])
        {
            if (!isFirstOutput)
            {
                printf(" ");
            }
            isFirstOutput = false;
            printf("%d", g_number[j]);
        }
    }
    printf("\n");
}

int main(void)
{
    while (~scanf("%d", &g_size) && 0!=g_size)
    {
        for (int i=0; i<g_size; ++i)
        {
            scanf("%d", &g_number[i]);
        }

        GoXXX();
    }
    return 0;
}

/**
 * PROG:   假币问题
 * Author: ouyangyewei
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_SIZE = 8;
const int MAX_COIN = 12;

char g_szLeft[MAX_SIZE] = {0};
char g_szRight[MAX_SIZE] = {0};
char g_szResult[MAX_SIZE] = {0};

int  g_weight[MAX_COIN] = {0};
bool g_isEven[MAX_COIN] = {false};

void MakeTag()
{
    if (0 == strcmp(g_szResult, "even"))
    {   // 左右重量相等
        for (int i=0; i<4; ++i)
        {
            g_weight[g_szLeft[i]-'A'] = 0;
            g_weight[g_szRight[i]-'A'] = 0;
            g_isEven[g_szLeft[i]-'A'] = true;
            g_isEven[g_szRight[i]-'A'] = true;
        }
    }
    else if (0 == strcmp(g_szResult, "up"))
    {   // 左重右轻
        for (int i=0; i<4; ++i)
        {
            if (false == g_isEven[g_szLeft[i]-'A'])
            {
                ++g_weight[g_szLeft[i]-'A'];
            }
            if (false == g_isEven[g_szRight[i]-'A'])
            {
                --g_weight[g_szRight[i]-'A'];
            }
        }
    }
    else if (0 == strcmp(g_szResult, "down"))
    {   // 左轻右重
        for (int i=0; i<4; ++i)
        {
            if (false == g_isEven[g_szLeft[i]-'A'])
            {
                --g_weight[g_szLeft[i]-'A'];
            }
            if (false == g_isEven[g_szRight[i]-'A'])
            {
                ++g_weight[g_szRight[i]-'A'];
            }
        }
    }
}

void debug()
{
    printf("------------------\n%s %s %s\n", g_szLeft, g_szRight, g_szResult);

    for (int i=0; i<MAX_COIN; ++i)
    {
        printf("%d ", g_weight[i]);
    }
    printf("\n");
    for (int i=0; i<MAX_COIN; ++i)
    {
        printf("%d ", g_isEven[i]);
    }
    printf("\n");
}

int main(void)
{
    int nCases = 0;

    scanf("%d", &nCases);
    while (nCases--)
    {
        memset(g_weight, 0, sizeof(g_weight));
        memset(g_isEven, false, sizeof(g_isEven));
        for (int i=0; i<3; ++i)
        {
            scanf("%s %s %s", g_szLeft, g_szRight, g_szResult);
            MakeTag();

            //debug();
        }

        for (int i=0; i<MAX_COIN; ++i)
        {
            if (false==g_isEven[i] && 0!=g_weight[i])
            {
                if (g_weight[i] < 0)
                {
                    printf("%c is the counterfeit coin and it is light.\n", 'A'+i);
                }
                else if (g_weight[i] > 0)
                {
                    printf("%c is the counterfeit coin and it is heavy.\n", 'A'+i);
                }
                break;
            }
        }
    }// End of While

    return 0;
}

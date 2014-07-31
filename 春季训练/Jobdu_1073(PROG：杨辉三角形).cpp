/**
 * PROG: Ñî»ÔÈý½ÇÐÎ
 */
#include <cstdio>

const int MAX_LEVEL = 128;

int g_level;

void YangHui(int level, int yanghui[])
{
    if (level > g_level)
    {
        return ;
    }

    int m_yanghui[MAX_LEVEL] = {0};
    for (int i=2; i<=level; ++i)
    {
        m_yanghui[i] = yanghui[i-1] + yanghui[i];
    }
    m_yanghui[1] = m_yanghui[level] = 1;

    printf("1");
    for (int j=2; j<=level; ++j)
    {
        printf(" %d", m_yanghui[j]);
    }
    printf("\n");

    YangHui(level+1, m_yanghui);
}

int main(void)
{
    int yanghui[MAX_LEVEL] = {0};
    while (~scanf("%d", &g_level))
    {
        yanghui[1] = 0;
        yanghui[2] = 1;
        YangHui(2, yanghui);
    }// end of while
    return 0;
}

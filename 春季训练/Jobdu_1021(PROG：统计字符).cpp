/**
 * PROG: Í³¼Æ×Ö·û
 */
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_STRING_SIZE = 84;
const int MAX_STATISTICS_SIZE = 8;

char g_szBunch[MAX_STRING_SIZE] = {0};

int main(void)
{
    map<char, int> count;
    char g_szStatistics[MAX_STATISTICS_SIZE] = {0};
    while (gets(g_szStatistics))
    {
        if ('#' == g_szStatistics[0])
        {
            break;
        }

        if (!count.empty())
        {
            count.clear();
        }

        //getchar();
        gets(g_szBunch);
        int strLen = strlen(g_szBunch);
        for (int i=0; i<strLen; ++i)
        {
            ++count[g_szBunch[i]];
        }

        int statLen = strlen(g_szStatistics);
        for (int j=0; j<statLen; ++j)
        {
            printf("%c %d\n", g_szStatistics[j], count[g_szStatistics[j]]);
        }
    }// End of While
    return 0;
}

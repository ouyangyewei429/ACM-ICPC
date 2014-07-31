/**
 * PROG: ACM
 */
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Team
{
    int m_nPass;
    int m_nPunish;
    char m_szName[128];

    Team()
    {
        m_nPass = 0;
        m_nPunish = 0;
        m_szName[0] = '\0';
    }
};

int compare_rule(Team a, Team b)
{
    if (a.m_nPass==b.m_nPass || a.m_nPunish==b.m_nPunish)
    {
        if (a.m_nPass==b.m_nPass && a.m_nPunish==b.m_nPunish)
        {
            return strcmp(a.m_szName, b.m_szName);
        }
        else if (a.m_nPass == b.m_nPass)
        {
            return (a.m_nPunish < b.m_nPunish);
        }
    }
    else
    {
        return (a.m_nPass > b.m_nPass);
    }
}

int main(void)
{
    int nTeams;
    while (~scanf("%d", &nTeams))
    {
        vector<Team> vect;
        for (int i=0; i<nTeams; ++i)
        {
            Team t;
            scanf("%s %d %d", t.m_szName, &t.m_nPass, &t.m_nPunish);
            vect.push_back(t);
        }

        sort(vect.begin(), vect.end(), compare_rule);

        for (int j=0; j<nTeams; ++j)
        {
            printf("%s\n", vect[j].m_szName);
        }
    }// End of While

    return 0;
}

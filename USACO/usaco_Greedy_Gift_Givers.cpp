/*
ID:     ouyangyewei
LANG:   C++
PROG:   gift1
*/
#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

char ans[50][50];
char giver[50], rece[50];
int  casenum, src, num;

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    while (~scanf("%d", &casenum))
    {
        map <string, int> mp;

        for (int i=1; i<=casenum; ++i)
        {
            scanf("%s", ans[i]);
            mp[ans[i]] = 0;
        }/* End of For */
        
        for (int k=1; k<=casenum; ++k)
        {
            scanf("%s %d %d", giver, &src, &num);
            
            if (num != 0)
            {
                mp[giver] += src%num - src;
                for (int i=1; i<=num; ++i)
                {
                    scanf("%s", rece);
                    mp[rece] += src/num;
                }/* End of For */
            }
            else
                mp[giver] += 0 - src;
        }/* End of For */
        
        map <string, int>:: iterator it;
        for (int i=1; i<=casenum; ++i)
        {
            printf("%s ", ans[i]);
            
            for (it=mp.begin(); it!=mp.end(); ++it)
            {
                if (strcmp((it->first).c_str(), ans[i]) == 0)
                {
                    printf("%d\n", it->second);
                    break;
                }
            }
        }/* End of For */
    }/* End of For */
    
    //system("pause");
    return 0;
}

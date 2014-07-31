#include <stdio.h>
#include <string.h>

//#define onlinejudge

const int maxn = 1010;

int  n=0;
bool IsSolved, hash[maxn];
char bunch[maxn], st[maxn], end[maxn];

void dfs(char sc, char ec)
{
    if (ec == 'm')
    {
        IsSolved = true;
        printf("Yes.\n");
        return ;
    }/* End of IF */
    
    for (int i=1; i<=n; ++i)
    {
        if (!hash[i] && st[i]==ec && end[i]!='b')
        {
            hash[i] = true;
            dfs(st[i], end[i]);
            hash[i] = false;
        }
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1181.txt", "r", stdin);
    freopen("E:\\hdoj_1181_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", bunch))
    {
        if (bunch[0] != '0')
        {
            ++n;
            st[n] = bunch[0];
            end[n] = bunch[strlen(bunch)-1];
        }
        else
        {
            IsSolved = false;
            memset(hash, false, sizeof(hash));
            for (int i=1; i<=n; ++i)
            {
                if (st[i] == 'b')
                {
                    hash[i] = true;
                    dfs(st[i], end[i]);
                }    
            }/* End of For */
            
            n = 0;  /* Reset */
            
            if (!IsSolved)
                printf("No.\n");
        }
    }/* End of While */
    
    return 0;
}

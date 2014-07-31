#include <stdio.h>
#include <memory.h>

#define MAX 500000
#define onlinejudge

int hash[MAX+MAX+10];
int nNum, mNum, temp, maxn, i, j;

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1425.txt", "r", stdin);
    freopen("E:\\hdoj1425(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum))
    {
        maxn = -1;
        memset(hash, 0, sizeof(hash));
        for (i=0; i<nNum; ++i)
        {
            scanf("%d", &temp);
            
            ++hash[temp+MAX];
            if (maxn < temp+MAX)
            {
                maxn = temp+MAX;
            }
        }/* End of For */
        
        for (i=maxn; mNum!=0; --i)
        {
            if (hash[i] > 0)
            {
                --mNum;
                printf(i==maxn? "%d":" %d", i-MAX);
            }
        }/* End of For */
        printf("\n");
    }/* End of While */
    
    return 0;
}

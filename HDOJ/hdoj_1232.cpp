#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

const int maxn = 1001;

int N, M, a, b, city[maxn];

int FindSet(int k)
{
    while (k != city[k])
        k = city[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return ;
    
    if (r1 < r2)
        city[r2] = r1;
    else
        city[r1] = r2;

    return ;
}/* Merge */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1232.txt", "r", stdin);
    freopen("E:\\hdoj_1232_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &N), N!=0)
    {
        for (int i=1; i<=N; ++i)
            city[i] = i;
        
        scanf("%d", &M);
        for (int i=1; i<=M; ++i)
        {
            scanf("%d %d", &a, &b);
            Merge(a, b);
        }/* End of For */

        int cnt = 0;
        for (int i=1; i<=N; ++i)
        {
            if (city[i] == i)
                ++cnt;
        }/* End of For */

        printf("%d\n", cnt-1);
    }/* End of While */
}

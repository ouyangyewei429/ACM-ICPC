#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int T, N, i, j, s, t, maxlen, cover[204];

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1050.txt", "r", stdin);
    freopen("E:\\hdoj_1050_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {
        memset(cover, 0, sizeof(cover));
        
        scanf("%d", &N);
        for (i=0; i<N; ++i)
        {
            scanf("%d %d", &s, &t);
            if (s > t)
            {
                int tmp = s;
                s = t;
                t = tmp;
            }/* swap if s > t */
            
            s = (s-1)/2, t = (t-1)/2;
            for (j=s; j<=t; ++j)
                cover[j]++;
        }/* End of For */
        
        for (i=0, maxlen=-1; i<=200; ++i)
        {
            if (maxlen < cover[i])
                maxlen = cover[i];
        }/* Find the maxLen */
        
        printf("%d\n", maxlen*10);
    }/* End of while */
    
    return 0;
} 

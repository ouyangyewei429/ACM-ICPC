#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlineiudge

int casenum, N, M, i, k, ans, w[10004];

inline int compare(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}/* compare */

int main()
{
#ifdef onlineiudge
    freopen("E:\\nyist_218.txt", "r", stdin);
    freopen("E:\\nyist_218_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &N, &M);
        for (i=0; i<N; ++i)
            scanf("%d", &w[i]);
        
        qsort(w, N, sizeof(w[0]), compare);
        
        if (M >= N)
        {
            int max = 0;
            for (i=1; i<N; ++i)
            {
                if (w[max] < w[i])
                    max = i;
            }/* End of For */
            
            printf("%d\n", w[max]);
        }/* Case: M>=N */
        else
        {
            ans = 0;
            while (w[M] != 0)
            {
                int min = 0x3F3F3F3F;
                for (i=0; i<M&&w[i]; ++i)
                {
                    if (min>w[i])
                        k=i, min=w[i];
                }/* Find The min within M numbers*/
                
                ans += min;
                for (i=0; i<N; ++i)
                {
                    if (i < k)
    					w[i] -= min;
    				else
    				{
    					w[i] = w[i+1];
    					if (i < M-1)
    						w[i] -= min;
    				}
    			}/* k for the middle elem */
            }/* End of For */
            
    		int max = -1;
    		for (i=0; i<M; ++i)
    		{
    			if (max < w[i])
    				max = w[i];
    		}		  

            printf("%d\n", ans+max);
        }    
    }/* End of While */
    
    return 0;
}

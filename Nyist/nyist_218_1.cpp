#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlineiudge

int w[10004], ti[104];
int casenum, N, M, i, j, ans, max, min;

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
            for (i=1,max=0; i<N; ++i)
            {
                if (w[max] < w[i])
                    max = i;
            }/* End of For */
            
            printf("%d\n", w[max]);
        }/* Case: M>=N */
        else
        {
            for (i=0; i<M; ++i)
                ti[i] = w[i];
            
            for (; i<N; ++i)
            {
                for (j=1,min=0; j<M; ++j)
                {
                    if (ti[min] > ti[j])
                        min = j;
                }/* Search for the min Value within M figure */
                
                ti[min] += w[i];
            }/* updata ti[] */
            
    		for (i=1,max=0; i<M; ++i)
    		{
    			if (ti[max] < ti[i])
                    max = i;
            }/* Find the max Value within M figure */  		

            printf("%d\n", ti[max]);
        }/* Case: M < N */
    }/* End of While */
    
    return 0;
}

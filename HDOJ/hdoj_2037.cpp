#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int i, N, ans, st, et;
struct program
{
    int s, e;
}ti[104];

inline int compare(const void *a, const void *b)
{
    if ((*(struct program *)a).e == (*(struct program *)b).e)
        return (*(struct program *)a).s - (*(struct program *)b).s;
    else
        return ((*(struct program *)a).e - (*(struct program *)b).e);
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2037.txt", "r", stdin);
    freopen("E:\\hdoj_2037_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &N), N!=0)
    {
        for (i=0; i<N; ++i)
            scanf("%d %d", &ti[i].s, &ti[i].e);
        
        qsort(ti, N, sizeof(ti[0]), compare);
        /***
        for (i=0; i<N; ++i)
            printf("%d %d\n", ti[i].s, ti[i].e);
        ****/
        st=ti[0].s, et=ti[0].e;
        for (i=1, ans=1; i<N; ++i)
        {
            if (ti[i].s >= et)
                et=ti[i].e, ans++;
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}

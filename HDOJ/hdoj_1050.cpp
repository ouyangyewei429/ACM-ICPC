#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int casenum, N, i, ans, et;
struct hotel
{
    int s, t;
}room[204];

inline int compare(const void *a, const void *b)
{
    return ((*(struct hotel *)a).t - (*(struct hotel *)b).t);
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1050.txt", "r", stdin);
    freopen("E:\\hdoj_1050_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &N);
        for (i=0; i<N; ++i)
            scanf("%d %d", &room[i].s, &room[i].t);
        
        qsort(room, N, sizeof(room[0]), compare);
        
        et=room[0].t;
        for (i=1, ans=10; i<N; ++i)
        {
            if (et>room[i].s || et+1==room[i].s)
                ans+=10, et=room[i].t;
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}

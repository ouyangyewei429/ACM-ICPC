#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int casenum, N, i, ans, tmp, xx[204];
struct hotel
{
    int s, t;
}room[204];

inline int compare(const void *a, const void *b)
{
    return ((*(struct hotel *)a).s - (*(struct hotel *)b).s);
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
        {
            scanf("%d %d", &room[i].s, &room[i].t);
            if (room[i].s > room[i].t)
                tmp=room[i].s, room[i].s=room[i].t, room[i].t=tmp;
        }/* Input */
            
        memset(xx, 0, sizeof(xx));
        qsort(room, N, sizeof(room[0]), compare);
        
        for (i=1; i<N; ++i)
        {
            if (room[i].s<room[i-1].t || room[i].s==room[i-1].t+1)
                xx[i-1] = xx[i] = 1;
        }/* ¼ÆËã½»²æÊý */ 
        
        for (i=0, ans=0; i<N; ++i)
            ans += xx[i];
        
        printf(ans==0? "10\n":"%d\n", ans*10);
    }/* End of While */
    
    return 0;
}

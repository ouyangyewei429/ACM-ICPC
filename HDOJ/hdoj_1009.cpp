#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

//#define onlinejudge

int i, M, N;
struct fatmouse
{
    int j, f;
    double rate;
}s[1004];

inline int compare(struct fatmouse a, struct fatmouse b)
{
    return (a.rate > b.rate);
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1009.txt", "r", stdin);
    freopen("E:\\hdoj_1009_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &M, &N), N+M!=-2)
    {
        for (i=0; i<N; ++i)
        {
            scanf("%d %d", &s[i].j, &s[i].f);
            s[i].rate = 1.0*s[i].j/s[i].f;
        }/* prepare */
        
        sort(s, s+N, compare);
        
        double ans = 0.0;
        for (i=0; i<N&&M>0; ++i)
        {
            if (M >= s[i].f)
                ans+=1.0*s[i].j, M-=s[i].f;
            else
                ans+=M*s[i].rate, M=0;
        }/* greedy */
        
        printf("%.3lf\n", ans);
    }/* End of While */
    
    return 0;
}

/*
PROG:   milk
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

int i, N, M, ans;
struct farmer
{
    int p, a;
}milk[5004];

inline int compare(const void *c, const void *d)
{
	if ((*(struct farmer *)c).p == (*(struct farmer *)d).p)
		return (*(struct farmer *)d).a - (*(struct farmer *)c).a;
	else
		return (*(struct farmer *)c).p - (*(struct farmer *)d).p;
}/* compare */

int main()
{/****
#ifdef onlinejudge
    freopen("E:\\milk.txt", "r", stdin);
    freopen("E:\\milk_ans.txt", "w", stdout);
#endif
***/
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    
    while (~scanf("%d %d", &N, &M))
    {
        for (i=0; i<M; ++i)
            scanf("%d %d", &milk[i].p, &milk[i].a);
        
        qsort(milk, M, sizeof(milk[0]), compare);
        
        for (i=0, ans=0; i<M&&N>0; ++i)
        {
            if (N >= milk[i].a)
                ans+=milk[i].p*milk[i].a, N-=milk[i].a;
            else
                ans+=milk[i].p*N, N=0;
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}

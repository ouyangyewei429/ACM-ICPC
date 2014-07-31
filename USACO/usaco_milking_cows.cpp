/*
PROG:   milk2
ID:     ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 5004;

int N, mx, my, s, e, l, r;
struct milk
{
    int st, et;
}seg[maxn];

int compare(const void *a, const void *b)
{
    return (*(struct milk *)a).st - (*(struct milk *)b).st;
}/* compare */

int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

    while (~scanf("%d", &N))
    {
		int i;
        for (i=0; i<N; ++i)
            scanf("%d %d", &seg[i].st, &seg[i].et);
        
        qsort(seg, N, sizeof(seg[0]), compare);
        
        l = r = 0;
        s = seg[0].st, e = seg[0].et;
        mx = e-s, my = 0;
        
        for (i=1; i<N; ++i)
        {
            if (seg[i].st <= e)
            {
				r = 0;
                l += (seg[i].st-s);
                s = seg[i].st;
                if (seg[i].et > e)
                    e = seg[i].et;
                if (mx < l+seg[i].et-s)
                    mx = l+seg[i].et-s;
            }/* End of If */
            else
            {
				l = 0;
                r += (seg[i].st-e);
                s = seg[i].st;
                e = seg[i].et;
                if (my < r)
                    my = r;
                r = 0;
            }
        }/* End of For */
        
        printf("%d %d\n", mx, my);
    }/* End of While */
    
    return 0;
}

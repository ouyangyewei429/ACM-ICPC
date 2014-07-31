#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int  T, N, i, j, ans;
struct stick
{
    int l, w;
}prev, wood[5004];

inline int compare(const void *a, const void *b)
{
    if ((*(struct stick *)a).l == (*(struct stick *)b).l)
        return ((*(struct stick *)a).w - (*(struct stick *)b).w);
    else
        return ((*(struct stick *)a).l - (*(struct stick *)b).l);
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1051.txt", "r", stdin);
    freopen("E:\\hdoj_1051_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--)
    {        
        scanf("%d", &N);
        for (i=0; i<N; ++i)
            scanf("%d %d", &wood[i].l, &wood[i].w);
            
        qsort(wood, N, sizeof(wood[0]), compare);
        
        for (i=0, ans=0; i<N; ++i)
        {
            if (wood[i].l+wood[i].w != 0)
            {
                prev = wood[i];
                wood[i].l = wood[i].w = 0;
                for (j=i+1; j<N; ++j)
                {
                    if (wood[j].l+wood[j].w && wood[j].l>=prev.l && wood[j].w>=prev.w)
                        prev=wood[j], wood[j].l=wood[j].w=0;
                }
                
                ++ans;
            }/* End of IF */        
        }/* count */
        
        printf("%d\n", ans);
    }/* End of WHile */
    
    return 0;
}

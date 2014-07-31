#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

bool cover[5004];
int  T, N, i, j, ans;
struct stick
{
    int l, w;
}wood[5004];

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
    {/***
        memset(cover, false, sizeof(cover));
        memset(wood, 0, sizeof(wood));
        ****/
        scanf("%d", &N);
        for (i=0; i<N; ++i)
        {
            cover[i] = false;
            scanf("%d %d", &wood[i].l, &wood[i].w);
        }/* prepare */
            
        qsort(wood, N, sizeof(wood[0]), compare);
        
        for (i=0, ans=0; i<N; ++i)
        {
            if (!cover[i])
            {
                for (j=i+1; j<N; ++j)
                {
                    if (!cover[j] && wood[j].l>=wood[i].l && wood[j].w>=wood[i].w)
                        cover[j] = true;
                }
                
                ++ans;
            }/* End of IF */        
        }/* count */
        
        /***
        for (i=0, ans=0; i<N; ++i)
        {
            if (!cover[i])
                ++ans;
        }****/
        
        printf("%d\n", ans);
    }/* End of WHile */
    
    return 0;
}

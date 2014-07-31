/*
PROG:   barn1
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

int M, S, C, i, j, ans;
int stall[204], len[204];

inline int compare_1(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}/* compare */

inline int compare_2(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}/* compare */

int main()
{/***
#ifdef onlinejudge
    freopen("E:\\barn.txt", "r", stdin);
    freopen("E:\\barn_ans.txt", "w", stdout);
#endif
****/

    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    while (~scanf("%d %d %d", &M, &S, &C))
    {
        for (i=0; i<C; ++i)
            scanf("%d", &stall[i]);
        qsort(stall, C, sizeof(stall[0]), compare_1);
        
        for (i=1; i<C; ++i)
            len[i-1] = stall[i]-stall[i-1]-1;
        qsort(len, C-1, sizeof(len[0]), compare_2);
        
        for (i=0,ans=stall[C-1]-stall[0]+1; i<M-1; ++i)
            ans -= len[i];
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}


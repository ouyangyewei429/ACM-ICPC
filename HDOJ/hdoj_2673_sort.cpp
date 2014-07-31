/*
PROG:   sh®£·Ã OrOrOrOrz
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 10004;

int N, i, j, src, a[maxn], b[maxn], acnt, bcnt;

inline int compare_1(int a, int b)
{
    return a<b;
}// compare_1

inline int compare_2(int c, int d)
{
    return c>d;
}// compare_2

int main()
{
    while (~scanf("%d", &N))
    {
        for (i=1; i<=N; ++i)
        {
            scanf("%d", &src);
            a[i] = b[i] = src;
        }// input
            
        sort(a+1, a+N+1, compare_1);
        sort(b+1, b+N+1, compare_2);
        //qsort(&a[1], N, sizeof(a[0]), compare_1);
        //qsort(&b[1], N, sizeof(b[0]), compare_2);
     /*   
        for (i=1; i<=N; ++i)
            printf("%d | %d\n", a[i], b[i]);
        printf("\n");
*/
        acnt = bcnt = 1;
        for (i=1; i<=N; ++i)
        {
            if (i&1)
                printf(i==1 ? "%d":" %d", b[acnt++]);
            else
                printf(" %d", a[bcnt++]);
        }
        printf("\n");

    }/* End of While */
    
    return 0;
}

/*
PROG:   Milk
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 104;

char ss[maxn]={0};
int  T, N, M, i, price, volum;
struct MILK
{
    int vol;
    double costs;
    char brand[maxn];
}milk[maxn];

int compare(const void *a, const void *b)
{
    MILK *c = (MILK *)a;
    MILK *d = (MILK *)b;
    
    if ( c->costs==d->costs )
        return ( d->vol - c->vol );
    else
        return ( c->costs>d->costs ? 1:-1 );
}// compare

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1070.txt", "r", stdin);
    freopen("E:\\hdoj_1070_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while ( T-- )
    {
        memset(milk, 0, sizeof(milk));
        
        M = 0;
        scanf("%d", &N);
        for (i=0; i<N; ++i)
        {
            getchar();
            scanf("%s %d %d", ss, &price, &volum);
            if ( volum<200 )
                continue;
            else
            {
                milk[M].vol = volum;
                strcpy(milk[M].brand, ss);
                if ( volum/200>5 )
                    milk[M++].costs = 1.0*price/5;
                else
                    milk[M++].costs = 1.0*price/(volum/200);
            }
        }// Input
        
        qsort(milk, M, sizeof(milk[0]), compare);
        
        /*
        printf("--------------------------\n");
        for (i=0; i<M; ++i)
            printf("%s %d %.2lf\n", milk[i].brand, milk[i].vol, milk[i].costs);
        */
        printf("%s\n", milk[0].brand);
    }// End of while
    
    return 0;
}

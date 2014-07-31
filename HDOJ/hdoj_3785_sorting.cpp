/*
PROG:   ZOJ
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int  N, M, wealth[100004];

inline compare(const void *c, const void *d)
{
    return ( *(int *)d - *(int *)c );
}// compare

int main()
{
    while ( ~scanf("%d %d", &N, &M), N+M!=0 )
    {
        for (int i=0; i<N; ++i)
            scanf("%d", &wealth[i]);
        
        qsort(wealth, N, sizeof(wealth[0]), compare);
        for (int i=0; i<M; ++i)
            printf(i==0 ? "%d":" %d", wealth[i]);
        printf("\n");
    }// End of while
    
    return 0;
}

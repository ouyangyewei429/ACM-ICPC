/*
PROG:   DNA Sorting
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

const int maxn = 60;

int T, N, M, rt=0;
struct ArcNode
{
    int inver;
    char ss[maxn];
}dna[maxn<<1];

int Inver(char str[])
{
    int cnt = 0;
    for (int i=0; i<N; ++i)
    {
        for (int j=i+1; j<N; ++j)
        {
            if (str[j] < str[i])
                ++cnt;
        }
    }// counting the inversion number
    
    return cnt;
}// Inver

int compare(ArcNode c, ArcNode d)
{
    return ( c.inver<d.inver );
}// compare

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1379.txt", "r", stdin);
    freopen("E:\\hdoj_1379_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d %d", &N, &M);
        for (int i=0; i<M; ++i)
        {
            scanf("%s", dna[i].ss);
            dna[i].inver = Inver( dna[i].ss );
            
            //----------------------
            //printf("%s %d\n", dna[i].ss, dna[i].inver);
            //-------------------------------------------
        }// Input
        
        if ( rt )   printf("\n");
        rt = 1;
        
        sort(dna, dna+M, compare);
        for (int i=0; i<M; ++i)
            printf("%s\n", dna[i].ss);
        //printf("\n");

    }// End of while
    
    return 0;
}

/*
PROG:   Ð¡Ï£µÄÃÔ¹¬
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 100004;

bool IsRing, mark[maxn];
int  a, b, N, i, setNums, parent[maxn];

int FindSet(int k)
{
    int s, tmp;
    for (s=k; parent[s]>=0; s=parent[s])
        ;
    while ( s!=k )
    {
        tmp = parent[k];
        parent[k] = s;
        k = tmp;
    }
    
    return s;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    int tmp = parent[r1]+parent[r2];
    
    if ( parent[r1]>parent[r2] )
        parent[r1]=r2, parent[r2]=tmp;
    else
        parent[r2]=r1, parent[r1]=tmp;
    
    return ;
}// Merge

int main()
{
    while (~scanf("%d %d", &a, &b), a+b!=-2)
    {
        if ( a+b==0 )
        {
            printf("Yes\n");
            continue;
        }// case 0
        
        for (i=1; i<maxn; ++i)
            parent[i]=-1, mark[i]=false;

        N = a>b ? a:b;
        IsRing=false, mark[a]=mark[b]=true;
        
        Merge( a, b );
        while (~scanf("%d %d", &a, &b), a+b!=0)
        {
            if ( FindSet(a)==FindSet(b) )   IsRing = true;
            if ( N<a )  N = a;
            if ( N<b )  N = b;
            mark[a] = mark[b] = true;
            Merge( a, b );
        }// end of while
        
        setNums = 0;
        for (i=1; i<=N; ++i)
        {
            if ( mark[i] && parent[i]<0 )
                ++setNums;
        }// counting the set's number
        
        if ( IsRing || setNums!=1 )
            printf("No\n");
        else
            printf("Yes\n");
    }// End of while
    
    return 0;
}

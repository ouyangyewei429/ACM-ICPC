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
int  a, b, N, i, setNums, cas=1, parent[maxn];

int FindSet(int k)
{
    while ( k!=parent[k] )
        k = parent[k];
    
    return k;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1==r2 )
        return ;
    
    if ( r1<r2 )
        parent[r2] = r1;
    else
        parent[r1] = r2;
    
    return ;
}// Merge

int main()
{
    while (~scanf("%d %d", &a, &b))
    {
        if ( a+b<0 )    break;

        if ( a+b==0 )
        {
            printf("Case %d is a tree.\n", cas++);
            continue;
        }// case 0

        for (i=1; i<maxn; ++i)
            parent[i]=i, mark[i]=false;

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
            if ( mark[i] && FindSet(i)==i )
                ++setNums;
        }// counting the set's number
        
        if ( IsRing || setNums!=1 )
            printf("Case %d is not a tree.\n", cas++);
        else
            printf("Case %d is a tree.\n", cas++);
    }// End of while
    
    return 0;
}

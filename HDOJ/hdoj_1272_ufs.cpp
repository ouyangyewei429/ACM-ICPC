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
int  a, b, N, i, setNums, rooms[maxn];

int FindSet( int k )
{
    while ( k!=rooms[k] )
        k = rooms[k];
    
    return k;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1==r2 )   // In the same set, ring is existing
    {
        IsRing = true;
        return ;
    }
        
    if ( r1<r2 )
        rooms[r2] = r1;
    else
        rooms[r1] = r2;
    
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
        }// connected
        
        for (i=0; i<=maxn; ++i)
            rooms[i]=i, mark[i]=false;
        
        IsRing = false;
        mark[a] = mark[b] = true;
        N = a>b ? a:b;  // get the maximum node number
        Merge( a, b );
        while (~scanf("%d %d", &a, &b), a+b!=0)
        {
            Merge(a, b);
            mark[a] = mark[b] = true;   // mark node a and b is appeared
            if ( N<a )  N = a;  // get the maximum node number
            if ( N<b )  N = b;  // get the maximum node number
        }// judging if the ring is existing
        
        setNums = 0;
        for (i=1; i<=N; ++i)
        {
            if ( mark[i] && FindSet(i)==i )
                ++setNums;
        }// counting the tree number
        
        if ( setNums!=1 || IsRing ) // setNums more than 1 means forest is existing
            printf("No\n");
        else
            printf("Yes\n");
    }// End of while
    
    return 0;
}

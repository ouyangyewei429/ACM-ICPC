/*
PROG:   µÐ±ø²¼Õó
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG 0

const int maxn = 50004;

int N, casenum, seg[maxn<<2]; // variable

void pushup( int rt )
{
    seg[rt] = seg[rt<<1]+seg[rt<<1|1];
}// pushup

void BuildTree( int l, int r, int rt )
{
    seg[rt] = 0;
    if ( l==r )
    {
        scanf("%d", &seg[rt]);
        return ;
    }// destination
    
    int mid = ( l+r )>>1;
    BuildTree( l, mid, rt<<1 );
    BuildTree( mid+1, r, rt<<1|1 );
    
    pushup( rt );
}// BuildTree

void updata( int k, int c, int l, int r, int rt )
{
    if ( l==r )
    {
        seg[rt] += c;
        return ;
    }// destination
    
    int mid = ( l+r )>>1;
    if ( k<=mid )   updata( k, c, l, mid, rt<<1 );
    else    updata( k, c, mid+1, r, rt<<1|1 );
    
    pushup( rt );
}// updata

int query( int L, int R, int l, int r, int rt )
{
    if ( L<=l && r<=R )
        return seg[rt];
    
    int ret = 0;
    int mid = ( l+r )>>1;
    if ( L<=mid )   ret += query( L, R, l, mid, rt<<1 );
    if ( R>mid )    ret += query( L, R, mid+1, r, rt<<1|1 );
    
    return ret;
}// query

void Solve()
{
    char cmd[10];
    int  a, b;
    
    while ( EOF!=scanf("%s", cmd), cmd[0]!='E' )
    {
        scanf("%d %d", &a, &b);
        if ( cmd[0]=='A' )
            updata( a, b, 1, N, 1 );
        else if ( cmd[0]=='S' )
            updata( a, -b, 1, N, 1 );
        else
            printf("%d\n", query( a, b, 1, N, 1 ));
    }// End of while
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1166.in", "r", stdin);
    freopen("E:\\hdoj_1166.out", "w", stdout);
#endif

    scanf("%d", &casenum);
    for ( int i=1; i<=casenum; ++i )
    {
        scanf("%d", &N);
        printf("Case %d:\n", i);
        
        BuildTree( 1, N, 1 );
        Solve();
    }// case
    
    return 0;
}

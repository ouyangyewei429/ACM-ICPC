/*
PROG:   I Hate It
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 200001;

char cmd;
int  N, M, a, b, seg[maxn<<2];

int Max( int x, int y )
{
    return ( x>y ? x:y );
}// Max

void pushup( int rt )
{
    seg[rt] = Max( seg[rt<<1], seg[rt<<1|1] );
}// pushup

void BuildTree( int l, int r, int rt )
{
    seg[rt] = 0;
    if ( l==r )
    {
        scanf("%d", &seg[rt]);
        return ;
    }// leaf
    
    int mid = ( l+r )>>1;
    BuildTree( l, mid, rt<<1 );
    BuildTree( mid+1, r, rt<<1|1 );
    
    pushup( rt );
    return ;
}// BuildTree

void updata( int A, int B, int l, int r, int rt )
{
    if ( l==r )
    {
        seg[rt] = B;
        return ;
    }// destination
    
    int mid = ( l+r )>>1;
    if ( A<=mid ) updata( A, B, l, mid, rt<<1 );
    else updata( A, B, mid+1, r, rt<<1|1 );
    
    pushup( rt );
    return ;
}// updata

int query( int L, int R, int l, int r, int rt )
{
    if ( L<=l && r<=R )
        return seg[rt];
    
    int ret = 0;
    int mid = ( l+r )>>1;
    if ( L<=mid )   ret = Max( ret, query( L, R, l, mid, rt<<1 ) );
    if ( R>mid )    ret = Max( ret, query( L, R, mid+1, r, rt<<1|1 ) );
    
    return ret;
}// query

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1754.in", "r", stdin);
    freopen("E:\\hdoj_1754.out", "w", stdout);
#endif

    while ( ~scanf("%d %d", &N, &M) )
    {
        BuildTree( 1, N, 1 );
        for ( int i=1; i<=M; ++i )
        {
            getchar();
            scanf("%c %d %d", &cmd, &a, &b);
            if ( cmd=='Q' )
                printf("%d\n", query( a, b, 1, N, 1 ));
            else if ( cmd=='U' )
                updata( a, b, 1, N, 1 );
        }
    }// End of while
    
    return 0;
}

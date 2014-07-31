/*
PROG:   sprime
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int Length;
int a[4]={2,3,5,7}, b[4]={1,3,7,9};

bool IsPrime(long long fig)
{
    if ( fig == 1 )
        return false;
    else if ( fig == 2 )
        return true;
    else
    {
        for (long long k=2; k<=(int)sqrt(fig); ++k)
        {
            if ( fig%k==0 )
                return false;
        }

        return true;
    }
}// IsPrime

void dfs(long long ss, int len)
{
    if ( len==Length )
    {
        printf("%lld\n", ss);
        return ;
    }// destination
    
    for (int i=0; i<4; ++i)
    {
        if ( IsPrime( ss*10+b[i] ) )
            dfs( ss*10+b[i], len+1 );
    }// Main Process
}// dfs

int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    scanf("%d", &Length);
    if ( Length==1 )
        printf("2\n3\n5\n7\n");
    else
    {
        for (int i=0; i<4; ++i)
            dfs( a[i], 1 );
    }// length > 1
    
//    system("pause");
    return 0;
}

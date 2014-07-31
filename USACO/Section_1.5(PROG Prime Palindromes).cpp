/*
PROG:   pprime
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int i, j, d1, d2, d3, d4;
long long left, right, temp;

bool IsPrime(long long fig)
{
    if ( fig == 1 )
        return false;
    else if ( fig == 2 )
        return true;
    else
    {
        for (long k=2; k<=(int)sqrt(fig); ++k)
        {
            if ( fig%k==0 )
                return false;
        }
        
        return true;
    }
}// IsPrime

int main()
{/*
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
*/
    scanf("%d %d", &left, &right);
    
    // less than 10
    for (i=left; i<10; ++i)
    {
        if ( IsPrime( i ) )
            printf("%d\n", i);
    }
    
    if (left<=11 && right>=11)
        printf("11\n");
    
    // 100 ~ 999
    for (d1=1; d1<=9; d1+=2)
    {
        if ( d1*100>right ) break;
        if ( d1==5 )    continue;
        for (d2=0; d2<=9; ++d2)
        {
            temp = d1*100+d2*10+d1;
            if ( left<=temp&&temp<=right && IsPrime( temp ) )
                printf("%lld\n", temp);
        }
    }
    
    // 10000 ~ 99999
    for (d1=1; d1<=9; d1+=2)
    {
        if ( d1*10000>right )   break;
        if ( d1==5 )    continue;
        for (d2=0; d2<=9; ++d2)
        {
            if ( d1*10000+d2*1000>right )   break;
            for (d3=0; d3<=9; ++d3)
            {
                temp = d1*10000+d2*1000+d3*100+d2*10+d1;
                if ( left<=temp&&temp<=right && IsPrime( temp ) )
                    printf("%lld\n", temp);
            }
        }
    }
    
    // 1000000 ~ 9999999
    for (d1=1; d1<=9; d1+=2)
    {
        if ( d1*1000000>right )   break;
        if ( d1==5 )    continue;
        for (d2=0; d2<=9; ++d2)
        {
            if ( d1*1000000+d2*100000>right )   break;
            for (d3=0; d3<=9; ++d3)
            {
                if ( d1*1000000+d2*100000+d3*10000>right )  break;
                for (d4=0; d4<=9; ++d4)
                {   
                    temp = d1*1000000+d2*100000+d3*10000+d4*1000
                    +d3*100+d2*10+d1;
                    if ( left<=temp&&temp<=right && IsPrime( temp ) )
                    {
                        printf("%lld\n", temp);
                    }    
                }
            }
        }
    }
    
    system("pause");
    return 0;
}

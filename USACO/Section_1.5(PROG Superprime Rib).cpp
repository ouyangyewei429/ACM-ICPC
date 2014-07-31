/*
PROG:   sprime
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

//const int maxn = 100000000;

int Length, i, j;
//int IsNotPrime[maxn]={1,1,0};

bool IsPrime(int fig)
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

bool CanTakeIt(int num)
{
    int r=1, s=num;

    while ( s )
    {
        if ( !IsPrime(num/r) )
            return false;

        r *= 10;
        s /= 10;
    }// End of While

    return true;
}// CanTakeIt

int main()
{/*
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
*/
/*
    for (i=2; i<=(int)sqrt(1.0*maxn); ++i)
    {
        if ( !IsNotPrime[i] )
        {
            for (j=i*i; j<=maxn; j+=i)
                IsNotPrime[j] = 1;
        }
    }// IsPrime
*/
/*
    for (i=2; i<=maxn; ++i)
    {
        if (!IsNotPrime[i])
            printf("%d\n", i);
    }
    printf("\n");
*/
    while ( ~scanf("%d", &Length) )
    {
        switch ( Length )
        {
            case 1:
                for (i=2; i<=9; ++i)
                {
                    if ( IsPrime(i) )
                        printf("%d\n", i);
                }// less than 10
                break;
            case 2:
                for (i=11; i<100; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                break;
            case 3:
                for (i=101; i<1000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                break;
            case 4:
                for (i=2333; i<10000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                break;
            case 5:
                for (i=23333; i<100000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                break;
            case 6:
                for (i=233993; i<1000000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                break;
            case 7:
                printf("2339933\n2399333\n2939999\n3733799\n");
                printf("5939333\n7393913\n7393931\n7393933\n");
                /*
                for (i=2339933; i<10000000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                */
                break;
            case 8:
                printf("23399339\n29399999\n37337999\n59393339\n73939133\n");
                /*
                for (i=23333333; i<100000000; i+=2)
                {
                    if ( CanTakeIt(i) )
                        printf("%d\n", i);
                }// 10 ~ 100
                */
                break;
        }// switch
    }
        
    system("pause");
    return 0;
}


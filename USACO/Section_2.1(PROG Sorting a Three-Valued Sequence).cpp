/*
PROG:   sort3
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 10004;

int  N, temp, a, b, c, cnt=0, num[maxn]={0}, zz[maxn]={0};

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

	int i, j, k;
    scanf("%d", &N);
    for (i=0; i<N; ++i)
    {
        scanf("%d", &temp);
        num[i] = zz[i]=temp;
    }// preprocess
    
    sort( num, num+N ); // sorting in ascending order
/*      
    for (int i=0; i<N; ++i)
    {
        if ( zz[i]!=num[i] )
            hash[i] = true;
    }// hashing
*/
    for (i=0; i<N-1; ++i)
    {
        for (j=i+1; j<N; ++j)
        {
            a = zz[i], b = zz[j];
            if ( a!=num[i] && b!=num[j]
                && a==num[j] && b==num[i] )
            {
                ++cnt;
                zz[i]=b, zz[j]=a;
            }
        }
    }// two figures sort
    
    for (i=0; i<N-2; ++i)
    {
        for (j=i+1; j<N-1; ++j)
        {
            for (k=j+1; k<N; ++k)
            {
                a=zz[i], b=zz[j], c=zz[k];
                if ( a!=num[i] && b!=num[j] && c!=num[k] )
                {
                    if ( a>b )  temp=a, a=b, b=temp;
					if ( a>c )  temp=a, a=c, c=temp;
                    if ( b>c )  temp=b, b=c, c=temp;
                    
                    if ( a==num[i] && b==num[j] && c==num[k] )
                    {
                        cnt += 2;
                        zz[i]=a, zz[j]=b, zz[k]=c;
                    }
                }
            }
        }
    }// Three figures sort

    printf("%d\n", cnt);
    
//    system("pause");
    return 0;
}

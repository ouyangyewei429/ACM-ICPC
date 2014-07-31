/*
PROG:   frac1
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 500040;

int N, M=0;
struct fraction
{
    int a, b;
    double value;
}frac[maxn]={0};
/*
int compare(const void *a, const void *b)
{
    fraction *c = (fraction *)a;
    fraction *d = (fraction *)b;
    
    
}// compare
*/

int compare(fraction c, fraction d)
{
    return ( c.value<d.value );
}// compare

bool CanTakeIt(int x, int y)
{
    int r, swap;
    if ( y>x )  swap=y, y=x, x=swap;
    
    r = x%y;
    while ( r )
    {
        x = y;
        y = r;
        r = x%y;
    }
    
    return ( y==1 ? true:false );
}// CanTakeIt

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    scanf("%d", &N);
    for (int i=1; i<N; ++i)
    {
        for (int j=N; j>1; --j)
        {
            if ( i>=j || i%2==0 && j%2==0 ) continue;
                if ( !CanTakeIt( i, j ) ) continue;
            
            frac[M].a=i, frac[M].b=j;
            frac[M++].value=1.0*i/j;
        }
    }// End of for
    
    sort(frac, frac+M, compare);
    //qsort( frac, M, sizeof(frac[0]), compare );
    
    printf("0/1\n");
    for (int i=0; i<M; ++i)
        printf("%d/%d\n", frac[i].a, frac[i].b);
    printf("1/1\n");
    
    //system("pause");
    return 0;
}

/*
PROG:   hamming
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 80;

int N, B, D, M=1, ham[maxn]={0};

bool HammingDist(int x)
{
    for (int i=0; i<M; ++i)
    {
        int cnt = 0;
        for (int j=0; j<B; ++j)
        {
            if ( ( ham[i]&(1<<j) )!=( x&(1<<j) ) )
                ++cnt;
        }
        
        if ( cnt<D )   return false;
    }// checking
    
    return true;
}// HammingDist

int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

	int i, j;
    scanf("%d %d %d", &N, &B, &D);
    for (i=1; M<N; ++i)
    {
        if ( HammingDist( i ) )
            ham[M++] = i;
		//for ()
    }// End of for
    
    for (i=0, j=1; i<M; ++i, ++j)
    {
        if ( i!=0 && i%10==0 )  printf("\n");
        printf(i%10==0 ? "%d":" %d", ham[i]);
    }// output
    printf("\n");
    
//    system("pause");
    return 0;
}

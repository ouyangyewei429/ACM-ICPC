/*
PROG:   fracdec
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 100004;

int  N, D, hash[maxn];
char buf[maxn], temp[maxn];

void Long_Div()
{
    int i, j, r;
    
	memset( hash, -1, sizeof(hash) );

    sprintf( buf, "%d.", N/D );
    for ( i=0, r=N%D; ; ++i )
    {
        if ( r==0 )
        {
            if ( i==0 )
                sprintf( buf+strlen( buf ), "0" );
            else
                sprintf( buf+strlen( buf ), "%s", temp );
            break;
        }
        if ( hash[ r ]!=-1 )
        {
            j = hash[ r ];
            sprintf( buf+strlen( buf ), "%.*s(%s)", j, temp, temp+j );
            break;
        }
        
        hash[ r ] = i;
        N = r*10;
        temp[ i ] = N/D+'0';
        r = N%D;
    }// End of for
    
    int slen = strlen( buf );
    for ( i=0; i<slen; ++i )
    {
        if ( i!=0 && i%76==0 )  printf("\n");
        printf("%c", buf[i]);
    }
    //if ( slen<=76 )
        printf("\n");
    
    return ;
}// Long_Div

int main()
{
    freopen( "fracdec.in", "r", stdin );
    freopen( "fracdec.out", "w", stdout );
    
    scanf("%d %d", &N, &D);
    Long_Div();
    
//    system("pause");
    return 0;
}

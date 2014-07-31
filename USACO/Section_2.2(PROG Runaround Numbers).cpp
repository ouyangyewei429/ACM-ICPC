/*
PROG:   runround
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

const int maxn = 10;

char M[maxn];
bool IsSolved=false, hash[maxn]={false};
int  N, tt, st, slen, cnt, runti, ans;

int Trans_To_String( int ss )
{
    int  ret = 0;
    char temp[maxn]={0};
    while ( ss )
    {
        temp[ ret++ ] = ss%10;
        ss /= 10;
    }//
    for (int i=0; i<ret; ++i)
        M[i] = temp[ret-i-1]+'0';
    
    return ret;
}// Trans_To_String

int main()
{
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    scanf("%d", &N);
    for (int k=N+1; ; ++k)
    {
        slen = Trans_To_String( k );
        memset( hash, false, sizeof(hash) );
        
        runti = M[0]-'0', st = 1;
        for (cnt=0; cnt<slen; )
        {
            tt = ( runti+st-1 )%slen;
            if ( hash[ M[tt]-'0' ] )    break;
            
            ++cnt, hash[ M[tt]-'0' ] = true;
            runti = M[tt]-'0', st = ( tt+1 )%slen;
            if ( cnt==slen && M[tt]==M[0] )
            {
                ans = k, IsSolved=true;
                break;
            }
        }//
        if ( IsSolved ) break;
    }// End of for
    
    printf("%d\n", ans);
    
//    system("pause");
    return 0;
}

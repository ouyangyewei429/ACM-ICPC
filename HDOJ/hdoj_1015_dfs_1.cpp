/*
PROG:   Safecracker
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 35;

bool hash[maxn];
char ss[maxn];
int  target, slen;
vector <char *> data;

inline int compare_1(const void *c, const void *d)
{
    return ( *(char *)d-*(char *)c );
}// compare_1

bool CanTakeIt(int v, int w, int x, int y, int z)
{
    return ( v-w*w+x*x*x-y*y*y*y+z*z*z*z*z==target );
}// CanTakeIt

bool dfs(int cnt, char keys[])
{
    if (cnt == 5)
    {
        if ( CanTakeIt(keys[0]-'A'+1, keys[1]-'A'+1,
        keys[2]-'A'+1, keys[3]-'A'+1, keys[4]-'A'+1) )
        {
            return true;
        }
        
        return false;
    }// destination
    
    for (int i=0; i<slen; ++i)
    {
        if ( !hash[i] )
        {
            hash[i]=true, keys[cnt]=ss[i];
            if ( dfs( cnt+1, keys ) )
                return  true;
                
            hash[i]=false;
        }
    }// Main Process
    
    return false;
}// dfs

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1015.txt", "r", stdin);
    freopen("E:\\hdoj_1015_ans.txt", "w", stdout);
#endif

    char keys[maxn]={0};
    while ( EOF!=scanf("%d %s", &target, ss) )
    {
        if (target==0 && !strcmp(ss, "END"))
            break;
        
        slen = strlen(ss);
        qsort( ss, slen, sizeof(ss[0]), compare_1 );
        
        memset(hash, false, sizeof(hash));
        
        if ( dfs( 0,keys ) )  /* cnt, keys */
            printf("%s\n", keys);
        else
            printf("no solution\n");
    }// End of while
    
    return 0;
}

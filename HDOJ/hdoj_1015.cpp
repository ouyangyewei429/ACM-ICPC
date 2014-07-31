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

#define DEBUG 1

const int maxn = 20;

char ss[maxn];
bool hash[maxn];
int  target, slen;
vector <char *> data;

bool CanTakeIt(int v, int w, int x, int y, int z)
{
    if ( v-w*w+x*x*x-y*y*y*y+z*z*z*z*z == target )
        return true;
    else
        return false;
}// CanTakeIt

void dfs(int cnt, char keys[])
{
    if (cnt == 5)
    {
        if ( CanTakeIt(keys[0]-'A'+1, keys[1]-'A'+1,
            keys[2]-'A'+1, keys[3]-'A'+1, keys[4]-'A'+1) )
        {
            keys[cnt] = '\0';
            data.push_back( keys );
        }
        return ;
    }// destination
    
    for (int i=0; i<slen; ++i)
    {
        if ( !hash[i] )
        {
            hash[i]=true, keys[cnt]=ss[i];
            dfs(cnt+1, keys);
            hash[i]=false;
        }    
    }// Main Process
}// dfs

int compare_1(char c, char d)
{
    return ( c>d );
}// compare_1

int compare_2(char *c, char *d)
{
    return ( strcmp(c, d) );
}// compare

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1015.txt", "r", stdin);
    freopen("E:\\hdoj_1015_ans.txt", "w", stdout);
#endif

    char keys[maxn];
    while (EOF != scanf("%d %s", &target, ss))
    {
        if (target==0 && !strcmp(ss, "END"))
            break;

        data.clear();
        memset(keys, 0, sizeof(keys));
        memset(hash, false, sizeof(hash));

        slen = strlen(ss);
        sort(ss, ss+slen, compare_1);
        //--------------------------------
        //printf("%s\n", ss);
        //---------------------------
        
        dfs( 0, keys ); /*   cnt, keys */

        if ( data.empty() )
            printf("no solution\n");
        else
        {
            sort(data.begin(), data.end(), compare_2);
            //printf("%s\n", data[0]);
            
            for (int i=0; i<data.size(); ++i)
                printf("%s\n", data[i]);
            printf("\n");
            
        }
    }// End of while

    return 0;
}

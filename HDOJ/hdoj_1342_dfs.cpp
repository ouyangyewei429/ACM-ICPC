/*
PROG:   Lotto
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int MAXN_N = 1949;
const int MAXN_K = 15;

int  K, ss[MAXN_K];
bool hash[MAXN_K], rt=false;

void dfs(int cnt, int start, int result[])
{
    if (cnt == 6)
    {
        for (int j=0; j<6; ++j)
            printf(j==0 ? "%d":" %d", result[j]);
        printf("\n");
        
        return ;
    }// destination
    
    for (int i=start; i<K; ++i)
    {
        if ( !hash[i] )
        {
            hash[i]=true, result[cnt]=ss[i];
            dfs(cnt+1, i+1, result);
            hash[i]=false;
        }
    }// Main Process
}// dfs

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1342.txt", "r", stdin);
    freopen("E:\\hdoj_1342_ans.txt", "w", stdout);
#endif    

    int result[MAXN_K] = {0};
    while (~scanf("%d", &K), K!=0)
    {
        memset(hash, false, sizeof(hash));
        for (int i=0; i<K; ++i)
            scanf("%d", &ss[i]);
        
        if ( rt )   printf("\n");
        rt = true;
        
        dfs( 0,0,result ); /* cnt, start, result */
    }// End of while
    
    return 0;
}

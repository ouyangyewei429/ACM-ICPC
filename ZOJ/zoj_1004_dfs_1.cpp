/*
PROG:   Anagrams by Stack
ID  :   ouyangyewei
LANG:   C++
*/
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

#define DEBUG 0

const int maxn = 1004;

int  alen, blen;
stack <char> st;
char src[maxn], dest[maxn], path[maxn];

void dfs(int i, int j, int k)
{
    if ( j==blen )
    {
        for (int y=0; y<k; ++y)
            printf(y==0 ? "%c":" %c", path[y]);
        printf("\n");
        
        return ;
    }// destination
    
    if ( i<alen )
    {   // st.empty() || st.top()!=dest[j]
        st.push( src[i] );
        path[k] = 'i';
        dfs( i+1, j, k+1 );
        st.pop();
    }
    if ( !st.empty() && st.top()==dest[j] )
    {
        char temp = st.top();
        st.pop();
        path[k] = 'o';
        dfs( i, j+1, k+1 );
        st.push( temp );
    }
}// dfs

int main()
{
#if DEBUG
    freopen("E:\\zoj_1004.txt", "r", stdin);
    freopen("E:\\zoj_1004_ans.txt", "w", stdout);
#endif

    while ( EOF!=scanf("%s %s", src, dest) )
    {
        alen = strlen( src );
        blen = strlen( dest );
        while ( !st.empty() )   st.pop();
        
        printf("[\n");
        dfs( 0, 0, 0 );    // src_index, dest_index, path_index
        printf("]\n");
    }// End of while
    
    return 0;
}

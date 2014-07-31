/*
PROG:   Prerequisites?
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory.h>
using namespace std;

const int maxn = 104;

string a, b;
int  result[maxn];
char ss[maxn], line[maxn];
map <char, int> index;

int main()
{
    while ( getline(cin, a, '\n') )
    {
        if ( a[0]=='#' )    break;
        
        index.clear();
        strcpy( ss, a.c_str() );
        for (int i=0; i<strlen(ss); ++i)
            index[ss[i]] = i+1;
        
        getchar();
        getline(cin, b, '\n');
        strcpy( line, b.c_str() );
        memset(result, 0, sizeof(result));
        for (int i=0; i<strlen(line); ++i)
        {
            if ( index[line[i]]!=0 )
                result[index[line[i]]]++;
        }// counting
        
        for (int i=0; i<strlen(ss); ++i)
            printf("%c %d\n", ss[i], result[ index[ ss[i] ] ]);
        
        getchar();
    }// End of while
    
    return 0;
}

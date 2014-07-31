/*
PROG:   Word Amalgamation
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 12;

bool IsNoAns;
string ss, tt, words;
map <string, string> dict;

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1113.txt", "r", stdin);
    freopen("E:\\hdoj_1113_ans.txt", "w", stdout);
#endif

    while ( cin >> ss )
    {
        if ( ss=="XXXXXX" )
            break;
        
        tt = ss;
        sort( ss.begin(), ss.end() );
        dict[tt] = ss;
    }// end of while
    
    while ( cin >> words )
    {
        if ( words=="XXXXXX" )
            break;
        
        sort( words.begin(), words.end() );
        
        IsNoAns = true;
        map <string, string>::iterator iter;
        for (iter=dict.begin(); iter!=dict.end(); ++iter)
        {
            if ( iter->second==words )
            {
                IsNoAns = false;
                cout << iter->first << endl;
            }
        }
        if ( IsNoAns )
            printf("NOT A VALID WORD\n");
        
        printf("******\n");
    }// End of while
    
    return 0;
}

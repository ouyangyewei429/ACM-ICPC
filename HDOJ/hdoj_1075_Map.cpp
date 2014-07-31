/*
PROG:   What Are You Talking About
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

int slen;
string s1, s2, line, result;
map <string, string> data;

int main()
{    
#if DEBUG
    freopen("E:\\hdoj_1075.in", "r", stdin);
    freopen("E:\\hdoj_1075.out", "w", stdout);
#endif

    cin >> s1;   // START
    while ( cin >> s1, s1!="END" )
    {
        cin >> s2;
        data[ s2 ] = s1;
    }// dictionary
    
    cin >> s1;
    getchar();  // fetch carry reture
    while ( getline( cin, line ) && line!="END" )
    {
        result = "";
        slen = line.length();
        for ( int i=0; i<slen; ++i )
        {
            if ( isalpha( line[i] ) )
            {
                result += line[i];
            }
            else
            {
                if ( data[ result ]=="" )
                    cout << result;
                else
                    cout << data[ result ];
                cout << line[i];
                
                result = "";
            }
        }// scanning
        
        cout << endl;
    }// books
    
    return 0;
}

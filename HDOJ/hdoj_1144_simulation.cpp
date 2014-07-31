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

bool result;
string course;
int  k, m, c, r, cnt;
map <string, int> data;

int main()
{
    while (~scanf("%d", &k), k!=0)
    {
        data.clear();
        
        scanf("%d", &m);
        for (int i=0; i<k; ++i)
        {
            cin >> course;
            data[course] = 1;
        }// preprocess
        
        result = true;
        for (int i=0; i<m; ++i)
        {
            cnt = 0;
            scanf("%d %d", &c, &r);
            for (int j=0; j<c; ++j)
            {
                cin >> course;
                if ( data[course] )
                    ++cnt;
            }// End of For
            if ( cnt<r )
                result = false;
        }// Main Process
        
        if ( !result )
            printf("no\n");
        else
            printf("yes\n");
    }// End of while
    
    return 0;
}

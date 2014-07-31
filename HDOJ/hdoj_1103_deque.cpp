/*
PROG:   Flo's Restaurant
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

#define DEBUG 0

char buf[10];
deque <int> q[3];
int  s[3], hh, mm, groups;

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1103.txt", "r", stdin);
    freopen("E:\\hdoj_1103_ans.txt", "w", stdout);
#endif

    while ( ~scanf("%d %d %d", &s[0], &s[1], &s[2]), s[0]+s[1]+s[2]!=0 )
    {
        //getchar();
        for (int i=0; i<3; ++i) q[i].clear();
        
        int ans = 0;
        while ( EOF!=scanf("%s", buf), buf[0]!='#' )
        {
            scanf("%d", &groups);
            sscanf( buf, "%d:%d", &hh, &mm );
            
            int k, tmp, t=hh*60+mm;
            if ( groups==1 || groups==2 )   k = 0;
            else if ( groups==3 || groups==4 )  k = 1;
            else if ( groups==5 || groups==6 )  k = 2;
            
            if ( q[k].size() < s[k] )
            {
                ans += groups;
                q[k].push_back( t );
            }// Empty seat
            else if ( q[k].size()==s[k] )
            {
                tmp = q[k].front()+30;
                if ( t+30 >= tmp )
                {
                    ans += groups;
                    if ( t < tmp )  t = tmp;
                    q[k].pop_front();
                    q[k].push_back( t );
                }
            }// Non Empty seat
        }// Main Process
        
        printf("%d\n", ans);
    }// end of while
    
    return 0;
}

/*
PROG:   Average is not Fast Enough!
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory.h>
using namespace std;

#define DEBUG 0

const int maxn = 24;

string ti;
double S, sum;
int N, M, i, a, b, c, num, sign;
struct player
{
    bool quit;
    int teamnum, mm, ss;
}race[maxn];

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1036.txt", "r", stdin);
    freopen("E:\\hdoj_1036_ans.txt", "w", stdout);
#endif

    scanf("%d %lf", &N, &S);
    
    M = 0;
    while ( ~scanf("%d", &num) )
    {
        sign=0, sum=0.0;
        for (i=0; i<N; ++i)
        {
            cin >> ti;
            if ( ti[0]=='-' )
                sign = 1;
            
            sscanf( ti.c_str(), "%d:%d:%d", &a, &b, &c );
            
            sum += ( a*3600+b*60+c );
        }// section M
        
        race[M].teamnum = num;
        if ( !sign )
        {
            race[M].quit = false;
            race[M].mm = (int)( sum/S+0.5 )/60;
            race[M].ss = (int)( sum/S+0.5 )%60;
        }
        else
            race[M].quit = true;
        
        ++M;
    }// players

    for (i=0; i<M; ++i)
    {
        if ( race[i].quit )
            printf("%3d: -\n", race[i].teamnum);
        else
            printf("%3d: %d:%02d min/km\n", race[i].teamnum, race[i].mm, race[i].ss);
    }// output
        
    return 0;
}
/*
            if ( ti!="-:--:--" )
            {
                sum += ( ti[0]-'0' )*3600;  // hour
                sum += ( (ti[2]-'0')*10+(ti[3]-'0') )*60;   // minutes
                sum += ( (ti[5]-'0')*10+(ti[6]-'0') );  // seconds
            }
            else
                sign = 1;
*/

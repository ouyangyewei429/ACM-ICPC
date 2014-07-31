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
int N, M, i, teamnum, sign;

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1036.txt", "r", stdin);
    freopen("E:\\hdoj_1036_ans.txt", "w", stdout);
#endif

    scanf("%d %lf", &N, &S);
    while ( ~scanf("%d", &teamnum) )
    {
        sum=0, sign=0;
        for (i=0; i<N; ++i)
        {
            cin >> ti;
            if ( ti!="-:--:--" )
            {
                sum += ( ti[0]-'0' )*3600;    // hour
                sum += ( (ti[2]-'0')*10+(ti[3]-'0') )*60;   // minutes
                sum += ( (ti[5]-'0')*10+(ti[6]-'0') );  // seconds
            }
            else
                sign = 1;
        }// section M
            
        if ( sign )
            printf("%3d: -\n", teamnum);
        else
            printf("%3d: %d:%02d min/km\n", teamnum, (int)(sum/S+0.5)/60, (int)(sum/S+0.5)%60);
    }// section
    
    return 0;
}

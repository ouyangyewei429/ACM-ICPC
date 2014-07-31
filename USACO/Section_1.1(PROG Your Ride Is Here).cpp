/*
PROG:   ride
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

int  i, ds, dt;
char ss[10], tt[10];

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    scanf("%s %s", ss, tt);
    for ( i=0, ds=1; i<strlen( ss ); ++i )  ds *= ( ss[i]-'A'+1 );
    for ( i=0, dt=1; i<strlen( tt ); ++i )  dt *= ( tt[i]-'A'+1 );
    
    if ( ds%47==dt%47 ) printf("GO\n");
    else    printf("STAY\n");
    
    //system("pause");
    return 0;
}

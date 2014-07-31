/*
PROG:   Clock
ID  :   ouyangyewei
LANG:   C++ 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int T, hh, mm, i;
struct CLOCK
{
    int h, m, tinum, degree;
}ti[5];

int Min(int x, int y)
{
    return ( x<y ? x:y );
}// Min

int compare(CLOCK c, CLOCK d)
{
    if ( c.degree==d.degree )
        return ( c.tinum < d.tinum );
    else
        return ( c.degree < d.degree );
}// compare

int main()
{
    scanf("%d", &T);

    while ( T-- )
    {
        //memset(ti, 0, sizeof(ti));

        for (i=0; i<5; ++i)
        {
            scanf("%d:%d", &hh, &mm);
            ti[i].h = hh, ti[i].m = mm, ti[i].tinum=hh*60+mm;
            ti[i].degree = Min( abs(hh%12*300-mm*55), 3600-abs(hh%12*300-mm*55) );
        }// Input
        
        sort(ti, ti+5, compare);
        printf("%02d:%02d\n", ti[2].h, ti[2].m);
        //for (i=0; i<5; ++i)
        //    printf("%02d:%02d %d %d\n", ti[i].h, ti[i].m, ti[i].tinum, ti[i].degree);
    }// End of while
    
    //system("pause");
    return 0;
}

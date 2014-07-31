/*
PROG:   preface
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

int N, tt, result[8];
int a[10][8], b[10][8], c[10][8], d[10][8]; // 个，十，百，千 

int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    // 个位 
    a[1][1]=a[4][1]=1, a[6][1]=a[9][1]=1;
    a[2][1]=a[7][1]=2, a[3][1]=a[8][1]=3, a[9][3]=1;
    for ( int i=4; i<=8; ++i )  a[i][2]=1;
    
    // 十位
    b[1][3]=b[4][3]=1, b[6][3]=b[9][3]=1;
    b[2][3]=b[7][3]=2, b[3][3]=b[8][3]=3, b[9][5]=1;
    for ( int i=4; i<=8; ++i )  b[i][4]=1;
    
    // 百位 
    c[1][5]=c[4][5]=1, c[6][5]=c[9][5]=1;
    c[2][5]=c[7][5]=2, c[3][5]=c[8][5]=3, c[9][7]=1;
    for ( int i=4; i<=8; ++i )  c[i][6]=1;
    
    // 千位
    d[1][7]=1, d[2][7]=2, d[3][7]=3;
    
    scanf("%d", &N);
    for ( int i=1; i<=N; ++i )
    {
        tt = i;
        if ( tt/1000 )
        {
            result[7] += d[ tt/1000 ][7];
            tt %= 1000;
        }// 
        if ( tt/100 )
        {
            result[5] += c[ tt/100 ][5];
            result[6] += c[ tt/100 ][6];
            result[7] += c[ tt/100 ][7];
            tt %= 100;
        }// 
        if ( tt/10 )
        {
            result[3] += b[ tt/10 ][3];
            result[4] += b[ tt/10 ][4];
            result[5] += b[ tt/10 ][5];
            tt %= 10;
        }// 
        if ( tt )
        {
            result[1] += a[ tt ][1];
            result[2] += a[ tt ][2];
            result[3] += a[ tt ][3];
        }
    }// simulation
    
    for ( int i=1; i<=7; ++i )
    {
        switch ( i )
        {
            case 1: if ( result[1] ) printf("I %d\n", result[1]); break;
            case 2: if ( result[2] ) printf("V %d\n", result[2]); break;
            case 3: if ( result[3] ) printf("X %d\n", result[3]); break;
            case 4: if ( result[4] ) printf("L %d\n", result[4]); break;
            case 5: if ( result[5] ) printf("C %d\n", result[5]); break;
            case 6: if ( result[6] ) printf("D %d\n", result[6]); break;
            case 7: if ( result[7] ) printf("M %d\n", result[7]); break;
        }
    }// output
    
    //system("pause");
    return 0;
}

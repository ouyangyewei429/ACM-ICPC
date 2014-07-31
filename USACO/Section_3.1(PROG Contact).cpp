/*
PROG:   contact
ID  :   ouyangyewei
LANG:   C++
*/
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

namespace
{
    int  A, B, N, hash[100000], dcnt=0;
    struct container
    {
        long ti, digit;
        container() { ti=0, digit=0; }
    }data[100000];
}// Non Name Space

void Scanning( long S, int length )
{
    long mask, mask2, tt;
    for ( int i=A; i<=B && i<=length; ++i )
    {
        mask = ( 1<<( i ) )-1;
        mask2 = mask+1;
        tt = ( S & mask ) | mask2;
        
        hash[ tt ]++;
    }
}// Scanning

void ReadData()
{
    char c;
    long val=0, count=0, limit=0;   // limit 作为极限掩码，2 的 B 次方减一 
    
    scanf("%d %d %d", &A, &B, &N);

	limit = ( 1<<(B) )-1;
    while ( ( c=getchar() )!=EOF )
    {
        if ( c!=' ' && c!='\n' )
        {
            ++count;
            val = ( (val<<1)+(c-'0') ) & limit; // 读入01串并计算十进制值 
            Scanning( val, count ); // 将当前01串扫描 A~B 位 
        }
    }
}// ReadData

int compare(const void *a, const void *b)
{
    container *c = ( container *)a;
    container *d = ( container *)b;
    
    if ( c->ti==d->ti )
        return ( c->digit - d->digit );
    else
        return ( d->ti - c->ti );
}// compare

void Calculate()
{
    long limit = ( 1<<(B+1) )-1;
    for ( int i=0; i<=limit; ++i )
    {
        if ( hash[ i ] )
        {
            data[ dcnt ].digit=i;
            data[ dcnt++ ].ti = hash[ i ];
        }
    }// Record the digit
    
    qsort( data, dcnt, sizeof(data[0]), compare );
}// Caluate

void Print_Bin( long t )
{
    char str[15];
    int  cnt = 0;
    
    while ( t )
    {
        str[ cnt++ ] = ( t&1 )+'0';
        t >>= 1;
    }
    for ( int i=cnt-2; i>=0; --i )
        printf("%c", str[ i ]);
}// Print_Bin

void Output()
{
    bool cr = true;
    long blocks=0, linecnt=0, current=-1;
    for ( int i=0; i<dcnt; ++i )
    {
        if ( data[i].ti!=current )
        {
            current = data[i].ti;
            if ( blocks==N )    break;
            
            if ( !cr )  printf("\n");
            else    cr = false;
            printf("%ld\n", data[i].ti);
            ++blocks; linecnt=0;
        }
        else
        {
            linecnt++;
            if ( linecnt==6 )
            {
                printf("\n");
                linecnt = 0;
            }
            else
                printf(" ");
        }
        
        Print_Bin( data[i].digit );
    }
    
    printf("\n");
    return ;
}// Output

int main()
{/*
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    */
    ReadData();
    Calculate();
    Output();
    
    //system("pause");
    return 0;
}

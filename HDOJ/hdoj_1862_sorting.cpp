/*
PROG:   EXCEL≈≈–Ú
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <memory.h>
using namespace std;

#define DEBUG 0

const int maxn = 100004;

int N, C, cas=1;
struct student
{
    int id, grade;
    char name[10]; 
}data[maxn]={0};

int compare_1(const void *a, const void *b)
{
    student *c = (student *)a;
    student *d = (student *)b;
    
    return ( c->id - d->id );
}// compare_1

int compare_2(const void *a, const void *b)
{
    student *c = (student *)a;
    student *d = (student *)b;
    
    if ( !strcmp( c->name, d->name ) )
        return ( c->id - d->id );
    else
        return ( strcmp( c->name, d->name ) );
}// compare_1

int compare_3(const void *a, const void *b)
{
    student *c = (student *)a;
    student *d = (student *)b;
    
    if ( c->grade==d->grade )
        return ( c->id - d->id );
    else
        return ( c->grade - d->grade );
}// compare_1

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1862.txt", "r", stdin);
    freopen("E:\\hdoj_1862_ans.txt", "w", stdout);
#endif

    while ( ~scanf("%d %d", &N, &C), N!=0 )
    {
        for (int i=0; i<N; ++i)
            scanf("%d %s %d", &data[i].id, &data[i].name, &data[i].grade);
            
        if ( C==1 )
            qsort( data, N, sizeof(data[0]), compare_1 );
        else if ( C==2 )
            qsort( data, N, sizeof(data[0]), compare_2 );
        else if ( C==3 )
            qsort( data, N, sizeof(data[0]), compare_3 );
        
        printf("Case %d:\n", cas++);
        for (int i=0; i<N; ++i)
            printf("%06d %s %d\n", data[i].id, data[i].name, data[i].grade);
    }// End of while
    
    return 0;
}

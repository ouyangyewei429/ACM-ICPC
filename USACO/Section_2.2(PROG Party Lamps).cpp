/*
PROG:   lamps
ID  :   ouyangyewei
LANG:   C++
*/
#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

set <string> result;
bool IsSolved=false, hash[80]={false};
int  N, C, temp, on[102], off[102];

bool CanTakeIt( int lamps )
{
	int i, tt;
	for ( i=1; on[i]!=-1; ++i )
	{
		tt = on[i]%6 ? 6-(on[i]%6):0;
	    if ( lamps & (1<<tt) )
            continue;
        else
            return false;
    }
    for ( i=1; off[i]!=-1; ++i )
    {
		tt = off[i]%6 ? 6-(off[i]%6):0;
        if ( lamps & ( 1<<tt ) )
            return false;
    }
    
    return true;
}// CanTakeIt

void Integer_To_String( int lamps )
{
    int i, slen=0;
    string a, b, c;
    while ( lamps )
    {
		slen++;
        a += lamps%2+'0';
        lamps >>= 1;
    }// convert to string
	
	for ( ; slen<6; ++slen )	a += '0';
    for ( i=0; i<slen; ++i )    b += a[ slen-i-1 ];
    for ( i=0; i<N; ++i )
	{
        if ( b[ i%6 ] ) c += b[ i%6 ];
		else  c += '0';
	}// output
	
    result.insert( c );
    return ;
}// Integer_To_String

void dfs( int lamps, int cnt )
{
    if ( cnt>C )    return ;
    if ( CanTakeIt( lamps ) )
    {
        IsSolved = true;
        Integer_To_String( lamps );
        
        //return ;
    }// Checking status
    //else
	//{
		int i;
		for ( i=5; i>=0; --i )  lamps ^= ( 1<<i );
		if ( !hash[ lamps ] )
		{
			hash[ lamps ] = true;
			dfs( lamps, cnt+1 );    // button press 1
			hash[ lamps ] = false;
		}
		for ( i=5; i>=0; --i )  lamps ^= ( 1<<i );
    
		for ( i=1; i<=5; i+=2 ) lamps ^= ( 1<<i );
		if ( !hash[ lamps ] )
		{
			hash[ lamps ] = true;
			dfs( lamps, cnt+1 );    // button press 2
			hash[ lamps ] = false;
		}
		for ( i=1; i<=5; i+=2 ) lamps ^= ( 1<<i );
    
		for ( i=2; i<=6; i+=2 ) lamps ^= ( 1<<(6-i) );
		if ( !hash[ lamps ] )
		{
			hash[ lamps ] = true;
			dfs( lamps, cnt+1 );    // button press 3
			hash[ lamps ] = false;
		}    
		for ( i=2; i<=6; i+=2 ) lamps ^= ( 1<<(6-i) );
    
		for ( i=1; i<=4; i+=3 ) lamps ^= ( 1<<(6-i) );
		if ( !hash[ lamps ] )
		{
			hash[ lamps ] = true;
			dfs( lamps, cnt+1 );    // button press 4
			hash[ lamps ] = false;
		}
		for ( i=1; i<=4; i+=3 ) lamps ^= ( 1<<(6-i) );
	//}
    
    return ;
}// dfs

int main()
{
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	int i;
    scanf("%d %d", &N, &C);
    for ( i=1; ; ++i )
    {
        scanf("%d", &on[i]);
		if ( on[i]==-1 )	break;
    }// lamps are on
    for ( i=1; ; ++i )
    {
        scanf("%d", &off[i]);
        if ( off[i]==-1 )	break;
    }// lamps are off
    
	hash[ 63 ] = true;
    dfs( 63, 0 );
    if ( !IsSolved )    printf("IMPOSSIBLE\n");
    else
    {
        set <string>::iterator iter;
        for ( iter=result.begin(); iter!=result.end(); ++iter )
			cout << *iter << endl;
    }

//    system("pause");
    return 0;
}
/*
50 
100 
1 -1 
-1

10010010010010010010010010010010010010010010010010
10101010101010101010101010101010101010101010101010
11000111000111000111000111000111000111000111000111
11111111111111111111111111111111111111111111111111

10 1
-1
7
-1

0000000000
0101010101
0110110110

20 3
-1
1 3 5 -1



100
2000
31 86 23 -1
42 -1
IMPOSSIBLE
*/

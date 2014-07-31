/*
PROG:   prefix
ID  :   ouyangyewei
LANG:   C++
*/
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

struct Trie_Node
{
    bool IsEnd;
    Trie_Node *branch[26];
    Trie_Node(): IsEnd( false )
    {
        memset( branch, 0, sizeof(branch) );
    }// Init
};

class Trie
{    
    public:
        Trie();
        void Trie_Insert( char tt[] );
        void Trie_Find( long j );
    
    private:
        Trie_Node *root;
}t; // type class "Trie" object t

long slen;
bool prefix[200400];
char line[204], ss[200400];

Trie::Trie()
{
    root = new Trie_Node();
}// Trie

void Trie::Trie_Insert( char tt[] )
{
    Trie_Node *ptr = root;
    int tlen = strlen( tt );
    for ( int i=0; i<tlen; ++i )
    {
        if ( ptr->branch[ tt[i]-'A' ]==NULL )
        {
            Trie_Node *tmp = new Trie_Node();
            ptr->branch[ tt[i]-'A' ] = tmp;
        }
                        
        ptr = ptr->branch[ tt[i]-'A' ];
    }
                    
    ptr->IsEnd = true;
}// Trie_Insert

void ReadData()
{    
    while ( gets( line ) )
    {
        if ( line[0]=='.' ) break;
        
        char *tok = strtok( line, " " );
        while ( tok )
        {
            t.Trie_Insert( tok );
            //printf("%s\n", tok);
            tok = strtok( NULL, " " );
        }// Insert
    }
    
    char str[204];
    while ( gets( str ) )
    {
        strcat( ss, str );
    }
    
    slen = strlen( ss );
    
    return ;
}// ReadData

void Trie::Trie_Find( long j )
{
    Trie_Node *ptr = root;
    for ( ; ; ++j )
    {
        ptr = ptr->branch[ ss[j]-'A' ];
        if ( ss[j]=='\0' || ptr==NULL )
            return ;
        if ( ptr->IsEnd )
			prefix[ j+1 ]=true;
    }
    
    return ;
}// Trie_Find

void Solve()
{
    prefix[0] = true;
    for ( long i=0; i<slen; ++i )
    {
        if ( !prefix[i] )   continue;
        
		t.Trie_Find( i );
    }// Searching
    
	int result;
	for ( result=slen; !prefix[result]; --result );
    printf("%d\n", result);

    return ;
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\prefix.txt", "r", stdin);
    freopen("E:\\prefix_ans.txt", "w", stdout);
#endif

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    ReadData();
    Solve();
    
//    system("pause");
    return 0;
}

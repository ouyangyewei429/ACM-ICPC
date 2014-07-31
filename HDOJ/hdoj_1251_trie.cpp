/*
PROG:   统计难题
ID  :   ouyangyewei
LANG:   C++
*/
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 0

struct Trie_Node
{
    int  cnt;
    Trie_Node *branch[27];
    Trie_Node():cnt( 0 )
    {
        memset( branch, 0, sizeof(branch) );
    }// Init
};

class Trie
{
    public:
        Trie();
        void Trie_Insert( char ss[] );
        int  Trie_Find( char ss[] );
        
    private:
        Trie_Node *root;
}t;

Trie::Trie()
{
    root = new Trie_Node();
}// Trie

void Trie::Trie_Insert( char ss[] )
{
    Trie_Node *ptr = root;
    Trie_Node *temp = NULL;
    int slen = strlen( ss );
    for ( int i=0; i<slen ;++i )
    {
        if ( ptr->branch[ ss[i]-'a' ]==NULL )
        {
            temp = new Trie_Node();
            ptr->branch[ ss[i]-'a' ] = temp;
        }
        
        ++( ptr->branch[ ss[i]-'a' ]->cnt );
        ptr = ptr->branch[ ss[i]-'a' ];
    }// Insert
    
    return ;
}// Trie_Insert

int Trie::Trie_Find( char ss[] )
{
    int i, slen = strlen( ss );
    Trie_Node *ptr = root;
    for ( i=0; i<slen; ++i )
    {
        ptr = ptr->branch[ ss[i]-'a' ];
        if ( ptr==NULL )    break;
    }
    
    if ( i==slen )
        return ( ptr->cnt );
    else
        return 0;
}// Trie_Find

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1251.txt", "r", stdin);
    freopen("E:\\hdoj_1251_ans.txt", "w", stdout);
#endif

    char vocabu[12];
    while ( gets( vocabu ) )
    {
		if ( !strcmp( vocabu, "" ) )	break;
        t.Trie_Insert( vocabu );
    }// creat the trie
    
    while ( EOF != scanf("%s", vocabu) )
    {
        printf("%d\n", t.Trie_Find( vocabu ));
    }// Find the prefix
    
    return 0;
}

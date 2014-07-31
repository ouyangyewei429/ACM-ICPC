/*
PROG:   What Are You Talking About
ID  :   ouyangyewei
LANG:   C++
*/
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 1

const int SIZE = 12;
const int MAXN = 3002;

struct Dicitionary
{
    char ss[20], tt[20];
}dict[1002];

struct Trie_Node
{
    int index;
    Trie_Node *branch[27];
    Trie_Node(): index( -1 )
    {
        memset( branch, 0, sizeof(branch) );
    }
};

class Trie
{
    public:
        Trie();
        void Trie_Insert( int k, char words[] );
        int Trie_Find( char words[] );
    
    private:
        Trie_Node *root;
}t;

Trie::Trie()
{
    root = new Trie_Node();
}// Trie

void Trie::Trie_Insert( int k, char words[] )
{
    Trie_Node *ptr = root;
    int wlen = strlen( words );
    for ( int i=0; i<wlen; ++i )
    {
        if ( ptr->branch[ words[i]-'a' ]==NULL )
        {
            Trie_Node *temp = new Trie_Node();
            ptr->branch[ words[i]-'a' ] = temp;
        }
        
        ptr = ptr->branch[ words[i]-'a' ];
    }// End of for
    
    ptr->index = k;
}// Trie_Insert

int Trie::Trie_Find( char words[] )
{
    Trie_Node *ptr = root;
    int wlen = strlen( words );
    for ( int i=0; i<wlen; ++i )
    {
        if ( ptr->branch[ words[i]-'a' ]!=NULL )
            ptr = ptr->branch[ words[i]-'a' ];
        else
            return -1;
    }// 
    
    return ptr->index;
}// Trie_Find

void Solve()
{
    int  slen, tlen, M=0;
    char line[SIZE<<1], s1[SIZE], s2[SIZE], keys[SIZE];
    
    while ( EOF!=scanf("%s", s1) )
    {
        if ( !strcmp( s1, "END" ) )   break;
        if ( !strcmp( s1, "START" ) ) continue;
        
        scanf("%s", s2);
        strcpy( dict[M].ss, s1 );
        strcpy( dict[M].tt, s2 );
        
        t.Trie_Insert( M++, s2 );   // Note " M++ "
    }// dictionary
    
    while ( gets( line ) )
    {
        if ( !strcmp( line, "END" ) )   break;
        if ( !strcmp( line, "START" ) ) continue;
        
        slen = strlen( line );
        for ( int i=0; i<slen;  )
        {
            tlen = 0;
            memset( keys, 0, sizeof(keys) );
            while ( isalpha( line[i] ) )
            {
                keys[tlen++] = line[i++];   // Note " tlen++ ", " i++ "
            }// draw the words
            keys[tlen] = '\0';
            
            // Searching keyword in Trie
            int kk = t.Trie_Find( keys );
            if ( kk!=-1 )
                printf("%s\n", dict[kk]);
            else
                printf("%s\n", keys);
            
            while ( !isalpha( line[i] ) )
            {
                printf("%c", line[i++]);    // Note " i++ "
            }// Not a alphabet
        }// scanning
    }// books
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1075.in", "r", stdin);
    freopen("E:\\hdoj_1075.out", "w", stdout);
#endif
    
    Solve();
    
    return 0;
}

/*
PROG:   Hat¡¯s Words
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG 0

//const int size = 102;
const int maxn = 50004;

struct Trie_Node
{
    bool IsEnd;
    Trie_Node *branch[27];
    Trie_Node():IsEnd( false )
    {
        memset( branch, 0, sizeof(branch) );
    }// Init
};

class Trie
{
    public:
        Trie();
        void Trie_Insert( char ss[] );
        bool Trie_Find( char ss[] );
    
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
    int slen = strlen( ss );
    for ( int i=0; i<slen; ++i )
    {
        if ( ptr->branch[ ss[i]-'a' ]==NULL )
        {
            Trie_Node *temp = new Trie_Node();
            ptr->branch[ ss[i]-'a' ] = temp;
        }
        
        ptr = ptr->branch[ ss[i]-'a' ];
    }// End of for
    
    ptr->IsEnd = true;
    //delete temp;
}// Trie_Insert

bool Trie::Trie_Find( char ss[] )
{
    Trie_Node *ptr = root;
    int slen = strlen( ss );
    for ( int i=0; i<slen; ++i )
    {
        if ( ptr->branch[ ss[i]-'a' ]!=NULL )
            ptr = ptr->branch[ ss[i]-'a' ];
        else
            return false;
    }
    
    return ptr->IsEnd;
}// Trie_Find

int  M=0;
char words[maxn][15];

void ReadData()
{
    while ( EOF!=scanf("%s", words[M]) )
    {
        t.Trie_Insert( words[M++] );
    }// Insert into Trie
}// ReadData

void Solve()
{
    int  tlen;
    char s1[15], s2[15];
    for ( int i=0; i<M; ++i )
    {
        tlen = strlen( words[i] );
        if ( tlen<2 )   continue;
        for ( int j=1; j<tlen; ++j )
        {
            memset( s1, 0, sizeof(s1) );
            memset( s2, 0, sizeof(s2) );
            strncpy( s1, words[i], j );
            strcpy( s2, words[i]+j );
            
            if ( t.Trie_Find( s1 ) && t.Trie_Find( s2 ) )
            {
                printf("%s\n", words[i]);
                break;
            }    
        }
    }// End of for
}// Solve

int main()
{
#if DEBUG
    freopen( "E:\\hatwords.in", "r", stdin );
    freopen( "E:\\hatwords.out", "w", stdout );
#endif
    
    ReadData();
    Solve();
    
//    delete t;
    return 0;
}

/*
PROG:   What Are You Talking About
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 15;

struct Dictionary
{
    char front[maxn];
    char back[maxn];
}dict[500004];

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
        ~Trie() { }
        void Trie_Insert( int k, char ss[] );
        int Trie_Find( char ss[] );
        
    private:
        Trie_Node *root;
}t;

/* Valiable */
int M=0;

Trie::Trie()
{
    root = new Trie_Node();
}// Trie

void Trie::Trie_Insert( int k, char ss[] )
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
    }
    
    ptr->index = k;
}// Trie_Insert

int Trie::Trie_Find( char ss[] )
{
    Trie_Node *ptr = root;
    int slen = strlen( ss );
    for ( int i=0; i<slen; ++i )
    {
        if ( ptr->branch[ ss[i]-'a' ]!=NULL )
            ptr = ptr->branch[ ss[i]-'a' ];
        else
            return -1;
    }
    
    return ptr->index;
}// Trie_Find

void ReadData()
{
    char s1[maxn], s2[maxn];
    
    scanf("%s", &s1);   // Words " START "
    while ( EOF!=scanf("%s", s1), strcmp(s1, "END")!=0 )
    {
        scanf("%s", &s2);
        strcpy( dict[M].front, s1 );
        strcpy( dict[M].back, s2 );
        
        t.Trie_Insert( M++, s2 );   // Note " M++ "
    }// dictionary
}// ReadData

void Solve()
{
    int  slen, tlen, kk;
    char words[maxn], line[3004];
    
    scanf("%s", line);  // Words " START "
    getchar();
    while ( gets( line ), strcmp( line, "END" )!=0 )
    {
        tlen = 0;
        slen = strlen( line );
        memset( words, 0, sizeof(words) );
        
        for ( int i=0; i<slen; ++i )
        {
            if ( isalpha( line[i] ) )
            {
                words[ tlen++ ] = line[i];
            }
            else
            {
                kk = t.Trie_Find( words );
                if ( kk==-1 )
                    printf("%s", words);
                else
                    printf("%s", dict[kk].front);
                printf("%c", line[i]);
                
                tlen = 0;
                memset( words, 0, sizeof(words) );
            }
        }// scanning
        
        printf("\n");
    }// books
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1075.in", "r", stdin);
    freopen("E:\\hdoj_1075.out", "w", stdout);
#endif

    ReadData();
    Solve();
    
    return 0;
}

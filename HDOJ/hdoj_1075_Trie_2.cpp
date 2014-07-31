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

struct Dictionary
{
    string front, back;
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
        void Trie_Insert( int k, string ss );
        int Trie_Find( string ss );
        
    private:
        Trie_Node *root;
}t;

/* Valiable */
int M=0;

Trie::Trie()
{
    root = new Trie_Node();
}// Trie

void Trie::Trie_Insert( int k, string ss )
{
    Trie_Node *ptr = root;
    int slen = ss.length();
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

int Trie::Trie_Find( string ss )
{
    Trie_Node *ptr = root;
    int slen = ss.length();
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
    string s1, s2;
    
    cin >> s1;   // Words " START "
    while ( cin >> s1 && s1!="END" )
    {
        cin >> s2;
        dict[M].front = s1;
        dict[M].back = s2;
        
        t.Trie_Insert( M++, s2 );   // Note " M++ "
    }// dictionary
}// ReadData

void Solve()
{
    int  slen, kk;
    string words, line;
    
    cin >> line;  // Words " START "
    getchar();
    while ( getline( cin, line ) && line!="END" )
    {
        words = "";
        slen = line.length();
        for ( int i=0; i<slen; ++i )
        {
            if ( isalpha( line[i] ) )
            {
                words += line[i];
            }
            else
            {
                kk = t.Trie_Find( words );
                if ( kk==-1 )
                    cout << words;
                else
                    cout << dict[kk].front;
                cout << line[i];
                
                words = "";
            }
        }// scanning
        
        cout << endl;
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

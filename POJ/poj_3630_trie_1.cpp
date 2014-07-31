/*
PROG:   Phone List
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

struct Trie_Node
{
    bool IsEnd;
    Trie_Node *branch[10];
}node[60024];

class Trie
{
    private:
        Trie_Node root;

    public:
        Trie() { root = node[0]; }
        bool Trie_Insert( char ss[] );
};

char phone[12];
int  T, N, nodeNums;
//-----------------------------------------------------------

bool Trie::Trie_Insert( char ss[] )
{
    Trie_Node *ptr = &root;
    int slen = strlen( ss );
    for ( int i=0; i<slen; ++i )
    {
        if ( i==slen-1 && ptr->branch[ ss[i]-'0' ]!=NULL )
        {
            return true;
        }
        if ( ptr->branch[ ss[i]-'0' ]==NULL )
        {
            ptr->branch[ ss[i]-'0' ] = &node[ nodeNums ];
            node[ nodeNums ].IsEnd = false;
            memset( node[ nodeNums ].branch, 0, sizeof( node[ nodeNums ].branch ) );
            ++nodeNums;
        }// creat a trie node
        if ( ptr->branch[ ss[i]-'0' ]->IsEnd )
        {
            return true;
        }
           
        ptr = ptr->branch[ ss[i]-'0' ];
    }// scanning the bunch
            
    ptr->IsEnd = true;
    return false;
}// Trie_Insert

void Solve()
{
    scanf("%d", &T);
    getchar();
    while ( T-- )
    {
        Trie t;     // Trie Tree
        bool IsPrefix = false;
        
        nodeNums = 1;   // node Numbers
        scanf("%d", &N);
        for ( int i=0; i<N; ++i )
        {
            scanf("%s", &phone);
            if ( t.Trie_Insert( phone ) )
                IsPrefix = true;
        }
        if ( IsPrefix )
            printf("NO\n");
        else
            printf("YES\n");
        //delete t;
    }// case
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\poj_3630.txt", "r", stdin);
    freopen("E:\\poj_3630_ans.txt", "w", stdout);
#endif

    Solve();

    return 0;
}

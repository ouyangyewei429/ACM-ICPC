/*
PROG:   Phone List
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 11;

bool IsPrefix;
char phone[maxn];
int  T, N, nodeNums;

struct Trie_Node
{
    bool IsEnd;
    Trie_Node *branch[maxn];
}node[60020];

class Trie
{
    private:
        Trie_Node root;
    
    public:
        bool Trie_Insert( char ss[] )
        {
            Trie_Node *ptr = &root;
            int slen = strlen( ss );
            for ( int i=0; i<slen; ++i )
            {
                if ( i==slen-1 && ptr->branch[ ss[i]-'0' ]!=NULL )
                {
                    return false;
                }// the shorter bunch index from the longer bunch
                if ( ptr->branch[ ss[i]-'0' ]==NULL )
                {
                    ptr->branch[ ss[i]-'0' ] = &node[ nodeNums ];
                    node[ nodeNums ].IsEnd = false;
                    memset( node[ nodeNums ].branch, 0, sizeof( node[ nodeNums ].branch ) );
                    ++nodeNums;
                }// creat a place
                if ( ptr->branch[ ss[i]-'0' ]->IsEnd==true )
                {
                    return false;
                }// some bunch is exist in trie
                
                ptr = ptr->branch[ ss[i]-'0' ];
            }// End of for
            
            ptr->IsEnd = true;
            return true;
        }// Trie_Insert
};

int main()
{
#if DEBUG
    freopen("E:\\phone_list.txt", "r", stdin);
    freopen("E:\\phone_list_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    getchar();
    while ( T-- )
    {
        Trie t;
        nodeNums = 1;
        IsPrefix = false;
        
        scanf("%d", &N);
        for ( int i=0; i<N; ++i )
        {
            scanf("%s", phone);
            if ( !t.Trie_Insert( phone ) )
                IsPrefix = true;
        }// trie
        if ( IsPrefix )
            printf("NO\n");
        else
            printf("YES\n");
    }// End of while
    
    return 0;
}

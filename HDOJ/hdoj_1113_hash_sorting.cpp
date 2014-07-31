/*
PROG:   Word Amalgamation
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

const int maxn = 12;

int  slen, N=0;
char words[maxn], temp[maxn];
bool IsOkey, IsNoAns, hash[104][30]={false};
struct DICTIONARY
{
    char ss[maxn];
}dict[104]={0};

int compare(const void *a, const void *b)
{
    DICTIONARY *c = (DICTIONARY *)a;
    DICTIONARY *d = (DICTIONARY *)b;
    
    return ( strcmp( c->ss, d->ss ) );
}// compare

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1113.txt", "r", stdin);
    freopen("E:\\hdoj_1113_ans.txt", "w", stdout);
#endif

    while ( EOF!=scanf("%s", temp) )
    {
        if ( !strcmp(temp, "XXXXXX") )
            break;

        strcpy( dict[N++].ss, temp );
    }// dictionary
    
    qsort( dict, N, sizeof(dict[0]), compare );
    for (int i=0; i<N; ++i)
    {
        slen = strlen( dict[i].ss );
        for (int j=0; j<slen; ++j)
            hash[i][dict[i].ss[j]-'a'] = true;;
    }// hashing
    /*
    for (int i=0; i<N; ++i)
        printf("%s\n", dict[i].ss);
    */

    while ( EOF!=scanf("%s", words) )
    {
        if ( !strcmp(words, "XXXXXX") )
            break;
            
        //-----------------------------------------
        //printf("%s\n", words);
        
        IsNoAns = true;
        for (int i=0; i<N; ++i)
        {
            slen = strlen( words );
            if ( slen!=strlen( dict[i].ss ) )
                continue;
            
            IsOkey = true;
            for (int j=0; j<slen; ++j)
            {
                if ( !hash[i][words[j]-'a'] )
                {
                    IsOkey = false;
                    break;
                }
            }// checking
            if ( IsOkey )
            {
                IsNoAns = false;
                printf("%s\n", dict[i].ss);
            }// some words exit in dictionary
        }
        if ( IsNoAns )
            printf("NOT A VALID WORD\n");

        printf("******\n");
    }// words

    return 0;
}

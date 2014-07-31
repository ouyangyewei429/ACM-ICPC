/*
PORG:   Play on Words
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0

const int maxn = 100004;

char words[1004];
bool Euler, hash[26];
int  T, N, stnum, etnum, od[26], id[26], parent[26];
struct EDGE
{
    int u, v;
}edge[maxn];

int FindSet(int k)
{
    while ( k!=parent[k] )
        k = parent[k];
    
    return k;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1==r2 )
        return ;
    
    if ( r1<r2 )
        parent[r2] = r1;
    else
        parent[r1] = r2;
}// Merge

bool Connect()
{
    for (int i=0; i<26; ++i)
        parent[i] = i;
    
    for (int i=0; i<N; ++i)
        Merge( edge[i].u, edge[i].v );
    
    int setNums=1, prev=-1;
    for (int i=0; i<26; ++i)
    {
        if ( !hash[i] ) continue;
        if ( prev==-1 ) prev = i;
        else if ( FindSet(i)!=FindSet(prev) )
            ++setNums;
    }// counting the set's number
    
    return ( setNums==1 ? true:false );
}// Connect

int main()
{
#if DEBUG
    freopen("E:\\zoj_2016.txt", "r", stdin);
    freopen("E:\\zoj_2016_ans.txt", "w", stdout);
#endif
    
    int tempu, tempv;
    
    scanf("%d", &T);
    while ( T-- )
    {
        memset(id, 0, sizeof(id));
        memset(od, 0, sizeof(od));
        memset(hash, false, sizeof(hash));

        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            scanf("%s", words);
            tempu=words[0]-'a', tempv=words[strlen(words)-1]-'a';
            
            od[tempu]++, id[tempv]++;
            hash[tempu] = hash[tempv] = true;
            edge[i].u = tempu, edge[i].v = tempv;
        }// creat the graph
        
        Euler = true;
        stnum = etnum = 0;
        for (int i=0; i<26; ++i)
        {
            if ( !hash[i] ) continue;
            if ( od[i]-id[i]>=2 || id[i]-od[i]>=2 )
            {
                Euler = false;
                break;
            }
            if ( od[i]==0 && id[i]==0 )
            {
                Euler = false;
                break;
            }
            if ( od[i]-id[i]==1 )
            {
                ++stnum;
                if ( stnum>1 )  {Euler=false; break;}
            }
            if ( id[i]-od[i]==1 )
            {
                ++etnum;
                if ( etnum>1 )  {Euler=false; break;}
            }
        }// judging by in-degree and out-degree
        
        if ( stnum!=etnum ) Euler = false;
        else if ( !Connect() )   Euler = false;
    
        if ( Euler )
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }// End of while
    
    return 0;
}

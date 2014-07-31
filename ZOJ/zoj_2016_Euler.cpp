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
        parent[r2]=r1;
    else
        parent[r1]=r2;
    
    return ;
}// Merge

bool Connect()
{
    int i, prev=-1, setNums=1;
    for (i=0; i<26; ++i)
        parent[i] = i;
    
    for (i=0; i<N; ++i)
    {
        if ( edge[i].u!=edge[i].v && FindSet(edge[i].u)!=FindSet(edge[i].v) )
            Merge(edge[i].u, edge[i].v);
    }
        
    for (i=0; i<26; ++i)
    {
        if ( !hash[i] ) continue;
        if ( prev==-1 ) prev = i;
        else if ( parent[i]!=parent[prev] )
            break;
    }// counting set's number
    
    //return true;
    if ( i<26 ) return false;
    else    return true;
    //return ( setNums==1 ? true:false );
}// Connect

int main()
{
#if DEBUG
    freopen("E:\\zoj_2016.txt", "r", stdin);
    freopen("E:\\zoj_2016_ans.txt", "w", stdout);
#endif

    int tu,tv;
    
    scanf("%d", &T);
    while ( T-- )
    {
        memset(od, 0, sizeof(od));
        memset(id, 0, sizeof(id));
        memset(hash, false, sizeof(hash));

        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            scanf("%s", words);
            tu=words[0]-'a', tv=words[strlen(words)-1]-'a';
            
            od[tu]++, id[tv]++;
            hash[tu] = hash[tv] = true;
            edge[i].u=tu, edge[i].v=tv;
        }// creat a graph
        
        Euler = true;
        stnum = etnum = 0;
        for (int i=0; i<26; ++i)
        {
            if ( hash[i]==false )   continue;
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
        }// judge by in-degree and out-degree
   
        if ( stnum!=etnum ) Euler=false;
        if ( !Connect() )   Euler=false;
        
        if ( Euler )
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");

    }// End of while
    
    return 0;
}

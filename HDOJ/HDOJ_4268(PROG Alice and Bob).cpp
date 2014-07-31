/*
PROG:   Alice and Bob
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef multiset<int> MSI;
typedef multiset<int>::iterator MSIT;

int main() 
{
    MSI mySet;
    MSIT iter;
    VPII va, vb;
    int i, j, testCases, nNums, h, w;
    
    scanf("%d", &testCases);
    while ( testCases-- ) {
        va.clear();
        vb.clear();
        mySet.clear();
        
        scanf("%d", &nNums);
        for (i = 0; i < nNums; ++i) {  // Alice
            scanf("%d %d", &h, &w);
            va.push_back( make_pair(h, w) );
        }// End of for
        for (i = 0; i < nNums; ++i) {  // Bob
            scanf("%d %d", &h, &w);
            vb.push_back( make_pair(h, w) );
        }// End of for
        
        sort( va.begin(), va.end() );
        sort( vb.begin(), vb.end() );
        
        int ans = 0;
        int vaSize = va.size();
        int vbSize = vb.size();
        for (i = j = 0; i < vaSize; ++i) {
            while ( (j < vbSize) && (vb[j].first <= va[i].first) ) {
                mySet.insert( vb[j].second );
                ++j;
            }
            
            iter = mySet.upper_bound( va[i].second );
            if ( iter != mySet.begin() && !mySet.empty() ) {
                --iter;
                mySet.erase( iter );
                ++ans;
            }
        }// End of for
        
        printf("%d\n", ans);
    }// End of while
    
    return 0;
}

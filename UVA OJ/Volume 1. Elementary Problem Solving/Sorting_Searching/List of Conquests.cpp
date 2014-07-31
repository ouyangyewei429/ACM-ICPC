/*
PROG:   List of Conquests
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

typedef pair<string, string> PII;
typedef set<PII> SPII;
typedef set<PII>::iterator SPIIT;
typedef map<string, int> MSI;
typedef map<string, int>::iterator MSIT;

void func( int &nNums, MSI &mp, SPII &mySet ) {
    char ch;
    SPIIT setIter;
    string ctry, names;
    
    for (int i = 0; i < nNums; ++i) {
        names = "";
        cin >> ctry;
        while ( (ch = getchar()) != EOF ) {
            if ( ch == '\n' ) {
                break;
            } else if ( ch != ' ' ) {
                names += ch;
            }
        }// End of whlie
        
        if ( mySet.empty()
            || mySet.find( make_pair(ctry, names) ) == mySet.end() ) {
            ++mp[ ctry ];
            mySet.insert( make_pair(ctry, names) );
        }
        //cout << country << " " << names << endl;
    }// End of for
}

int main() {
#if DEBUG
    freopen("E:\\10420.in", "r", stdin);
    freopen("E:\\10420.out", "w", stdout);
#endif

    int nNums;
    MSI mp;
    MSIT iter;
    SPII mySet;
    
    while (cin >> nNums) {
        mp.clear();
        mySet.clear();
        func( nNums, mp, mySet );
        for (iter = mp.begin(); iter != mp.end(); ++iter) {
            cout << iter -> first << " " << iter -> second << endl;
        }
    }// End of while
    
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10588478 	10420 	List of Conquests 	Accepted 	C++ 	0.020 	2012-09-11 02:16:39
*/

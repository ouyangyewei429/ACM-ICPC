/*
PROG:   141 - The Spot Game
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 1
#define DEBUG_1 1

typedef map<string, bool> MSB;

const int MAXN = 52;

void hashGraph(MSB &vis, string &graph, int &nSize) {
    int i, j;
    string s;
    
    for (j = 0; j < nSize; ++j) { // rotate 90 degree
        for (i = nSize - 1; i >= 0; --i) {
            s += graph[ j * nSize + i ];
        }
    }
    vis[s] = true;
    //vis.insert( make_pair(s, true) );
    
    #if DEBUG_1
    cout << "Here are s : " << endl;
    cout << s << " " << vis[s] << endl;
    #endif
    
    s = "";
    for (j = nSize - 1; j >= 0; --j) { // rotate 270 degree
        for (i = 0; i < nSize; ++i) {
            s += graph[ j * nSize + i ];
        }
    }
    vis[s] = true;
    //vis.insert( make_pair(s, true) );
    
    #if DEBUG_1
    cout << s << " " << vis[s] << endl;
    #endif
    
    s = "";
    for (i = 0; i < nSize; ++i) {
        for (j = nSize - 1; j >= 0; --j) {
            s += graph[ i * nSize + j ];
        }
    }
    vis[s] = true;
    //vis.insert( make_pair(s, true) );
    
    #if DEBUG_1
    cout << s << " " << vis[s] << endl;
    cout << "-------------------------" << endl;
    #endif
}

int main() {
#if DEBUG
    freopen("E:\\141.in", "r" ,stdin);
    freopen("E:\\141.out", "w", stdout);
#endif

    MSB vis;
    char cmd;
    int nSize, px, py, rounds;
    
    while (~scanf("%d", &nSize) && nSize) {
        vis.clear();
        string graph;
        bool p1 = false, p2 = false;
        
        for (int i = 0; i < nSize * 2; ++i) {  // origin graph
            graph += '0';
        }
        for (int i = 1; i <= nSize * 2; ++i) {
            scanf("%d %d %c", &px, &py, &cmd);
            if ( cmd == '+' ) {
                graph[ (px - 1) * nSize + (py - 1) ] = '1';
            } else if ( cmd == '-' ) {
                graph[ (px - 1) * nSize + (py - 1) ] = '0';
            }
            
            #if DEBUG_1
            cout << graph << endl;
            #endif
            
            if ( !vis[graph] ) {
                #if DEBUG_1
                cout << "In : " << graph << " " << vis[graph] << endl;
                #endif
            
                vis[graph] = true;
                hashGraph( vis, graph, nSize );
            } else if (!p1 && !p2) {
                if (i & 1) {
                    p2 = true;
                    rounds = i - 1;
                } else {
                    p1 = true;
                    rounds = i - 1;
                }
            }
        } /*
        if (p1 == p2) {
            printf("Draw\n");
        } else {
            if (p1) {
                printf("Player %d wins on move %d\n", 1, rounds);
            } else {
                printf("Player %d wins on move %d\n", 2, rounds);
            } 
        } */
    }// End of while

    return 0;
}


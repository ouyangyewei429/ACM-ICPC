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

//#define DEBUG 0
//#define DEBUG_1 0

typedef map<string, bool> MSB;

//const int MAXN = 4049;

MSB vis;
char cmd;
string graph, s1, s2, s3;
int nSize, px, py, rounds, i, j, k, row, col;

int main() {
#if DEBUG
    freopen("E:\\141.in", "r" ,stdin);
    freopen("E:\\141.out", "w", stdout);
#endif
    
    while (~scanf("%d", &nSize) && nSize) {
        vis.clear();
        bool p1 = false, p2 = false;
        
        for (k = 0, graph = ""; k < nSize * 2; ++k) {
            graph += '0';
        }
        for (k = 1; k <= nSize * 2; ++k) {
            scanf("%d %d %c", &px, &py, &cmd);
            if ( cmd == '+' ) {
                graph[ (px - 1) * nSize + (py - 1) ] = '1';
            } else if ( cmd == '-' ) {
                graph[ (px - 1) * nSize + (py - 1) ] = '0';
            }
            
            if ( !vis[graph] ) {
                vis[graph] = true;
                for (j = 0, s1 = ""; j < nSize; ++j) {  // rotate 90 degree
                    for (i = nSize - 1; i >= 0; --i)
                        s1 += graph[ j * nSize + i ];
                }
                for (j = nSize - 1, s2 = ""; j >= 0; --j) {
                    for (i = 0; i < nSize; ++i)
                        s2 += graph[ j * nSize + i ];
                }
                for (i = 0, s3 = ""; i < nSize; ++i) {
                    for (j = nSize - 1; j >= 0; --j)
                        s3 += graph[ i * nSize + j ];
                }
                vis[s1] = true, vis[s2] = true, vis[s3] = true;
                
            } else if (!p1 && !p2) {
                if ( k & 1 )
                    p2 = true;
                else
                    p1 = true;
                rounds = k;    
            }
        }// End of for
        if ( !p1 && !p2 ) {
            printf("Draw\n");
        } else {
            if (p1) {
                printf("Player %d wins on move %d\n", 1, rounds);
            } else {
                printf("Player %d wins on move %d\n", 2, rounds);
            } 
        }
    }// End of while

    return 0;
}


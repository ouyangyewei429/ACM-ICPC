/*
PROG:   The Dole Queue
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 25;

void ballInit( int &N, int  ball[] ) {
    //memset( ball, 0, sizeof(ball) );
    for (int i = 1; i < N; ++i) {
        ball[i] = i;
    }
    ball[0] = N;
}

int countClockwise( int ball[], int &N, int &K, int &fidx ) {
    int cnt = 0;
    while ( cnt < K ) {
        if ( ball[fidx] ) ++cnt;
		if ( cnt < K ) fidx = ( fidx + 1 ) % N;
    }
    return ball[fidx];
}

int countAnticlockwise( int ball[], int &N, int &M, int &sidx ) {
    int cnt = 0;
    while ( cnt < M ) {
        if ( ball[sidx] ) ++cnt;
		if ( cnt < M ) sidx = ( sidx >= 1 ) ? ( sidx - 1 ) : ( N - 1 );
    }
    return ball[sidx];
}

int main() {
    int N, K, M, ballNums;
    int ball[MAXN], fi, si, fidx, sidx;
    
    while ( ~scanf("%d %d %d", &N, &K, &M) && N + K +M != 0 ) {
        memset( ball, 0, sizeof(ball) );
		ballInit( N, ball );
        
        ballNums = N;
        fidx = 1, sidx = 0;
        while ( ballNums ) {
            fi = countClockwise( ball, N, K, fidx );
            si = countAnticlockwise( ball, N, M, sidx );
            if ( fi == si ) {
                --ballNums;
				if ( ballNums > 0 ) {
					printf("%3d,", fi);
				} else {
					printf("%3d\n", fi);
				}
            } else {
                ballNums -= 2;
                if ( ballNums > 0 ) {
                    printf("%3d%3d,", fi, si);
                } else {
                    printf("%3d%3d\n", fi, si);
                }
            }
            
            ball[fidx] = ball[sidx] = 0;
        }
    }// End of while
    
    return 0;
}

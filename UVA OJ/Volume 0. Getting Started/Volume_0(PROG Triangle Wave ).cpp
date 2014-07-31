/*
PROG:   Triangle Wave 
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

#define DEBUG 0

namespace {

bool waveform, delimiter;
int test_case, amplitude, frequency;

}// wave

int main() {
#if DEBUG
    freopen("E:\\488.in", "r", stdin);
    freopen("E:\\488.out", "w", stdout);
#endif

    scanf("%d", &test_case);
    while (test_case--) {
        if (delimiter) {
            printf("\n");
        }
        
        waveform = false;
        scanf("%d %d", &amplitude, &frequency);
        for (int i = 1; i <= frequency; ++i) { // wave's number
            if (waveform) {
                printf("\n");
            }
            
            for (int j = 1; j <= amplitude; ++j) {  // upper triangular
                for (int k = 1; k <= j; ++k) {
                    printf("%d", j);
                }
                printf("\n");
            }
            for (int j = amplitude - 1; j >= 1; --j) {  // lower triangular
                for (int k = 1; k <= j; ++k) {
                    printf("%d", j);
                }
                printf("\n");
            }
            
            waveform = true;
        }
        
        delimiter = true;
    }// End of while
    
    //system("pause");
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10536193 	488 	Triangle Wave 	Accepted 	C++ 	0.416 	2012-08-29 01:47:09
*/

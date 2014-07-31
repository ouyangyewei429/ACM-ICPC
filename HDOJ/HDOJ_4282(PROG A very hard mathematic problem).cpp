/*
PROG:   A very hard mathematic problem
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    long k;
    
    while (~scanf("%ld", &k), k) {
        int ans = 0;
        
        for (int z = 2; z <= 30; ++z) {
            double limit = (int)pow(1.0 * k, 1.0 / z) + 1;
            
            for (int x = 1; x <= (int)limit; ++x) {
                int left = x + 1;
                int right = (int)limit;
                
                while (left <= right) {
                    int y = (left + right) >> 1;
                    double fx = pow((double)x, z)
                                + pow((double)y, z) + x * y * z;
                        
                    if (fx == k) {
                        ++ans;
                        break;
                    } else if (fx > k) {
                        right = y - 1;
                    } else {
                        left = y + 1;
                    }
                }// binary search
            }
        }
        printf("%d\n", ans);
    }// End of while

    return 0;
}

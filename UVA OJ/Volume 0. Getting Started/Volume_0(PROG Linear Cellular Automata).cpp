/*
PROG:   Linear Cellular Automata
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

// Input The DNA program
void Input(int DNA[]) {
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &DNA[i]);
    }
}

// Output the density
void Output(int density[]) {
    for (int i = 1; i <= 40; ++i) {
        if (density[i] == 0) {
            printf(" ");
        } else if (density[i] == 1) {
            printf(".");
        } else if (density[i] == 2) {
            printf("x");
        } else if (density[i] == 3) {
            printf("W");
        }
    }
    printf("\n");
}

// The changes of density for the next day
void ChangeOfDensity(int DNA[], int density[]) {
    int sum[42] = {0};
    
    // calculate sum of the density of current dish
    // and it's  neighbor with population density
    for (int i = 1; i <= 40; ++i) {
        sum[i] = density[i - 1] + density[i] + density[i + 1];
    }
    // the density of dish changes with DNA[k]
    for (int j = 1; j <= 40; ++j) {
        density[j] = DNA[sum[j]];
    }
}

// Simulate the changes of culture dish's density
void Simula(int DNA[]) {
    int density[42] = {0};
    
    density[20] = 1;
    for (int i = 1; i <= 50; ++i) {
        Output(density);
        ChangeOfDensity(DNA, density);
    }
}

int main() {
#if DEBUG
    freopen("E:\\457.in", "r", stdin);
    freopen("E:\\457_1.out", "w", stdout);
#endif

    int testCases, DNA[12];

    scanf("%d", &testCases);
    while (testCases--) {
        Input(DNA);
        Simula(DNA);
        
        if (testCases > 0) {
            printf("\n");
        }
    }// End of while
    
    return 0;
}

#include <cstdio>
#include <cstdlib>

const int MAXN = 10005;

int nCases, milk[MAXN];

int compare(const void *c, const void *d) {
    return (*(int *)c - *(int *)d);
}

int main() {
    while (~scanf("%d", &nCases)) {
        for (int i = 0; i < nCases; ++i)
            scanf("%d", &milk[i]);
        
        qsort(milk, nCases, sizeof(milk[0]), compare);
        /* // debug 
        for (int i = 0; i < nCases; ++i)
            printf("%d\n", milk[i]);
        */
        printf("%d\n", milk[nCases >> 1]);
    }// End of while
    return 0;
}

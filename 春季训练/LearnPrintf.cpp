/**
 * Test Printf
 */
#include <cstdio>

int main(void)
{
    printf("%5.3s\n", "computer");
    printf("%5.1lf\n", 12.123456);
    printf("%5.1lf\n", 123.123456);
    printf("%#o\n", 64);
    printf("%#x\n", 64);
    printf("%#lf\n", 3.14);

    return 0;
}

#include <stdio.h>

long pthFactor(long n, long p);

int main() {
    printf("n=10, p=3 → %ld (expected 5)\n", pthFactor(10, 3));
    printf("n=10, p=1 → %ld (expected 1)\n", pthFactor(10, 1));
    printf("n=10, p=4 → %ld (expected 10)\n", pthFactor(10, 4));
    printf("n=10, p=5 → %ld (expected 0)\n", pthFactor(10, 5));

    printf("n=36, p=5 → %ld (expected 6)\n", pthFactor(36, 5));
    printf("n=1, p=1 → %ld (expected 1)\n", pthFactor(1, 1));
    printf("n=1, p=2 → %ld (expected 0)\n", pthFactor(1, 2));

    return 0;
}
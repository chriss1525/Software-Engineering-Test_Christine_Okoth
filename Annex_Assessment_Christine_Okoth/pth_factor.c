long pthFactor(long n, long p) {
    long count = 0;
    long i;

    for (i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            count++;

            if (count == p) {
                return i;
            }
        }
    }

    i--;

    for (; i >= 1; i--) {
        if (n % i == 0) {
            if (i == n / i) {
                continue;
            }

            count++;

            if (count == p) {
                return n / i;
            }
        }
    }

    return 0;
}
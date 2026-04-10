#include<stdio.h>
#include<time.h>

long long fibonacci(long long n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (long long n = 1; n <= 50; n++) {
        clock_t start = clock();
        long long fn = fibonacci(n);
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("F(%lld) = %lld, 시간: %.6f초\n", n, fn, elapsed);
    }
    return 0;
}

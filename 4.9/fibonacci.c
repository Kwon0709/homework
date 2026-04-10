#include<stdio.h>
#include<time.h>

long long fibo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    long long result, temp1 = 1, temp2 = 0;
    for (int i = 2; i <= n; i++) {
        result = temp1 + temp2;
        temp2 = temp1;
        temp1 = result;
    }
    return result;
}

int main() {
    for (int n = 1; n <= 50; n++) {
        clock_t start = clock();
        long long fn = fibo(n);
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("F(%d) = %lld, 시간: %.6f초\n", n, fn, elapsed);
    }
    return 0;
}

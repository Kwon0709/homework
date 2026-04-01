#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"my_fibonacci.h"

int main() {
    printf("n\tF(n)\t\tGCD(F(n),F(n-1))\tTime(ms)\n");
    printf("----------------------------------------------------------\n");

    for (my_fibonacci n = 5; n <= 45; n++) {

        clock_t start = clock();
        my_fibonacci fn = fibonacci(n);
        my_fibonacci fn_1 = fibonacci(n - 1);
        my_fibonacci result = find_Gcd(fn, fn_1);
        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        printf("%llu\t%llu\t%llu\t\t%.3f ms\n", n, fn, result, elapsed);
    }

    return 0;
}

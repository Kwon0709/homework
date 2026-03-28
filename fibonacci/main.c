#include<stdio.h>
#include<stdlib.h>

#include"my_fibonacci.h"

int main() {
    printf("n\tF(n)\t\tGCD(F(n),F(n-1))\n");
    printf("-------------------------------------------\n");

    for (my_fibonacci n = 5; n <= 90 ; n++) {

        my_fibonacci fn = fibonacci(n);
        my_fibonacci fn_1 = fibonacci(n - 1);
        my_fibonacci result = find_Gcd(fn, fn_1);

        printf("%llu\t%llu\t%llu\n", n, fn, result);
    }   

    return 0;
}

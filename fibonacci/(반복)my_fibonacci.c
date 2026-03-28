#include<stdio.h>
#include<stdlib.h>

#include"my_fibonacci.h"

my_fibonacci find_Gcd(my_fibonacci a, my_fibonacci b) {
	while (b != 0) {
		my_fibonacci tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

    my_fibonacci fibonacci(my_fibonacci n) {
        if (n <= 1) return n;

        my_fibonacci prev = 0, curr = 1;
        for (my_fibonacci i = 2; i <= n; i++) {
            my_fibonacci next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }

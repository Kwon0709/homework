typedef unsigned long long my_fibonacci; //피보나치수열 f(n)이 f(47)이상으로 가면 int형에서는 오버플로 발생, 따라서 long long형 사용하여 계산 범위를 더 크게 늘려줌

extern my_fibonacci find_Gcd(my_fibonacci i, my_fibonacci j);
extern my_fibonacci fibonacci(my_fibonacci n);

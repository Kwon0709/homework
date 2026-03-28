# 피보나치 수열 GCD 프로파일링 보고서

## 1. 개요

피보나치 수열의 n번째 값 F(n)에 대해 GCD(F(n), F(n-1))을 계산하면서
CPU 사용량과 메모리 사용량을 프로파일링하고, 이전 과제에서 분석한 GCD 알고리즘의 시간복잡도를 실제로 검증하는 것을 목표로 한다.

---

## 2. 코드



### 2.1 재귀 피보나치

```c
my_fibonacci fibonacci(my_fibonacci n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### 2.2 반복문 피보나치

```c
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
```

### 2.3 GCD 및 main

```c
my_fibonacci find_Gcd(my_fibonacci a, my_fibonacci b) {
    while (b != 0) {
        my_fibonacci tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    printf("n\tF(n)\t\tGCD(F(n),F(n-1))\n");
    printf("-------------------------------------------\n");
    for (my_fibonacci n = 5; n <= 90; n++) {
        my_fibonacci fn = fibonacci(n);
        my_fibonacci fn_1 = fibonacci(n - 1);
        my_fibonacci result = find_Gcd(fn, fn_1);
        printf("%llu\t%llu\t%llu\n", n, fn, result);
    }
    return 0;
}
```

---

## 3. 실행 결과

### 3.1 GCD 결과

n=5부터 n=90까지 계산한 결과, 모든 경우에서 GCD 값은 **1**로 나타났다.
이는 인접한 피보나치 수가 항상 서로소라는 성질과 일치한다.

| n   | F(n)                | GCD(F(n), F(n-1)) |
| --- | ------------------- | ----------------- |
| 5   | 5                   | 1                 |
| 6   | 8                   | 1                 |
| 7   | 13                  | 1                 |
| 8   | 21                  | 1                 |
| ... | ...                 | ...               |
| 90  | 2880067194370816120 | 1                 |

---

### 3.2 재귀 vs 반복문 성능 비교

| 구분         | 재귀 피보나치 | 반복문 피보나치 |
| ---------- | ------- | -------- |
| 시간복잡도      | O(2^n)  | O(n)     |
| n=46 도달 시간 | 295분 이상 | 1초 미만    |
| n=90 완료 여부 | 불가      | 3.804초   |

재귀 방식은 호출 횟수가 지수적으로 증가하여 n이 커질수록 실행 시간이 급격히 증가한다.
반면 반복문 방식은 선형 시간에 계산이 가능하여 매우 빠르게 결과를 얻을 수 있다.

---

## 4. 프로파일링 결과

### 4.1 재귀 피보나치
<img width="2877" height="1625" alt="image" src="https://github.com/user-attachments/assets/8a19520a-9a7c-4aaf-90b7-aa82bbec488a" />

* 메모리는 약 788KB로 거의 일정하게 유지됨
* CPU 사용량은 일정부분에서 지속됨
* n이 증가할수록 실행 시간이 급격히 증가

이는 재귀 피보나치의 시간복잡도인 **O(2^n)** 때문으로, 호출 횟수가 폭발적으로 증가하기 때문이다.

---

### 4.2 반복문 피보나치
<img width="1799" height="1026" alt="image" src="https://github.com/user-attachments/assets/e012690b-536b-43a8-ac39-ce21da2f8eee" />

* 메모리는 거의 변화 없음
* 실행 시간이 매우 짧아 프로파일링 그래프에서 뚜렷한 변화가 나타나지 않음

이는 반복문 피보나치(O(n))와 GCD(O(log n)) 모두 효율적인 알고리즘이기 때문에
전체 실행 시간이 매우 작게 유지되기 때문이다.

---

## 5. GCD 시간복잡도 검증

이전 과제에서 유클리드 호제법 기반 GCD 알고리즘의 시간복잡도를 **O(log n)**으로 분석하였다.

유클리드 호제법은 입력값이 클수록 반복 횟수가 증가하며,
특히 피보나치 수열의 인접한 두 수는 GCD 알고리즘에서 **최악의 경우**를 발생시키는 입력이다.

최악의 경우 반복 횟수는 다음과 같이 계산할 수 있다.

b > a 인 경우:
n × (1/2)^(k-1) = 1  →  k = log₂n + 1

b < a 인 경우:
n × (1/2)^k = 1      →  k = log₂n

두 경우 모두 반복 횟수는 로그에 비례하며,
Big-O 표기법에서 상수는 무시되므로
GCD 알고리즘의 시간복잡도는 **O(log n)** 이 된다.


또한 GCD 알고리즘의 시간복잡도는 입력값 k에 대해 O(log k)인데,
본 실험에서는 k 대신 피보나치 수 F(n)을 사용하였다.

피보나치 수는 n이 증가할수록 지수적으로 증가하므로
log(F(n))은 n에 비례하는 관계를 가진다.

따라서 실험에서는 GCD의 수행 시간이
n에 비례하는 형태로 증가하는 것처럼 나타나며,
이는 이론적인 시간복잡도 O(log n)과 일치하는 결과이다.

초기에는 재귀 피보나치를 사용하였으나,
피보나치 계산 자체의 시간복잡도(O(2^n))가 너무 커서
GCD 알고리즘의 성능을 정확히 관찰하기 어려웠다.

따라서 입력 생성 비용이 낮은 반복문 피보나치(O(n))를 사용하여 실험을 진행하였으며,
이를 통해 GCD 알고리즘의 효율성을 보다 명확하게 확인할 수 있었다.

---

## 6. 결론

* GCD(F(n), F(n-1))은 항상 1로 나타나며, 이론적 성질과 일치한다.
* 재귀 피보나치는 O(2^n)으로 매우 비효율적이며 n이 증가하면 실행이 어려워진다.
* 반복문 피보나치를 사용하면 GCD 알고리즘의 성능을 정확히 관찰할 수 있다.
* 실험을 통해 GCD 알고리즘의 시간복잡도 O(log n)이 실제로도 타당함을 확인하였다.

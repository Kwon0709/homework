# 피보나치 수열 GCD 프로파일링 보고서

## 1. 개요
피보나치 수열의 n번째 숫자 F(n)에 대해 GCD(F(n), F(n-1))을 계산하며
CPU 사용량과 메모리 사용량을 프로파일링하고, 앞선 GCD 시간복잡도 분석을 검증한다.

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
n=5부터 n=90까지 GCD(F(n), F(n-1))을 계산한 결과, 모든 경우에서 **GCD = 1** 이 나왔다.
이는 인접한 피보나치 수는 항상 서로소라는 수학적 성질과 일치한다.

| n | F(n) | GCD(F(n), F(n-1)) |
|---|------|-------------------|
| 5 | 5 | 1 |
| 6 | 8 | 1 |
| 7 | 13 | 1 |
| 8 | 21 | 1 |
| ... | ... | ... |
| 90 | 2880067194370816120 | 1 |

### 3.2 재귀 vs 반복문 성능 비교

| 구분 | 재귀 피보나치 | 반복문 피보나치 |
|------|-------------|----------------|
| 시간복잡도 | O(2^n) | O(n) |
| n=46 도달 시간 | 103분 이상 | 1초 미만 |
| n=90 완료 여부 | 불가 | 3.804초 |

---

## 4. 프로파일링 결과

### 4.1 재귀 피보나치 프로파일링


- **메모리**: 788KB로 일정하게 유지
- **CPU**: 지속적으로 높은 사용량 유지
- n=46 이후 실질적으로 종료 불가 수준으로 느려짐

### 4.2 반복문 피보나치 프로파일링


- **메모리**: 거의 변화 없음
- **CPU**: 3.804초 만에 종료되어 그래프가 거의 나타나지 않음
- n=90까지 빠르게 완료

---

## 5. GCD 시간복잡도 검증

앞선 1) 과제에서 GCD 알고리즘의 시간복잡도를 **O(log n)** 으로 분석하였다.

재귀 피보나치로 검증을 시도하였으나, 피보나치 자체의 시간복잡도가 **O(2^n)** 으로
n이 커질수록 피보나치 계산이 병목이 되어 GCD의 O(log n) 검증이 어려웠다.

따라서 반복문 피보나치 **O(n)** 으로 변경하여 검증을 진행하였으며,
n=5부터 n=90까지 모든 GCD 연산이 빠르게 완료되어 **O(log n)** 의 효율성이 확인되었다.

---

## 6. 결론

- GCD(F(n), F(n-1))은 항상 **1** 로, 인접한 피보나치 수는 서로소임이 확인되었다.
- 재귀 피보나치는 O(2^n) 으로 n이 커지면 사실상 실행 불가능하다.
- 반복문 피보나치와 함께 실행한 결과, GCD 알고리즘의 **O(log n)** 시간복잡도가 검증되었다.

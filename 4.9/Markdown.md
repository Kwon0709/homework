# 피보나치 수열 성능 분석 보고서

## 1. 개요

이번 과제에서는 피보나치 수열을 **반복(순환) 방법**과 **재귀 방법** 두 가지로 구현하고, N=1부터 N=50까지 각각의 수행시간을 측정하여 두 방법의 성능을 비교 분석하였다.

피보나치 수열의 정의는 다음과 같다.

> F(1) = 1, F(2) = 1, F(n) = F(n-1) + F(n-2) (n ≥ 3)

---

## 2. 구현 코드

### 2-1. 반복(순환) 방법

```c
#include <stdio.h>
#include <time.h>

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
```
반복 방법은 이전 두 값을 저장한 뒤 반복문을 통해 순차적으로 계산하는 방식이다.
불필요한 중복 계산 없이 한 번의 순회로 결과를 도출한다.

### 2-2. 재귀 방법

```c
#include <stdio.h>
#include <time.h>

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
```

재귀 방법은 피보나치 수열의 정의를 그대로 코드로 표현한 방식으로,

문제 구조가 직관적으로 드러나는 장점이 있다. 그러나 동일한 값을 반복적으로 계산하는 특징을 가진다.

---

## 3. 알고리즘 분석

### 3-1. 반복(순환) 방법

- **시간복잡도**: O(n)
- **공간복잡도**: O(1)

for문이 n-1번 반복되므로 시간복잡도는 O(n)이다. 추가로 사용하는 변수가 result, temp1, temp2 세 개뿐이므로 공간복잡도는 O(1)로 매우 효율적이다.

### 3-2. 재귀 방법

- **시간복잡도**: O(2^n)
- **공간복잡도**: O(n)

재귀 피보나치의 수행 시간은 다음과 같은 점화식으로 표현된다.

T(n) = T(n-1) + T(n-2) + O(1)

이 점화식은 피보나치 수열과 동일한 형태를 가지며, 그 해는 다음과 같이 알려져 있다.

T(n) ≈ φⁿ (φ ≈ 1.618)

따라서 재귀 피보나치의 시간복잡도는

O(φⁿ)
상한으로 O(2ⁿ)으로 표현할 수 있다.

재귀 방법에서는 동일한 부분 문제가 반복적으로 계산된다.
예를 들어 F(5)를 계산할 때 F(3), F(2)가 여러 번 호출되며, 이러한 중복 계산으로 인해 전체 호출 횟수가 지수적으로 증가한다.

또한 재귀 호출 깊이는 최대 n이므로

공간복잡도: O(n)이다.

---

## 4. 수행시간 측정 결과

### 4-1.반복피보나치 결과
<img width="1336" height="688" alt="image" src="https://github.com/user-attachments/assets/f0aa0bae-a678-4c8b-be43-92b202af5724" />

반복 방법의 경우 N=50까지 측정한 결과 모든 구간에서 실행 시간이 0초에 가깝게 나타났다.

이는 알고리즘이 매우 빠르기 때문이기도 하지만,
clock() 함수의 측정 해상도 한계로 인해 매우 짧은 실행 시간은 0으로 측정되기 때문이다.

즉, 실제 시간복잡도는 O(n)이지만 N ≤ 50 범위에서는 측정 도구로 차이를 구분하기 어렵다.

### 4-2.재귀피보나치 결과표
<img width="1332" height="696" alt="image" src="https://github.com/user-attachments/assets/3e8de554-a59c-4b5c-ae8b-8dbf5af6068e" />

재귀 방법은 N이 증가함에 따라 수행 시간이 급격히 증가하였다.

N ≈ 20 이하: 거의 측정 불가
N ≈ 30 이후: 눈에 띄는 증가
N ≈ 40 이후: 급격한 시간 증가
N = 50: 약 80초 이상 소요

이는 이론적으로 예측된 **지수 시간복잡도 O(φⁿ)**의 특성과 일치한다.

---

## 5. 그래프

### 5-1. 반복(순환) 방법 수행시간
<img width="481" height="586" alt="image" src="https://github.com/user-attachments/assets/da498681-5a7e-4bd3-8755-07ad9817c7e3" />
<img width="1500" height="750" alt="image" src="https://github.com/user-attachments/assets/3a74f53f-1713-4e73-9e16-ecb41bea871e" />

반복 알고리즘은 이론적으로 O(n)의 시간복잡도를 가지지만, 측정 범위에서는 실행 시간이 매우 작아 그래프상에서 거의 0으로 나타난다.

### 5-2. 재귀 방법 수행시간
<img width="386" height="612" alt="image" src="https://github.com/user-attachments/assets/2dc5f679-6a32-4ee7-ab6e-19cb4f8dda66" />
<img width="1500" height="750" alt="image" src="https://github.com/user-attachments/assets/bdaf343b-725b-4d58-8141-e4ba15e53b7b" />

재귀 알고리즘의 실행 시간 그래프는 지수 함수 형태의 증가 곡선을 보인다.

특히 N이 증가할수록 증가율이 급격히 커지며, 이는 φⁿ 형태의 성장과 일치한다.

---

## 6. 비교 및 결론

| 항목 | 반복(순환) | 재귀 |
|:---:|:---:|:---:|
| 시간복잡도 | O(n) | O(2^n) |
| 공간복잡도 | O(1) | O(n) |
| N=50 수행시간 | ≈ 0초 | 82.713초 |
| 중복 계산 | 없음 | 있음 |

두 방법을 비교한 결과, 재귀 방법은 코드가 피보나치 수열의 수학적 정의와 거의 동일하여 직관적이고 이해하기 쉽다는 장점이 있다. 그러나 중복 계산 문제로 인해 시간복잡도가 O(2^n)에 달하며, N이 조금만 커져도 수행시간이 폭발적으로 증가한다는 심각한 단점이 있다.

반면 반복 방법은 이전 두 값만 저장하며 한 번의 루프로 계산을 끝내기 때문에 O(n)에 달성한다. 실제 측정에서도 N=50 기준 반복은 0초에 가까운 반면 재귀는 약 60초가 소요되어 성능 차이가 매우 크게 나타났다.

그래서 피보나치 수열 프로그램을 효과적으로 실행시키기 위해서는 재귀피보나치보다 반복피보나치가 더 좋다는 결론을 내렸다.

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

반복 방법은 for문을 이용해 F(1)부터 F(n)까지 순서대로 계산한다. 이전 두 값만 변수에 저장해두고 계속 갱신하는 방식으로 동작한다.

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

재귀 방법은 피보나치 수열의 수학적 정의를 그대로 코드로 옮긴 것이다. F(n)을 구하기 위해 F(n-1)과 F(n-2)를 재귀적으로 호출한다.

---

## 3. 알고리즘 분석

### 3-1. 반복(순환) 방법

- **시간복잡도**: O(n)
- **공간복잡도**: O(1)

for문이 n-1번 반복되므로 시간복잡도는 O(n)이다. 추가로 사용하는 변수가 result, temp1, temp2 세 개뿐이므로 공간복잡도는 O(1)로 매우 효율적이다.

### 3-2. 재귀 방법

- **시간복잡도**: O(2^n)
- **공간복잡도**: O(n)

재귀 방법은 F(n)을 구하기 위해 F(n-1)과 F(n-2)를 각각 따로 계산한다. 이 과정에서 이미 계산한 값을 다시 계산하는 **중복 계산** 문제가 발생한다. 예를 들어 F(5)를 구할 때 F(3)을 2번, F(2)를 3번 중복 계산하게 된다. 이로 인해 시간복잡도가 O(2^n)으로 N이 커질수록 수행시간이 기하급수적으로 늘어난다.

또한 재귀 호출이 깊어질수록 콜 스택을 많이 사용하기 때문에 공간복잡도는 O(n)이다.

---

## 4. 수행시간 측정 결과

### 4-1.반복피보나치 결과 표
<img width="1336" height="688" alt="image" src="https://github.com/user-attachments/assets/f0aa0bae-a678-4c8b-be43-92b202af5724" />

N의 값을 50으로 잡고 프로그램을 돌린 결과 총 프로그램 수행시간은 반복 피보나치 같은 경우 **3.602초**가 나왔다. 

추가로 프로그램 실행이 너무 빨라 메모리와 cpu사용량이 그래프에 나타나지 않는 모습을 확인할 수 있었다

### 4-2.재귀피보나치 결과표
<img width="1332" height="696" alt="image" src="https://github.com/user-attachments/assets/3e8de554-a59c-4b5c-ae8b-8dbf5af6068e" />

N의 값을 50으로 잡고 프로그램을 돌린 결과 총 프로그램 수행시간은 재귀 피보나치 같은 경우 **3분40초**가 나왔다.

추가로 프로그램 실행 중 사용된 메모리와 cpu값이 그래프에 잘 나타난 모습을 확인할 수 있었다

---

## 5. 그래프

### 5-1. 반복(순환) 방법 수행시간
<img width="481" height="586" alt="image" src="https://github.com/user-attachments/assets/da498681-5a7e-4bd3-8755-07ad9817c7e3" />
<img width="1500" height="750" alt="image" src="https://github.com/user-attachments/assets/3a74f53f-1713-4e73-9e16-ecb41bea871e" />

반복 방법은 N=50까지 모든 구간에서 수행시간이 0초로 나타났다. O(n)의 시간복잡도를 가지지만 N=50 수준에서는 연산 자체가 너무 간단해 측정 시간이 모든 구간에서 0으로 나타났.


### 5-2. 재귀 방법 수행시간
<img width="386" height="612" alt="image" src="https://github.com/user-attachments/assets/2dc5f679-6a32-4ee7-ab6e-19cb4f8dda66" />
<img width="1500" height="750" alt="image" src="https://github.com/user-attachments/assets/bdaf343b-725b-4d58-8141-e4ba15e53b7b" />

재귀 방법은 N=23부터 측정 가능한 시간이 나타나기 시작하며, N=40을 넘어서면서 수행시간이 급격히 증가한다. N=50에서는 약 **82.713초**가 소요되었다. 그래프에서 지수적 증가 곡선이 명확하게 확인된다.

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

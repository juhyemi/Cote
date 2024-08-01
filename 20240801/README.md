## 20240801 문제

### 백준 [예산](https://www.acmicpc.net/problem/2512)

- 접근방식

  [은상]
  - 이분 탐색
    - 분배할 예산의 범위는 `0 ~ 요청 최대 금액` 사이의 값
    - 1원씩 증가하며 모든 경우의 수를 판단하면 시간초과
  
  [주혜]
  

- 피드백

  [은상]
  - 이분 탐색을 진행할 때 최소 예산 금액을 `0`이 아닌 `*min_element()`로 설정하여 약 20분 동안 삽질 → 이분 탐색 문제를 풀 때 처음 범위 설정에 신경 쓰자!
  - 처음 풀이 코드와 비교
    
    ```cpp
    // 처음 풀이 코드
    while((s + e) / 2 != limit) {
    	limit = (s + e) / 2;
    	price = getPrice();
    	if(price < M) {
    		s = limit;
    	} else if(price > M) {
    		e = limit;
    	}
    }
    
    // 리팩토링 코드
    while(s <= e) {
    	m = s + (e - s) / 2;
    	if(getPrice() <= M) {
    		limit = m;
    		s = m + 1;
    	} else {
    		e = m - 1;
    	}
    }
    ```
    
    - 틀린 코드는 아니지만 `틀`을 기억할 수 있도록 간결한 코드 선호
    - `mid` 값을 구할 땐 `int`형 범위를 초과하지 않도록 주의
  
  [주혜]


### 프로그래머스 [가장 큰 수](https://school.programmers.co.kr/learn/courses/30/lessons/42746)

- 접근방식

  [은상]

  
  [주혜]
  
- 피드백

  [은상]
  
  [주혜]
  
  

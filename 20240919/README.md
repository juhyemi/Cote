## 20240919 문제

### 프로그래머스 [사칙연산](https://school.programmers.co.kr/learn/courses/30/lessons/1843)

- 접근방식

  [은상]
  - `min_dp[][]`와 `max_dp[][]`를 선언
    - `dp[i][j]`: k가 연산자의 위치를 나타날 때, {i ~ k}, {(k+1) ~ j} 연산의 최대, 최소값 저장
    - 연산자에 따라 최대값의 조건이 달라지기 때문
        - 연산자가 '-' 일 때
            - 최대값은 `max_dp[i][j] - min_dp[i][j]`
            - 최소값은 `min_dp[i][j] - max_dp[i][j]`
        - 연산자가 '+' 일 때
            - 최대값은 `max_dp[i][j] + max_dp[i][j]`
            - 최소값은 `min_dp[i][j] + min_dp[i][j]`
    - 모든 `[i, k, j]`의 경우에 대해 max_dp와 min_dp 값을 계산
    - 마지막으로 연산한 `max_dp[i][j]` 값을 정답으로 반환
  
  [주혜]
  
  
- 피드백

  [은상]
  - 이런 문제도 있구나~ 하고 넘어갈 것
  
  [주혜]
  

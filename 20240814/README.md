## 20240814 문제

### 백준 [주식](https://www.acmicpc.net/problem/11501)

- 접근방식

  [은상]
  
  [주혜]
  
- 피드백

  [은상]
  
  [주혜]

### 프로그래머스 [구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885)

- 접근방식

  [은상]

  [주혜]
  - 최대 2명을 태우기 때문에 sort하여 비교
  - idx로 작은순 인덱스 관리
  - 최대+최소 무게 > limit 인 경우 answer counting
  - 최대+최소 무게 <= limit 인 경우 answer, idx counting
  - 범위는 idx까지로 제한
  
  
- 피드백

  [은상]
  
  [주혜]
  - 범위를 0으로 제한해서 오답 -> 이렇게 하면 idx와 겹치게도 확인함을 깨닫고 idx로 수정
  - 빠른 로직 설계 -> Good

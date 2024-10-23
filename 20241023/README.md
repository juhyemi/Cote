## 20241023 문제

### 프로그래머스 [가장 먼 노드](https://school.programmers.co.kr/learn/courses/30/lessons/49189)

- 접근방식

  [은상]
  - 일반적인 최단 경로 탐색
  - 하지만 각 노드에서 1번 노드로부터 떨어진 거리를 확인하며, 그 거리값이 최대일 때 최대 거리값의 총 개수를 출력
  
  [주혜]
  
  
- 피드백

  [은상]
  - 큰 고민없이 빠르게 접근 Idea 구상 → Good!
  - 삽질 포인트 (너 왜 그래?)
    - `q.first().front` (X) → `q.front().first`
    - `q.first().second` (X) → `q.frint().second`
    - `q.pop()` 빼먹으면 무한루프 시간초과
 
  [주혜]
  
  
  

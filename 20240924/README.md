## 20240924 문제

### 프로그래머스 [타켓넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165)

- 접근방식

  [은상]
  - 순서가 정해져 있는 각 수들의 더하거나 빼는 경우를 확인해야 한다 → 완전탐색 → DFS
  
  [주혜]
  - visit를 고민하다가 for문으로 하나씩 도는 것을 구현했더니 stack overflow 발생
  - 순서가 바뀌지 않고 모든 수를 사용해야 하기 때문에 DFS 로 +, - 를 교차하여 구현하였다.
  
- 피드백

  [은상]
  - 유형만 파악할 수 있다면 어렵지 않게 해결 가능한 문제
  
  [주혜]
  - 빠른 판단으로 바로 풀이 과정을 변경하였다. -> GOOD!
  

## 20240920 문제

### 백준 20922 [겹치는 건 싫어](https://school.programmers.co.kr/learn/courses/30/lessons/20922)

- 접근방식

  [은상]
  
  [주혜]
  - map 선언 후 처음부터 인덱스를 하나씩 증가시키며 탐색
  - k이상 되면 break 후 Math.max 함수 이용하여 answer과 cnt 비교 => 시간초과
  - start, end로 인덱스를 조절, cnt 배열 선언하여 k이하가 될 수 있도록 구현
  - 개수가 k이하일 경우 end++, Math.max 함수 이용하여 answer, end-start 갱신
  - k개가 넘어갈 경우 start++, cnt 배열 -- 하여 조절
  
  
- 피드백

  [은상]
  
  [주혜]
  - 요즘 시간초과의 늪에서 허우적 거리는 중 ㅠ
  - 시간초과 없이 한 번에 구현할 수 있도록 문제 풀이 전 조금 더 시간 가질 것
  

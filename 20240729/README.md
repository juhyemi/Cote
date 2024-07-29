## 20240729 문제

### 백준 [카드2](https://www.acmicpc.net/problem/2164)

- 접근방식<br/>
  [은상]
  1. deque 선언과 요소 삽입
  2. deque에 요소가 한 개 남을 때까지 문제에서 제시한 카드를 버리고 옮기는 과정을 반복
  <br/>
  [주혜] Queue를 이용하여 구현했다.

- 피드백<br/>
  [은상]
  - 문제를 읽자마자 접근 Idea가 쉽게 떠올랐는데 함정 문제는 아닌지 시간복잡도를 먼저 계산 → Good
  - deque라는 자료구조를 사용하면 좋겠다는 생각을 먼저 떠올림 → Good
  <br/>
  [주혜]

### 프로그래머스 [디스크 컨트롤러](https://school.programmers.co.kr/learn/courses/30/lessons/42627)

- 접근방식<br/>
  [은상]
  <br/>
  [주혜]
  - ShortestJobFirst 스케줄링 사용이 필요함 인지
  - 기존 배열 정렬 후 작업 대기 배열을 priorityQueue를 사용해야 정렬하는데 시간 단축할 수 있다고 생각
  - idx와 cnt를 따로두어 작업대기와 반복문 끝날 시점 설정
  
- 피드백<br/>
  [은상]
  <br/>
  [주혜]
  - 스케줄링 떠올림 -> Good
  - 정렬시 priorityQueue 사용해 정렬시간 줄임 -> Good
  - if문으로 끝내면 될 조건에 while을 써서 테케 계속 틀림 -> Bad 큰 틀을 수도코드 먼저 작성하는 버릇이 필요할 듯

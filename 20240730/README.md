## 20240730 문제

### 백준 [주유소](https://www.acmicpc.net/problem/13305)

- 접근방식

  [은상]
  - 각 도시를 순회하며
  - 현재까지 방문한 주요소 중 가장 싼 주요소에서 다음 도시까지 이동할 수 있는 양의 기름을 구매
  - (현실에서는 불가능하지만 코드상으로 구현 가능)
  
  [주혜]
  - 처음엔 무조건 정해진 가격으로 주유해야함
  - 양 방향이 아니기 때문에 첫 가격을 min으로 놓고 갱신하면 되겠다고 생각
  

- 피드백

  [은상]
  - 접근 Idea가 쉽게 떠올라서 함정 문제가 아닌지 검토 후 코드 작성 → Good
  - 100% 정답이 뜨지 않아 문제 조건을 다시 읽고 자료형에 관한 문제임을 빠르게 파악 → Good!
  - 문제의 난이도치고 시간이 너무 오래 걸렸다
    
    → 실전을 대비하여 상세한 주석 작성이나 코드 리팩토링은 답안 제출 후 진행
  
  [주혜]
  - 배열을 n개로 만들어 놓고 idx로 조절했을 때 테스트케이스는 통과했지만 마지막 케이스가 통과되지 않았다. 생각하지 못한 예외 케이스들이 있는 것 같아 distance 배열을 n-1로 변경하고 idx로 조정하지 않으니까 성공! => 내가 조정하려하지말고 쉽게쉽게 가자
  

### 프로그래머스 [이중우선순위큐](https://school.programmers.co.kr/learn/courses/30/lessons/42628)

- 접근방식

  [은상]
  - 삽입, 삭제의 시간복잡도가 크지 않으면서 자동 정렬이 가능하고 중복을 허용하는 `multiset` 선언
  - Insert 명령어일 경우에 문자열의 2번째 idx부터 마지막 idx까지 추출한 결과를 int type으로 변환 후 multiset에 삽입
  
  [주혜]
  
  
- 피드백

  [은상]
  - 처음에 priority_queue를 사용하는 로직을 생각하다가 포기 → 20분 소요
    - 생각이 나지 않으면 빠르게 다른 해결 방안을 모색 → Good!
    - cf. 다른 사람의 풀이를 참고하니 최대힙, 최소힙 2개의 priority_queue를 선언하여 푸는 방법도 존재
  - multiset 이라는 자료구조의 사용 방법 익히기 → 20분 소요
    - [`multiset`](https://choiiis.github.io/cpp-stl/basics-of-set-multiset-class/)
    - 중복 허용
    - default → 오름차순 정렬
    - 검색, 삽입, 삭제의 시간복잡도 → O(logn)
    - `s.size()`
    - `s.empty()`
    - `s.find()`
    - `s.insert()`
    - `s.erase(it)`
    - `s.clear()`
    
    ```cpp
    // 최대값 참조
    cout << *ms.rbegin() << '\n';
    
    // 최소값 참조
    cout << *ms.begin() << '\n';
    
    // 최대값 삭제
    ms.erase(prev(ms.end()));
    ms.erase(--ms.end());
    
    // 최소값 삭제
    ms.erase(ms.begin());
    ```
  
  [주혜]
  

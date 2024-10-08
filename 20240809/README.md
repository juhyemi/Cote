## 20240809 문제

### 백준 [IF문 좀 대신 써줘](https://www.acmicpc.net/problem/19637)

- 접근방식

  [은상]
  - 각 캐릭터의 전투력을 측정할 때, 전투력 상한값을 기준으로 오름차순 정렬되어 있는 모든 칭호를 순서대로 살펴보며, 해당하는 칭호를 찾으면
    
    → `시간복잡도: O(MN)` ⇒ 시간 초과
    
  - 각 캐릭터의 전투력이 상한값보다 크거나 같은 칭호를 찾아야 하므로 → `이분 탐색(lower_bound)`
    - `시간복잡도: O(MlogN)` ⇒ 시간 초과 X
  
  [주혜]
  - 여러 조건에 해당하면 먼저 입력된 값이 출력되어야 하기 때문에 sort X
  - 시간복잡도 고려하여 이분탐색 진행
  
- 피드백

  [은상]
  - 삽질 과정
    - 처음에 시간복잡도를 계산하지 않고 이중반복문 코드 작성 → 시간 초과
    - 문제를 대충 읽고, 캐릭터의 전투력이 오름차순으로 입력된다고 이해 → 시간복잡도를 줄이는 방법으로, 현재까지 살펴본 `index` 변수를 사용
    - 오답 처리되자 오답이 발생한 예외 Case를 알아내기 위해 오랜 시간 동안 삽질
    - 이후에 문제를 다시 제대로 파악하고 답지를 참고하여 이분 탐색을 이용해야 한다는 사실을 파악
    
    → 코드에 오류가 없는데 오답이 발생하면 문제를 잘못 이해하고 있을 수 있다는 걸 기억하자!
    
  - 잘 기억이 나지 않았던 `이분 탐색 틀`과 몰랐던 `lower_bound`, `upper_bound`에 대한 확실한 학습 필요
    - `lower_bound`
        - 찾고 있는 값보다 크거나 같은 값의 첫 번째 위치 반환 → 이상
    - `upper_bound`
        - 찾고 있는 값보다 큰 값의 첫 번째 위치 반환 → 초과
    - `이분 탐색(lower_bound) 틀`
        
        ```cpp
        string getTitle(int power) {
          string value;
        
          int l = 0, m = 0, r = N-1;
          while(l <= r) {
            m = l + (r - l) / 2;
            if(v[m].second >= power) {
              value = v[m].first;
              r = m - 1;
            } else {
              l = m + 1;
            }
          }
        
          return value;
        }
        ```
  
  [주혜]
  - 주혜의 삽질 😊
  - 같은 전투력이 들어오지 않는 줄 알고 정렬안하려고 PRIORITYQUEUE 사용했다가 순서 이슈로 다시
  - ARRAY 를 SORT 해서 삽질
  - SORT가 되어있지 않은 상황에서 이분탐색은 어떻게 해야하는지 답지 참고
  - 종합 : 자료구조를 사용해보려는 시도는 좋았으나 문제의 조건을 파악하고 이분탐색 구현 방법 완전한 습득 필요요


### 프로그래머스 [모음사전](https://school.programmers.co.kr/learn/courses/30/lessons/84512)

- 접근방식

  [은상]
  - 모음을 조합하여 만들 수 있는 모든 단어를 저장 후 정렬
    - 모음을 조합하여 만들 수 있는 모든 단어를 찾는 과정 → 중복순열
    - 자동 정렬 되는 `set`에 저장
  - `set`을 처음부터 순회하며 찾는 단어와 일치할 때까지 순서(정답)를 1씩 증가
    - 일치하는 단어를 찾으면 순서(정답) 반환

  [주혜]
  - 시간초과 실패
  - https://seongho96.tistory.com/50
  - 이해중,,
  ```JAVA
  class Solution {
  
    static final String MAPPING = "AEIOU";
    static final int[] RATE_OF_INCREASE = {781, 156, 31, 6, 1};

    public int solution(String word) {
        int answer = word.length();

        for (int i = 0; i < word.length(); i++) {
            answer += (RATE_OF_INCREASE[i] * MAPPING.indexOf(word.charAt(i)));
        }

        return answer;
     }
  }
  ```

  
- 피드백

  [은상]
  - 적절한 자료구조를 이용했다 → Good!
  - 코드를 작성하면서 내가 의도한 대로 동작하는지 직접 테스트를 했다 → Good!
    - `set`에 단어를 저장하고 처음부터 살펴보면 그 순서가 올바르게 나타날 것인지 간단한 예시 코드를 작성하고 직접 출력해보며 확인
    - 코드를 다 작성했는데 내가 의도한 대로 동작하지 않으면 시간 낭비가 심해질 수 있기 때문에 Good!
  - 중복순열 `틀`이 기억나지 않았지만 머리를 써서 빠르게 코드를 작성했다 → Good!
    
    ```cpp
    void dfs(string word) {
        if(종료조건만족) return;
        
        // 중복순열
        for(int i=0; i<5; ++i) {
            dfs(word + c[i]);
        }
    }
    ```
    
  - 정답 확인 이후 코드 리팩토링을 진행하는 연습을 잘 실천하고 있다 → Good!
  
  [주혜]

  
  

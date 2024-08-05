## 20240805 문제

### 백준 [진우의 달 여행 (Small)](https://www.acmicpc.net/problem/17484)

- 접근방식

  [은상]
  - 달까지 가는 모든 경로의 연료량을 비교하여 최소 연료량을 출력
    - dfs를 사용한 브루트포스 알고리즘 사용
    - 현재 위치에서 다음 방향의 위치를 재귀호출하는 방식으로 모든 경로를 탐색
  
  [주혜]
  - 2<=n,m<=6을 확인한 후 전체 탐색해도 시간 초과 안날거라고 생각하여 DFS 탐색으로 진행
  - idx를 비교하며 이전과 같은 방향으로는 진행 불가하게 설정

- 피드백

  [은상]
  - 삽질 Point
    - `board[y][x]`에서 y와 x의 순서를 혼동하여 오랜 시간 동안 삽질
    - `board`의 크기를 6으로 설정하고 6 이상의 y값 index를 참조하는 로직을 작성하여 삽질
  - 사소한 삽질을 제외하면 빠르게 접근 방법 구상과 코드 구현을 했다 → Good
-   문제의 알고리즘 분류를 확인하고 알게됐지만, DP로 풀 수 있다
  
  [주혜]
  - 범위가 커질 때 어떻게 해야하는지 확인 필요
  - 빠른 문제 풀이 및 접근 방식 -> Good


### 프로그래머스 [소수 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/42839)

- 접근방식

  [은상]
  - 종이 조각으로 만들 수 있는 모든 숫자를 만드는 과정에서 완전탐색이 필요
    - `백트래킹` 사용
  - 만들 수 있는 각 숫자에 대해 소수인지 판별
    - 효율적인 소수 판별을 위해 `에라토스테네스의 체` 사용
    - 중복 확인

  [주혜]
  
- 피드백

  [은상]
  - 백트래킹 `틀`이 기억이 나지 않아 코드를 작성하는 데 시간을 많이 소비
    1. index 참조를 위한 `visited[]` 배열은 전역으로 선언
    2. 종료 조건은 항상 존재
    3. 각 `dfs()` 내에서, 현재 `idx`가 `true`인 상태에서<br>
        → 다음 `dfs()`를 호출한 이후<br>
        → 현재 `idx`를 다시 `false`로 변환
        

    ```cpp
    bool visited[MAX_LEN];

    void dfs(string numbers, string s) {
        if(s.length() && !checked[stoi(s)]) {
            if(prime[stoi(s)]) ++answer;
            checked[stoi(s)] = true;
            if(s.length() == numbers.length()) return;
        }

        for(int i=0; i<numbers.length(); ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            dfs(numbers, s + numbers[i]);
            visited[i] = false;
        }
    }
    ```

  - 종이 조각으로 만들 수 있는 모든 숫자를 만드는 과정은 결국 `순열` → 이 과정에서 백트래킹 이외에 다양한 방법이 존재한다는 사실을 기억하자
  
  [주혜]
  
  

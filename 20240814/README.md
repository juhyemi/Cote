## 20240814 문제

### 백준 [주식](https://www.acmicpc.net/problem/11501)

- 접근방식

  [은상]
  - 마지막 날부터 살펴보며
    - 최댓값을 갱신하면 → 주식을 파는 날
    - 주식을 파는 날 해당 주식을 판매했을 때 이익을 계산
  
  [주혜]
  - 첫날부터 계산하며 max값 갱신 -> 시간초과
  - PriorityQueue이용하여 구현 -> 시간초과
  - 마지막 날 부터 갱신하며 이익 계산산
  
- 피드백

  [은상]
  - 정렬과 최댓값 index를 활용하여 푸는 알고리즘을 작성했지만 오답이 발생했고, 예외 Case를 찾기 위해 GPT와 30분 동안 삽질
    - 코드
        
        ```cpp
        #include <iostream>
        #include <vector>
        #include <algorithm>
        using namespace std;
        typedef long long ll;
        
        int T, N;
        vector<int> sorted, v;
        ll answer;
        int maxIdx;
        int cnt;
        
        void reset() {
          sorted.clear();
          v.clear();
          answer = 0;
          maxIdx = 0;
          cnt = 0;
        }
        
        int main() {
        	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
        
        	cin >> T;
          while(T--) {
            cin >> N;
            for(int i=0; i<N; ++i) {
              int n;
              cin >> n;
              v.push_back(n);
              sorted.push_back(n);
            }
        
            sort(sorted.begin(), sorted.end(), greater<int>());
        
            for(int i=0; i<N; ++i) {
              if(sorted[maxIdx] <= v[i]) {
                answer += (ll)(sorted[maxIdx] * cnt);
                cnt = 0;
                ++maxIdx;
                continue;
              }
        
              answer -= (ll)v[i];
              ++cnt;
            }
        
            cout << answer << '\n';
            reset();
          }
        }
        ```
        
    - 예외 case
        
        ```cpp
        1
        8
        1 2 3 4 5 4 3 2
        
        // 기대: 10
        // 출력: 5
        ```
        
        - 주식을 팔지 않고 구매만 하다가 끝나는 경우 오답
    - 접근 Idea를 구상할 때 예외 Case를 생각하지 못한 건 내 머릿속의 한계인데 어떻게 보완해야 할까? 문제를 많이 풀어보는 수밖에?
  - `그리디 알고리즘` 유형 3일 연속 광탈 중 → 많이 풀어보자
  
  [주혜]
  - 시간초과가 난 이후로 자료구조를 이용하여 구현하려다가 오히려 삽질
  - 이런류의 문제는 뒤에서부터 탐색하는 방법도 잘 생각해 볼 것

### 프로그래머스 [구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885)

- 접근방식

  [은상]
  - 몸무게를 기준으로 정렬하여 모두 구출할 때까지 순회
    - 남은 사람 중 가장 가벼운 사람과 가장 무거운 사람의 몸무게 합을 계산하여
    - 무게 제한을 초과하는 모든 가장 무거운 사람에 대해 정답을 count 하고
        - 무거운 사람은 따로 구출해야 하는 걸로 간주하기 때문
    - 그 외의 경우 → 남은 가장 가벼운 사람이 가장 무거운 사람일 경우를 포함하여 가장 가벼운 사람과 가장 무거운 사람을 동시에 구출

  [주혜]
  - 최대 2명을 태우기 때문에 sort하여 비교
  - idx로 작은순 인덱스 관리
  - 최대+최소 무게 > limit 인 경우 answer counting
  - 최대+최소 무게 <= limit 인 경우 answer, idx counting
  - 범위는 idx까지로 제한
  
  
- 피드백

  [은상]
  - 처음에 ‘구명보트에 한 번에 최대 2명’ 탑승 가능하다는 조건을 확인하지 못해 삽질 → 실전에서 가장 하지 말아야 할 실수
  - 다른 사람의 코드와 비교했을 때 비교적 클린 코드 작성 → Good!
  
  [주혜]
  - 범위를 0으로 제한해서 오답 -> 이렇게 하면 idx와 겹치게도 확인함을 깨닫고 idx로 수정
  - 빠른 로직 설계 -> Good

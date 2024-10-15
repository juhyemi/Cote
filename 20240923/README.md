## 20240923 문제

### 백준 1446번 [지름길](https://www.acmicpc.net/problem/1446)

- 접근방식

  [은상]
  - 출발 지점부터 도착 지점까지 모든 지점에 대해 해당 지점까지 최단 비용을 저장할 `dp[]` 선언
  - 도착 지점을 인덱스로 하는 출발 지점과 비용 정보를 저장할 `지름길 배열` 선언
  - bottom-up 방식으로 `dp[D]`의 값을 구하여 출력
  
  [주혜]
  - 은상햄 도움 땡큐~!~!
  - 배열에 주어지는 시작점, 도착점, 비용 저장하려다 예외처리와 함께 인덱스 이슈
  - 인덱스에 구애받지 않는 리스트 사용으로 해결결
  
- 피드백

  [은상]
  - 이 문제를 DP로 풀 생각을 어떻게…?
  - vector 선언 시 크기 설정과 초기값 설정 방법을 기억하자
    
    ```cpp
    vector<int> dp(MAX, INT_MAX);
    ```
    
  - 3가지 정보를 저장하기 위해 tuple을 사용하는 방법 외 “2차원 배열을 사용하여 index에 한 가지 정보를 저장하는 스킬”을 기억하고 적절히 활용해보자
    
    ```cpp
    vector<pair<int, int>> v[MAX]; // v[도착지점] = {출발지점, 비용}
    ```
    
  - 예외 Case?
    
    ```cpp
    #include <iostream>
    #include <tuple>
    #include <algorithm>
    using namespace std;
    
    int N, D;
    vector<tuple<int, int, int>> v; // 실질적으로 사용할 수 있는 지름길 배열
    bool visited[12];
    int maxReduceDistance;
    
    void dfs(int idx, int npos, int totalReduceDistance) {
      if(idx == v.size()) {
        if(maxReduceDistance < totalReduceDistance) {
          maxReduceDistance = totalReduceDistance;
        }
        return;
      }
    
      for(int i=idx; i<v.size(); ++i) {
        if(visited[i]) continue;
    
        int s, e, d;
        tie(s, e, d) = v[i];
        int reduceDistance = (e - s) - d;
    
        if(npos > s) continue; // 현재 위치가 지름길의 시작 위치보다 앞선 경우 건너뜀
    
        visited[i] = true;
        dfs(i + 1, e, totalReduceDistance + reduceDistance);
        visited[i] = false;
      }
    }
    
    bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
      return get<0>(a) < get<0>(b);
    }
    
    int main() {
    	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    
    	cin >> N >> D;
      for(int i=0; i<N; ++i) {
        int s, e, d; // 시작, 끝 위치, 지름길의 길이
        cin >> s >> e >> d;
        if(e - s < d) continue;
        if(e > D) continue;
        v.push_back({s, e, d});
      }
    
      sort(v.begin(), v.end(), comp);
      
      dfs(0, 0, 0);
    
      cout << D - maxReduceDistance << '\n'; 
    }
    ```
  
  [주혜]
  - 이게 dp라면,, 실전에서 과연 시간내에 해결할 수 있을까..? 연습이 엄청 필요할 것 같음음
  

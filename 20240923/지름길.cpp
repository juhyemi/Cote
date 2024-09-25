#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX 10010

int N, D;
vector<int> dp(MAX, INT_MAX); // dp[i]: i 지점까지 가는 데 최단 비용
vector<pair<int, int>> v[MAX]; // 지름길 저장, v[도착지점] = {출발지점, 비용}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> D;

  for(int i=0; i<N; ++i) {
    int s, e, d; // 시작, 끝 위치, 지름길의 길이
    cin >> s >> e >> d;
    // 예외 처리
    if(e - s < d) continue; // 지름길이 오히려 더 오래 걸리는 경우
    if(e > D) continue; // 지름길의 도착 지점이 목표 지점보다 큰 경우
    v[e].push_back({s, d});
  }

  dp[0] = 0;
  for(int i=1; i<=D; ++i) {
    dp[i] = dp[i-1] + 1;
    // 해당 지점까지 연결된 모든 지름길 탐색
    for(const auto& shortcut : v[i]) {
      // dp[i] = min(이전 지점에서 1만큼 이동했을 때 비용, 지름길을 이용했을 때 비용)      
      dp[i] = min(dp[i], dp[shortcut.first] + shortcut.second);
    }
  }

  cout << dp[D] << '\n';
}

// 시간복잡도: O(D+N)

#include <iostream>
#include <queue>
using namespace std;
#define MAX 100010

int N, K, X; // X: 현재 위치
queue<pair<int, int>> q; // 위치, depth
bool visited[MAX];
int d[3] = {0, -1, 1}; // 주의! 순간이동 하는 경우를 먼저 살펴봐야 한다
                       // 현재 위치가 1, 비용이 0일 때 → 다음 위치인 2는 비용이 1이 아니라 0이어야 하기 때문
int depth;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N >> K;

  q.push({N, 0});
  visited[N] = true;
  while(!q.empty()) {
    d[0] = X = q.front().first; // d[0]에 현재 위치 저장
    depth = q.front().second;
    q.pop();

    // 목적지 도착
    // 만약, 출발점과 목적지가 같은 경우 depth = 0 출력 후 종료
    if(X == K) {
      cout << depth << '\n';
      return 0;
    }

    for(int i=0; i<3; ++i) {
      int next = X + d[i]; // (i=2) 일 때, (2*X) 위치로 이동
      if(next < 0 || next > 100000) continue;
      if(visited[next]) continue;

      // 순간이동을 하는 경우 0초가 걸리기 때문에 depth(시간)을 증가하지 않는다
      if(i == 0) q.push({next, depth});
      // 그 외 경우는 depth(시간)을 증가
      else q.push({next, depth + 1});

      visited[next] = true;
    }
  }
}

// 시간복잡도: O(MAX)

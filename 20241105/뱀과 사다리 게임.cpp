#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define MAX 110

int N, M;
map<int, int> warp; // 사다리, 뱀의 이동 정보
bool visited[MAX];
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;

  // 사다리, 뱀의 이동 정보 저장
  for(int i=0; i<N+M; ++i) {
    int s, e;
    cin >> s >> e;
    warp[s] = e;
  }

  // 최단 거리 탐색 - BFS
  q.push({1, 0});
  while(!q.empty()) {
    int current = q.front().first;
    int depth = q.front().second;
    q.pop();
    
    if(current == 100) {
      cout << depth << '\n';
      return 0;
    }

    for(int i=1; i<=6; ++i) {
      int next = current + i;
      if(warp[next]) next = warp[next]; // 사다리, 뱀을 통한 이동

      if(next > 100) continue;
      if(visited[next]) continue;

      q.push({next, depth + 1});
      visited[next] = true;
    }
  }
}

// 시간복잡도: O(MAX)

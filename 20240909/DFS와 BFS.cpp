#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 1010

int N, M, V;
vector<int> graph[MAX];
vector<int> dfs_seq, bfs_seq;
bool visited[MAX];

void dfs(int now) {
  visited[now] = true;
  dfs_seq.push_back(now);

  for(int i=0; i<graph[now].size(); ++i) {
    int next = graph[now][i];
    if(!visited[next]) dfs(next);
  }
}

void bfs() {
  queue<int> q;
  // visited 배열 초기화
  memset(visited, false, sizeof(visited));

  q.push(V);
  visited[V] = true;
  while(!q.empty()) {
    int now = q.front(); q.pop();
    bfs_seq.push_back(now);

    for(int i=0; i<graph[now].size(); ++i) {
      int next = graph[now][i];
      if(!visited[next]) {
        q.push(next);
        visited[next] = true;
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N >> M >> V;
  for(int i=0; i<M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // 노드 번호 순으로 정렬 (번호가 낮은 노드 순으로 방문하기 위함)
  for(int i=1; i<=N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(V);
  bfs();

  for(const auto& iter : dfs_seq) cout << iter << ' ';
  cout << '\n';
  for(const auto& iter : bfs_seq) cout << iter << ' ';
  cout << '\n';
}

// 시간복잡도: O(N+M)
// 공간복잡도: O(N*MAX)

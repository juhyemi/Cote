#include <iostream>
using namespace std;
#define MAX 8

int N, M;
int board[MAX][MAX];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
int answer = 600;

void dfs(pair<int, int> n, int prevDirection, int fuel) {
  // 달에 도착했으면 소비한 연료를 저장하고 종료
  if(n.first == N) {
    if(fuel < answer) answer = fuel;
    return;
  }

  // 다음 위치로 이동
  for(int dir=0; dir<3; ++dir) {
    if(dir == prevDirection) continue;
    int nx = n.second + dx[dir];
    int ny = n.first + dy[dir];
    if(nx < 0 || nx >= M) continue;
    dfs({ny, nx}, dir, fuel + board[ny][nx]);
  }
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> board[i][j];
    }
  }

  for(int i=0; i<M; ++i) {
    dfs({0, i}, -1, board[0][i]);
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N * M)

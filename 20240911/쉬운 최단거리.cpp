#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 1010

int n, m;
bool visited[MAX][MAX];
int board[MAX][MAX], input[MAX][MAX];
queue<tuple<int, int, int>> q; // {y, x, 목표지점까지 거리}
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
  
  cin >> n >> m;

	for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> input[i][j];

      // bfs 시작 지점 queue에 삽입
      if(input[i][j] != 2) continue;
      q.push({i, j, 0});
      visited[i][j] = true;
    }
  }

  // bfs
  while(!q.empty()) {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int depth = get<2>(q.front());
    q.pop();
    board[y][x] = depth;

    for(int i=0; i<4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(visited[ny][nx]) continue;
      if(input[ny][nx] == 0) continue;
      q.push({ny, nx, depth + 1});
      visited[ny][nx] = true;
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      // 갈 수 있는 땅인데, 가지 못한 경우 -1 출력
      if(input[i][j] == 1 && board[i][j] == 0) board[i][j] = -1;
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

// 시간복잡도: O(n*m)

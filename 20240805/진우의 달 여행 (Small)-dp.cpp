#include <iostream>
using namespace std;
#define MAX 6
#define MAX_VALUE 600

int N, M;
int dp[MAX][MAX][3];
int board[MAX][MAX];
int answer = MAX_VALUE;

int getDP(int i, int j, int k) {
  // index를 벗어나는 범위의 경로는 계산에 포함되지 않도록 최대값으로 설정
  if((j == 0 && k == 0) || (j == M-1 && k == 2)) return MAX_VALUE;
  // 지구에서 출발한 직후의 dp값은 기본값으로 설정
  if(i == 0) return board[i][j];

  int value;
  if(k == 0) {
    value = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + board[i][j];
  } else if(k == 1) {
    value = min(dp[i-1][j][0], dp[i-1][j][2]) + board[i][j];
  } else if(k == 2) {
    value = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + board[i][j];
  }

  // 달에 도착했을 때 사용 연료의 최소값(정답) 갱신
  if(i == N-1) {
    answer = min(answer, value);
  }

  return value;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> board[i][j];
      for(int k=0; k<3; ++k) {
        dp[i][j][k] = getDP(i, j, k);
      }
    }
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N * M)

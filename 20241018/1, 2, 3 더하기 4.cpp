#include <iostream>
using namespace std;
#define MAX 10010

int T, n;
int dp[MAX][4];
/*
  dp[i][1]: 1을 이용하여 i를 만드는 경우의 수
  dp[i][2]: 1과 2를 이용하여 i를 만드는 경우의 수 (2를 필수로 포함, 1은 선택)
  dp[i][3]: 1과 2와 3을 이용하여 i를 만드는 경우의 수 (3을 필수로 포함, 1과 2는 선택)
  구하고자 하는 값 = dp[n][1] + dp[n][2] + dp[n][3]
*/

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  dp[1][1] = 1;

  dp[2][1] = 1;
  dp[2][2] = 1;

  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  for(int i=4; i<MAX; ++i) {
    dp[i][1] = dp[i-1][1]; // 1 만큼 작은 수의 모든 식에, 1의 개수만 하나 추가
    dp[i][2] = dp[i-2][1] + dp[i-2][2]; // 2 만큼 작은 수의 모든 식에, 2의 개수만 1개 추가 + 1의 개수만 2개 추가
    dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3]; // 3 만큼 작은 수의 모든 식에, 3의 개수만 1개 추가 + ...
  }

	cin >> T;
  while(T--) {
    cin >> n;
    cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
  }
}

// 시간복잡도: O(MAX)

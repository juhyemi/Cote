#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int n;
int s; // 시작 idx
int answer;
int arr[200010];
int cnt[100010]; // 1 ~ 100000까지 수열 내 각 숫자의 개수

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> K;
  for(int e=0; e<N; e++){
    int n;
    cin >> n;
    arr[e] = n;

    cnt[n]++;

    while(cnt[n] > K) {
      cnt[arr[s]]--;
      s++;
    }

    answer = max(answer, e - s + 1);
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N)

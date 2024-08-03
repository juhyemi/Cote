#include <iostream>
using namespace std;
#define MAX 20010

int N, K;
char table[MAX];
bool visited[MAX];
int cnt;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> K;
  for(int i=0; i<N; ++i) {
    cin >> table[i];
  }

  // table의 각 자리를 순회
  // 사람 자리이면
  // 가능한 가장 왼쪽의 햄버거를 선택
  for(int i=0; i<N; ++i) {
    if(table[i] != 'P') continue;
    for(int j=i-K; j<=i+K; ++j) {
      // 예외 조건 설정
      // 1. 범위 밖일 때
      // 2. 햄버거가 아닐 때
      // 3. 이미 임자가 있는 햄버거일 때
      if(j<0 || j>=N) continue;
      if(table[j] != 'H') continue;
      if(visited[j]) continue;

      visited[j] = true;
      ++cnt;
      break;
    }
  }

  cout << cnt << '\n';
}

// 시간복잡도: O(N*K)
// 20:21
// https://resilient-aura-65d.notion.site/19941-a143238d084f492199c9b483aab25672?pvs=4

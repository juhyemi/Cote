#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 3001

int N, d, k, c, answer, cnt;
vector<int> v;
bool selected[MAX];

int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
	cout.tie(0);

  cin >> N >> d >> k >> c;

  int sushi;
  for(int i=0; i<N; ++i) {
    cin >> sushi;
    v.push_back(sushi);
  }

  // 모든 경우의 수 고려
  for(int i=0; i<N; ++i) {
    // 쿠폰 미리 먹음
    selected[c] = true;
    ++cnt;

    // 연속된 k개의 초밥 검사
    for(int j=0; j<k; ++j) {
      if(!selected[v[(i+j)%N]]) {
        selected[v[(i+j)%N]] = true;
        ++cnt;
      }
    }

    // 정답 갱신
    answer = max(answer, cnt);

    // 초기화
    cnt = 0;
    fill(selected, selected+MAX, false);
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N * (k + MAX))

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int T, N;
vector<int> v;
ll answer;
int maxValue;

void reset() {
  v.clear();
  answer = 0;
  maxValue = 0;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> T;
  while(T--) {
    cin >> N;
    for(int i=0; i<N; ++i) {
      int n;
      cin >> n;
      v.push_back(n);
    }

    // 마지막 날부터 확인
    for(int i=N-1; i>=0; --i) {
      // 최댓값 갱신 → 주식 파는 날
      if(maxValue < v[i]) maxValue = v[i];
      // 주식을 파는 날 해당 주식을 판매했을 때 이익을 계산
      answer += maxValue - v[i];
    }

    cout << answer << '\n';
    reset();
  }
}

// 시간복잡도: O(N)
// cf. https://novlog.tistory.com/entry/CC-BOJ백준-11501-주식-문제-풀이-소스-코드
// https://resilient-aura-65d.notion.site/11501-b38db82ec5d8438395ef7e4489c7877f?pvs=4

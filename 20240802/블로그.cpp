#include <iostream>
#include <vector>
using namespace std;

int N, X;
int sum, cnt;
vector<int> v;
int maxValue;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N >> X;
  for(int i=0; i<N; ++i) {
    int n;
    cin >> n;
    v.push_back(n);

    // 구간합 계산
    if(i >= X) sum -= v[i-X];
    sum += n;

    // 구간합의 최대값이 갱신되면 기간의 개수를 1초 초기화
    if(sum > maxValue) {
      maxValue = sum;
      cnt = 1;
    }
    
    // 구간합의 최대값과 같으면 기간의 개수를 증가
    else if(sum == maxValue) {
      ++cnt;
    }
  }

  if(maxValue == 0) cout << "SAD" << '\n';
  else cout << maxValue << '\n' << cnt << '\n';
}

// 시간복잡도: O(N)
// 17:59

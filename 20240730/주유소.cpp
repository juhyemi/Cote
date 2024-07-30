#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;
vector<int> price, length;
int minPrice = 1000000010;
ll answer;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=0; i<N-1; i++) {
    int l;
    cin >> l;
    length.push_back(l);
  }

  for(int i=0; i<N; i++) {
    int p;
    cin >> p;
    price.push_back(p);
  }

  // 각 도시를 순회하며
  // 현재까지 방문한 주요소 중 가장 싼 주요소에서 다음 도시까지 이동할 수 있는 양의 기름을 구매
  // (현실에서는 불가능하지만 코드는 가능)
  for(int i=0; i<N-1; i++) {
    if(price[i] < minPrice) minPrice = price[i];
    answer += (ll)minPrice * (ll)length[i];
  }

  cout << answer << "\n";
}

// 시간복잡도: O(N)
// 공간복잡도: O(N)
// 20:53
// https://resilient-aura-65d.notion.site/13305-3ecef6425fca40398067e132700a69e0?pvs=4

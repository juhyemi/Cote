#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=1; i<=N; ++i) dq.push_back(i);

  while(dq.size() > 1){
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }

  cout << dq.front() << '\n';
}

// 시간복잡도: O(N)
// 공간복잡도: O(N)
// 06:15
// https://resilient-aura-65d.notion.site/2-a776037283574799a2e65c44470af03c?pvs=4

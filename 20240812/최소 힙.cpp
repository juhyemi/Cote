#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  while(N--) {
    int x;
    cin >> x;

    if(x) {
      pq.push(x);
      continue;
    }
    
    if(pq.empty()) cout << 0 << '\n';
    else {
      cout << pq.top() << '\n';
      pq.pop();
    }
  }
}

// 시간복잡도: O(NlogN)
// 05:17

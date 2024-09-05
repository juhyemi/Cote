#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N;
  for(int i=0; i<N*N; ++i) {
    int n;
    cin >> n;
    pq.push(n);
    // N개의 수만 저장
    if(pq.size() > N) pq.pop();
  }
	
	// 큰 N개의 수를 저장한 최소 힙에서 top(가장 작은 수) = N번째 큰 수
  cout << pq.top() << '\n';
}

// 시간복잡도: O(N^2 * logN)
// https://codejin.tistory.com/215

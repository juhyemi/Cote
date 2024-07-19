#include <iostream>
using namespace std;
#define MAX 52

int N, x, y;
int weight[MAX], height[MAX];

int getRank(int idx) {
  int value = 1;

  for(int i=0; i<N; ++i) {
    if(weight[idx] < weight[i] && height[idx] < height[i]) ++value;
  }

  return value;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=0; i<N; ++i) {
    cin >> weight[i] >> height[i];
  }

  for(int i=0; i<N; ++i) {
    cout << getRank(i) << " ";
  }
}

// 시간복잡도: O(N^2)
// 공간복잡도: O(MAX)
// https://resilient-aura-65d.notion.site/7568-a7e52a6a4cd84cb195cfa938c099866a?pvs=4

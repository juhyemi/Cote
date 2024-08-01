#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> v;
int price, limit;
int s, e, m;

int getPrice() {
  int sum = 0;
  for(int i=0; i<v.size(); ++i) {
    sum += min(v[i], m);
  }
  return sum;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=0; i<N; ++i) {
    int n;
    cin >> n;
    v.push_back(n);
    if(e < n) e = n;
  }
  cin >> M;

  while(s <= e) {
    m = s + (e - s) / 2;
    if(getPrice() <= M) {
      limit = m;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }

  cout << limit << '\n';
}

// 시간복잡도: O(N * log(max_element))
// 01:03:53
// https://resilient-aura-65d.notion.site/1fdf2de2b25f4a3f8e1ef92be5ca3d06?pvs=4

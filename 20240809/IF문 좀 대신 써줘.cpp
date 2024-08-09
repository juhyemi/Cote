#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<pair<string, int>> v;

// 이분 탐색(lower_bound)
string getTitle(int power) {
  string value;

  int l = 0, m = 0, r = N-1;
  while(l <= r) {
    m = l + (r - l) / 2;
    if(v[m].second >= power) {
      value = v[m].first;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return value;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;
  for(int i=0; i<N; ++i) {
    string title;
    int limit;
    cin >> title >> limit;
    v.push_back({title, limit});
  }
  
  for(int i=0; i<M; ++i) {
    int power;
    cin >> power;
    cout << getTitle(power) << '\n';
  }
}

// 시간복잡도: O(MlogN)
// https://resilient-aura-65d.notion.site/IF-3e003df3c2814ae0aa5c6e5214dd8a10?pvs=4

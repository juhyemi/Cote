#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, K;
vector<pair<int, tuple<int, int, int>>> v;
tuple<int, int, int> t;
int answer = 1;

bool comp(pair<int, tuple<int, int, int>> c1, pair<int, tuple<int, int, int>> c2) {
	if(get<0>(c1.second) == get<0>(c2.second)) {
		if(get<1>(c1.second) == get<1>(c2.second)) {
			return get<2>(c1.second) > get<2>(c2.second);
		}
		return get<1>(c1.second) > get<1>(c2.second);
	}
	return get<0>(c1.second) > get<0>(c2.second);
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> K;
  for(int i=0; i<N; ++i) {
    int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({a, {b, c, d}});

		if(a == K) {
			t = {b, c, d};
		}
  }

	sort(v.begin(), v.end(), comp);

	for(const auto& c : v) {
		if(c.first == K) {
			cout << answer << '\n';
			break;
		}

		if(c.second == t) continue;
		
		++answer;
	}
}

// 시간복잡도: O(N)
// 공간복잡도: O(N)
// https://resilient-aura-65d.notion.site/8979-d4a7c8def85f4bb5b7db7e54db9edc6d?pvs=4

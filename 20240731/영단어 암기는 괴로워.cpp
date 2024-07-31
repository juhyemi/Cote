#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
map<string, int> m; // {단어, 등장 횟수}
vector<pair<string, int>> v; // map → vector
string s;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if(a.second == b.second) {
		if(a.first.length() == b.first.length()) {
			// 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
			return a.first < b.first;
		}
		// 2. 해당 단어의 길이가 길수록 앞에 배치
		return a.first.length() > b.first.length();
	}
	// 1. 자주 나오는 단어일수록 앞에 배치
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> s;
		if(s.length() < M) continue;
		++m[s];
	}

	// map → vector
	v.assign(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	for(const auto& it : v) {
		cout << it.first << '\n';
	}
}

// 시간복잡도: O(N)
// cf. sort의 시간복잡도: O(NlogN)
// 23:21
// https://resilient-aura-65d.notion.site/90fdaad246094d4ca20ea50f86adc0e3?pvs=4

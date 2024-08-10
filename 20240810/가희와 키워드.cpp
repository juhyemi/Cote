#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int N, M;
set<string> s;

// 특정 문자를 기준으로 문자열을 나누는 함수
// string 벡터에 저장하여 반환
vector<string> split(string str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string temp;
    
  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
	}
    
  return result;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> M;

	// 키워드를 set에 저장
	for(int i=0; i<N; ++i) {
		string keyword;
		cin >> keyword;
		s.insert(keyword);
	}

	// set에서 글에 사용된 keyword 제거
	// set의 크기 반환
	for(int i=0; i<M; ++i) {
		string content;
		cin >> content;
		vector<string> result = split(content, ',');
		for(const auto& keyword : result) {
			if(s.find(keyword) == s.end()) continue;
			s.erase(keyword);
		}

		cout << s.size() << '\n';
	}
}

// 시간복잡도: O((N + (M * 블로그 글의 길이))logN)
// 23:05
// https://resilient-aura-65d.notion.site/22233-dca25de266fe41f8997ee6b648ad565b?pvs=4

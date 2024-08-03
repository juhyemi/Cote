#include <iostream>
#include <string>
using namespace std;

int N, idx;
string str;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> str;

  while(idx < str.length()) {
    // N을 하나씩 증가하며 확인
    ++N;
    string stringN = to_string(N);

    // N의 각 자리수와 입력받은 문자열의 각 자리수를 비교
    for(int i=0; i<stringN.length(); ++i) {
      if(stringN[i] != str[idx]) continue;
      ++idx;
    }
  }

  cout << N << '\n';
}

// 시간복잡도: O(N^2)
// https://resilient-aura-65d.notion.site/1515-d5b67f3e0d444b0bafb090925b8500af?pvs=4

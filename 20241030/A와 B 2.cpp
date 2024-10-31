#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S, T, reverseT;
int answer;

void dfs(string s) {
  // S를 T로 바꿀 수 있을 때
  if(s == T) {
    answer = 1;
    return;
  }

  // 시간초과로 인한 시간복잡도를 줄이기 위한 방법
  // 중간 과정에서 어떻게 해도 바꿀 수 없는 경우 종료
  if(T.find(s) == string::npos && reverseT.find(s) == string::npos) return;

  // 1. 문자열의 뒤에 A를 추가하는 경우
  dfs(s + "A");

  // 2. 문자열의 뒤에 B를 추가하고 문자열을 뒤집는 경우
  reverse(s.begin(), s.end());
  dfs("B" + s);
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> S >> T;

  reverseT = T;
  reverse(reverseT.begin(), reverseT.end());
  
  dfs(S);

  cout << answer << '\n';
}

// 시간복잡도: O(문자열길이^2)

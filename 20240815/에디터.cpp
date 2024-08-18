#include <iostream>
#include <string>
#include <stack>
using namespace std;

int M;
string str, ans;
// cursor 기준 왼쪽에 위치한 문자 저장
// cursor와 가까운 문자를 top에 저장
// 출력하기 전에 cursorRight stack에 옮길 예정
stack<char> cursorLeft;
// cursor 기준 오른쪽에 위치한 문자 저장
// cursor와 가까운 문자를 top에 저장
// 왼쪽 stack의 요소를 모두 옮긴 후 top부터 순서대로 출력
stack<char> cursorRight;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> str;
  for(int i=0; i<str.length(); ++i) {
    cursorLeft.push(str[i]);
  }

  cin >> M;
  for(int i=0; i<M; ++i) {
    char command;
    cin >> command;

    if(command == 'L') {
      if(cursorLeft.empty()) continue;
      cursorRight.push(cursorLeft.top());
      cursorLeft.pop();
    }

    else if(command == 'D') {
      if(cursorRight.empty()) continue;
      cursorLeft.push(cursorRight.top());
      cursorRight.pop();
    }

    else if(command == 'B') {
      if(cursorLeft.empty()) continue;
      cursorLeft.pop();
    }

    else if(command == 'P') {
      char c;
      cin >> c;
      cursorLeft.push(c);
    }
  }

  while(!cursorLeft.empty()) {
    cursorRight.push(cursorLeft.top());
    cursorLeft.pop();
  }

  while(!cursorRight.empty()) {
    ans += cursorRight.top();
    cursorRight.pop();
  }

  cout << ans << '\n';
}

// 시간복잡도: O(문자열의 길이 + M)
// cf. https://velog.io/@jmink002/C1406
// https://resilient-aura-65d.notion.site/1406-b76a3a065ab047628bda86905ec70262?pvs=4

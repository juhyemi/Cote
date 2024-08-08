#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int N;
string base, comp;
int baseAlphabetCnt[26], compAlphabetCnt[26]; // 각 문자(알파벳)의 개수 저장
int answer;

bool isSimillar() {
  // 단어의 길이가 2 이상 차이나면 false
  if(abs((int)(base.length() - comp.length())) > 1) return false;

  int DifferentCnt = 0; // 개수 차이가 1인 문자의 개수
  for(int i=0; i<26; ++i) {
    if(baseAlphabetCnt[i] != compAlphabetCnt[i]) {
      // 특정 문자의 개수 차이가 2 이상이면 false
      if(abs(baseAlphabetCnt[i] - compAlphabetCnt[i]) > 1) return false;
      ++DifferentCnt;
    }
  }

  // 단어의 길이가 같은 경우
  // 1. 구성이 같거나
  // 2. 한 문자를 다른 문자로 바꾸면 된다
  if(base.length() == comp.length()) {
    return DifferentCnt == 0 || DifferentCnt == 2;
  }

  // 단어의 길이가 1 차이 나는 경우
  // 3. 한 문자를 더하면 된다
  else {
    return DifferentCnt == 1;
  }
}


int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N;
	cin >> base;
  for(int i=0; i<base.length(); ++i) ++baseAlphabetCnt[base[i] - 'A'];
  for(int i=1; i<N; ++i) {
    cin >> comp;
    memset(compAlphabetCnt, 0, sizeof(compAlphabetCnt));
    for(int j=0; j<comp.length(); ++j) ++compAlphabetCnt[comp[j] - 'A'];
    if(isSimillar()) ++answer;
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N)
// https://resilient-aura-65d.notion.site/2607-6693143f06b849a991c51d527ccacfc2?pvs=4

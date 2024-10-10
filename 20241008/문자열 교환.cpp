#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

string s;
int n; // s.length()
int minChangeBCnt;
int aCnt; // 문자열 내 a의 개수
int changBCnt; // 슬라이딩 윈도우 내 a로 바꿔야 할 b의 개수

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> s;
  n = s.length();
  minChangeBCnt = INT_MAX;
  for(const char& c : s) {
    if(c == 'a') aCnt++;
  }

  s += s; // 문자열이 원형으로 이어져 있기 때문에 모든 경우의 슬라이딩 윈도우를 검사하기 위해 문자열을 복사하여 확장
  
  for(int i=0; i<n; ++i) {
    int j = i + aCnt - 1;
    // i, j: 슬라이딩 윈도우의 시작과 끝 idx

    // 슬라이딩 윈도우 내 a로 바꿔야 할 b의 개수 계산
    for(int k=i; k<=j; ++k) {
      if(s[k] == 'b') changBCnt++;
    }

    minChangeBCnt = min(minChangeBCnt, changBCnt); // 정답(최소값) 갱신
    changBCnt = 0; // 다음 경우를 살펴보기 위해 초기화
  }

  cout << minChangeBCnt << '\n';
}

// 시간복잡도: O(len^2)
// https://dfdfg42.tistory.com/entry/백준-1522번-문자열-교환-C

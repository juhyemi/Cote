#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int T, K;
string W;
int w_length;
int alphabetCnt[26]; // W 문자열의 각 알파벳 등장 빈도수 저장
int answer_3, answer_4;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> T;
  while(T--) {
    cin >> W >> K;
    w_length = W.length();
    memset(alphabetCnt, 0, sizeof(alphabetCnt));
    answer_3 = INT_MAX;
    answer_4 = -1;
    
    // W 의 알파벳 문자별로 등장 빈도수 저장
    for(int i=0; i<w_length; i++) {
      alphabetCnt[W[i] - 'a']++;
    }

    for(int i=0; i<w_length; i++) {
      // 빈도수가 K개 미만이면 Pass
      if(alphabetCnt[W[i] - 'a'] < K) continue;

      int cnt = 0; // 현재 문자의 등장 횟수
      for(int j=i; j<w_length; j++) {
        // 연속 문자열의 시작 문자 W[i]
        // 연속 문자열의 끝 문자 W[j]

        if(W[i] == W[j]) cnt++; // answer_4 조건 자동 충족

        if(cnt == K) {
          answer_3 = min(answer_3, j - i + 1);
          answer_4 = max(answer_4, j - i + 1);
          break;
        }
      }
    }

    (answer_3 == INT_MAX ? cout << -1 << "\n" : cout << answer_3 << " " << answer_4 << "\n");
  }
}

// 시간복잡도:

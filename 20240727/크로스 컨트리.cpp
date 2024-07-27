#include <iostream>
#include <map>
using namespace std;
#define MAX 1010

int T, N;
int t[MAX];
map<int, int> cnt; // 각 팀의 참가한 인원수
map<int, int> currentCnt; // 각 팀의 현재까지 계산한 인원수
map<int, int> fifth; // 각 팀의 5번째 완주한 선수의 등수
map<int, int> score; // 각 팀의 점수
int currentScore; // 현재 저장할 점수
int minScore = 987654321; // 가장 낮은 팀의 점수
int winner; // 우승팀

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> T;
  while(T--) {
    cin >> N;
    for(int i=0; i<N; ++i) {
      cin >> t[i];
      ++cnt[t[i]];
    }

    for(int i=0; i<N; ++i) { 
      // 참가 인원이 6명보다 적으면 점수 기록 제외
      if(cnt[t[i]] < 6) continue;

      // 기록할 점수 증가
      ++currentScore;

      // 4명의 점수를 모두 계산했을 때
      if(currentCnt[t[i]] == 4) {
        // 동점일 경우를 고려하여 5번째 통과한 선수의 등수가 없으면 기록
        if(!fifth[t[i]]) fifth[t[i]] = i;
        continue;
      }

      // 점수 합산
      score[t[i]] += currentScore;
      ++currentCnt[t[i]];
    }

    for(const auto& s : score) {
      if(s.second < minScore) {
        winner = s.first;
        minScore = s.second;
      }

      // 점수가 같으면 5번째 통과한 선수의 등수를 비교
      else if(s.second == minScore) {
        if(fifth[s.first] < fifth[winner]) winner = s.first;
      }
    }

    cout << winner << '\n';

    // 초기화
    cnt.clear();
    currentCnt.clear();
    fifth.clear();
    score.clear();
    currentScore = 0;
    minScore = 987654321;
  }
}

// 시간복잡도: T * O(N)
// 공간복잡도: O(MAX)
// https://resilient-aura-65d.notion.site/9017-c1ead60ea28541f78c009898a3f42cac?pvs=4

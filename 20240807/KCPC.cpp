#include <iostream>
#include <cstring>
using namespace std;
#define MAX 105

int T;
//  팀의 개수 n, 문제의 개수 k, 당신 팀의 ID t, 로그 엔트리의 개수 m
int n, k, t, m;
// 팀 ID i, 문제 번호 j, 획득한 점수 s
int i, j, s;
int score[MAX];
int submitCnt[MAX];
int lastSubmit[MAX];
int problemScore[MAX][MAX]; // problemScore[팀ID][문제ID] = 문제에 대한 최종 점수
int ranking = 1;

void reset() {
  memset(score, 0, sizeof(score));
  memset(submitCnt, 0, sizeof(submitCnt));
  memset(lastSubmit, 0, sizeof(lastSubmit));
  memset(problemScore, 0, sizeof(problemScore));
  ranking = 1;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> T;
  while(T--) {
    cin >> n >> k >> t >> m;
    for(int k=0; k<m; ++k) {
      cin >> i >> j >> s;
      ++submitCnt[i];
      lastSubmit[i] = k;

      // 해당 문제에 대한 점수가 기존의 점수보다 더 높으면
      // 팀 점수와 해당 문제에 대한 점수를 갱신
      if(problemScore[i][j] >= s) continue;
      score[i] += (s - problemScore[i][j]);
      problemScore[i][j] = s;
    }

    // 내 팀의 등수 계산
    for(int k=1; k<=n; ++k) {
      if(t == k) continue;
      if(score[k] > score[t]) ++ranking;
      // 최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높다
      else if(score[k] == score[t]) {
        if(submitCnt[k] < submitCnt[t]) ++ranking;
        // 최종 점수도 같고 제출 횟수도 같은 경우, 마지막 제출 시간이 더 빠른 팀의 순위가 높다
        else if(submitCnt[k] == submitCnt[t]) {
          if(lastSubmit[k] < lastSubmit[t]) ++ranking;
        }
      }
    }

    cout << ranking << '\n';
    reset();
  }
}

// 시간복잡도: O(T * (m + n))
// 39:25
// https://resilient-aura-65d.notion.site/3758-KCPC-9b1127381e704d239d1d7bd21082a4e0?pvs=4

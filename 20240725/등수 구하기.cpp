#include <iostream>
#include <vector>
using namespace std;

int N, P, tsScore;
vector<int> score;
int tsRanking = 1;
int duplicateCnt; // 태수와 동일한 점수의 개수

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N >> tsScore >> P;

  // N이 0이면 태수는 항상 1등
	if(!N) {
    cout << 1 << '\n';
    return 0;
  }

  for(int i=0; i<N; ++i) {
    int s;
    cin >> s;
    score.push_back(s);
    // 태수와 동일한 점수의 개수 count
    if(s == tsScore) ++duplicateCnt;
  }

  // 태수의 랭킹 계산:
  // 배열을 순회하며 태수의 점수보다 크지 않은 점수가 있을 때까지 태수의 ranking을 하나씩 증가
  for(const auto& s : score) {
    if(s <= tsScore) break;
    ++tsRanking;
  }

  // '만약, 랭킹 리스트가 꽉 차있을 때, 새 점수가 이전 점수보다 더 좋을 때만 점수가 바뀐다'는 조건을 고려
  // 태수와 동일한 점수의 개수를 ranking에 포함하여 판별
  tsRanking + duplicateCnt > P ? cout << -1 << '\n' : cout << tsRanking << '\n';
}

// 시간복잡도: O(N)
// 공간복잡도: O(N)
// https://resilient-aura-65d.notion.site/1205-f126effebe534154a3d4d4796cc9509c?pvs=4

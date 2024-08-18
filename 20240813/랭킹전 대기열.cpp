#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 310

// 플레이어의 수 p, 플레이어의 닉네임 n, 플레이어의 레벨 l, 방 한개의 정원 m
int p, l, m;
string n;
int groupCnt;
int groupLevel[MAX][2]; // 각 방의 최소, 최대 level
vector<pair<int, string>> groupPlayer[MAX]; // 각 방에 입장한 플레이어 저장

// 사전순 출력을 위한 정렬 비교 함수
bool comp(const pair<int, string>& a, const pair<int, string>& b) {
  return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> p >> m;
  for(int i=0; i<p; ++i) {
    cin >> l >> n;

    bool isJoin = false; // 방 입장 여부
    for(int j=0; j<groupCnt; ++j) {
      // 방 입장 조건 검사
      if(groupPlayer[j].size() == m) continue;
      if(groupLevel[j][0] > l) continue;
      if(groupLevel[j][1] < l) continue;

      // 방 입장
      groupPlayer[j].push_back({l, n});
      isJoin = true;
      break;
    }

    // 방 생성
    if(isJoin) continue;
    groupPlayer[groupCnt].push_back({l, n});
    groupLevel[groupCnt][0] = l - 10;
    groupLevel[groupCnt][1] = l + 10;
    ++groupCnt;
  }

  // 출력
  for(int i=0; i<groupCnt; ++i) {
    groupPlayer[i].size() == m ? cout << "Started!" << '\n' : cout << "Waiting!" << '\n';
    // 사전순 출력을 위한 정렬
    sort(groupPlayer[i].begin(), groupPlayer[i].end(), comp);
    for(int j=0; j<groupPlayer[i].size(); ++j) {
      cout << groupPlayer[i][j].first << ' ' << groupPlayer[i][j].second << '\n';
    }
  }
}

// 시간복잡도: (불가능하게 높게 잡아도) O(p * groupCnt) + O(groupCnt * m * mlogm) ??
// O(p * groupCnt): 입력
// O(groupCnt * m * mlogm): 출력 → groupCnt와 m이 최댓값이라고 가정하면 300 * 300 * 300 * log300 < 3억
// https://resilient-aura-65d.notion.site/20006-f8d696013b6442f1b8423e499c25ef85?pvs=4

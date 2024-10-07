#include <iostream>
using namespace std;

int N, d, k, c;
int dish[30010]; // 회전 초밥 접시
int selected[3010]; // 현재 선택한 각 초밥의 개수
int answer;
int selectedK; // 현재까지 고른 접시의 개수(슬라이딩 윈도우 개수)
int selectedD; // 현재 고른 초밥의 종류
int s, e; // 두 포인터의 시작과 끝

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> d >> k >> c;

  // 쿠폰 초밥은 미리 추가
  selected[c]++;
  selectedD++;

  for(int i=0; i<N; ++i) {
    cin >> dish[i];

    // 아직 접시를 k개 고르지 않았을 때 실행
    if(selectedK >= k) continue;

    // 새로운 초밥 종류 추가
    if(selected[dish[i]] == 0) selectedD++;

    // 선택한 초밥의 개수 count
    selected[dish[i]]++;
    selectedK++;
  }

  // 처음 접시부터 순서대로 k개의 접시를 선택했을 때
  // 먹을 수 있는 초밥의 가짓수 계산
  s = 0;
  e = k - 1;
  answer = selectedD;

  while(s != N - 1) {
    // 시작 포인터 관리
    selected[dish[s]]--;
    if(selected[dish[s]] == 0) selectedD--;
    s = (s + 1) % N;

    // 끝 포인터 관리
    e = (e + 1) % N;
    if(selected[dish[e]] == 0) selectedD++;
    selected[dish[e]]++;

    // 정답 갱신
    if(answer < selectedD) answer = selectedD;
  }

  cout << answer << '\n';
}

// 시간복잡도: O(N)

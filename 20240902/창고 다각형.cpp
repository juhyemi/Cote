#include <iostream>
using namespace std;
#define MAX 1010

int N, L, H;
int pillars[MAX]; // 기둥의 위치와 높이 정보 저장
int answer;
int maxHeight, maxPos;
int leftMaxHeight, rightMaxHeight;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=0; i<N; ++i) {
    cin >> L >> H;
    pillars[L] = H;

    // 가장 높은 기둥의 높이와 위치를 저장
    if(maxHeight < H) {
      maxHeight = H;
      maxPos = L;
    }
  }

  // 가장 높은 기둥 기준 오른쪽 탐색
  // 0번째 기둥부터 살펴보며
  // 현재까지 등장한 가장 높은 기둥의 높이를 추가
  for(int i=0; i<maxPos; ++i) {
    if(pillars[i] > leftMaxHeight) leftMaxHeight = pillars[i];
    answer += leftMaxHeight;
  }

  // 왼쪽 탐색
  // 마지막 기둥부터 살펴본다
  for(int i=MAX-1; i>maxPos; --i) {
    if(pillars[i] > rightMaxHeight) rightMaxHeight = pillars[i];
    answer += rightMaxHeight;
  }

  // 가장 높은 기둥의 높이를 추가
  answer += pillars[maxPos];

  cout << answer << '\n';
}

// https://non-stop.tistory.com/36
// https://resilient-aura-65d.notion.site/2304-949c2aa248f344e3bae364b4de5ca890?pvs=4

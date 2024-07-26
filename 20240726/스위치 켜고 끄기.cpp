#include <iostream>
using namespace std;
#define MAX 110

int switchN, studentN;
bool switches[MAX];

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> switchN;
  for(int i=1; i<=switchN; ++i) {
    cin >> switches[i];
  }

  cin >> studentN;
  for(int i=0; i<studentN; ++i) {
    int gender, n;
    cin >> gender >> n;

    // 남성
    if(gender == 1) {
      for(int i=n; i<=switchN; i+=n) {
        switches[i] = !switches[i];
      }
    }

    // 여성
    else {
      // 구간 탐색
      int sectionSize = 0;
      while(true) {
        if(n - (sectionSize + 1) < 1 || n + (sectionSize + 1) > switchN) break;
        if(switches[n - (sectionSize + 1)] != switches[n + (sectionSize + 1)]) break;
        ++sectionSize;
      }

      // 구간에 속한 스위치의 상태 변경
      for(int i=n-sectionSize; i<=n+sectionSize; ++i) {
        switches[i] = !switches[i];
      }
    }
  }

  for(int i=1; i<=switchN; ++i) {
    cout << switches[i] << " ";
    if(i % 20 == 0) cout << '\n';
  }
  cout << '\n';
}

// 시간복잡도: O(switchN * studentN)
// 공간복잡도: O(switchN)

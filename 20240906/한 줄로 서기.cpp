#include <iostream>
using namespace std;
#define MAX 12

int N;
int result[MAX];
string s;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=1; i<=N; ++i) {
    int cnt; // 현재 사람보다 왼쪽에 키가 큰 사람의 총 인원
    cin >> cnt;

    for(int j=0; j<N; ++j) {
      // 왼쪽부터 살펴보며 현재 사람보다 키가 큰 사람이 더 이상 없을 경우
      // 빈 자리를 찾아 사람을 배치
      if(cnt == 0 && result[j] == 0) {
        result[j] = i;
        break;
      }

      // 아직 사람이 배치되지 않은 자리는 현재 사람보다 키가 큰 사람의 자리 (키가 작은 순서대로 살펴보기 때문)
      // 따라서 왼쪽부터 살펴보며 배치되지 않은 자리가 나타날 때마다
      // 현재 사람보다 키가 큰 사람의 수를 줄여준다
      else if(result[j] == 0) --cnt;
    }
  }

  for(int i=0; i<N; ++i) {
    cout << result[i] << ' ';
  }
}

// 시간복잡도: O(N^2)

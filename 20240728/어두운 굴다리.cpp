#include <iostream>
using namespace std;

int N, M;
int height, maxHeight;
int pos, prevPos;

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N >> M;
  for(int i=0; i<M; i++){
    cin >> pos;
    
    // 첫 번째 가로등일 때
    if(i == 0) {
      maxHeight = pos;
    }

    // 첫 번째 가로등이 아닐 때
    else {
      int interval = pos - prevPos;
      height = interval % 2 ? interval / 2 + 1 : interval / 2;
      if(maxHeight < height) maxHeight = height;
    }

    // 마지막 가로등일 때
    // cf. 가로등의 개수가 한 개이면 첫 번째 가로등이면서 마지막 가로등일 수 있다
    if(i == M-1) {
      if(maxHeight < N - pos) maxHeight = N - pos;
    }

    prevPos = pos;
  }

  cout << maxHeight << '\n';
}

// 시간복잡도: O(M)
// 공간복잡도: O(1)
// https://resilient-aura-65d.notion.site/17266-390aced786c440078dd415226f58b857?pvs=4

#include <iostream>
using namespace std;
#define MAX 110

int N, K;
int A[2 * MAX]; // 내구도
int step;
int zeroCnt; // 내구도 0인 벨트의 개수
int upIdx, downIdx; // 올리는 위치, 내리는 위치
bool robot[2 * MAX]; // 해당 idx의 로봇 존재 여부

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> K;
  for(int i=0; i<2*N; ++i) {
    cin >> A[i];
  }

  upIdx = 0;
  downIdx = N - 1;

  while(zeroCnt < K) {
    ++step;

    // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    upIdx = (upIdx == 0 ? 2 * N - 1 : upIdx - 1);
    downIdx = (downIdx == 0 ? 2 * N - 1 : downIdx - 1);
    // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
    if(robot[downIdx]) robot[downIdx] = false;

    // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    /*
      가장 먼저 벨트에 올라간 로봇은 내리는 위치와 가장 가까운 로봇이기 때문에,
      (내리는 위치 - 1)부터 올리는 위치까지 차례로 살펴본다 (내리는 위치는 이미 위에서 확인 완료)
      그 외 위치에는 로봇이 존재할 수 없다
    */
   int currentIdx = downIdx;
    for(int i=0; i<N-1; ++i) {
      int nextIdx = currentIdx;
      currentIdx--;
      if(currentIdx < 0) currentIdx = 2 * N - 1;

      if(!robot[currentIdx]) continue; // 현재 위치에 옮길 로봇이 없으면 continue
      if(robot[nextIdx]) continue; // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며,
      if(A[nextIdx] < 1) continue; // 그 칸의 내구도가 1 이상 남아 있어야 한다.
      
      robot[currentIdx] = false;
      robot[nextIdx] = true;
      if(--A[nextIdx] == 0) ++zeroCnt;
    }

    // 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
    robot[downIdx] = false;

    // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    if(A[upIdx] == 0) continue;
    robot[upIdx] = true;
    if(--A[upIdx] == 0) ++zeroCnt;
  }

  cout << step << '\n';
}

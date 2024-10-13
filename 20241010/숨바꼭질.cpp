#include <iostream>
#include <queue>
using namespace std;
#define MAX 100010

int N, K, X; // X: 현재 위치
queue<pair<int, int>> q; // 위치, depth
bool visited[MAX];
int d[3] = {-1, 1, };
int depth;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

    cin >> N >> K;

    q.push({N, 0});
    visited[N] = true;
    while(!q.empty()) {
        d[2] = X = q.front().first; // d[2]에 현재 위치 저장
        depth = q.front().second;
        q.pop();

        // 목적지 도착
        // 출발점과 목적지가 같은 경우 depth = 0 출력 후 종료
        if(X == K) {
            cout << depth << '\n';
            return 0;
        }

        for(int i=0; i<3; ++i) {
            int next = X + d[i]; // (i=2) 일 때, (2*X) 위치로 이동
            if(next < 0 || next > 100000) continue;
            if(visited[next]) continue;
            q.push({next, depth + 1});
            visited[next] = true;
        }
    }
}

// 시간복잡도: O(MAX)

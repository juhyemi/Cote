#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 110

int answer;
queue<tuple<int, int, int>> q;
bool visited[MAX][MAX];
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps) {
    n = maps.size() - 1;
    m = maps[0].size() - 1;
    
    q.push({0, 0, 1}); // cf. 주의! 지나가야 하는 칸의 개수는 1부터 시작
    visited[0][0] = true;
    while(!q.empty()) {
        int y; // 현재 행 위치
        int x; // 현재 열 위치
        int depth; // 이동 횟수
        tie(y, x, depth) = q.front();
        q.pop();
        
        // 목적지에 도착하면 이동 횟수를 반환하고 종료
        if(y == n && x == m) return depth;
        
        // 동, 서, 남, 북 방향으로 이동
        for(int d=0; d<4; ++d) {
            int ny = y + dy[d]; // 이동 후 행 위치
            int nx = x + dx[d]; // 이동 후 열 위치
            // 예외 조건 검사
            if(nx < 0 || ny < 0 || nx > m || ny > n) continue;
            if(visited[ny][nx]) continue;
            if(!maps[ny][nx]) continue; // 벽이 있으면 이동 불가
            
            q.push({ny, nx, depth + 1});
            visited[ny][nx] = true;
        }
    }
    
    // 목적지에 도착하지 못했다면 -1을 반환
    return -1;
}

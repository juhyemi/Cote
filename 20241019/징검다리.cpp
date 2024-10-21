#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    // 이분탐색
    // 기준(mid): 각 기점 사이의 거리의 최솟값
    int left = 0;
    int right = distance;
    
    while(left <= right) {
        /*
            각 지점 사이의 거리의 최소값이 mid 값이 될 수 있는지 판단
            모든 각 지점 사이의 거리를 확인, 그 거리가 mid 보다 작으면 해당 바위를 제거
            제거한 바위의 개수로 mid 값 가능 여부를 확인
        */
        int mid = left + (right - left) / 2;

        int prev = 0; // 이전 바위의 위치
        int cnt = 0; // 제거한 바위 수
        for(int i=0; i<rocks.size(); ++i) {
            // 현재 바위와 이전 바위의 거리가 mid 미만이면
            // 현재 바위를 제거하여 거리를 늘린다
            if(rocks[i] - prev < mid) {
                cnt++;
            }
            
            // 현재 바위와 이전 바위의 거리가 mid 이상이면
            // 이전 바위의 위치를 현재 바위로 초기화
            else {
                prev = rocks[i];
            }
        }
        
        // 도착지점과 마지막 바위의 거리 판단
        if(distance - prev < mid) {
            cnt++;
        }
        
        // 제거한 바위의 개수가 n 이하면
        // 각 지점 사이의 거리의 최솟값이 mid 보다 클 수 있다
        if(cnt <= n) {
            answer = mid;
            left = mid + 1;
        }
        
        // 그렇지 않으면
        // mid 값 축소
        else {
            right = mid - 1;
        }
    }
    
    return answer;
}

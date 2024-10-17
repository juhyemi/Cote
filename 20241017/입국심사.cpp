#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll answer;

ll solution(int n, vector<int> times) {
    // 입국심사 시간 기준 오름차순 정렬
    // 입국심사를 하는데 소요될 수 있는 최대 시간을 구하기 위함
    sort(times.begin(), times.end());
    
    // 이분탐색
    // n명을 입국심사 하는데 걸리는 최소 시간을 구하기 위해
    // mid 시간이 주어졌을 때 몇 명을 입국심사 할 수 있는지 확인
    
    ll left = 1; // 입국심사를 하는데 소요될 수 있는 최소 시간
    ll right = n * (ll)times[times.size() - 1]; // 최대 시간
    
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        
        ll passed = 0; // 입국심사를 통과한 사람 수
        for(int i=0; i<times.size(); ++i) {
            passed += (mid / (ll)times[i]);
        }
        
        // mid 시간으로 n명 이상을 입국심사 할 수 있을 때 
        if(passed >= n) {
            answer = mid;
            right = mid - 1;
        }
        
        // 그렇지 않을 때
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}

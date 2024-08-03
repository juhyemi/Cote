#include <vector>
#include <cmath>
using namespace std;

int maxw, maxh;

int solution(vector<vector<int>> sizes) {
    for(const auto& size : sizes) {
        // 세로가 더 작은 경우
        if(max(size[0], maxw) * max(size[1], maxh) < max(size[0], maxh) * max(size[1], maxw)) {
            maxw = max(size[0], maxw);
            maxh = max(size[1], maxh);
        }
        
        // 가로가 더 작은 경우
        else {
            maxw = max(size[1], maxw);
            maxh = max(size[0], maxh);
        }
    }
    
    return maxw * maxh;
}

// 21:59
// https://resilient-aura-65d.notion.site/974ba567c93b4336a430ee1f16606d51?pvs=4

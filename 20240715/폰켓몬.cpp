#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int type;
map<int, bool> m;

int solution(vector<int> nums) {
    for(const auto& num : nums) {
        // 이미 존재하는 종류의 폰켓몬일 때
        if(m[num]) continue;
        
        // 그렇지 않을 때
        ++type;
        m[num] = true;
    }
    
    return min(type, (int)nums.size() / 2);
}

// https://resilient-aura-65d.notion.site/ebdbae5c5c8f4821906ded147fdabae3?pvs=4

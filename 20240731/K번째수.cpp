#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
vector<int> slice;
int startIdx, endIdx, findIdx;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    for(const auto& command : commands) {
        startIdx = command[0] - 1;
        endIdx = command[1] - 1;
        findIdx = command[2] - 1;
        
        // 하위 벡터 추출
        slice.assign(array.begin() + startIdx, array.begin() + endIdx + 1);
        
        sort(slice.begin(), slice.end());
        
        answer.push_back(slice[findIdx]);
        
        // reset
        slice.clear();
    }
    
    return answer;
}

// 10:44
// https://resilient-aura-65d.notion.site/K-1d983262015e4583b6e38d9928b2c292?pvs=4

#include <vector>
#include <algorithm>
using namespace std;

int answer;
int n; // peopleCnt
int lastIdx;

int solution(vector<int> people, int limit) {
    n = people.size();
    sort(people.begin(), people.end());
    lastIdx = n - 1;
    
    for(int i=0; i<=lastIdx; ++i) {
        // 현재 사람과 마지막 사람의 몸무게 합이 무게 제한을 넘으면
        // 마지막 사람은 따로 구출해야 하므로 count
        while(i != lastIdx && people[i] + people[lastIdx] > limit) {
            ++answer;
            --lastIdx;
        }
        
        // 현재 사람이 마지막 사람일 경우를 포함하여
        // 현재 사람과 마지막 사람을 구출
        ++answer;
        --lastIdx;
    }
    
    return answer;
}

// https://resilient-aura-65d.notion.site/3e657e8ff55448789b040ef196f8d00c?pvs=4

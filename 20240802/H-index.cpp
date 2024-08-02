#include <vector>
#include <algorithm>
using namespace std;

int answer;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    // i번째 논문이 (i+1)번 이상 인용되지 않을 때까지 정답을 하나씩 증가
    for(int i=0; i<citations.size(); ++i) {
        if(citations[i] < i + 1) break;
        ++answer;
    }
    
    return answer;
}

// https://resilient-aura-65d.notion.site/H-index-378c8d8762d94f91836ec96c07cdf8ec?pvs=4

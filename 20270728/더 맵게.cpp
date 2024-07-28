#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int answer;

int solution(vector<int> scoville, int K) {
    for(const auto& s : scoville) pq.push(s);
    
    while(pq.size() > 1 && pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int newScoville = first + second * 2;
        pq.push(newScoville);
        ++answer;
    }
    
    if(pq.top() < K) answer = -1;
    
    return answer;
}

// https://resilient-aura-65d.notion.site/d4e4141af534458e82c8a88e2dbceb7b?pvs=4

#include <vector>
#include <stack>
using namespace std;

stack<int> s; // 초 저장

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    for(int i=0; i<size; ++i) {
        // stack에 존재하는 가격이 떨어진 모든 주식가격에 대해
        while(!s.empty() && prices[s.top()] > prices[i]) {
            // 정답 배열에 기록
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        // 현재 주식가격에 대한 정보를 stack에 저장
        s.push(i);
    }
    
    // 반복문 순회 완료 이후 stack에 남아 있는 모든 주식가격에 대해
    while(!s.empty()) {
        // 정답 배열에 기록
        answer[s.top()] = size - 1 - s.top();
        s.pop();
    }
    
    return answer;
}

// 참고: https://ssocoit.tistory.com/15
// https://resilient-aura-65d.notion.site/fe7b562db5c94269b6936cec8425d1d1?pvs=4

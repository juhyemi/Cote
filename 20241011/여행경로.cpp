#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> answer;
bool visited[10010];
bool finished; // 항공권을 알파벳 순서대로 정렬 후, 처음 찾은 경로를 정답으로 반환하기 위한 변수 선언
               // cf. 이 변수가 없으면 마지막에 찾은 경로를 반환하게 되어 알파벳 순서가 앞서는 경로를 반환하지 X

bool comp(const vector<string>& a, const vector<string>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

void dfs(const vector<vector<string>>& tickets, string now, vector<string> path) {
    if(finished) return;
    
    if(path.size() == tickets.size() + 1) {
        answer = path;
        finished = true; // 해당 코드 필수
        return;
    }

    for(int i=0; i<tickets.size(); ++i) {
        if(visited[i]) continue;
        if(now != tickets[i][0]) continue;
        
        string next = tickets[i][1];
        
        // 백트래킹
        visited[i] = true;
        path.push_back(next);
        dfs(tickets, next, path);
        visited[i] = false;
        path.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), comp);
    vector<string> path; // 경로를 저장 할 배열
    path.push_back("ICN"); // 첫 번째 경로는 항상 "ICN"
    dfs(tickets, "ICN", path); // (tickets, 현재 도시, 경로)
    return answer;
}

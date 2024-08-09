#include <string>
#include <set>
using namespace std;

int answer;
char c[5] = {'A', 'E', 'I', 'O', 'U'};
set<string> s;

void dfs(string word) {
    if(word.length()) s.insert(word); // dfs() 처음 실행 시 set에 빈 문자열 삽입을 방지
    if(word.length() == 5) return;
    
    // 중복순열
    for(int i=0; i<5; ++i) {
        dfs(word + c[i]);
    }
}

int solution(string word) {
    dfs("");
    
    // 찾는 단어와 일치할 때까지 순서(정답)를 1씩 증가
    for(const auto& it : s) {
        ++answer;
        if(it == word) break;
    }
    
    return answer;
}

// 13:47
// https://resilient-aura-65d.notion.site/7e8cc0f398ae489384640aca9456940e?pvs=4

#include <string>
#include <vector>
using namespace std;

bool visited[55]; // words 배열 내 이미 바꿨던 단어가 있는지 여부 확인
int answer;

// 하나의 문자만 변경하여 해당 단어로 변환할 수 있는지 확인
// 가능하면 true, 불가능하면 false
bool check(string str1, string str2) {
    int cnt = 0;
    
    for(int i=0; i<str1.length(); ++i) {
        if(str1[i] != str2[i]) ++cnt;
    }
    
    if(cnt == 1) return true;
    return false;
}

void dfs(string changed, string target, vector<string> words, int depth) {
    // 변환 가능한 단어가 target 일 때, 변환 횟수(재귀 호출 횟수)를 반환하고 종료
    if(changed == target) {
        answer = depth;
        return;
    }
    
    // 백트래킹
    for(int i=0; i<words.size(); ++i) {
        if(visited[i]) continue;
        if(!check(changed, words[i])) continue;

        visited[i] = true;
        dfs(words[i], target, words, depth + 1);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    return answer;
}

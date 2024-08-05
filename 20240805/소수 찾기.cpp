#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define MAX_LEN 10
#define MAX_NUM 10000010

int answer;
bool prime[MAX_NUM];
bool visited[MAX_LEN];
map<int, bool> checked;

// 범위 내 모든 소수 판별 (에라토스테네스의 체)
void getPrime() {
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<=MAX_NUM; ++i) {
        if(!prime[i]) continue;
        for(int j=i*i; j<=MAX_NUM; j+=i) {
            prime[j] = false;
        }
    }
}

// 완전탐색 (백트래킹)
void dfs(string numbers, string s) {
    if(s.length() && !checked[stoi(s)]) {
        if(prime[stoi(s)]) ++answer;
        checked[stoi(s)] = true;
        if(s.length() == numbers.length()) return;
    }

    for(int i=0; i<numbers.length(); ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(numbers, s + numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {
    getPrime();
    dfs(numbers, "");
    return answer;
}

// 01:00:30
// https://resilient-aura-65d.notion.site/b3ecefed4d3c4af6b1e87aab0d896c4d?pvs=4

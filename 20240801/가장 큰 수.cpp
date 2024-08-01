#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string answer;
vector<string> v; // 정렬을 위한 vector

// 비교 함수
// 문자열 a + b와 b + a를 비교하여 내림차순 정렬
bool comp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    for(const auto& number : numbers) {
        v.push_back(to_string(number));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(const auto& it : v) {
        answer += it;
    }
    
    // 정답이 "000..."인 경우 "0" return
    if(answer[0] == '0') return "0";
    return answer;
}

// https://resilient-aura-65d.notion.site/324263a49446426c9c06c8c0b70f6520?pvs=4

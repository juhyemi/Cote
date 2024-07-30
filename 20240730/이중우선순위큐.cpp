#include <string>
#include <vector>
#include <set>
using namespace std;

multiset<int> ms; // 중복을 허용하는 set, default 오름차순 정렬

vector<int> solution(vector<string> operations) {
    for(const auto& operation : operations) {
        if(operation[0] == 'I') {
            int n = stoi(operation.substr(2));
            ms.insert(n);
        }
        
        else if(operation == "D 1") {
            if(ms.empty()) continue;
            ms.erase(prev(ms.end()));
        }
        
        else if(operation == "D -1") {
            if(ms.empty()) continue;
            ms.erase(ms.begin());
        }
    }
    
    if(ms.empty()) return {0, 0};
    return {*ms.rbegin(), *ms.begin()};
}

// 41:13
// https://resilient-aura-65d.notion.site/76ae2c09a4c649aaa3f48d3a741ab633?pvs=4

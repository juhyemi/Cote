#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
int answer = 1;

int solution(vector<vector<string>> clothes) {
    for(const auto& c : clothes) {
        ++m[c[1]];
    }
    
    for(auto it = m.begin(); it != m.end(); ++it) {
        answer *= (it->second + 1);
    }
    
    return answer - 1;
}

// https://resilient-aura-65d.notion.site/09ef87794cab42d69f297c00705f2e27?pvs=4

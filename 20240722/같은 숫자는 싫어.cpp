#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;

vector<int> solution(vector<int> arr) {
    int recent = -1;
    for(const auto& it : arr) {
        if(it == recent) continue;
        recent = it;
        answer.push_back(it);
    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string answer;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); ++i) {
        if(i == completion.size()) {
            answer = participant[i];
            break;
        }
        
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}

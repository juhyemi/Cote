#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; ++i) {
        if(phone_book[i+1].substr(0, phone_book[i].length()) == phone_book[i]) return false;
    }
    
    return true;
}

// https://resilient-aura-65d.notion.site/65e64723aed84210abdac0b2bff07111?pvs=4

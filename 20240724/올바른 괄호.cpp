#include <string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

bool solution(string s) {
    for(int i=0; i<s.length(); ++i) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        
        else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') return false;
            st.pop();
        }
    }
    
    if(!st.empty()) return false;

    return true;
}

// https://resilient-aura-65d.notion.site/329140ce9bb241af97c1b41baa0bc5ea?pvs=4

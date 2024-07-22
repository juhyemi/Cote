#include <iostream>
#include <string>
using namespace std;

string password;

bool condition() {
  bool flag = true; // 모음이 하나라도 있으면 false
  string recentType;
  char recent;
  int cmo = 0; // 연속되는 모음의 개수
  int cja = 0; // 연속되는 자음의 개수

  for(int i=0; i<password.length(); ++i) {
    // 모음일 때
    if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
      flag = false;
      if(recentType == "mo") ++cmo;
      else cmo = 1;
      recentType = "mo";
    }
    
    // 자음일 때
    else {
      if(recentType == "ja") ++cja;
      else cja = 1;
      recentType = "ja";
    }

    // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    if(cmo == 3 || cja == 3) return false;
    
    // 3. 같은 글자가 연속적으로 두 번 오면 안 되나, ee 와 oo는 허용한다.
    if(recent == password[i] && !(password[i] == 'e' || password[i] == 'o')) return false;
    recent = password[i];
  }

  // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
  if(flag) return false;

  return true;
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  while(true) {
    cin >> password;
    if(password == "end") break;
    if(condition()) cout << "<" << password << "> is acceptable." << '\n';
    else cout << "<" << password << "> is not acceptable." << '\n';
  }
}

// https://resilient-aura-65d.notion.site/4659-024b3626bab943018d5028d2ed2ce0dc?pvs=4

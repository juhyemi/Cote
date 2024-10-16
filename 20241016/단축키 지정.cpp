#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int N;
bool alphabet[26]; // 해당 idx의 알파벳을 단축키로 지정했는지 여부
vector<vector<string>> options;

// 공백을 포함한 문자열을, 공백을 기준으로 나눠 배열에 저장하여 반환하는 함수
vector<string> split(string str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string temp;

  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

// 해당 idx의 문자를 []로 감싸는 함수
string wrap(const string& s, int idx) {
  return s.substr(0, idx) + "[" + s[idx] + "]" + s.substr(idx + 1);
}

// 알파벳의 idx를 구하는 함수
// 대문자일 경우와 소문자일 경우를 구분하기 위해 선언
int getIdx(char c) {
  if(c >= 'A' && c <= 'Z') return c - 'A';
  return c - 'a';
}

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  cin.ignore(); // N을 입력받은 후 버퍼에 남아있는 개행 문자를 제거
                // cf. 이 코드가 없으면, 첫 번째 기능을 입력받을 때, 강제로 버퍼에 남아있는 개행 문자가 삽입

  for(int i=0; i<N; ++i) {
    vector<string> functions; // 각 option의 기능을 저장할 배열
    string s;
    getline(cin, s, '\n');
    functions = split(s, ' ');
    options.push_back(functions);
  }

  for(int i=0; i<N; ++i) {
    // 각 기능의 첫 글자를 단축키로 지정
    bool isChanged = false; // 단축키 지정 여부
    for(int j=0; j<options[i].size(); ++j) {
      char c = options[i][j][0]; // 각 기능의 첫번째 알파벳
      int idx = getIdx(c); // 알파벳의 idx

      
      if(alphabet[idx]) continue; // 해당 글자가 단축키로 지정되지 않았을 때 실행
      options[i][j] = wrap(options[i][j], 0); // 해당 글자를 []로 감싼다
      alphabet[idx] = true;
      isChanged = true;
      break;
    }

    // 미 단축키 지정 옵션 단축키 지정
    // 각 기능의 첫 글자를 제외한 나머지 글자 중 하나를 단축키로 지정
    // "각 기능의 첫 글자를 단축키로 지정"할 때의 로직과 같은 방식으로 진행
    if(isChanged) continue;
    for(int j=0; j<options[i].size(); ++j) {
      for(int k=1; k<options[i][j].size(); ++k) {
        char c = options[i][j][k];
        int idx = getIdx(c);
 
        if(alphabet[idx]) continue;
        options[i][j] = wrap(options[i][j], k);
        alphabet[idx] = true;
        isChanged = true;
        break;
      }
      if(isChanged) break;
    }
  }

  // 정답 출력
  for(int i=0; i<N; ++i) {
    for(int j=0; j<options[i].size(); ++j) {
      cout << options[i][j] << ' ';
    }
    cout << '\n';
  }
}

// 시간복잡도: O(N * "옵션별 기능의 개수 + 각 기능의 문자열 길이의 합(최대 55)")

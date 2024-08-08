#include <iostream>
#include <string>
using namespace std;

string S;
int zeroCnt, oneCnt;
int deleteZeroCnt, deleteOneCnt;
int idx;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> S;
  for(int i=0; i<S.length(); ++i) {
    if(S[i] == '0') zeroCnt++;
    if(S[i] == '1') oneCnt++;
  }

  // 앞에서부터 1의 개수의 절반만큼 1 제거
  idx = 0;
  while(deleteOneCnt < oneCnt / 2) {
    if(S[idx] != '1') {
      ++idx;
      continue;
    }

    S.erase(idx, 1);
    ++deleteOneCnt;
  }
  
  // 뒤에서부터 0의 개수의 절반만큼 0 제거
  idx = S.length() - 1;
  while(deleteZeroCnt < zeroCnt / 2) {
    if(S[idx] != '0') {
      --idx;
      continue;
    }

    S.erase(idx, 1);
    ++deleteZeroCnt;
  }

  cout << S << '\n';
}

// 시간복잡도: O(S.length)
// 11:44
// https://resilient-aura-65d.notion.site/20310-7b203b592fa6460c8ba529ffdc4a7b9d?pvs=4

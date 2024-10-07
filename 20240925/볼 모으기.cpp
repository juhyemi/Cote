#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N;
string ball;
char lastColor, firstColor;
int cnt1, cnt2, cnt3, cnt4;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;

  for(int i=0; i<N; ++i) {
    char c;
    cin >> c;
    ball.push_back(c);
  }

  /* 뒤로 몰아넣는 경우 */
  lastColor = ball[ball.length() - 1];
  bool flag = false; // 순서대로 살펴봤을 때, 처음과 다른 색의 볼이 나왔으면 true로 변환
  for(int i=ball.length()-2; i>=0; --i) {
    if(ball[i] == lastColor) {
      // 처음과 같은 색의 볼이 나왔을 때
      if(flag) cnt1++; // 처음과 다른 색의 볼이 나온 이후부터 count 증가
    }
    
    else {
      // 처음과 다른 색의 볼이 나왔을 때
      if(!flag) flag = true;
      cnt2++;
    }
  }

  /* 앞으로 몰아넣는 경우 */
  // 위와 같은 방식으로 진행
  firstColor = ball[0];
  flag = false;
  for(int i=1; i<ball.length(); ++i) {
    if(ball[i] == firstColor) {
      if(flag) cnt3++;
    }

    else {
      if(!flag) flag = true;
      cnt4++;
    }
  }
 
  // 네 가지 경우 중 가장 적은 횟수를 출력
  cout << min(min(cnt1, cnt2), min(cnt3, cnt4)) << "\n";
}

// 시간복잡도: O(N)

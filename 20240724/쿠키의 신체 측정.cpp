#include <iostream>
#include <vector>
using namespace std;
#define MAX 1010

int N;
char board[MAX][MAX];
bool findHeart;
pair<int, int> heart, spot, now;
int leftArm, rightArm, leftLeg, rightLeg, body;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N;
  for(int i=1; i<=N; ++i) {
    for(int j=1; j<=N; ++j) {
      cin >> board[i][j];

      if(!findHeart && board[i][j] == '*') {
        findHeart = true;
        heart = {i + 1, j};
      }
    }
  }

  // 왼쪽 팔
  now = {heart.first, heart.second - 1};
  while(board[now.first][now.second] == '*') {
    ++leftArm;
    now.second -= 1;
  }

  // 오른쪽 팔
  now = {heart.first, heart.second + 1};
  while(board[now.first][now.second] == '*') {
    ++rightArm;
    now.second += 1;
  }

  // 허리
  now = {heart.first + 1, heart.second};
  while(board[now.first][now.second] == '*') {
    ++body;
    now.first += 1;
    spot = now;
  }

  // 왼쪽 다리
  now = {spot.first, spot.second - 1};
  while(board[now.first][now.second] == '*') {
    ++leftLeg;
    now.first += 1;
  }

  // 오른쪽 다리
  now = {spot.first, spot.second + 1};
  while(board[now.first][now.second] == '*') {
    ++rightLeg;
    now.first += 1;
  }

  cout << heart.first << ' ' << heart.second << '\n';
  cout << leftArm << ' ' << rightArm << ' ' << body << ' ' << leftLeg << ' ' << rightLeg << '\n';

}

// 시간복잡도: O(N^2)
// 공간복잡도: O(MAX^2)
// https://resilient-aura-65d.notion.site/20125-375c9950f3714ff4af5802e6a3cf8335?pvs=4

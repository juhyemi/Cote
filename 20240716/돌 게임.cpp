#include <iostream>
using namespace std;
#define MAX 1010

int N;
int dp[MAX] = {0, 1, 2, 1, };

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> N;

  cout << (N % 2 == 1 ? "SK" : "CY");
}

// 시간복잡도: O(1)
// 공간복잡도: O(MAX)
// https://resilient-aura-65d.notion.site/9655-af07220f055f48cca0a15c1c308a3330?pvs=4

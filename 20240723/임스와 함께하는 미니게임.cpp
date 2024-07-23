#include <iostream>
#include <set>
using namespace std;

int N;
char game;
string name;
set<string> s;

int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

	cin >> N >> game;
  for(int i=0; i<N; ++i) {
    cin >> name;
    s.insert(name);
  }

  if(game == 'Y') {
    cout << s.size() << '\n';
  } else if(game == 'F') {
    cout << s.size() / 2 << '\n';
  } else if(game == 'O') {
    cout << s.size() / 3 << '\n';
  }
}

// 시간복잡도: O(N)
// 공간복잡도: O(1)
// https://resilient-aura-65d.notion.site/5c71e4ae4eb4426083505c09c2f09cd9?pvs=4

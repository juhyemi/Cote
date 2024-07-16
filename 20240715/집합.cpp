#include <iostream>
#include <cstring>
using namespace std;
#define MAX 22

int M, n;
string command;
bool number[MAX];

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> M;
	while(M--) {
		cin >> command;
		if(command == "add") {
			cin >> n;
			number[n] = true;
		} else if(command == "remove") {
			cin >> n;
			number[n] = false;
		} else if(command == "check") {
			cin >> n;
			cout << (number[n] ? 1 : 0) << "\n";
		} else if(command == "toggle") {
			cin >> n;
			number[n] = !number[n];
		} else if(command == "all") {
			memset(number, true, sizeof(number));
		} else if(command == "empty") {
			memset(number, false, sizeof(number));
		} else return 0;
	}
}

// 시간복잡도: O(M)
// 공간복잡도: O(MAX)
// https://resilient-aura-65d.notion.site/11723-4476880fd7a34229966ac2757a8fd8ee?pvs=4

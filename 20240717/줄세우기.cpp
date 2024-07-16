#include <iostream>
#include <vector>
using namespace std;
#define MAX 22

int P, T;
vector<int> student;
int n, answer;

int main() {
  ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);

  cin >> P;
  while(P--) {
    cin >> T;
    for(int i=0; i<20; i++) {
      cin >> n;
      if(student.empty() || student[student.size() - 1] < n) {
        student.push_back(n);
        continue;
      }

      for(int j=0; j<student.size(); j++) {
        if(student[j] > n) {
          answer += student.size() - j;
          student.insert(student.begin() + j, n);
          break;
        }
      }
    }

    cout << T << " " << answer << "\n";
    answer = 0;
    student.clear();
  }
}

// 시간복잡도: O(n^2) * P
// 공간복잡도: O(MAX)
// https://resilient-aura-65d.notion.site/aaef673008e5473381a88d7da0a10952?pvs=4

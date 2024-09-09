#include <vector>
using namespace std;

int answer;

int solution(vector<vector<int>> triangle) {
    for(int i=1; i<triangle.size(); ++i) {
        for(int j=0; j<=i; ++j) {
            // 맨 왼쪽
            if(j==0) triangle[i][j] += triangle[i-1][j];
            // 맨 오른쪽
            else if(j==i) triangle[i][j] += triangle[i-1][j-1];
            // 그 외
            // 둘 중 큰 수를 더하며 값을 갱신
            else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            
            answer = max(answer, triangle[i][j]);  
        }
    }
    
    return answer;
}

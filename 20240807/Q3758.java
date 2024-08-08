// KCPC
import java.util.*;
import java.io.*;
public class Q3758 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine()); //테스트 수
        for(int i=0; i<T; i++){
            int rank = 1;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); // 팀의 개수
            int k = Integer.parseInt(st.nextToken()); // 문제의 개수
            int t = Integer.parseInt(st.nextToken()); // 팀 ID
            int m = Integer.parseInt(st.nextToken()); // 풀이 개수
            int[][] arr = new int[n+1][k+1]; // 팀별 문제에 대한 점수
            int[] totalScore = new int[n+1]; // 총 점수
            int[] tried = new int[n+1]; // 시도횟수
            int[] submit = new int[n+1]; // 마지막 제출
            // 팀 ID, 문제번호, 점수
            for(int j=0; j<m; j++){
                st = new StringTokenizer(br.readLine());
                int team = Integer.parseInt(st.nextToken());
                int problem = Integer.parseInt(st.nextToken());
                int score = Integer.parseInt(st.nextToken());
                int now = arr[team][problem];
                tried[team]++;
                submit[team]=j;
                // 기존 점수보다 새로운 점수가 크면 둘의 차이만큼만 total에 더해준 후 갱신
                if(now<score){
                    totalScore[team] += score-now;
                    arr[team][problem]=score;
                }
            }
            for(int j=1; j<=n; j++) {
                if(j==t) continue;
                // 점수 낮으면 순위 밀려남
                if(totalScore[t]<totalScore[j]) rank++;
                // 점수 같을 때
                else if(totalScore[t]==totalScore[j]) {
                    // 시도 횟수 크면 밀려남
                    if(tried[t]>tried[j]) rank++;
                    // 시도 횟수 같을 때
                    else if(tried[t]==tried[j]) {
                        // 최종제출이 늦으면 밀려남
                        if(submit[t]>submit[j]) rank++;
                    }
                }
            }
            sb.append(rank).append("\n");
        }
        System.out.print(sb);
    }
}
//1:50~2:50
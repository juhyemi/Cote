// 1, 2, 3 더하기 4
import java.io.*;
public class Q15989 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[10001][4]; //만들기위한수, 마지막으로 끝나는 조합
        // 합이 3이하인 경우
        dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
        // 10000까지 만들 수 있는 경우의 수 미리 저장
        for(int j=4; j<=10000; j++){
            dp[j][1] = dp[j-1][1];
            dp[j][2] = dp[j-2][1] + dp[j-2][2];
            dp[j][3] = dp[j-3][1] + dp[j-3][2] + dp[j-3][3];
        }
        for(int i=0; i<n; i++){
            int k = Integer.parseInt(br.readLine());
            sb.append(dp[k][1]+dp[k][2]+dp[k][3]).append("\n");
        }
        System.out.print(sb);
    }
}

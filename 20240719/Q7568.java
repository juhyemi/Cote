import java.util.*;
import java.io.*;
public class Q7568 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][n];
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            int rank = 1;
            int tmpkg = arr[i][0];
            int tmpheight = arr[i][1];
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                if(arr[j][0]>tmpkg && arr[j][1]>tmpheight) rank++;
            }
            sb.append(rank).append(" ");
        }
        System.out.println(sb);
    }
}

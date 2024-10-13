// 주식
import java.util.*;
import java.io.*;
public class Q11501 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<t; i++){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] arr = new long[n];
            for(int j=0; j<n; j++){
                arr[j] = Long.parseLong(st.nextToken());
            }
            long max=0;
            long answer=0;
            for(int j=n-1; j>=0; j--){
                if(arr[j]>max) max=arr[j];
                else answer+=max-arr[j];
            }
            sb.append(answer).append("\n");
        }
        System.out.print(sb);
    }
}
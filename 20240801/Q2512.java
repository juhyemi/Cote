import java.util.*;
import java.io.*;
public class Q2512 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long total=0;
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            total+=arr[i];
        }
        Arrays.sort(arr);
        // 총예산
        int max = Integer.parseInt(br.readLine());
        int answer = 0;
        if(total<=max) answer = arr[n-1];
        else{
            int start = 0;
            int end = arr[n-1];
            // 예산 범위
            while(start<=end){
                // 예산 중앙값
                int mid = (start+end)/2;
                total = 0;
                for(int i=0; i<n; i++){
                    if(arr[i]<=mid) total += arr[i];
                    else total+=mid;
                }
                if(total>max) {
                    // 예산 최대값을 구하는 것이기 때문에 answer이랑 같이 갱신
                    end = mid-1;
                    answer = end;
                }else start = mid+1;
            }
        }
        System.out.println(answer);
    }
}
//11:27 - 11:56
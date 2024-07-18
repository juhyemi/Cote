import java.util.*;
import java.io.*;
public class Q10431 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            sb.append(st.nextToken()+" ");
            int[] arr = new int[20];
            int answer = 0;
            for(int j=0; j<20; j++){
                arr[j] = Integer.parseInt(st.nextToken());
                for(int k=0; k<j; k++) {
                    if(arr[k]>arr[j]) {
                        answer++;
                    }
                }
            }
            sb.append(answer+"\n");
        }
        System.out.print(sb);
    }

}

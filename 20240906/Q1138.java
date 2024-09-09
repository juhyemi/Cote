import java.util.*;
import java.io.*;
public class Q1138 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int[] answer = new int[n+1];
        for(int i=1; i<=n; i++){
            int j=1;
            while(true){
                if(arr[i]==0&&answer[j]==0){
                    answer[j]=i;
                    break;
                }else if(answer[j]==0){
                    arr[i]--;
                }
                j++;
            }
        }
        for(int i=1; i<=n; i++) {
            System.out.print(answer[i]+" ");
        }
    }
}

// 겹치는 건 싫어
import java.io.*;
import java.util.*;
public class Q20922 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        int answer = 0;
        int[] cnt = new int[100001];
        for(int i=0; i<n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int start=0,end=0;
        while(start<n && end<n){
            if(cnt[arr[end]]<k){
                cnt[arr[end]]++;
                end++;
                answer = Math.max(answer,end-start);
            }else{
                cnt[arr[start]]--;
                start++;
            }
        }
        System.out.println(answer);
    }
}
// 1:55 ~ 2:01 - 시간초과;

import java.util.*;
import java.io.*;
public class Q2607 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int answer = 0;
        String standard = br.readLine();
        int[] arr = new int[26];
        for(int i=0; i<standard.length(); i++) {
            arr[standard.charAt(i) - 'A']++;
        }
        for(int i=0; i<n-1; i++){
            String str = br.readLine();
            if(standard.length()<str.length()-1) continue;
            if(standard.length()>str.length()+1) continue;
            int[] temp = new int[26];
            for(int j=0;j<str.length(); j++){
                temp[str.charAt(j)-'A']++;
            }
            int cnt=0;
            int cnt2=0;
            for(int j=0; j<26; j++){
                if(temp[j]!=arr[j]) cnt+=Math.abs(temp[j]-arr[j]);
                if(Math.abs(temp[j]-arr[j])==1) cnt2++;
            }
            if(cnt<=1) {
                answer++;
            }else if(cnt==2&&cnt2==2){
                answer++;
            }
        }
        System.out.println(answer);
    }
}
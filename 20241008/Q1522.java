// 문자열교환
// 4:19~4:30->1번 test case 이해 x 답지확인
import java.util.*;
import java.io.*;
public class Q1522 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int maxA = 0;
        int cnta = 0;
        for(int i=0; i<str.length(); i++) if(str.charAt(i)=='a') cnta++;
        for(int i=0; i<str.length(); i++){
            int cnt=0;
            for(int j=i; j<i+cnta; j++){
                int idx = j;
                if(j>=str.length()) idx=j-str.length();
                if(str.charAt(idx)=='a') cnt++;
            }
            maxA = Math.max(cnt, maxA);
        }

        System.out.print(cnta-maxA);
    }
}

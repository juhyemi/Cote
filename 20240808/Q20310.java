// 타노스
import java.io.*;
public class Q20310 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();
        // 1의개수, 0의개수 count
        int cnt1 = 0;
        int cnt0 = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='0') cnt0++;
            else cnt1++;
        }
        // 절반 없앤다했기 때문에 2로 나눔
        cnt0/=2;
        cnt1/=2;
        // 사전순으로 나타내야 하기 때문에 1은 앞에서부터 0은 뒤에서부터 삭제
        if(cnt1!=0){
            for(int i=0; i<s.length(); i++){
                if(cnt1==0) break;
                if(chars[i]=='1') {
                    cnt1--;
                    chars[i]='2';
                }
            }
        }
        if(cnt0!=0){
            for(int i=s.length()-1; i>=0; i--){
                if(cnt0==0) break;
                if(chars[i]=='0') {
                    cnt0--;
                    chars[i]='2';
                }
            }
        }
        for(int i=0; i<chars.length; i++){
            if(chars[i]!='2') sb.append(chars[i]);
        }

        System.out.print(sb);
    }
}
// 23:18 ~ 23:25 - 25점;
// 23:50 - 문제 잘못이해해서 다시 풀고 완료

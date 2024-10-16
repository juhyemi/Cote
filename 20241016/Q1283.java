// 2:29 ~ 3:16
// 단축키 지정
import java.util.*;
import java.io.*;
public class Q1283 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] order = new String[n];
        for(int i=0; i<n; i++) order[i]=br.readLine();
        StringBuilder sb = new StringBuilder();
        Set<String> set = new HashSet<>();
        for(int i=0; i<n ;i++){
            // " " 로 나눠진 단어들 중 첫번째 단어가 set에 있는지 확인 후 없으면 [] 넣고 있으면 continue;
            String[] str = order[i].split(" ");
            boolean flag = true;
            for(int j=0; j<str.length; j++){
                String s = str[j];
                if(!set.contains(String.valueOf(s.charAt(0)).toUpperCase())){
                    set.add(String.valueOf(s.charAt(0)).toUpperCase());
                    str[j] = "["+str[j].charAt(0)+"]"+str[j].substring(1);
                    sb.append(String.join(" ", str)+"\n");
                    flag = false;
                    break;
                }
            }

            // 전체 단어 중 set에 없는게 있는지 확인
            if(flag){
                String str1 = order[i];
                for(int j=0; j<str1.length(); j++){
                    String s = String.valueOf(str1.charAt(j)).toUpperCase();
                    if(!s.equals(" ")&&!set.contains(s)){
                        set.add(s);
                        sb.append(str1.substring(0,j)+"["+str1.charAt(j)+"]"+str1.substring(j+1)).append("\n");
                        flag = false;
                        break;
                    }
                }
            }

            // 첫번째 단어에도 없고 전체 단어에도 없으면 그대로 넣기
            if(flag) sb.append(order[i]).append('\n');
        }
        System.out.println(sb);


    }
}

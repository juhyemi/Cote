// 에디터
import java.util.*;
import java.io.*;
public class Q1406 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int m = Integer.parseInt(br.readLine());
        Stack<String> s1 = new Stack<>();
        Stack<String> s2 = new Stack<>();
        for(int i=0; i<str.length(); i++){
            s1.push(String.valueOf(str.charAt(i)));
        }
        for(int i=0; i<m; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            switch(st.nextToken()){
                case "L": if(!s1.isEmpty()) s2.push(s1.pop()); break;
                case "D": if(!s2.isEmpty()) s1.push(s2.pop()); break;
                case "B": if(!s1.isEmpty()) s1.pop(); break;
                case "P": s1.push(st.nextToken()); break;
            }
        }
        while(!s1.isEmpty()){s2.push(s1.pop());}
        StringBuilder sb = new StringBuilder();
        while(!s2.isEmpty()){sb.append(s2.pop());}
        System.out.println(sb.toString());
    }
}

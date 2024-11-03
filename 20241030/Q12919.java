// A와 B 2
import java.util.*;
import java.io.*;
public class Q12919 {
    static int answer=0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        CHK(s,t);
        System.out.println(answer);
    }
    static void CHK(String s, String t){
        if(s.length()==t.length()) {
            if(s.equals(t)) answer=1;
            return;
        }
        if(t.charAt(t.length()-1)=='A') CHK(s, t.substring(0, t.length()-1));
        if(t.charAt(0)=='B') CHK(s,new StringBuilder(t.substring(1)).reverse().toString());
    }
}

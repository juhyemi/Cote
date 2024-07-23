import java.util.*;
import java.io.*;
public class Q25757 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        String s = st.nextToken();
        int m = 0;
        if(s.equals("Y")) {
            m=1;
        }else if(s.equals("F")) {
            m=2;
        }else if(s.equals("O")) {
            m=3;
        }
        HashSet<String> set = new HashSet<>();
        for(int i=0;i<n;i++) {
            set.add(br.readLine());
        }
        System.out.print(set.size()/m);
    }
}
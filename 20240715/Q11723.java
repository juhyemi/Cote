import java.util.*;
import java.io.*;

public class Q11723 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<Integer> set  = new HashSet<>();
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            switch(s){
                case "add":
                    set.add(Integer.parseInt(st.nextToken()));
                    break;
                case "remove":
                    set.remove(Integer.parseInt(st.nextToken()));
                    break;
                case "check":
                    if(set.contains(Integer.parseInt(st.nextToken()))) sb.append(1).append("\n");
                    else sb.append(0).append("\n");
                    break;
                case "toggle":
                    int tmp = Integer.parseInt(st.nextToken());
                    if(set.contains(tmp)) set.remove(tmp);
                    else set.add(tmp);
                    break;
                case "all":
                    int k = 1;
                    while(k<=20){
                        set.add(k);
                        k++;
                    }
                    break;
                case "empty":
                    set.clear();
                    break;
            }
        }
        System.out.print(sb);
    }

}

import java.util.*;
import java.io.*;
public class Q17266 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++) {
            stack.push(Integer.parseInt(st.nextToken()));
        }
        int max = n-stack.peek();
        while(stack.size()>1){
            int tmp = stack.pop()-stack.peek();
            if(tmp%2==0) max = Math.max(max, tmp/2);
            else max = Math.max(max, tmp/2 +1);

        }
        max = Math.max(stack.peek(), max);
        System.out.println(max);
    }
}

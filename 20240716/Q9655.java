//돌게임
import java.io.*;
public class Q9655 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String answer = "SK";
        if(n%2==0) answer="CY";
        System.out.println(answer);
    }
}

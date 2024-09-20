// 창고 다각형
import java.io.*;
import java.util.*;
public class Q2304 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][2];
        int max = 0;
        int idx = 0;
        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken()); // L
            arr[i][1] = Integer.parseInt(st.nextToken()); // H
        }
        // 넓이 순서대로 정렬
        Arrays.sort(arr, (o1,o2)->o1[0]-o2[0]);
        // 가장 높은 곳 기준으로 왼, 오 탐색 예정이기 때문에 가장 높은 곳 탐색
        for(int i=0; i<n; i++){
            if(max<arr[i][1]){
                max=arr[i][1];
                idx=i;
            }
        }
        // 가장 높은 곳 더해줌
        int answer = max;
        Stack<Con> stack = new Stack<>();
        // 왼쪽 먼저 탐색, 높은 곳 인덱스까지
        for(int i=0; i<=idx; i++){
            if(stack.isEmpty()) stack.push(new Con(arr[i][0],arr[i][1]));
            else if(stack.peek().h<=arr[i][1]){
                answer += (arr[i][0]-stack.peek().l) * stack.peek().h;
                stack.push(new Con(arr[i][0],arr[i][1]));
            }
        }
        stack = new Stack<>();
        // 오른쪽 탐색, 뒤에서 부터 높은 곳 까지
        for(int i=n-1; i>=idx; i--){
            if(stack.isEmpty()) stack.push(new Con(arr[i][0],arr[i][1]));
            else if(stack.peek().h<=arr[i][1]){
                answer += (stack.peek().l-arr[i][0]) * stack.peek().h;
                stack.push(new Con(arr[i][0],arr[i][1]));
            }
        }
        System.out.print(answer);
    }
}
// 넓이와 높이를 한 번에 처리하기 위한 class 선언
class Con{
    int l;
    int h;
    public Con(int l, int h){
        this.h=h;
        this.l=l;
    }
}
// 가희와 키워드
import java.util.*;
import java.io.*;
public class Q22233 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        HashSet<String> set = new HashSet<>();
        // 한 번 사용한 키워드는 삭제되어야 함. 키워드 여러번 사용가능 -> set 이용
        for(int i=0; i<n; i++){
            set.add(br.readLine());
        }
        for(int i=0; i<m; i++){
            // 사용한 키워드 배열 분리
            String[] str = br.readLine().split(",");
            // 사용한 키워드 set에서 삭제
            for(int j=0; j<str.length; j++) {
                set.remove(str[j]);
            }
            // 삭제 후 남은 키워드 append
            sb.append(set.size()).append("\n");
        }
        System.out.println(sb);
    }
}
// 4:16~4:23

// 영단어 암기는 괴로워
import java.util.*;
import java.io.*;
public class Q20920 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        // 빈도수 확인 위해 map에 넣음
        HashMap<String, Integer> map = new HashMap<>();
        for(int i=0; i<n; i++){
            String s = br.readLine();
            if(s.length()>=m){
                map.put(s, map.getOrDefault(s, 0)+1);
            }
        }
        // value값 순으로 내림차순
        List<String> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys, (v2,v1)->{
            // 빈도 수 같으면
            if(map.get(v1)==map.get(v2)){
                // 길이
                if(v1.length()==v2.length()){
                    //사전순
                    String[] str = {v1, v2};
                    Arrays.sort(str);
                    return Arrays.binarySearch(str, v2)-Arrays.binarySearch(str, v1);
                }
                return v1.length()-v2.length();
            }
           return map.get(v1)-map.get(v2);
        });
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(String s : keys) bw.write(s+"\n");
        bw.flush();
    }
}
// 25m
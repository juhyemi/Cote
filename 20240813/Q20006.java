// 랭킹전 대기열
import java.util.*;
import java.io.*;
public class Q20006 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Game>> ls = new ArrayList<>();
        for(int i = 0; i < p; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            String n = st.nextToken();
            boolean flag = false;
            if(ls.size()!=0){
                for(int j=0; j<ls.size(); j++){
                    // 방이 다 차지 않았고 level 범위 안에 들 때
                    if(ls.get(j).size()<m&&ls.get(j).get(0).level-10<=l&&ls.get(j).get(0).level+10>=l){
                        ls.get(j).add(new Game(l,n));
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
            }
            // 방이 없거나 level 범위 안에 드는 값이 없을 때
            ls.add(new ArrayList<>());
            ls.get(ls.size()-1).add(new Game(l,n));
        }
        for(int i=0; i<ls.size(); i++){
            if(ls.get(i).size()==m)sb.append("Started!").append("\n");
            else sb.append("Waiting!").append("\n");
            List<Game> game = ls.get(i);
            // name 기준으로 정렬
            Collections.sort(game,(o1,o2)->o1.name.compareTo(o2.name));
            for(Game g : game) sb.append(g.level+" "+g.name).append("\n");
        }
        System.out.println(sb);
    }
}
class Game{
    int level;
    String name;
    Game(int level, String name){
        this.level = level;
        this.name = name;
    }
}
//1:48 ~ 2:20

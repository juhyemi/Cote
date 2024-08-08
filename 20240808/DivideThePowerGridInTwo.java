// 전력망을 둘로 나누기
import java.util.*;
class DivideThePowerGridInTwo {
    static ArrayList<ArrayList<Integer>> ls = new ArrayList<>();
    static boolean[] visit;
    public int divideThePowerGridInTwo(int n, int[][] wires) {
        for(int i=0; i<=n; i++) ls.add(new ArrayList<Integer>());
        int answer = n;
        for(int i=0; i<wires.length; i++){
            ls.get(wires[i][0]).add(wires[i][1]);
            ls.get(wires[i][1]).add(wires[i][0]);
        }//map
        for(int i=0; i<wires.length; i++){
            int a = ls.get(wires[i][0]).indexOf(wires[i][1]);
            int b = ls.get(wires[i][1]).indexOf(wires[i][0]);
            // 선 연결 제거
            ls.get(wires[i][0]).remove(a);
            ls.get(wires[i][1]).remove(b);
            visit = new boolean[n+1];
            // 한쪽의 연결된 개수
            int k = BFS(1,0);
            // 원상복구
            ls.get(wires[i][0]).add(wires[i][1]);
            ls.get(wires[i][1]).add(wires[i][0]);
            // 연결되어있는 개수가 k일 때 다른 한 쪽의 개수는 n-k
            answer = Math.min(answer, Math.abs(n-2*k));
        }
        return answer;
    }
    static int BFS(int start, int cnt){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int k = q.poll();
            visit[k] = true;
            cnt++;
            for(int i=0; i<ls.get(k).size(); i++){
                int tmp = ls.get(k).get(i);
                if(!visit[tmp]) q.add(tmp);
            }
        }
        return cnt;
    }
}
// 22:47~23:05
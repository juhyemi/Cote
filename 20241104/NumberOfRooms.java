// 방의 개수
import java.util.*;
public class NumberOfRooms {
    // 0~7 방향별 움직임
    static int[] dx = {-1,-1,0,1,1,1,0,-1};
    static int[] dy = {0,1,1,1,0,-1,-1,-1};
    class numberOfRooms {
        public int solution(int[] arrows) {
            int answer = 0;
            // 0,0에서 시작
            Node now = new Node(0,0);
            // 방문확인 - 중복방문 -> 이어진다는 것! 원형
            Map<Node, List<Node>> map = new HashMap<>();
            for(int i:arrows){
                // 교차점 이슈 해결하려면 스케일 키워야해서 필요
                for(int j=0; j<=1; j++){
                    Node next = new Node(now.x+dx[i], now.y+dy[i]);
                    // 처음 방문
                    if(!map.containsKey(next)){
                        map.put(next, makeNode(now));
                        if(map.get(now)==null) map.put(now, makeNode(next));
                        else map.get(now).add(next);
                    }
                    // 재방문, 같은 간선 없는 경우 -> 원형! 카운트
                    else if(!map.get(next).contains(now)){
                        map.get(next).add(now);
                        map.get(now).add(next);
                        answer++;
                    }
                    // 이동 후 현재 노드 업데이트
                    now = next;
                }
            }
            return answer;
        }
        static List<Node> makeNode(Node n){
            List<Node> edge = new ArrayList<>();
            edge.add(n);
            return edge;
        }
        class Node{
            int x,y;
            Node(int x, int y){
                this.x=x;
                this.y=y;
            }
            // x,y 값 비교를 위해 밑의 오버라이드 필요함
            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Node node = (Node) o;
                return x == node.x && y == node.y;
            }

            @Override
            public int hashCode() {
                return Objects.hash(x, y);
            }
        }
    }

}

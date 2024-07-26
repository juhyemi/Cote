import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> q = new LinkedList<>();
        int answer = 0; //걸린시간
        int total = 0; //다리위에 있는 트럭 무게
        for(int i=0; i<truck_weights.length; i++){
            int tmp = truck_weights[i];
            while(true){
                if(q.isEmpty()){
                    q.add(tmp);
                    total+=tmp;
                    answer++;
                    break;
                }else if(q.size()==bridge_length){
                    total-=q.poll();
                }else{
                    if(weight>=tmp+total){
                        q.add(tmp);
                        total+=tmp;
                        answer++;
                        break;
                    }else{
                        q.add(0);
                        answer++;
                    }
                }
            }

        }
        return answer+bridge_length;
    }
}
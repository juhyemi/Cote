// 구명보트
import java.util.*;
class LifeBoat {
    public int lifeBoat(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int idx = 0;
        for(int i=people.length-1; i>=idx; i--){
            answer++;
            if(people[i]+people[idx]>limit) continue;
            else if(people[i]+people[idx]<=limit) {
                idx++;
            }
            if(idx==i) break;
        }
        return answer;
    }
}
// 4:29~4:41
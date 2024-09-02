//단속카메라
import java.util.*;

public class SurveillanceCamera {
    class surveillanceCamera {
        public int solution(int[][] routes) {
            int answer = 1;
            // 나간지점 정렬
            Arrays.sort(routes, (o1,o2)->o1[1]-o2[1]);
            int start = routes[0][1];
            for(int i=1; i<routes.length; i++){
                if(routes[i][0]>start){
                    start = routes[i][1];
                    answer++;
                }
            }
            return answer;
        }
    }
}

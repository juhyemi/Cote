// K번째수
import java.util.*;
class KthNumber {
    public int[] kthNumber(int[] array, int[][] commands) {
        int n = commands.length;
        int[] answer = new int[n];
        for(int i=0; i<n; i++){
            int st = commands[i][0];
            int end = commands[i][1];
            int k = commands[i][2];
            // 구간에 있는 수를 넣기 위해 tmp 배열 선언
            int[] tmp = new int[end-st+1];
            // for문 구간은 기존 배열에서 꺼내와야하는 인덱스.
            // 따로 계산하면 오히려 헷갈릴 것 같아 tmp배열용 idx 선언
            int idx = 0;
            for(int j=st-1; j<end; j++){
                tmp[idx] = array[j];
                idx++;
            }
            Arrays.sort(tmp);
            answer[i] = tmp[k-1];
        }
        return answer;
    }
}
// 9m
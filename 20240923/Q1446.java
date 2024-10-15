import java.util.*;
import java.io.*;

public class Q1446 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int[] minCost = new int[d + 1]; // 최단거리 저장용 배열
        List<Distance> distance = new ArrayList<>(0);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            if (end > d) continue;
            if (end - start < cost) continue;
            distance.add(new Distance(start, end, cost));
        }
        for (int i = 1; i <= d; i++) {
            minCost[i] = minCost[i - 1] + 1;
            for (int j = 0; j < distance.size(); j++) {
                if (distance.get(j).end == i) {
                    minCost[i] = Math.min(minCost[i], minCost[distance.get(j).start] + distance.get(j).cost);
                }
            }
        }
        System.out.print(minCost[d]);
    }
}
class Distance{
    int start,end,cost;
    Distance(int start, int end, int cost){
        this.start = start;
        this.end = end;
        this.cost = cost;
    }
}

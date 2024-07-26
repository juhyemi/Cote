import java.util.*;
import java.io.*;

public class Q9017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            int[] arr1 = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int j = 0; j < n; j++) {
                int k = Integer.parseInt(st.nextToken());
                arr1[j] = k;
                map.put(k, map.getOrDefault(k, 0) + 1);
            }
            List<Integer> ls = new ArrayList<>(); // 6명 모인 팀 번호
            for (int tmp : map.keySet()) {
                if (map.get(tmp) == 6) ls.add(tmp);
            }
            int[] score = new int[map.size() + 1];
            int[] count = new int[map.size() + 1];
            List<Integer> realArr = new ArrayList<>();
            for(int j=0; j<arr1.length; j++){
                if(ls.contains(arr1[j])){
                    realArr.add(arr1[j]);
                }
            }
            List<Checking> list = new ArrayList<>(); // 각 팀별 5번째 주자 점수
            for (int j = 0; j < realArr.size(); j++) {
                if (ls.contains(realArr.get(j))) {
                    if (count[realArr.get(j)] < 4) {
                        score[realArr.get(j)] += j+1;
                    } else if (count[realArr.get(j)] == 4) {
                        list.add(new Checking(realArr.get(j), j));
                    }
                    count[realArr.get(j)]++;
                }
            }

            int tmp = Integer.MAX_VALUE;
            int winteam = -1;
            int win5th = Integer.MAX_VALUE;

            for (int j = 1; j < score.length; j++) {
                if (score[j] == 0) continue;
                else {
                    if (tmp > score[j]) {
                        tmp = score[j];
                        winteam = j;
                        for (Checking c : list) {
                            if (c.team == j) {
                                win5th = c.th5_num;
                                break;
                            }
                        }
                    } else if (tmp == score[j]) {
                        int tmp5th = Integer.MAX_VALUE;
                        for (Checking c : list) {
                            if (c.team == j) {
                                tmp5th = c.th5_num;
                                break;
                            }
                        }
                        if (tmp5th < win5th) {
                            winteam = j;
                            win5th = tmp5th;
                        }
                    }
                }
            }
            sb.append(winteam).append("\n");
        }
        System.out.print(sb);
    }
}

class Checking {
    int team, th5_num;

    Checking(int team, int th5_num) {
        this.team = team;
        this.th5_num = th5_num;
    }
}

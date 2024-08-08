import java.util.*;
class Pirodo {
    static boolean[] visit;
    static int[][] dungeons;
    static int answer;
    public int pirodo(int k, int[][] dungeons) {
        answer = 0;
        this.dungeons = dungeons;
        visit = new boolean[dungeons.length];
        piro(k, 0);
        return answer;
    }
    static void piro(int k, int cnt){
        for(int i=0; i<dungeons.length; i++){
            if(k>=dungeons[i][0]&&!visit[i]){
                visit[i]=true;
                piro(k-dungeons[i][1], cnt+1);
                visit[i]=false;
            }
        }
        answer = Math.max(answer, cnt);
    }
}

//22:34~22:43
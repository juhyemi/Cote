import java.io.*;
import java.util.*;

public class Q8979 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Olim> ls = new ArrayList<>();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int gold = Integer.parseInt(st.nextToken());
            int silver =  Integer.parseInt(st.nextToken());
            int bronze = Integer.parseInt(st.nextToken());

            ls.add(new Olim(num, gold, silver, bronze, 0));
        }
        Collections.sort(ls);
        ls.get(0).rank=1;

        for(int i=1;i<ls.size();i++){
            Olim olim = ls.get(i);

            int tmpGold = ls.get(i-1).gold;
            int tmpSilver = ls.get(i-1).silver;
            int tmpBronze = ls.get(i-1).bronze;

            if(ls.get(i).num == k){
                answer = i;
            }
            if(olim.gold == tmpGold && olim.silver == tmpSilver && olim.bronze == tmpBronze){
                ls.get(i).rank = ls.get(i-1).rank;
            }else{
                ls.get(i).rank = i+1;
            }
        }
        System.out.println(ls.get(answer).rank);

    }
}

class Olim implements Comparable<Olim>{
    int num, gold, silver, bronze, rank;
    Olim(int num, int gold, int silver, int bronze, int rank) {
        this.num = num;
        this.gold = gold;
        this.silver = silver;
        this.bronze = bronze;
        this.rank = rank;
    }
    @Override
    public int compareTo(Olim n) {
        if(this.gold == n.gold){
            if(this.silver == n.silver){
                return n.bronze - this.bronze;
            }else{
                return n.silver - this.silver;
            }
        }else{
            return n.gold - this.gold;
        }
    }
}

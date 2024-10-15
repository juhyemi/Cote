//20:27~21:18
import java.util.*;
class TravelRoute {
    static boolean[] visit;
    static String[][] tickets;
    static List<String> ls = new ArrayList<>();
    public String[] travelRoute(String[][] tickets) {
        visit = new boolean[tickets.length];
        this.tickets = tickets;
        DFS("ICN", 1, "ICN");
        Collections.sort(ls);
        String[] answer = ls.get(0).split(" ");
        return answer;
    }
    static void DFS(String start, int cnt, String route){
        if(cnt>tickets.length) {
            ls.add(route);
        }
        for(int i=0; i<tickets.length; i++){
            if(!visit[i]&&tickets[i][0].equals(start)){
                visit[i] = true;
                DFS(tickets[i][1], cnt+1, route+" "+tickets[i][1]);
                visit[i] = false;
            }
        }

    }
}
import java.io.*;

public class Q4659 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
            String word = br.readLine();
            if(word.equals("end")) break;
            int cnt = 1;
            int chk1 = 0;
            int chk2 = 1;
            boolean flag = true;
            for(int i=0; i<word.length(); i++){
                if(word.charAt(i)=='a'||word.charAt(i)=='e'||word.charAt(i)=='i'||word.charAt(i)=='o'||word.charAt(i)=='u'){
                    if(chk1==0)chk1+=2;
                    else chk1++;
                    chk2=1;
                }else{
                    chk2++;
                    if(chk1!=0) chk1=1;
                }
                if(chk1==4||chk2==4){
                    flag=false;
                    break;
                }
                if(i!=0&&word.charAt(i)==word.charAt(i-1)){
                    if(word.charAt(i)=='e'||word.charAt(i)=='o'){
                        if(cnt<2) cnt++;
                        else{
                            flag=false;
                            break;
                        }
                    }else{
                        flag=false;
                        break;
                    }
                }else cnt=1;
            }
            if(chk1==0) {
                flag=false;
            }
            if(flag) sb.append("<"+word+"> is acceptable.").append("\n");
            else sb.append("<"+word+"> is not acceptable.").append("\n");
        }
        System.out.print(sb);
    }
}

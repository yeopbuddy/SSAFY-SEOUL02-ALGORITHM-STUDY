import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        Set<String> hashSet = new HashSet<>();
        int ansPerson = 0;
        int cnt = 0;
        char lastWord = ' ';
        boolean isOk = true;
        
        for(int i=0; i<words.length;i++){
            if (i==0) {
                hashSet.add(words[i]);
                lastWord = words[i].charAt(words[i].length()-1);
                continue;
            }
            if(!hashSet.contains(words[i])&&lastWord == words[i].charAt(0)) { 
                hashSet.add(words[i]);
                lastWord = words[i].charAt(words[i].length()-1);
                System.out.println(lastWord);
            } else { 
                ansPerson = i;
                System.out.println(i);
                isOk = false;
                break;
                        }
        }
        return isOk? new int[] {0,0} : new int[]{(ansPerson)%n+1, (ansPerson)/n+1};
        
        
    }
}

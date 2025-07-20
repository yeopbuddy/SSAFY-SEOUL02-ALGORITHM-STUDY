import java.util.*;
class Solution {
    
    public int solution(String[] want, int[] number, String[] discount) {
        
        // wish에 있으면 .. 원하는 걸 연속으로 얻을 수 있으면 ..
        int ans = 0;
        for(int i=0;i<=discount.length-10;i++){ // 시작하는 시점 
            Map<String,Integer> map = new HashMap<>();
            
            for(int j=0;j<want.length;j++){
                map.put(want[j],number[j]);
            }
            
            for(int j=i;j<i+10;j++){ // 시작점부터 10개 
                String target = discount[j];
                if(map.containsKey(target)){
                    map.put(target, map.get(target)-1);
                    if(map.get(target)==0) map.remove(target);
                }
                
            }
            if(map.isEmpty()) ans++;
        }
        return ans;
        
        
        
    }
}

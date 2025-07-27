import java.util.*;

class Solution {
    static int max;
    public int solution(int[] priorities, int location) {
        //순회하면서, 
        Queue<int[]> que = new LinkedList<>();
            // 첫번째에는 인덱스와 priority를 담자!
            // index, priorities 값 
        for(int i=0; i<priorities.length; i++){
            que.add(new int[] {i, priorities[i]}); 
        } // 값 넣기 
        updateMax(que);
        
        int ans = 1;
        
        while(!que.isEmpty()){
            int[] check = que.poll(); // 순회하면서 차근차근 조회하기 
            
            if(check[1] < max) { // 나온 숫자가 최대값보다 작은 경우 다시 가야함.... 
                que.add(check);
                // ans++;
                continue;
            }
            if(location == check[0] ) { //찾고자하는 값이 지금 뽑은 것과 일치하면 바로 출력
                updateMax(que);
                return ans;
            }
            
            
            if(check[1] == max){ //나온 숫자가 최대값인 경우 
                updateMax(que);
                ans++;
                continue;
            } 
            
            
                
            
        }
        
        return ans;
    }
    
    void updateMax(Queue<int[]> que){
        max = 0;
        int size = que.size();
        for(int i=0; i<que.size(); i++){
            int[] current = que.poll();
            max = Math.max(max, current[1]);
            que.add(current);
        }
    }
    
}

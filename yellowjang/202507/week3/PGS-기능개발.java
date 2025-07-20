import java.util.*; 

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        int cnt= 0; //전체 배포수 
        // 전체 배포수가 progresses 의 수와 동일할 때 다 완료된 것임! 
        int current = 0; //현재 타겟? 이 되는 순서 
        int cntOnce=0;
        while(cnt != progresses.length){
            // 포인터를 지정해놔야겠다. 
            cntOnce=0;
            for(int j=current;j<progresses.length;j++){ 
                progresses[j] += speeds[j];
                if(progresses[current]>=100) {
                    current++;
                    cnt++;
                    cntOnce++;
                }
            }
            
            if(cntOnce>0)answer.add(cntOnce);
            
        }   
        int[] result = new int[answer.size()];
        for (int i = 0; i < answer.size(); i++) {
            result[i] = answer.get(i);
        }
        return result;
    }
}
//-> 스택, 큐로 다시 풀어보기

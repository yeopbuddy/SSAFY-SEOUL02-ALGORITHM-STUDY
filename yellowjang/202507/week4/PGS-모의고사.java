import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        // 매
        int[] APattern = {1,2,3,4,5}; // 5개 단위로 반복 %5
        int[] BPattern = {2,1,2,3,2,4,2,5}; // 8개 단위로 반복 index 나누기 % 8
        int[] CPattern = {3,3,1,1,2,2,4,4,5,5}; //10개 단위로 반복 
        List<Integer> answer = new ArrayList<>();
        int A = 0;
        int B = 0;
        int C = 0;
        int maxScore = Integer.MIN_VALUE;
        for(int i=0; i<answers.length; i++){
            if(answers[i]==APattern[i%5]) A++;
            if(answers[i]==BPattern[i%8]) B++;
            if(answers[i]==CPattern[i%10]) C++;
                
        }
        maxScore = Math.max(A,Math.max(B,C));

        if(maxScore == A) answer.add(1);
        if(maxScore == B) answer.add(2);
        if(maxScore == C) answer.add(3);

        
        return answer.stream().mapToInt(i->i).toArray();
    }
}

import java.util.*; 

class Solution {
    public String solution(int[] numbers) {
        String[] strNumbers = new String[numbers.length];
        for(int i=0; i< numbers.length; i++){
            strNumbers[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strNumbers, (a,b)-> (b+a).compareTo(a+b));
        
        StringBuilder result =  new StringBuilder();
        for(String num : strNumbers){
            result.append(num);
        }
        
        if(result.charAt(0)=='0'){
            return "0";
        }
        return result.toString();
    }
}

class Solution
{
    public int solution(int n, int a, int b)
    {
        int A = a;
        int B = b;
        int N = n;
        int round=0;
        
        while(n!=1){
            A = (A+1)/2;
            B = (B+1)/2;
            round++;
            n/=2;
            if (A==B) break;
        }
        return round;
    }
    
}

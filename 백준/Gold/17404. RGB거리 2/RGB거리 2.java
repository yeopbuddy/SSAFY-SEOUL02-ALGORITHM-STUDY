
import java.io.*;
import java.util.*;

/*
 * BOJ 17404 : RGB거리 2
 * RGB 거리에 집이 N개 (1000 이하) 
 * 집은 빨강 초록 ㅍ ㅏ랑중 하나로 칠한다.
 * 1번집은 2번 N번과 다르다.
 * N번은 N-1, 1과 다르다.
 * i는 i-1, i+1번과 다르다. 색이
 * 
 * 각 집마다 각 색별 가격이 주어진다.
 * 모든 집을 규칙에 맞게 칠하는 최소비용을 구하라
 * 
 * 2차원 dp
 * dp[n][c] : n번째 집까지 봤을때 c 색으로 칠할때 최소 비용
 *  = min (dp[n-1][notC]..)+ color[n][c] 
 */
public class Main {
	
	static BufferedReader br;
	static StringTokenizer st;
	static int N;
	static int[][] cost;
	static int[][][] dp;
	final static int r =0;
	final static int g =1;
	final static int b =2;
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		cost = new int[N+2][3];
		dp = new int[N+1][3][3];
		
		for(int idx= 1; idx<=N;idx++) { 
			st = new StringTokenizer(br.readLine());
			for(int color = 0;color<3;color++) {
				cost[idx][color] = Integer.parseInt(st.nextToken());
			}
		}
		

		for(int i = 0;i<3;i++) {
			Arrays.fill(dp[1][i], 1001);
			Arrays.fill(dp[N][i], Integer.MAX_VALUE);
		}
		
		for(int startColor = 0; startColor<3 ; startColor++) {
			for(int idx=1; idx<=N;idx++) {
				if(idx==1) {
					dp[1][startColor][startColor] = cost[1][startColor];
					continue;
				}
				if(!((idx==N)&&startColor==r)) 
				dp[idx][r][startColor] = cost[idx][r] +
						Math.min(dp[idx-1][g][startColor], dp[idx-1][b][startColor]);
				if(!((idx==N)&&startColor==g)) 
				dp[idx][g][startColor] = cost[idx][g] +
						Math.min(dp[idx-1][r][startColor], dp[idx-1][b][startColor]);
				if(!((idx==N)&&startColor==b)) 
				dp[idx][b][startColor] = cost[idx][b] +
						Math.min(dp[idx-1][r][startColor], dp[idx-1][g][startColor]);

			}
		}
//		for(int startColor = 0; startColor<3 ; startColor++) {
//			System.out.println(Arrays.toString(dp[1][startColor]));
//			System.out.println(Arrays.toString(dp[2][startColor]));
//			System.out.println(Arrays.toString(dp[3][startColor]));
//		}
		
		
		int min = Integer.MAX_VALUE;
		for(int startColor = 0; startColor<3 ; startColor++) {
			for(int endColor = 0; endColor<3 ; endColor++) {
				min = Math.min(min, dp[N][endColor][startColor]);
			}
		}
		
		System.out.println(min);
		
	}
}
